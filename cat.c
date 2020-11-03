// concatenates ints   
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <math.h>
  
// Function to concatenate two integers into one 
int concat(unsigned int a, unsigned int b) 
{ 
  
    char firstBits[20]; 
    char offsetBits[20]; 
  
    // Convert both the integers to string 
    sprintf(firstBits, "%d", a); 
    sprintf(offsetBits, "%d", b); 
    // Appends offsetbits to firstBits
    strcat(firstBits, offsetBits); 
    // Convert the concatenated string to integer 
    unsigned int physicalAddr = atoi(firstBits); 
  
    // return the formed integer 
    return physicalAddr; 
} 
  
int main() 
{ 
    unsigned int a = 23; 
    unsigned int b = 43; 
  
    printf("%d\n", concat(a, b)); 
    
    print("\nI'm too lazy to write another program, log math\n");
    unsigned int x, result;
    x = 8
    result = log10()


    return 0; 
} 
  
// This code is contributed by Ayush Singla(@ayusin51) 