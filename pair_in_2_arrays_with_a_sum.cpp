#include <iostream>
#include<vector>
using namespace std;
bool findpair(vector<int>&V,vector<int>&A,int sum){
  int first = 0;
  int last = A.size()-1;
  while(first<V.size() && last>=0){
    if(V[first]+A[last] ==  sum){
      cout<<"Pairs are : "<<V[first]<<" and "<<A[last];
      return 1;
    }
    else{
      // if(V[first]+A[last] > sum )
      // {
      //   last--;
      // }
      // else{
      //   first++;
      // }
      (V[first]+A[last] > sum)?last--:first++;
    }
  }
  return 0;
}
int main() {
  vector<int> V {6,7,11,12,13,16};
  vector<int> A {3,4,10,23,25,27,30}; 
  int sum = 40;
  if(!findpair(V,A,sum)){
    cout<<"No pair found :(";
  }
  return 0;
}
