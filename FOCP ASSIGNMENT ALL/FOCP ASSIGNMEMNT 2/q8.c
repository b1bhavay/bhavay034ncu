#include <stdio.h>

int main() {
    int marks[] = {12, 92, 79, 76, 32, 13}; 
    int n = sizeof(marks) / sizeof(marks[0]); 

    int max = marks[0];
    int min = marks[0]; 

    for (int i = 1; i < n; i++) {
        if (marks[i] > max) {
            max = marks[i]; 
        }
        if (marks[i] < min) {
            min = marks[i];
        }
    }

    
    printf("Maximum score: %d\n", max);
    printf("Minimum score: %d\n", min);

    return 0;
}
