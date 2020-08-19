#include<iostream>
#include <vector>
#include<map>
#include<algorithm>
using namespace std;
void findpair_using_HASHING(vector<int>&V ,int sum)
{
  map<int,int> m;
  int diff;
  for(int i=0;i<V.size();i++)
  {
    diff = sum - V[i];
    
    auto itr = m.find(diff);
    if(itr!=m.end()){  
      cout<<V[i]<<" "; 
      cout<<diff ;
      return ;
    }
    m[V[i]] = diff;
  }
  return ;
}
void findpair_using_TWO_POINTER(vector<int>&V ,int sum)
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
  findpair_using_TWO_POINTER(V,sum);
  findpair_using_HASHING(V,sum);
  return 0;
}
