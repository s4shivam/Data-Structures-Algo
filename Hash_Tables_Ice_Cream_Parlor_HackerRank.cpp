void whatFlavors(vector<int> cost, int money) {
    unordered_map<int,int> M;
    int diff=0;
    for(int i=0;i<cost.size();i++){
      diff = money - cost[i];
      if(M.find(diff)!=M.end()){
        auto it = find(cost.begin(),cost.end(),diff); 
        int index = distance(cost.begin(),it);
        cout<<index+1<<" "<<i+1<<endl;
        return;
      }
      M[cost[i]] = diff;
    }
    return;
}

