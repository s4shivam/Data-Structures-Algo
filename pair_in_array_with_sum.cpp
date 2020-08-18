#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
void findpair(vector<int>&V ,int sum)
{
  sort(V.begin(),V.end());
  int l = 0;
  int r = V.size()-1;
  while(l<r)
  {
    if(V[l]+V[r] ==  sum){
      cout<<"pairs are : "<<V[l]<<" and "<<V[r];
      return;
    }
    else{
      V[l]+V[r] > sum ? r--:l++;
    }
  }
  return ;
}
int main()
{
  vector<int> V {5,2,4,3,9,7,11};
  int sum = 8;
  findpair(V,sum);
  return 0;
}
