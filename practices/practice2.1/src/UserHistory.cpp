#include "../include/UserHistory.hpp"
#include <fstream>

UserHistory::UserHistory(const std::string& filename) : filename(filename) {
    loadHistory();
}

void UserHistory::loadHistory() {
    std::ifstream in(filename);
    std::string name;
    int count;
    while (in >> name >> count) {
        userCount[name] = count;
    }
}

void UserHistory::saveHistory() {
    std::ofstream out(filename);
    for (const auto& [name, count] : userCount) {
        std::println(out, "{} {}", name, count);
    }
}

void UserHistory::resetUser(const std::string& name) {
    userCount.erase(name);
    saveHistory();
}

void UserHistory::resetAllUsers() {
    userCount.clear();
    saveHistory();
}

int UserHistory::incrementFor(const std::string& name) {
    int newCount = ++userCount[name];
    saveHistory();
    return newCount;
}
