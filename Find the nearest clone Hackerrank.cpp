#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<list>
#include<unordered_map>
using namespace std;


int main()
{
    int no_of_nodes,no_of_edges;
    //cout<<"nodes/edges"<<endl;
    cin>>no_of_nodes>>no_of_edges;
    int u,v;
    map<int,list<int>> G;
    queue<int> Q;
    unordered_map<int,int> distance;
    vector<int> visited(no_of_nodes+1,0);
    while(no_of_edges--){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    //cout<<"edges done"<<endl;
    vector<int> colorcodes(no_of_nodes+1,0);
    for(int i=1;i<=no_of_nodes;i++){
        //cout<<"enter element "<<i<<endl;
        cin>>colorcodes[i];
    }
    //cout<<"done now time for desired color \n";
    int dcolor;
    cin>>dcolor;
    for(int i=1;i<=no_of_nodes;i++){
        if(colorcodes[i]==dcolor){
            Q.push(i);
            distance[i]=0;
        }
    }
    if(Q.size()<2){
        cout<<"-1";
        return 0;
    }
    while(!Q.empty()){
        int front = Q.front();
        //cout<<"front is now ="<<front<<endl;
        Q.pop();
        visited[front] = 1;
        //cout<<"visited of "<<front<<" is marked 1"<<endl;
        for(int nbr:G[front]){
            //cout<<"neighbour is ="<<nbr<<endl;
            auto itr = distance.find(nbr);
            if(itr != distance.end() && visited[nbr]==0){
                //cout<<"Inside first cnditn"<<endl;
                cout<<distance[nbr]+distance[front]+1;
                return 0;
            }
            else{
                distance[nbr]++;
                //cout<<"distance of "<<nbr<<" is marked "<<distance[nbr]<<endl;
                Q.push(nbr);
            }
        }
    }
    cout<<"-1";
    return 0;
}
