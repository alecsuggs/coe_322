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

struct primesequence {
  int num_primes_found; int last_num_tested;
};

int nextprime(struct primesequence &sequence) {
  int counter = sequence.last_num_tested + 1;
  bool prime=test_if_prime(counter);
   while (prime==false) {
    counter++;
    prime=test_if_prime(counter);
  }
  sequence.num_primes_found++;
  sequence.last_num_tested = counter;
  return counter;
}

int main() {
  int nprimes;
  cin>>nprimes;
  struct primesequence sequence={0.,1.};
  while (sequence.num_primes_found<nprimes){
    int number = nextprime(sequence);
    cout << "Number " << number << " is prime" << endl;
  }



}
