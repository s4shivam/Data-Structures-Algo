class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        if(nums.size()<2){
            return ans;
        }
        map<int,int> M;
        int diff;
        for(int i=0;i<nums.size();i++)
        {
            diff = target - nums[i];
            auto itr = M.find(diff);
            if(itr!=M.end()){  
                ans.push_back(M[diff]);
                ans.push_back(i);
            }
            M[nums[i]] = i;
        }
        return  ans  ;        
        }
};
