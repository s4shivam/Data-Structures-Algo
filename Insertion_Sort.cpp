#include<iostream>
#include<vector>
using namespace std;
void Insertion_Sort(vector<int>&arr){
	int i=0;
	for(int j=1;j<arr.size();j++)
	{
		int key = arr[j];
		i=j-1;
		while(i>=0 && key<arr[i] ){
			arr[i+1] = arr[i];
			i--;
		}
		arr[i+1] = key;
	}
}
int main()
{
	vector<int> arr;
	int n;
	cout<<"Enter numbers to sort(press -1 to stop)"<<endl;
	cin>>n;
	while(n!=-1){
		arr.push_back(n);
		cin>>n;		
	}
	cout<<endl<<"Before Sorting: ";
	for(int x:arr){
		cout<<x<<" ";
	}
	cout<<endl;
	Insertion_Sort(arr);
	cout<<"After Sorting: ";
	for(int x:arr){
		cout<<x<<" ";
	}
	return 0;
}
