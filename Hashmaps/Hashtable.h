#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

class Hashtable {
    int size;
    int capacity;
    std::string* table;
public:
    Hashtable(int cap);
    void insert(const std::string& data);
    void find(const std::string& data);
    int generateKey(const std::string& data);
};

#endif