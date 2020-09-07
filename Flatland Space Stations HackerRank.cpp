// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, vector<int> c) {
    int m = c.size();
    if(n==1 || n==m){
        return 0;
    }
    else if(m==1){
        return max(c[0]-0,n-1-c[0]);
    }
    sort(c.begin(),c.end());
    int ans = 0;
    for(int i=1;i<m;i++){
        ans = max(ans,(c[i]-c[i-1])/2);
    }
    ans = max(ans,c[0]-0);
    ans = max(ans,n-1-c[m-1]);
    return ans;
}
