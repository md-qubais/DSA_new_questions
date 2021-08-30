class Solution{
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
    }
};