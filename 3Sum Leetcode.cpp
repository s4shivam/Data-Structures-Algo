#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

//====================Leetcode Specific Solution============================================================================================
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        vector<vector<int>> ans;
  if(nums.size()<3)
  {
    return ans;
  }
  sort(nums.begin(),nums.end());
  for(int i=0;i<nums.size()-2;i++){
    int low = i+1;
    int high = nums.size()-1;
    int remtarget = target - nums[i];
    while(low<high){
      if(nums[low] + nums[high] > remtarget){
        high--;
      }
      else if(nums[low] + nums[high] < remtarget){
        low++;
      }
      else if(nums[low] + nums[high] == remtarget){
        vector<int> subans(3,0);
        subans[0] = nums[i];
        subans[1] = nums[low];
        subans[2] = nums[high];
        ans.push_back(subans);
        low++;high--;
        while( nums[low] == subans[1] && low<high){low++;}
        while( nums[high] == subans[2] && low<high){high--;}
      }  
    }
    while(nums[i] == nums[i+1] && i<nums.size()-2){
      i++;
    }
  }
  return ans;
    }
};


//=====================================Full solution below===============================================================================================================

vector<vector<int>> triplets(vector<int>&nums,int target)
{
  vector<vector<int>> ans;
  if(nums.size()<3)
  {
    return ans;
  }
  sort(nums.begin(),nums.end());
  for(int i=0;i<nums.size()-2;i++){
    int low = i+1;
    int high = nums.size()-1;
    int remtarget = target - nums[i];
    while(low<high){
      if(nums[low] + nums[high] > remtarget){
        high--;
      }
      else if(nums[low] + nums[high] < remtarget){
        low++;
      }
      else if(nums[low] + nums[high] == remtarget){
        vector<int> subans(3,0);
        subans[0] = nums[i];
        subans[1] = nums[low];
        subans[2] = nums[high];
        ans.push_back(subans);
        low++;high--;
        while( nums[low] == subans[1] && low<high){low++;}
        while( nums[high] == subans[2] && low<high){high--;}
      }  
    }
    while(nums[i] == nums[i+1] && i<nums.size()-2){
      i++;
    }
  }
  return ans;
}
int main()
{
  vector<int> nums = {0,-1,2,-3,1,1,3};
  vector<vector<int>> ans;
  int target = 0;
  ans = triplets(nums,target);
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
}
