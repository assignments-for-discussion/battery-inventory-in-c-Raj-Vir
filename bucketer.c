//===========================================================================================================
// Input: Number of test Cases t, size of array numberOfBatteries, enter the levels chargeCycleCounts
// Output: printing the level count
//===========================================================================================================
// Sample testcases: 
/* Tested for different arrays
  50 -1 1100 500 -> array
  200 600 100
  100, 300, 500, 600, 900, 1000
*/
//===========================================================================================================
#include <stdio.h>
#include <assert.h>

// structure definition consiting of 3 fields lowCount, mediumCount, highCount
struct CountsByUsage {
  int lowCount;
  int mediumCount;
  int highCount;
};

// funtion to increment the count by taking two inputs 
// cycles array-[]={100, 300, 500, 600, 900, 1000} 
// nBatteries- number of batteries
struct CountsByUsage countBatteriesByUsage(const int* cycles, int nBatteries) {
  // counts contains the counting values of 3 fields in the structure
  struct CountsByUsage counts = {0, 0, 0};



  // loop begins from i=0 -> nBatteries-1
  for(int i=0;i<nBatteries;++i){

    // checks for any negative values present
    /*
    if(cycles[i]<0){
      printf("Invalid level: %d\n",cycles[i]);
    }
    */
    // checks the status of Battery if it is less than 410 then Low is printed
    if(cycles[i]<410){
      counts.lowCount+=1;
    }

    // else if it is greater than 410  and less 949 than then Medium is printed
    else if(cycles[i]>= 410 && cycles[i]<=949){
      counts.mediumCount+=1;
      
    }

    // else if it is greater than 950 than then High is printed
    else{
      counts.highCount+=1;
    }
  }
  return counts;
}

void testBucketingByNumberOfCycles() {
  
  const int chargeCycleCounts[] = {100, 300, 500, 600, 900, 1000};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0])
  printf("Counting batteries by usage cycles...\n");

  // count variable will contain all the battery count with different levels
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  
  
  assert(counts.lowCount == 2);
  assert(counts.mediumCount == 3);
  assert(counts.highCount == 1);
  printf("Done counting :)\n");
 
  /*
  // printing the number of count batteries as well
  // printf("Printing the count as well\n");
  printf("%d\n",counts.lowCount);
  printf("%d\n",counts.mediumCount);
  printf("%d\n",counts.highCount);
  */
  
  
}

int main() {
  testBucketingByNumberOfCycles();
  return 0;
}
