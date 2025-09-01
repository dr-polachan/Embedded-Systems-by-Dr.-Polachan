
// Prepared by Dr. Kurian Polachan
#include <stdio.h>

int main() 
{
    int arr[2][4] = {  {1,2,3,7}, 
                       {4,5,6,8}  };

    printf("arr[1][2] = %d\n", arr[1][2]);   

    int *ptr;
    ptr = &arr[0][0];      
    printf("*(ptr+4)    = %d\n", *(ptr+4));      
        
    ptr = arr[0];
    printf("ptr[2]  = %d\n", ptr[2]);    

    ptr = arr[1];
    printf("ptr[2]  = %d\n", ptr[2]);    
        
    ptr = &arr[0][2];   
    printf("*ptr: %d\n", *ptr);        
    printf("*(ptr+4): %d\n", *(ptr+4));        


    return 0;
}
