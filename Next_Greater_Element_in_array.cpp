//BAD CODING PRACTICE
#include <iostream>
#include<vector>
using namespace  std;
//IN = [4,5,2,1,25]
//OUT = [5,25,25,25,-1]
//IN = [11,3,7,6,11,12]
//OUT = [12,7,11,11,12,-1]
//IN = [25,5,7,4,6]
//OUT = [-1,7,-1,6,-1]
//BRUTE FORCE APPROACH
int main() {
  vector<int> myvec;
  int size;
  cout<<"Enter the size"<<endl;
  cin>>size;
  vector<int> result(size);
  int temp=0;
  for(int i=0;i<size;i++){
    cin>>temp;
    myvec.push_back(temp);
  }
  for(int j=0;j<size;j++){
    result[j] =-1;
    for(int k=j+1;k<size;k++){
      if(myvec[k] > myvec[j]){
        result[j] = myvec[k];
        break;
      }
    }
  }
  for(auto x:result){
    cout<<x<<" , ";
  }
  return 0;
}
