#include "Hashmap.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
    Hashmap map(100);

    map.insert("Hello");
    map.insert("dlroW");
    map.insert("World");
    map.insert("!");
    map.insert(":)");

    map.find("World");
    map.find("Goodbye");
    map.find(":)");

    return 0;
}