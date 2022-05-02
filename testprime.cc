#include <iostream>
#include <cmath>
using namespace std;

bool test_if_prime(int num){
  for(int i = 2; i<num;i++){
    if (num%i==0){
      return false;
    }
  }
  return true;
}
int main() {
  bool prime;
  int how_many;
  cin>>how_many;
  int counter=0;
  int j=2;
  do {
    prime=test_if_prime(j);
	if(prime){
	  cout<<j<<endl;
	  counter=counter+1;
	}
	j=j+1;
  }while(counter<how_many);
}
