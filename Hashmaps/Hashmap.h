#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>
#include <string>

class Hashmap {
    int capacity;
    std::vector<std::vector<std::string>> map;
public:
    Hashmap(int cap);
    void insert(const std::string& data);
    void find(const std::string& data);
    int generateKey(const std::string& data);
};

#endif