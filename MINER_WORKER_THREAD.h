#ifndef MINER_WORKER_THREAD_H
#define MINER_WORKER_THREAD_H

#include "CONSENSUS_POW_ENGINE.h"
#include "BLOCK_HEADER_BASE.h"
#include <atomic>
#include <thread>

class MinerWorker {
private:
    PoWEngine pow_engine;
    std::atomic<bool> is_mining;
    std::thread mine_thread;
    BlockHeader template_block;

    void mine_loop();

public:
    MinerWorker() : is_mining(false) {}
    ~MinerWorker();
    
    void start_mining(const BlockHeader& block);
    void stop_mining();
    bool is_mining_active() const { return is_mining; }
    BlockHeader get_mined_block() const { return template_block; }
};

#endif
