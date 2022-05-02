#include <iostream>
#include <iomanip>
#include <cmath>
#include <memory>
#include <vector>
using namespace std;
using std::vector;
using std::shared_ptr;
using std::make_shared;

class Node { 
private:
  int datavalue{0}; 
  shared_ptr<Node> next{nullptr};
  shared_ptr<Node> head{0};
  shared_ptr<Node> current{nullptr};
  shared_ptr<Node> tail{nullptr};
public:
  Node(int value)  : datavalue(value) {};
  void print() {
    cout << datavalue;
    if (next==nullptr)
      cout << endl;
    else {
      cout << ","<<current;
    }
  };
  void insert( shared_ptr<Node> data ){
    if(current==nullptr){
      current=data;
      tail=data;
    }
    if(data>current && data>tail){
      tail=data;
      next=nullptr;
    }
    if(data>current && data<tail){
      current=data;
      next=current;
    }
    if(data<current){
      next=current;
      current=data;
    }
  };
};

int main() {
  auto
    head = make_shared<Node>(0);
  int data;
  cin >> data;
  while (data>0) {
    auto newnode = make_shared<Node>(data);
    head->insert(newnode);
    head->print();
    cin >> data;
  };
  return 0;
}
