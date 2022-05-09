#include <iostream>
using namespace std;

unsigned int getOneCount(unsigned int n);

int main() {
  for (int i = 0; i <= 12; i++) {
    cout<<"by "<<i<<" has 1 count: "<<getOneCount(i)<<endl;
  }
}

unsigned int getOneCount(unsigned int n) {
  if (n == 1) return 1;
  if (n == 0) return 0;

  if (n % 2 == 0) {
    return getOneCount(n / 2);
  } else {
    return getOneCount(n / 2) + 1;
  }
}
