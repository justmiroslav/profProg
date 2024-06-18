#include "include/UserHistory.hpp"

namespace {
    constexpr std::string_view RESET_ALL_COMMAND = "bread";
    constexpr std::string_view DELETE_COMMAND = "delete";
}

int main(int argc, char* argv[]) {

    if (argc < 2 || argc > 3) {
        std::println("Usage: ./program.exe <name> [delete]");
        return 1;
    }

    bool isDelete = argc == 3 && std::string(argv[2]) == DELETE_COMMAND;
    if (!isDelete && argc == 3) {
        std::println("Unknown command: {}", argv[2]);
        return 1;
    }

    UserHistory userHistory("data/history.txt");
    userHistory.loadHistory();
    std::string name = argv[1];

    if (name == RESET_ALL_COMMAND) {
        userHistory.resetAllUsers();
    } else if (isDelete) {
        userHistory.resetUser(name);
    } else {
        int count = userHistory.incrementFor(name);
        if (count == 1) {
            std::println("Welcome, {}!", name);
        } else {
            std::println("Hello again(x{}), {}", count - 1, name);
        }
    }

    return 0;
}