#pragma once
#include <functional>
#include <mutex>
#include <typeindex>
#include <any>
#include <atomic>
#include <condition_variable>
#include <thread>
#include <queue>

struct GreenMessage {
    std::string message;
    int counter;
};

struct BlueMessage {
    double value1;
    double value2;
};

struct OrangeMessage {
    std::string message1;
    std::string message2;
    int counter;
    double value;
};

class MessageDispatcher {
public:
    MessageDispatcher() : running(true) {
        dispatchThread = std::thread(&MessageDispatcher::dispatchMessages, this);
    }

    ~MessageDispatcher() {
        running = false;
        cv.notify_one();
        if (dispatchThread.joinable()) {
            dispatchThread.join();
        }
    }

    template<typename MessageType>
    void publish(const MessageType& message) {
        std::lock_guard<std::mutex> lock(mutex_);
        messageQueue.push([this, message] { dispatch(message); });
        cv.notify_one();
    }

    template<typename MessageType>
    void subscribe(std::function<void(const MessageType&)> callback) {
        std::lock_guard<std::mutex> lock(mutex_);
        subscribers_[std::type_index(typeid(MessageType))].push_back(callback);
    }

private:
    template<typename MessageType>
    void dispatch(const MessageType& msg) {
        auto& subscribers = subscribers_[std::type_index(typeid(MessageType))];
        for (auto& subscriber : subscribers) {
            std::any_cast<std::function<void(const MessageType&)>>(subscriber)(msg);
        }
    }

    void dispatchMessages() {
        while (running) {
            std::unique_lock<std::mutex> lock(mutex_);
            cv.wait(lock, [this] { return !messageQueue.empty() || !running; });

            if (messageQueue.empty()) {
                continue;
            }

            std::function<void()> task = std::move(messageQueue.front());
            messageQueue.pop();
            lock.unlock();

            task();
        }
    }

    std::mutex mutex_;
    std::unordered_map<std::type_index, std::vector<std::any>> subscribers_;
    std::condition_variable cv;
    std::queue<std::function<void()>> messageQueue;
    std::atomic<bool> running;
    std::thread dispatchThread;
};
