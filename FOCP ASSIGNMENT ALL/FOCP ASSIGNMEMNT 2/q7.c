#include <stdio.h>

int main() {
    int marks[] = {15, 42, 90, 10, 45, 13}; 
    int n = sizeof(marks) / sizeof(marks[0]); 

    for (int i = 0; i < n; i++) {
        if (marks[i] % 2 == 0) {
            printf("Student %d (Marks = %d): Even\n", i + 1, marks[i]);
        } else {
            printf("Student %d (Marks = %d): Odd\n", i + 1, marks[i]);
        }
    }

    return 0;
}
