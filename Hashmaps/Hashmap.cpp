/**
 * This is a hashmap implementation which uses 2d vectors
 */
#include "Hashmap.h"
#include <iostream>

Hashmap::Hashmap(int cap) : capacity(cap), map(cap) {
}

void Hashmap::insert(const std::string& data) {
    int key = generateKey(data);
    map[key].push_back(data);
}

void Hashmap::find(const std::string& data) {
    int key = generateKey(data);
    for (int i = 0; i < map[key].size(); i++) {
        if (map[key][i] == data) {
            std::cout << "Found " << data << " at key: " <<
                key << " pos: " << i << std::endl;
            return;
        }
    }
    std::cout << "Did not find: " << data << std::endl;
}
int Hashmap::generateKey(const std::string& data) {
    int sum = 0;
    for (char c : data)
        sum+= static_cast<int>(c);
    return sum % capacity;
}