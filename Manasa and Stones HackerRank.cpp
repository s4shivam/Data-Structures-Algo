vector<int> stones(int n, int a, int b) {
    vector<int> V;
    set<int> S;
    int i = n-1;
    int j = 0;
    while(i>=0 && j<n){
        S.insert(((i*a)+(j*b)));
        i--;
        j++;
    }
    for(auto itr:S){
        V.push_back(itr);
    }
    return V;


}
