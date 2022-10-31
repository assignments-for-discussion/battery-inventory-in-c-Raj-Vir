//===========================================================================================================
// Input: Number of test Cases t, size of array numberOfBatteries, enter the levels chargeCycleCounts
// Output: level indication and count
//===========================================================================================================
// Sample testcases: 
/*2-> number of test cases
  4 -> size
  50 -1 1100 500 -> array
  3
  200 600 100
 */
//===========================================================================================================
#include <stdio.h>
#include <stdlib.h> // for dynamic allocation of memory
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
  for(int i=0;i<nBatteries;i++){

    // checks for any negative values present
    if(cycles[i]<0){
      printf("Invalid level: %d\n",cycles[i]);
    }

    // checks the status of Battery if it is less than 410 then Low is printed
    else if(cycles[i]<410){
      counts.lowCount++;
      printf("Low\n");
    }

    // else if it is greater than 410  and less 949 than then Medium is printed
    else if(cycles[i]>= 410 and cycles[i]<=949){
      counts.mediumCount++;
      printf("Medium\n");
    }

    // else if it is greater than 950 than then High is printed
    else if(cycles[i]>=950){
      counts.highCount++;
      printf("High\n");
    }
  }
  return counts;
}

void testBucketingByNumberOfCycles() {
  int numberOfBatteries;
  // allowing user to enter the number of battery levels
  printf("Enter the number of battery levels you want to enter: ");
  scanf("%d",&numberOfBatteries);

  // dynamically allocation of array chargeCycleCounts
  int *chargeCycleCounts;
  chargeCycleCounts = (int *)malloc(numberOfBatteries*sizeof(int));
  
  // if memory is not allocated
  if(chargeCycleCounts==NULL){
    printf("Dynamic Allocation failed\n");
    exit(0);
  }


  // taking values from user
  printf("Enter the battery levels now: \n");
  for(int i=0;i<numberOfBatteries;i++){
    scanf("%d",&chargeCycleCounts[i]);
  }
  printf("Counting batteries by usage cycles...\n");

  // count variable will contain all the battery count with different levels
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  
  // hard coded value
  /*
  assert(counts.lowCount == 2);
  assert(counts.mediumCount == 3);
  assert(counts.highCount == 1);
  */
  

  // printing the number of count batteries as well
  printf("Printing the count as well\n");
  printf("Number of Low count batteries: %d\n",counts.lowCount);
  printf("Number of Medium count batteries: %d\n",counts.mediumCount);
  printf("Number of High count batteries: %d\n",counts.highCount);
  printf("Done counting :)\n");
  // freeing the dynamically allocated space after counting is done
  free(chargeCycleCounts);
}

int main() {
  // number of test cases
  int t;
  printf("Enter the Number of test cases:\n");
  scanf("%d",&t);
  // looping till test cases are finished
  while(t--)
    testBucketingByNumberOfCycles();
  return 0;
}
