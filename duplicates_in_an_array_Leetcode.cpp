#include <iostream>
#include<vector>
using namespace std;
void duplicates(vector<int> &V)
{
  for (int i = 0; i < V.size(); i++) 
  { 
    if (V[abs(V[i])] >= 0) 
      V[abs(V[i])] = -V[abs(V[i])]; 
    else
      cout << abs(V[i]) << " "; 
  } 
}
int main() {
  vector<int> V {1,2,3,4,1,5,5} ;
  duplicates(V);
  return 0;
}
