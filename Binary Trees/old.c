#include <stdio.h>
#include <math.h>
#define SIZE 15

// function prototypes
void printArray(const int* list, int size);
void displayTree(const int* list, int size);

int main() {
    // create a linked list and show it and its binary tree in the console
    int list[SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4 };
    printArray(list, SIZE);
    displayTree(list, SIZE);

    return 0;
}

void printArray(const int* list, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d%s", *(list+i), ", ");
    }
    printf("\b\b]\n\n");
}

void displayTree(const int* list, int size) {
    int levels = 1+(log(size)/log(2)); // we can determine number of levels tree will have with 2^x = size
    // read math section 1

    for (int i = 0; i <= levels; i++) { // parse throug every level of the tree
        // calculate the space between (delta) value and the space before
        // see math section 2
        int between = pow(2, (levels-i+1));
        int before = (between/2)-1;

        for (int j = pow(2,i); j < pow(2,i+1); j++) {
            if (j > size) break; // stop the loop if going outside bounds

            if (j == pow(2,i)) { // first leaf of the left side of the tree
                printf("%*d", before, *(list+j-1));
            } else {
                printf("%*d", between, *(list+j-1));
            }
        }
        
        printf("\n"); // new line for every level
    }
}

/* math section 1
level 0 contains nodes 0 (1 node)
level 1 contains nodes 1 2 (2 nodes)
level 2 contains nodes 3 4 5 6 (4 nodes)
level 3 contains nodes 7 8 9 10 11 12 13 14 (8 nodes)

starting index of each level is 2^(level#)-1
number of nodes is also given by 2^(level#)
ending index is given by 2^(level#+1)-2
*/

/* math section 2
 0
1 2

   0
 1   2
3 4 5 6

       0
   1       2
 3   4   5   6
7 8 9 0 1 2 3 4

levels: 5
               0
total space = nodes*32
delta = 32 = 2^(levels-level)
space before = 15 = delta/2 - 1

       1               2
total space = nodes*16
delta = 16 = 2^(levels-level)
space before = 7 = delta/2 - 1

   3       4       5       6
total space = nodes*8
delta = 8 = 2^(levels-level)
space before = 3 = delta/2 - 1

 7   8   9   0   1   2   3   4
total space = nodes*4
delta = 4 = 2^(levels-level)
space before = 1 = delta/2 - 1

5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0
total space = nodes*2
delta = 2 = 2^(levels-level)
space before = 0 = delta/2 - 1
*/