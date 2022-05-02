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
  shared_ptr<Node> tail_ptr{nullptr};
public:
  Node() {} Node(int value)
    : datavalue(value) {};
  int value() { return datavalue; };
  bool has_next() {
    if (tail_ptr==nullptr)
      return false;
    else return true;
  };
  void set_tail( shared_ptr<Node> tail ) {
    tail_ptr = tail;
  };
  void append( shared_ptr<Node> tail ) {
    if (!has_next()) {
      set_tail(tail);
    } else {
      tail_ptr->append(tail);
    }
  };
  void insert (shared_ptr<Node> tail) {
    if (tail_ptr==nullptr) {
      set_tail(tail);
    }
    else if (tail->datavalue>tail_ptr->datavalue){
      tail_ptr->insert(tail);
    }
    else if (tail->datavalue==tail_ptr->datavalue){
      tail_ptr->datavalue = tail->datavalue;
    }
    else {
      auto next = make_shared<Node>(tail_ptr->datavalue) ;
      tail_ptr->datavalue = tail->datavalue;
      tail_ptr->insert(next);
    }
  };
  int list_length() {
    if (!has_next()) return 1;
    else
      return 1+tail_ptr->list_length();
  };
  void print() {
    cout << datavalue;
    if (!has_next())
      cout << endl;
    else {
      cout << ",";
      tail_ptr->print();
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
  }
  return 0;
}
