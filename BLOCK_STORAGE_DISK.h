#ifndef BLOCK_STORAGE_DISK_H
#define BLOCK_STORAGE_DISK_H

#include "BLOCK_HEADER_BASE.h"
#include <string>
#include <vector>

class BlockDiskStorage {
private:
    std::string storage_root_path;

public:
    BlockDiskStorage(const std::string& root_path) : storage_root_path(root_path) {}
    
    bool save_block(const BlockHeader& block);
    BlockHeader load_block(uint64_t height);
    bool save_block_data(uint64_t height, const std::string& data);
    std::string load_block_data(uint64_t height);
    bool create_storage_directory();
};

#endif
