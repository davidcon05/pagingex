#include <stdio.h>

// Won't need these if doing extra credit, they become user specified 
#define PHYSMEM 1024 // 10 bits
#define VIRTMEM 4096 // 12 bits virtual address
#define BYTESPPG 128 // 7 bit offset 

struct PGTABLE
{
	int validBit;
    int frameNum;
    unsigned int refCount;
};
                        
int main(int argc, char *argv[])
{

    int i;                          // iterator
    int LRU;
    int pgFault = 0;                // track page faults, when validBit == 0
    int nextFreeFrame = 1;          // track next free frame number 
    unsigned int refCounter = 0;    // track reference count for LRU 
    unsigned int p;
    unsigned int d;
    struct PGTABLE pgTable[VIRTMEM/BYTESPPG];

    // Initialize entire pgTable: validBit to 0 and others to -1  
    for(i = 0; i < VIRTMEM/BYTESPPG; i++) {
        pgTable[i].validBit = 0;
        pgTable[i].refCount = -1;
        pgTable[i].frameNum = -1;
    }

    // Translation: Starts with VA, ends with PA. 
    
    // LRU SNIPPET
    if (nextFreeFrame < (PHYSMEM/BYTESPPG))
            pgTable[p].frameNum = nextFreeFrame++;
    else {
        LRU = findLeastRecentlyUsed(pgTable);
        pgTable[p].frameNum = pgTable[LRU].frameNum;
        pgTable[LRU].validBit = 0;
    }
    pgTable[p].refCount = refCounter++;
    pgTable[p].validBit = 1;
    
    //Debug for pgTable.validBit initialization
    for(i = 0; i < VIRTMEM/BYTESPPG; i++) {
        printf("pgTable[%d].validBit = %d\n", i, pgTable[i].validBit);
        printf("pgTable[%d].frameNum = %d\n", i, pgTable[i].frameNum);
        printf("pgTable[%d].refCount = %d\n", i, pgTable[i].refCount);
        printf("======================================================\n");
    }
    
    return 0;
}

/************************** findLeastRecentlyUse ***********************************
 * Purpose:
 *     Locates the least recently used frame number in order to allocate it to a new 
 *     addresss
 * 
 * Parameters:
 *     struct PGTABLE pgTable[] - pgTable array for process memory allocations
 * 
 * Return:
 *     i - page table index number for least recently used frameNum
 *  9999 - error, failed to fine least recently used frame number index value
 * Notes:
 *     
 **********************************************************************************/
int findLeastRecentlyUsed(struct PGTABLE pgTable[])
{
    int i;                              // iterator
    int leastRecentlyUsed = 9999;       // index number of LRU
    // Iterate through pgTable active validBits and find the least recently used
    for(i = 0; i < (VIRTMEM/BYTESPPG); i++)
    {
        // Valid bit is active
        if(pgTable[i].validBit == 1)
            // Find index of lowest refCount value 
            if(leastRecentlyUsed > pgTable[i].refCount)
                leastRecentlyUsed = i;
    }

    return leastRecentlyUsed;
}