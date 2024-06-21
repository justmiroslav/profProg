#pragma once
#include <string>
#include <unordered_map>

class UserHistory {
public:
    explicit UserHistory(const std::string& filename);
    void loadHistory();
    void saveHistory();
    void resetUser(const std::string& name);
    void resetAllUsers();
    int incrementFor(const std::string& name);
private:
    std::unordered_map<std::string, int> userCount;
    std::string filename;
};
