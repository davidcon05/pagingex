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
    const int pageTable[] = {2, 4, 1, 7, 3, 5, 6};    //
    FILE *fpIn;                                       //
    FILE *fpOut;                                      //
    int i, inputIndex;                                //
    unsigned int physAddrOut[16];                     //
    unsigned long bRead;                              //
    unsigned char virtualAddrIn[16];                  //
    
    /* Initialize and error check file pointers */
    if ((fpIn = fopen(argv[1], "rb")) == NULL) {
        printf("Error trying to open file %s\n", argv[1]);
        exit(1);
    }

    if ((fpOut = fopen(argv[2], "ab+")) == NULL) {
        printf("Error trying to open file %s\n", argv[1]);
        exit(2);
    }
    
    /* Translate and Write to Outfile*/
    inputIndex = 0;
    // Read in 16 bytes at a time, translate one address at a time
    while ((bRead = fread(virtualAddrIn, 1, sizeof(virtualAddrIn), fpIn)) > 0) 
    {
        // Translation Virtual Address to Physical Address
        for (i = 0; i < 16; i++)
        {
            // translate
            physAddrOut[i] = 
            // Write to Outfile
            fprintf(fpOut, "%02x ", virtualAddrIn[i]);

        }
    }

    // Close File pointers
    fclose(fpIn);
    fclose(fpOut);
    
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