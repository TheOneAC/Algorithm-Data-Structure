class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i =-1;
        if(nums.size() == 0)return i;
        for(i =0;i< nums.size() ;i++){
            if(i-1>=0 && nums[i-1]> nums[i])continue;
            if(i+1 < nums.size() && nums[i+1] > nums[i])continue;
            break;
        }
        return i;
    }
};