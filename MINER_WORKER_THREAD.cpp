#include "MINER_WORKER_THREAD.h"

MinerWorker::~MinerWorker() {
    stop_mining();
}

void MinerWorker::start_mining(const BlockHeader& block) {
    if (is_mining) return;
    template_block = block;
    is_mining = true;
    mine_thread = std::thread(&MinerWorker::mine_loop, this);
}

void MinerWorker::stop_mining() {
    if (!is_mining) return;
    is_mining = false;
    if (mine_thread.joinable()) mine_thread.join();
}

void MinerWorker::mine_loop() {
    while (is_mining) {
        template_block = pow_engine.mine_block(template_block);
        is_mining = false;
    }
}
