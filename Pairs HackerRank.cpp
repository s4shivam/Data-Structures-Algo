int pairs(int k, vector<int> nums) {
    sort(nums.begin(),nums.end());
    int i=0,j=1,count=0;
    
    while(j < nums.size()) {
        int diff = nums[j] - nums[i];
        
        if (diff == k) {
            count++;
            j++;
        } else if (diff > k) {
            i++;
        } else if (diff < k) {
            j++;
        }
    }
    return count;
}
