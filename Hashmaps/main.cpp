#include "Hashmap.h"
#include "Hashtable.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
    // TEST THE MAP
    // Hashmap map(100);

    // map.insert("Hello");
    // map.insert("dlroW");
    // map.insert("World");
    // map.insert("!");
    // map.insert(":)");

    // map.find("World");
    // map.find("Goodbye");
    // map.find(":)");

    // TEST THE TABLE
    Hashtable table(100);

    table.insert("Hello");
    table.insert("dlroW");
    table.insert("World");
    table.insert("!");
    table.insert(":)");

    table.find("World");
    table.find("dlroW");
    table.find("Goodbye");
    table.find(":)");

    return 0;
}