#include<iostream>
#include<algorithm>
#include<cctype>
using namespace std;
string printrev(string str){
	int l=0;
	int r= str.length()-1;
	while(l<r){
		if(!isalpha(str[l])){
			l++;
		}
		if(!isalpha(str[r])){
			r--;
		}
		else{
			swap(str[l],str[r]);
			l++;
			r--;
		}
	}
	return str;
}
int main()
{
	string str;
	cin>>str;
	cout<<"Before : "<<str;
	string temp = printrev(str);
	cout<<"\nAfter : ";
	cout<<temp;
	return 0;
}
