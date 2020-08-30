long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long>arr(n+1,0);
    for(long i=0;i<queries.size();i++){
        long a=queries[i][0]-1;
        long b=queries[i][1]-1;
        long k=queries[i][2];
        arr[a] = arr[a] + k;
        arr[b+1] = arr[b+1] - k;
    }
    long sum=0;
    long max = 0;
    for(long i=0;i<n;i++){
        sum = sum + arr[i];
        if(sum>max){
            max = sum;
        }
    }
    return max;

}
