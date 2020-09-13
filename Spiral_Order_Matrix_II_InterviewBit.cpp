vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> arr(A,vector<int>(A,0));
    if(A==0){
        return arr;
    }
    int T,B,L,R;
    T = 0;
    B = arr.size()-1;
    L = 0;
    R = arr[0].size()-1;
    int dir = 0;
    int num = 1;
    while(T<=B && L<=R){
        if(dir==0){
            for(int i=L;i<=R;i++){
                arr[T][i]=num;
                num++;
            }
            T++;
        }
        else if(dir==1){
            for(int i=T;i<=B;i++){
                arr[i][R] = num;
                num++;
            }
            R--;
        }
        else if(dir==2){
            for(int i=R;i>=L;i--){
                arr[B][i] = num;
                num++;
            }
            B--;
        }
        else if(dir==3){
            for(int i=B;i>=T;i--){
                arr[i][L] = num;
                num++;
            }
            L++;
        }
        dir = (dir+1)%4;
    }
    return arr;
}
