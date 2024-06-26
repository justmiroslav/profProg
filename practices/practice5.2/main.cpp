#include "MegaDataPool.hpp"
#include <print>
#include <thread>

MegaData& acquireFromPool() {
    return MegaDataPool::getInstance().acquire();
}

void releaseToPool(MegaData& obj) {
    MegaDataPool::getInstance().release(obj);
}

size_t getPoolUsage() {
    return MegaDataPool::getInstance().getUsedCount();
}

void worker(const std::stop_token& st, int thread_id) {
    if (st.stop_requested()) return;

    MegaData* obj = &acquireFromPool();
    if (obj) {
        double* bigArray = obj->getBigArray();
        float* smallArray = obj->getSmallArray();
        bigArray[0] = 2.71;
        smallArray[1] = 3.14f;
        std::println("Thread {} acquired object at address {}", thread_id, static_cast<void*>(obj));
        releaseToPool(*obj);
    } else {
        std::println("Thread {} failed to acquire object - pool is empty", thread_id);
    }
    std::println("Thread {} pool size: {}, pool usage: {}", thread_id, MegaDataPool::getInstance().getSize(), getPoolUsage());
}

int main() {
    MegaDataPool::getInstance(5);
    try {
        std::vector<std::jthread> threads;
        for (int i = 0; i < 10; ++i) {
            threads.emplace_back(worker, i);
        }
    } catch (const std::exception& e) {
        std::println("Exception caught: {}", e.what());
    }
    return 0;
}
