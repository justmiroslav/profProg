#pragma once
#include <string>
#include <unordered_map>
#include <print>

class UserHistory {
public:
    explicit UserHistory(std::string filename);
    void loadHistory();
    void saveHistory();
    void resetUser(const std::string& name);
    void resetAllUsers();
    int incrementFor(const std::string& name);
private:
    std::unordered_map<std::string, int> userCount;
    std::string filename;
};