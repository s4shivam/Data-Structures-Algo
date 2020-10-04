class Solution {
public:
    void dfs_to_mark_island(vector<vector<char>> &grid,int i,int j,int rows,int col)
    {
        if(i<0 || i>=rows || j<0 || j>=col || grid[i][j]!='1'){
            return;
        }
        grid[i][j]='2'; //marked visited
        dfs_to_mark_island(grid,i-1,j,rows,col);
        dfs_to_mark_island(grid,i+1,j,rows,col);
        dfs_to_mark_island(grid,i,j-1,rows,col);
        dfs_to_mark_island(grid,i,j+1,rows,col);
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        
        int answer = 0;
        if(rows==0){
            return 0;
        }
        int col = grid[0].size();
        for(int i=0;i<rows;i++)
        {
            for(int j =0;j<col;j++){
               if(grid[i][j]=='1'){
                   dfs_to_mark_island(grid,i,j,rows,col);
                   answer++;
               }
            }
        }
        return answer;
    }
};
