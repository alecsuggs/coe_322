#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
using std::vector;

class pascal{
private:
  int n; //height of triangle in rows
  vector<vector<int> > triangle; //array holding pascal coeffecients
public:
  pascal(int nrows) { //method creating coeffecient array
    n=nrows;
    int row=0;
    triangle=vector< vector<int> >(nrows, vector<int>(nrows));
    triangle[row][row]=1;
    row=1;
    while(row<n){
      int col=0;
      while (col<=row){
	if (col==0 or col==row){
	  triangle[row][col]=1;
	}
	else{
	  triangle[row][col]=triangle[row-1][col-1]+triangle[row-1][col];
	}
	col++;
      }
      row++;
    }
  };
  int get(int i,int j){ //method that retrieves a given row,column coeffecient
    return triangle.at(i).at(j);
  };
  void print(int m){   //method that prints triangular pascal coeffcient array
    for(int i = 0; i<n; i++){
      for(int j = 0; j<(n-i-1); j++)
	cout <<setw(3)<< " ";//printing space for triangular form
      for(int j = 0; j<(i+1); j++)
	  if(get(i,j) % m != 0){
	    cout <<setw(3)<< "*" <<setw(3)<< " "; //printing stars for non-zero modulo
	  }
	  else{
	    cout << setw(3)<< " "<< setw(3)<< " ";//blank space for zero modulo
	  }
      cout << endl;
    }
  };
};

  int main(){
    int n;
    int m;
    cout<<"Enter Number Of Rows"<< endl;
    cin>>n;
    pascal triangle(n);
    cout<<"Enter Modulo Numbers"<< endl;
    while(cin >> m){  //loop to accept numerous modulo values
      triangle.print(m);
    }
}
