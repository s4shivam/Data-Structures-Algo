#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<list>
#include<climits>
using namespace std;
void findDistances(int start,map<int,list<int>> &G,vector<int> &result)
{
    result[start] = 0;
    queue<int> Q;
    Q.push(start);
    while (!Q.empty())
    {
        int front = Q.front();
        Q.pop();
        for(int nbr:G[front]){
            if(result[nbr]==-1){
                Q.push(nbr);
                result[nbr] = 6 + result[front];
            }
        }
    }
    return;
    
}
int main()
{
    int no_of_queries;
    cin>>no_of_queries;
    
    while(no_of_queries--)
    {
        int no_of_nodes,no_of_edges;
        cin>>no_of_nodes>>no_of_edges;
        map<int,list<int>> G;
        vector<int> result(no_of_nodes+1,-1);
        int u,v;
        while(no_of_edges--){
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int start;
        cin>>start;
        findDistances(start,G,result);
        for(int i=1;i<no_of_nodes+1;i++){
            if(result[i]!=0){
                cout<<result[i]<<" ";
            }   
        }
        cout<<endl;
    }   
    return 0;
}
