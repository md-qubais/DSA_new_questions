class Solution {
public:
    int dominantIndex(vector<int>& nums){
        int curr=nums[0];
        int maxIndex=0;
        for(int i=0;i<nums.size();i++){
            if(curr<nums[i]){
                curr=nums[i];
                maxIndex=i;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(maxIndex!=i and nums[maxIndex]!=nums[i] and nums[maxIndex]<2*nums[i]){
                return -1;
            }
        }
        return maxIndex;
    }
};