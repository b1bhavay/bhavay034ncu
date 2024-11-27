#include <stdio.h>

int main() {
    int marks[] = {80, 72, 14, 10, 25, 13}; 
    int n = sizeof(marks) / sizeof(marks[0]); 
    int sum = 0; 

    
    for (int i = 0; i < n; i++) {
        sum += marks[i]; 
    }

    
    printf("The sum of all scores is: %d\n", sum);

    return 0;
}
