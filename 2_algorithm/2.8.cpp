#include <vector>
#include <ctime>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

long int* getRandomList1(long int size);
long int* getRandomList2(long int size);
long int* getRandomList3(long int size);
long int* computeAlgTime(long int* (*func)(long int), long int arg);

int main() {
  cout<<"=== one ==="<<endl;
  long int *nums1 = computeAlgTime(getRandomList1, 250);
  long int *nums2 = computeAlgTime(getRandomList1, 500);
  long int *nums3 = computeAlgTime(getRandomList1, 1000);
  long int *nums4 = computeAlgTime(getRandomList1, 2000);
  cout<<"=== two ==="<<endl;
  long int *nums5 = computeAlgTime(getRandomList2, 25000);
  long int *nums6 = computeAlgTime(getRandomList2, 50000);
  long int *nums7 = computeAlgTime(getRandomList2, 100000);
  long int *nums8 = computeAlgTime(getRandomList2, 200000);
  long int *nums9 = computeAlgTime(getRandomList2, 400000);
  long int *nums10 = computeAlgTime(getRandomList2, 800000);
  cout<<"=== three ==="<<endl;
  long int *nums11 = computeAlgTime(getRandomList3, 100000);
  long int *nums12 = computeAlgTime(getRandomList3, 200000);
  long int *nums13 = computeAlgTime(getRandomList3, 400000);
  long int *nums14 = computeAlgTime(getRandomList3, 800000);
  long int *nums15 = computeAlgTime(getRandomList3, 1600000);
  long int *nums16 = computeAlgTime(getRandomList3, 3200000);
  long int *nums17 = computeAlgTime(getRandomList3, 6400000);

  return 0;
}

// O(N^3)
long int* getRandomList1(long int size) {
  long int *nums = new long int[size];
  long int i = 0;

  srand(time(0));
  while (i < size)
  {
    long int randNum = (rand() * rand()) % size;
    bool hasNum = false;

    for (long int j = 0; j < i; j++)
    {
      if (nums[j] == randNum) {
        hasNum = true;
        break;
      }
    }
    if (!hasNum) {
      nums[i] = randNum;
      i++;
    }
  }

  return nums;
}

// O(N^2)
long int* getRandomList2(long int size) {
  long int* nums = new long int[size];
  long int i = 0;
  bool referArr[size];
  memset(referArr, false, size);

  srand(time(0));

  while (i < size)
  {
    // rand max num: 32700
    long int randNum = (rand() * rand()) % size;

    if (!referArr[randNum]) {
      referArr[randNum] = true;
      nums[i] = randNum;
      i++;
    }
  }

  return nums;
}

// O(N)
long int* getRandomList3(long int size) {
  long int *nums = new long int[size];
  
  srand(time(0));

  for (long int i = 0; i < size; i++) {
    nums[i] = i;
  }
  for (long int i = 1; i < size; i++) {
    swap(nums[i], nums[rand() % i]);
  }

  return nums;
}

long int* computeAlgTime(long int* (*func)(long int), long int arg) {
  struct timeb startTime, endTime;
  long int *nums;

  ftime(&startTime);
  nums = func(arg);
  ftime(&endTime);
  cout<<"spend time: "<<(endTime.time - startTime.time) * 1000 + (endTime.millitm - startTime.millitm)<<"ms"<<endl;

  return nums;
}
