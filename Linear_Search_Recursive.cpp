#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int LinearSearch(vector<int>&myvec,int begin,int size,int target)
{	
	if(begin>size){
		return -1;
	}
	if(myvec[begin]==target){
		return begin;
	}
	else
		return LinearSearch(myvec,begin+1,size,target);
}
int main()
{
	vector<int> myvec{1,4,6,2,7,8,3,9};
	int size = myvec.size();
	int begin=0;
	int result;
	int target;
	cout<<"Enter the number to search : "; cin>>target;
	
	result = LinearSearch(myvec,begin,size,target);
	if(result==-1){
		cout<<"Element not found\n";
	}
	else{
		cout<<"element "<<target<<" was found at index: "<<result<<endl;
	}
	return 0;
}
