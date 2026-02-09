#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    int i, j;
    char temp;

    scanf("%s", s);          // read the string
    j = strlen(s) - 1;       // last index

    for (i = 0; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    printf("%s", s);         // print reversed string
    return 0;
}

