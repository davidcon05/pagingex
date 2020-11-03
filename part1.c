/******************************************************************
 * part1.c by David Contreras nsp028
 * Purpose:
 *     This program translates a logical address to a physical
 *     address. Program will read in all the logical addresses from
 *     Infile, translate them, and finally write them to specified 
 *     Outfile.
 *     
 * Usage:
 *      ./part1 Infile Outfile
 * 
 * Parameters:
 *      Infile - file of 12 bit binary virtual addresses
 *      Outfile - file of 10 bit binary physical addresses
 * 
 * Return:
 *      Hex translations of binary data 
 * Notes:
 * (1) What is the maximum number of pages a process can access? ( Answer: 32 pages ) VIRTMEM/BYTESPPG
 * (2) What is the total number of frames? ( Answer: 8 frames ) PHYSMEM/BYTESPPG
 * (3) How many entries does the pagetable contain? ( Answer: 32 entries ) 
 ******************************************************************/
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

// Won't need these if doing extra credit, they become user specified 
#define PHYSMEM 1024 // 10 bits
#define VIRTMEM 4096 // 12 bits virtual address
#define BYTESPPG 128 // 7 bit offset 

int main(int argc, char *argv[])
{
    // Parameter Check
    if (argc != 3)
        printf("Usage error: ./part3 InFile OutFile\n");
    // Intialize variables and pageTable
    const int pageTable[] = {2, 4, 1, 7, 3, 5, 6};
    //const int physicalFrame[] = {0, }
    FILE *fp;
    char inBuf[VIRTMEM];
    char *ptr;
    unsigned int physAddress;
    // Read in Infile
    // Close Infile
    // Translate
    // Write to Outfile
    // Close Outfile
    
    
    return 0;
}

/**************************** logicaAddTranslation ****************************
 * Purpose: 
 *     Translate 12 bit logical addresses to 10 bit physical address 
 * 
 * Parameters:
 *     unsigned int a,b     two unsigned representing frame number 'f'
 *                          and the offset 'd'
 * Returns: 
 *     physical address = 'f' + 'd'
 * 
 * Notes:
 *     
 ******************************************************************************/
void logicalAddrTranslation()
{

}

/********************************* concat *************************************
 * Purpose: 
 *     concatenate frame number and offset bits 
 * 
 * Parameters:
 *     unsigned int a,b     two unsigned representing frame number 'f'
 *                          and the offset 'd'
 * 
 * Returns: 
 *     physical address = 'f' + 'd'
 * 
 * Notes:
 *     Used to translate logical address to physical address
 ******************************************************************************/
int concat(unsigned int f, unsigned int d) 
{ 
    char firstBits[10]; 
    char offsetBits[12]; 
  
    // Convert both the integers to string 
    sprintf(firstBits, "%d", f);        // frame number bits
    sprintf(offsetBits, "%d", d);       // offset bits from logical address
    strcat(firstBits, offsetBits);      // Appends offsetbits to firstBits 
    unsigned int physicalAddr = atoi(firstBits); // convert string to usigned int
    return physicalAddr; 
} 