#include <stdio.h>

int main() {
    int marks[] = {95, 50, 100, 31, 65, 63}; 
    int n = sizeof(marks) / sizeof(marks[0]);
    int sum = 0; 
    float average; 

    for (int i = 0; i < n; i++) {
        sum += marks[i]; 
    }

    average = (float)sum / n; 

    printf("The average score is: %.2f\n", average);

    return 0;
}
