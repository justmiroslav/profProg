#pragma once
#include <functional>
#include <mutex>
#include <typeindex>
#include <any>

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
    template<typename MessageType>
    void publish(const MessageType& message) {
        std::lock_guard<std::mutex> lock(mutex_);
        auto type = std::type_index(typeid(MessageType));
        for (auto& subscriber : subscribers_[type]) {
            std::any_cast<std::function<void(const MessageType&)>>(subscriber)(message);
        }
    }

    template<typename MessageType>
    void subscribe(std::function<void(const MessageType&)> callback) {
        std::lock_guard<std::mutex> lock(mutex_);
        auto type = std::type_index(typeid(MessageType));
        subscribers_[type].push_back(callback);
    }

private:
    std::mutex mutex_;
    std::unordered_map<std::type_index, std::vector<std::any>> subscribers_;
};
