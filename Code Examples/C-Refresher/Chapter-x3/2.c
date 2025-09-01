// Prepared by Dr. Kurian Polachan
#include <stdio.h>

int main() {

    int marks = 10;
    char grade;

    if (marks >= 90) grade = 'A';
    else if (marks >= 75) grade = 'B';
    else if (marks >= 50) grade = 'C';
    else grade = 'F';

    switch(grade) {
        case 'A':
            printf("Excellent\n");
            break;

        case 'B':
            printf("Very Good\n");
            break;

        case 'C':
            printf("Good\n");
            break;

        default:
            printf("Failed\n");
    }

    return 0;
}
