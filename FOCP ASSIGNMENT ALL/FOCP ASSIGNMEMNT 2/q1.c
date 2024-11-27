#include <stdio.h>

int main() {
    int n;


    printf("Enter the number of students: ");
    scanf("%d", &n);

    int marks[n]; 

    
    printf("Enter marks for %d students:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    
    for (int i = 0; i < n; i++) {
        marks[i] += 5;
    }

    
    printf("\nUpdated marks after increasing by 5:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: %d\n", i + 1, marks[i]);
    }

    return 0;
}
