#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;
void Merge(vector<int>&A,int l,int m,int r)
{
  int i,j,k;
  int n1 = m-l+1;
  int n2 = r - m;
  int L[n1];
  int R[n2];
  for(i=0;i<n1;i++) L[i] = A[l+i];
  
  for(j=0;j<n2;j++) R[j] = A[m+j+1];
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  i=0;
  j=0;
  for(k=l;k<=r;k++)
  {
    if(L[i]<=R[j])
    {
      A[k] = L[i];
      i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
  }

}
void Merge_sort(vector<int>&A,int l,int r)
{
  if(l<r){
    int m = l+(r-l)/2;
    Merge_sort(A,l,m);
    Merge_sort(A,m+1,r);
    Merge(A,l,m,r);
  }
}

int main() {
  vector<int> A{9,8,7,6,5,4,3,2,1};
  cout<<"SIZE ="<<A.size()<<endl;
  cout<<"Before :";
  for(int x:A) cout<<x<<" ";
  Merge_sort(A,0,A.size()-1);
  cout<<"\nAfter  :";
  for(int x:A) cout<<x<<" ";
  cout<<endl;
}
