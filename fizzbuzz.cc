#include <iostream>
using namespace std;

int main() {
  int i;

  cin>>i;
  if (i%3==0 && i%5==0) 
  {
    cout << "Fizzbuzz!" << endl;
  } 
  else if (i%5==0) 
  {
    cout << "Buzz!"<< endl;
  }
  else if (i%3==0) 
  {
    cout << "Fizz!"<< endl;
  }
  return 0;
  }
