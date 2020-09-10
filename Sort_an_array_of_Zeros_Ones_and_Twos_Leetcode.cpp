#include <iostream>
#include<vector>
#include <algorithm>
using namespace  std;
void PrintArray(vector<int>arr){
  for(int itr:arr){
    cout<<itr<<" ";
  }
  cout<<endl;
  return;
}
void SortingUsing3Pointers(vector<int>&arr){
  int low =0;int mid = 0;
  int high = arr.size()-1;
  while(mid<=high){
    if(arr[mid]==0){
      swap(arr[mid],arr[low]);
      low++;
      mid++;
    }
    else if(arr[mid]==1){
      mid++;
    }
    else if(arr[mid]==2){
      swap(arr[mid],arr[high]);
      high--;     
    }
  }
  PrintArray(arr);
  return ;
}
void SortingUsingMap(vector<int>arr){
  int temp[3]={0,0,0};
  for(int itr:arr){
    if(itr==0){
      temp[0]++;
    }
    if(itr==1){
      temp[1]++;
    }
    if(itr==2){
      temp[2]++;
    }
  }
  cout<<"no of zero="<<temp[0]<<endl;
  cout<<"no of ones="<<temp[1]<<endl;
  cout<<"no of 2's="<<temp[2]<<endl;
  for(int i=0;i<temp[0];i++){
    arr[i] = 0;
  }
  for(int i=temp[0];i<temp[0]+temp[1];i++){
    arr[i] = 1;
  }
  for(int i=temp[1]+temp[0];i<temp[2]+temp[1]+temp[0];i++){
    arr[i] = 2;
  }
  PrintArray(arr);
}
void SortingUsingMergeSort(vector<int> arr){
  sort(arr.begin(),arr.end());
  PrintArray(arr);
  return;
}
int main()
{
  int N;
  cin>>N;
  vector<int> arr(N,-1);
  for(int i=0;i<N;i++){
    cin>>arr[i];
  }
  SortingUsingMergeSort(arr);
  SortingUsingMap(arr);
  SortingUsing3Pointers(arr);
  return 0;

}
