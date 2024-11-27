#include <stdio.h>

int main() {
    int marks[] = {55, 12, 98, 90, 19 , 33, 71}; 
    int n = sizeof(marks) / sizeof(marks[0]); 

    for (int i = 0; i < n; i++) {
        printf("Student %d: Marks = %d, Grade = ", i+1, marks[i]);

        if (marks[i] >= 75) {
            printf("A\n");
        } else if (marks[i] >= 60) {
            printf("B\n");
        } else if (marks[i] >= 40) {
            printf("C\n");
        } else {
            printf("D\n");
        }
    }

    return 0;
}
