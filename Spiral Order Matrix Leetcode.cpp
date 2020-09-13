class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        if(matrix.size()==0){
            return ans;
        }
        int T,B,L,R;
        T = 0;
        B = matrix.size()-1;
        L = 0;
        R = matrix[0].size()-1;
        int dir = 0;
          while(T<=B && L<=R)
          {
            if(dir==0){
              for(int i=L;i<=R;i++){
                ans.push_back(matrix[T][i]);
              }
              T++;
            }
            else if(dir==1){
              for(int i=T;i<=B;i++){
                ans.push_back(matrix[i][R]);
              }
              R--;
            }
            else if(dir==2){
              for(int i=R;i>=L;i--){
                ans.push_back(matrix[B][i]);
              }
              B--;
            }
            else if(dir==3){
              for(int i=B;i>=T;i--){
                ans.push_back(matrix[i][L]);
              }
              L++;
            }
            dir = (dir+1)%4;
          }
        return ans;    
    }
};
