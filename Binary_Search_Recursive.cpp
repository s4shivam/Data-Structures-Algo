#include<iostream>
#include<vector>
using namespace std;
int BinarySearch(vector<int>&myvec,int l_index,int r_index,int target)
{
	while(l_index<=r_index){
		int m_index;
		m_index = (l_index+r_index) /2;
		if(myvec.at(m_index)==target){
			return m_index;
		}
		if(target > myvec[m_index]){
			return BinarySearch(myvec,m_index+1,r_index,target);
		}
		else{
			return BinarySearch(myvec,l_index,m_index-1,target);
		}
	}
	return -1;
}
int main()
{
	vector<int> myvec{1,3,4,5,7,8,9,10,11,14,16,18,19};
	int l_index = 0,r_index=myvec.size();
	int target,result;
	cout<<"Enter Element to search :";
	cin>>target;
	result = BinarySearch(myvec,l_index,r_index,target);
	if(result==-1){
		cout<<"Element not found\n";
	}
	else{
		cout<<"element "<<target<<" was found at index: "<<result<<endl;
	}
	return 0;
}
