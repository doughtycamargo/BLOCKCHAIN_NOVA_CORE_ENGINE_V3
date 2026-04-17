#include "BLOCK_STORAGE_DISK.h"
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

bool BlockDiskStorage::create_storage_directory() {
    return fs::create_directories(storage_root_path);
}

bool BlockDiskStorage::save_block(const BlockHeader& block) {
    std::string path = storage_root_path + "/block_" + std::to_string(block.block_height) + ".dat";
    std::ofstream file(path);
    if (!file.is_open()) return false;
    
    file << block.block_height << "\n";
    file << block.prev_block_hash << "\n";
    file << block.merkle_root << "\n";
    file << block.nonce << "\n";
    file << block.difficulty << "\n";
    file << block.timestamp << "\n";
    return true;
}

BlockHeader BlockDiskStorage::load_block(uint64_t height) {
    BlockHeader block;
    std::string path = storage_root_path + "/block_" + std::to_string(height) + ".dat";
    std::ifstream file(path);
    if (!file.is_open()) return block;
    
    file >> block.block_height;
    file >> block.prev_block_hash;
    file >> block.merkle_root;
    file >> block.nonce;
    file >> block.difficulty;
    file >> block.timestamp;
    return block;
}

bool BlockDiskStorage::save_block_data(uint64_t height, const std::string& data) {
    std::string path = storage_root_path + "/data_" + std::to_string(height) + ".bin";
    std::ofstream file(path, std::ios::binary);
    if (!file.is_open()) return false;
    file.write(data.c_str(), data.size());
    return true;
}

std::string BlockDiskStorage::load_block_data(uint64_t height) {
    std::string path = storage_root_path + "/data_" + std::to_string(height) + ".bin";
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) return "";
    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}
