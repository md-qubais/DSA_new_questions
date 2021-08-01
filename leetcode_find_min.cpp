class Solution {
public:
    int findMin(vector<int>& nums){
        if(nums.size()==0){
            return nums[0];
        }
        int s=0;
        int e=nums.size()-1;
        while(s<e){
            int mid=(s+e)/2;
            if(nums[s]<nums[e]){
                e=s;
            }
            if(nums[mid]<nums[e]){
                e=mid;
            }else{
                s=mid+1;
            }

        }
        return nums[s];
    }
};