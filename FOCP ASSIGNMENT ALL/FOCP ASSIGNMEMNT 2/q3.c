#include <stdio.h>

int main() {
    int marks[] = {85, 72, 99, 90, 99, 65, 33}; 
    int n = sizeof(marks) / sizeof(marks[0]); 

    int found = 0; 

    
    for (int i = 0; i < n; i++) {
        if (marks[i] == 99) {
            printf("The first student who scored 99 is at index %d (Student %d).\n", i, i + 1);
            found = 1;
            break; 
        }
    }

    if (!found) {
        printf("No student scored 99.\n");
    }

    return 0;
}
