
// Prepared by Dr. Kurian Polachan
#include <stdio.h>

int main() 
{
    int arr[] = {9, 1, 12, -3, 4, 22};
    int i;
    int *ptr;

    printf("1. Array Indexing:\n");
    printf("arr[3] = %d\n", arr[3]);

    printf("\n2. Pointer Traversal:\n");
    ptr = arr; printf("*ptr = %d\n", *ptr);
    ptr = ptr+1; printf("*ptr = %d\n", *ptr);
    ptr = &arr[3]; printf("*ptr = %d\n", *ptr);
    ptr = ptr - 1; printf("*ptr = %d\n", *ptr);

    printf("\n3. Pointer as Array: \n");
    ptr = arr; printf("ptr[2] = %d\n", ptr[2]);
    ptr = &arr[3]; printf("ptr[2] = %d\n", ptr[1]);
    ptr = &arr[3]; printf("ptr[-1] = %d\n", ptr[-1]);

    printf("\n4. Size of Pointer vs Array\n");
    printf("Size of pointer (ptr) = %d bytes\n", sizeof(ptr));
    printf("Size of array (arr) = %d bytes\n", sizeof(arr));
    printf("Number of elements in arr = %d\n", sizeof(arr) / sizeof(arr[0]));

    printf("\n5. Pointers\n");
    ptr = arr;     // now ptr stores address of arr[0]
    printf("%p\n", ptr);   // prints address of arr[0]
    printf("%d\n", *ptr);  // prints the content of arr[0] → 9
    printf("%p\n", &ptr);  // prints where ptr is stored in memory
    printf("%p\n", *&ptr);  // prints the content of ptr, i.e., address of arr[0]

    return 0;
}
