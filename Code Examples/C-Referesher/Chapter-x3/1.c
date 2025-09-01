// Prepared by Dr. Kurian Polachan
#include <stdio.h>

int main() {
    int marks = 60;

    if (marks >= 90) {
        printf("Grade: A\n");
    }
    else if (marks >= 75) {
        printf("Grade: B\n");
    }
    else if (marks >= 50) {
        printf("Grade: C\n");
    }
    else {
        printf("Grade: F (Fail)\n");
    }

    return 0;
}
