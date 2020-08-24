#include<iostream>
#include<queue>
#include<map>
#include<list>
using namespace std;
map<int,list<int> > G;
map<int,bool> vis;
void bfs(int src){
    queue<int> Q;
    Q.push(src);
    vis[src] = 1;
    while(!Q.empty())
    {
        int first = Q.front();
        Q.pop();
        for(int nbr:G[first]){
            if(!vis[nbr]){
                Q.push(nbr);
                vis[nbr] = 1;
            }
        }
    }
}
int main()
{
    int nodes,edges,u,v;
    cin>>nodes>>edges;
    while(edges--){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    bfs(1);
    if(vis[5]){
        cout<<"We reached 5";
    }
    else{
        cout<<"we coudn't reach 5";
    }
    return 1;
}