#include <iostream>
#include<map>
#include<vector>
#include<list>
using namespace std;
//vector<vector<long>> G;
long dfs(long src,map<long,list<long>>&G,vector<bool>&visited)
{
  long count=0;
  visited[src] = 1;
  count++;
  for(long nbr:G[src])
  {
    if(!visited[nbr]){
      
      count+=dfs(nbr,G,visited);
    }
  }
  return count;
}
int main() {
  long queries;
  cin>>queries;
  while(queries--)
  {
    long noofnodes=0;
    long noofedges=0;
    long c_lib=0;
    long c_road=0;
    map<long,list<long>> G;
    vector<bool> visited;
    long u,v;
    cin>>noofnodes>>noofedges>>c_lib>>c_road;
    visited.resize(noofnodes+1,0);
    //G.resize(noofnodes+1);
    while(noofedges--){
      cin>>u>>v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    long components = 0;
    vector<long> nodesInComponents;
    for(long i=1;i<=noofnodes;i++){
      if(!visited[i]){
        //components++;
        //nodesInComponents = dfs(i);
        nodesInComponents.push_back(dfs(i,G,visited));
        //cout<<"No. of nodes in graph "<<components<<" is "<<nodesInComponents[components]<<endl;
        components++;
      }
    }
    long mincost=0;
    for(long item:nodesInComponents)
    {
        mincost += min((c_lib + ((item-1)*c_road)),(item*c_lib));
    }
    cout<<mincost<<endl;
  }
  return 0;
}
