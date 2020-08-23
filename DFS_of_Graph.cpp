 1-->2-->5-->4
     ↑   ↑  /
     |   | /
     3   6


#include <iostream>
#include<vector>
using namespace std;
#define N 10
vector<int> G[N];
bool vis[N] = {0};
void dfs(int n)
{
  vis[n] = 1;
  cout<<"visited = "<<n<<endl;
  for(auto i:G[n])
  {
    if(vis[i]==1){
      continue;
    }
    dfs(i);
  }
}
int main() {
  int n,e,u,v;
  cin>>n>>e;
  while(e--){
    cin>>u>>v;
    G[u].push_back(v);
  }
  dfs(1);
  if(vis[6]){
    cout<<"YES";
  }
  else{
    cout<<"NOI";
  }
  return 0;
}
