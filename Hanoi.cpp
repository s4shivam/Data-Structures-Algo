#include<iostream>
using namespace std;
void TOH(int,char,char,char);
main()
{
	int a=3;
	TOH(a,'A','B','C');
}
void TOH(int n,char SRC,char AUX,char DES)
{
	if(n>=1){
		TOH(n-1,SRC,DES,AUX);
		cout<<"Move disk "<<n<<" from "<<SRC<<" to "<<DES<<endl;
		TOH(n-1,AUX,SRC,DES);
	}
}
