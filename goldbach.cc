#include <iostream>
#include <cmath>
using namespace std;

bool test_if_prime(int num){
  for (int i=2; i < num; ++i){
    if(num % i == 0){
      return false;
    }
  }
  return true;
}

class primegenerator{
private:
  int how_many_primes_found,last_number_tested;
public:
  primegenerator(int num_found,int last_tested) : how_many_primes_found(num_found),last_number_tested(last_tested) {};
  int nextprime() {
    int counter = last_number_tested+1;
    bool prime=test_if_prime(counter);
    while (prime==false) {
      counter++;
      prime=test_if_prime(counter);
    }
    how_many_primes_found++;
    last_number_tested = counter;
    return counter;
  };
  int get_last_number_tested(){
    return last_number_tested;
  };
};


int main() {
  int upper;
  cout<< "Enter an even number- ";
  cin>>upper;
  for(int e = 4; e<=upper; e = e+2){
    primegenerator sequence (0.,1.);
    while (sequence.get_last_number_tested()<e){
      int q = e - sequence.nextprime();
      if(test_if_prime(q)){
        cout << "The number " << e << " is " << sequence.get_last_number_tested() << "+" << q << endl;
        break;
      }
    }
  }
}
