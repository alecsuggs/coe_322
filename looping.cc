#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      if (i*j > N){
	cout << i << "," << j << endl;
	i=11;
	break;
      }
    }
  }
  for(int sum=0; sum<=18; sum++){
    for(int i=0; i<10; i++){
      for(int j=0; j<10; j++){
	if(sum == i+j and i*j > N){
	  cout << i << "," << j << endl;
	  return 0;
	}
      }
    }
  }
}

