class Solution {
public:
    void permutate(vector<int>&nums,int start,vector<vector<int>>&ans){
      if(start==nums.size()-1){
         vector<int> subans;
        for(auto itr:nums){
          subans.push_back(itr);
        }
        ans.push_back(subans);
        return;
      }
      for(int i=start;i<=nums.size()-1;i++){
        swap(nums[i],nums[start]);
        permutate(nums,start+1,ans);
        swap(nums[i],nums[start]);
      }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int start = 0;
        vector<vector<int>> ans;
        permutate(nums,start,ans);
        return ans;       
    }    
};
