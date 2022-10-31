#include <stdio.h>
#include <assert.h>

// structure definition consiting of 3 fields lowCount, mediumCount, highCount which will contain the count of each value
struct CountsByUsage {
  int lowCount;
  int mediumCount;
  int highCount;
};

// funtion to increment the count by taking two inputs 
// cycles array []={100, 300, 410, 500, 600, 900, 950, 1000, -10} 
// nBatteries: number of batteries
struct CountsByUsage countBatteriesByUsage(const int* cycles, int nBatteries) {
  // initializing the counts by 0, 0, 0
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
  // returning the count structure
  return counts;
}

void testBucketingByNumberOfCycles() {
  const int chargeCycleCounts[] = {100, 300, 410, 500, 600, 900, 950, 1000, -10};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");

  // count variable will contain all the battery count with different levels
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  
  // hard coded value
  /*
  assert(counts.lowCount == 2);
  assert(counts.mediumCount == 3);
  assert(counts.highCount == 1);
  */
  printf("Done counting :)\n");

  // printing the number of count batteries as well
  printf("Printing the count as well\n");
  printf("Number of Low count batteries: %d\n",counts.lowCount);
  printf("Number of Medium count batteries: %d\n",counts.mediumCount);
  printf("Number of High count batteries: %d\n",counts.highCount);
}

int main() {
  // calling testBucketingByNumberOfCycles() from main()
  testBucketingByNumberOfCycles();
  // since main is returning nothing 
  return 0;
}
