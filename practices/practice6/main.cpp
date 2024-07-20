#include "MessageDispatcher.hpp"
#include <print>
#include <random>

void messageGenerator(MessageDispatcher& dispatcher) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 3);

    for (int i = 0; i < 5; ++i) {
        int msgType = dis(gen);
        if (msgType == 1) {
            GreenMessage msg{"Green Message", dis(gen)};
            dispatcher.publish(msg);
        } else if (msgType == 2) {
            BlueMessage msg{dis(gen) * 1.1, dis(gen) * 1.2};
            dispatcher.publish(msg);
        } else if (msgType == 3) {
            OrangeMessage msg{"Orange Msg 1", "Orange Msg 2", dis(gen), dis(gen) * 1.3};
            dispatcher.publish(msg);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    MessageDispatcher dispatcher;

    dispatcher.subscribe<GreenMessage>([](const GreenMessage& msg) {
        std::println("Green Message: {} {}", msg.message, msg.counter);
    });

    dispatcher.subscribe<BlueMessage>([](const BlueMessage& msg) {
        std::println("Blue Message: {} {}", msg.value1, msg.value2);
    });

    dispatcher.subscribe<OrangeMessage>([](const OrangeMessage& msg) {
        std::println("Orange Message: {} {} {} {}", msg.message1, msg.message2, msg.counter, msg.value);
    });

    std::thread t1(messageGenerator, std::ref(dispatcher));
    std::thread t2(messageGenerator, std::ref(dispatcher));

    t1.join();
    t2.join();

    return 0;
}
