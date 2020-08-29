//1---2    4   6     7     9
//    |    |         |
//    |    |         |
//    3    5         8

#include <iostream>
#include<vector>
using namespace std;
//map<int,list<int>> G;
//unordered_map<int,bool> visited;
int dfs(int data,vector<vector<int>> &G,vector<int> &visited)
{
  int x=0;
  visited[data] = 1;
  for(auto nbr:G[data])
  {
    if(!visited[nbr]){
      x = x + dfs(nbr,G,visited);
    }
  }
  return 1+x;
}
int main() {
  int nodes=0;
  int edges=0;
  int noOfNodesInSubGraph = 0;
  cin>>nodes>>edges;
  vector<vector<int>> G(nodes+1);
  vector<int> visited(nodes+1,0);
  int u,v;
  int subgraphs=0;
  while(edges--){
    cin>>u>>v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for(int i=1;i<=nodes;i++)
  {
    if(!visited[i]){
      subgraphs++;
      noOfNodesInSubGraph  = dfs(i,G,visited);
      cout<<"No. of nodes in graph "<<subgraphs<<" is "<<noOfNodesInSubGraph<<endl;
    }
  }
  
  cout<<"No of components = "<<subgraphs;
  return 0;
}
