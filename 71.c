/*Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.*/

#include <stdio.h>
#include <string.h>

#define EMPTY -1

int hash(int key, int m) {
    return key % m;
}

int main() {
    int m, q;
    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations
    
    int table[m];
    int i, j;
    
    for (i = 0; i < m; i++) {
        table[i] = EMPTY;
    }
    
    char op[10];
    int key;
    
    for (i = 0; i < q; i++) {
        scanf("%s %d", op, &key);
        
        if (strcmp(op, "INSERT") == 0) {
            for (j = 0; j < m; j++) {
                int idx = (hash(key, m) + j * j) % m;
                
                if (table[idx] == EMPTY) {
                    table[idx] = key;
                    break;
                }
            }
        }
        else if (strcmp(op, "SEARCH") == 0) {
            int found = 0;
            
            for (j = 0; j < m; j++) {
                int idx = (hash(key, m) + j * j) % m;
                
                if (table[idx] == key) {
                    found = 1;
                    break;
                }
                
                if (table[idx] == EMPTY) {
                    break;
                }
            }
            
            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }
    
    return 0;
}


