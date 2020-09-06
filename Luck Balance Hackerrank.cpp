bool f(int x,int y){
    return x>y;
}
// Complete the luckBalance function below..
int luckBalance(int k, vector<vector<int>> contests) {
    vector<int> V;
    int luck = 0;
    for(int i=0;i<contests.size();i++){
        if(contests[i][1] == 1){
            V.push_back(contests[i][0]);
        }
        if(contests[i][1] == 0){
            luck+= contests[i][0];
        }
    }
    sort(V.begin(),V.end(),f);
    for(int i=0;i<V.size();i++){
        if(i<k){
            luck+=V[i];
        }
        else{
            luck-=V[i];
        }
    }
    return luck;
}
