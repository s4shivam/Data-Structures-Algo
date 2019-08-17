#include <iostream>
using namespace std;
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
} 
int partition(int arr[],int l,int r)
{
    int x = arr[r];
    int i=l-1;
    for(int j=l;j<=r-1;j++)
    {
      if(x>=arr[j])
      {
        i++;
        swap(&arr[i], &arr[j]);
      }
    }
    swap(&arr[i+1], &arr[r]);
    return i+1;
}
void quick_sort(int arr[],int l,int r)
{
  if(l<r)
  {
    int p;
    p = partition(arr,l,r);
    quick_sort(arr, l, p-1);
    quick_sort(arr, p+1, r);
  }
}
int main()
{
  int arr[] = {11,10,9,8,6,5,7,4,-5,2,-6,-1};
  cout<<"Array Before Sorting : ";
  for(int x:arr){
    cout<<x<<" ";
  }
  cout<<endl;
  quick_sort(arr,0,11);
  cout<<"Array After Sorting : ";
  for(int x:arr){
    cout<<x<<" ";
  }
  return 0;
}

