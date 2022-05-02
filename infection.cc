#include <iostream>
#include <iomanip>
#include <cmath>
#include <memory>
#include <vector>
using namespace std;
using std::vector;

class Person {
private:
  int state = 0;
public:
  Person() {};
  string status_string() {
    if (state==0)
      return "susceptible";
    if (state==-1)
      return "recovered";
    else 
      return "sick";

  };
  void update() {
    if (state>0)
      state=state-1;
    else if (state==1)
      state = -1;
    else
      state = state;
  };
  void infect (int ndays) {
    if (state==0)
      state = ndays+1;
  };
  bool is_stable() {
    if (state==-1)
      return true;
    else 
      return false;
  };
  int status() {
    return state;
  };
};

class Population {
private:
  int pop;
  vector<Person> people;
  vector<int> popstatus;
public:
  Population (int npeople)
    : pop(npeople), people(npeople,Person()), popstatus(npeople) {};
  void random_infection(int ndays) {
    int random = rand() % pop-1;
    people[random].infect(ndays);
  };
  auto get(int num) {return people[num]; };
  void count_infected() {
    for (int i=0; i=pop-1; i++) {
      Person who = people[i];
      if (who.status_string()=="sick")
	popstatus[i]=1;
      else if (who.status_string()=="susceptible")
	popstatus[i]=0;
      else 
	popstatus[i]=-1;
    }
  };
  void updatepop() {
    for (int i=0; i=pop-1; i++) {
      people[i].update();
    }    
  };
  void print() {
    for (int i = 0; i=pop-1; i++){
      cout<<people[i].status()<<",";
    }
    cout<< endl;
  };
};


int main() {
  Population Pop(5);
  int step = 1;
  Pop.random_infection(6);
  for(; ; step++) {
    Pop.updatepop();
    Pop.print(); 
    if (step==10)
      break;
  }
};
