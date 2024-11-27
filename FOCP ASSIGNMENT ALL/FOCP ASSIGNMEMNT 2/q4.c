#include <stdio.h>

int main() {
    int marks[] = {85, 98, 70, 99, 80, 61, 99, 33}; 
    int n = sizeof(marks) / sizeof(marks[0]); 
    int count = 0; 

    
    printf("Students who scored 99: ");
    for (int i = 0; i < n; i++) {
        if (marks[i] == 99) {
            printf("Student %d (Index %d) ", i + 1, i);
            count++; 
        }
    }

    if (count > 0) {
        printf("\nTotal number of students who scored 99: %d\n", count);
    } else {
        printf("\nNo student scored 99.\n");
    }

    return 0;
}
