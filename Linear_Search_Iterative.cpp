#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int LinearSearch(vector<int>&myvec,int target)
{
	int i=0;
	while(i<myvec.size())
	{
		if(myvec.at(i)==target){
			return i;
		}
		i++;
	}
	return -1;
}
int main()
{
	vector<int> myvec{1,4,6,2,7,8,3,9};
	int result;
	int target;
	cout<<"Enter the number to search : "; cin>>target;
	
	result = LinearSearch(myvec,target);
	if(result==-1){
		cout<<"Element not found\n";
	}
	else{
		cout<<"element "<<target<<" was found at index: "<<result<<endl;
	}
	return 0;
}
