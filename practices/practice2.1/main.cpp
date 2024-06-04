#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>

std::unordered_map<std::string, int> userCount;

void loadHistory() {
    std::ifstream in("data/history.txt");
    std::string name;
    int count;
    while (in >> name >> count) {
        userCount[name] = count;
    }
}

void saveHistory() {
    std::ofstream out("data/history.txt");
    for (const auto& pair : userCount) {
        out << pair.first << " " << pair.second << "\n";
    }
}

void resetUser(const std::string& name) {
    userCount.erase(name);
    saveHistory();
}

void resetAllUsers() {
    userCount.clear();
    saveHistory();
}

void greetUser(const std::string& name) {
    if (userCount.find(name) == userCount.end()) {
        std::cout << "Welcome, " << name << "!\n";
    } else {
        std::cout << "Hello again(x" << userCount[name] << "), " << name << "\n";
    }
    userCount[name]++;
    saveHistory();
}

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        std::cout << "Error: Incorrect number of arguments.\n";
        return 1;
    }

    loadHistory();
    std::string name = argv[1];

    if (name == "bread") {
        resetAllUsers();
        return 0;
    }

    if (argc == 3 && std::string(argv[2]) == "delete") {
        resetUser(name);
        return 0;
    }

    greetUser(name);
    return 0;
}