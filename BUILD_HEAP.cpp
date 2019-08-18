#include <iostream>
#include<math.h>
#include<limits.h>
#include<vector>
using namespace std;
void max_heapify(vector<int>&arr,int i)
{
	int largest;
	int l = 2*i;
	int r = (2*i) + 1;
	if( l<= arr.size() && arr[l] > arr[i]) largest = l;
	else largest = i;
  	if(r <= arr.size() && arr[r] > arr[largest]) largest = r;
  	if(largest != i)
  	{
    	swap(arr[i],arr[largest]);
    	max_heapify(arr,largest);
	}
}
void min_heapify(vector<int>&arr,int i)
{
	int smallest;
	int l = 2*i;
	int r = (2*i) + 1;
	if( l<= arr.size() && arr[l] < arr[i]) smallest = l;
	else smallest = i;
	if(r <= arr.size() && arr[r] < arr[smallest]) smallest = r;
	if(smallest != i)
  	{
    	swap(arr[i],arr[smallest]);
    	min_heapify(arr,smallest);
  	}
}
int main() {
  
	vector<int> arr{INT_MAX,9,6,5,0,8,2,7,1,3};
	cout<<"Before Heapify : ";
	for(int i=1;i<=arr.size()-1;i++)     cout<<arr[i]<<" ";
	for(int i=floor((double)(arr.size()-1)/(double)2);i>=1;i--) {
    	max_heapify(arr,i);
  	}
	cout<<endl<<" After max Heapify : ";
  	for(int i=1;i<=arr.size()-1;i++)     cout<<arr[i]<<" ";
	for(int i=floor((double)(arr.size()-1)/(double)2);i>=1;i--) {
    	min_heapify(arr,i);
  	}
  	cout<<endl<<" After min Heapify : ";
  	for(int i=1;i<=arr.size()-1;i++)
    	cout<<arr[i]<<" ";
	return 0;
}
