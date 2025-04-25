/**
 * This is a hashtable implementation which uses single array
 */
#include "Hashtable.h"
#include <iostream>

Hashtable::Hashtable(int cap) : capacity(cap), size(0) {
    table = new std::string[cap];
}

void Hashtable::insert(const std::string& data) {
    if (size == capacity) {
        std::cout << "Table is full!";
        return;
    }

    int key = generateKey(data);
    while (!table[key].empty())
        key = (key+1) % capacity;
    table[key] = data;
    size++;
}

void Hashtable::find(const std::string& data) {
    int key = generateKey(data);
    int count = 0;
    while (table[key] != data) {
        key = (key+1) % capacity;
        if(count++ > capacity) break;
    }
    if (table[key] == data) std::cout << "Found " << data << " at key: " <<
        key << std::endl;
    else std::cout << "Did not find: " << data << std::endl;
}
int Hashtable::generateKey(const std::string& data) {
    int sum = 0;
    for (char c : data)
        sum+= static_cast<int>(c);
    return sum % capacity;
}