class NumArray{
public:
    vector<int> presum;
    NumArray(vector<int>& nums){
        presum.resize(nums.size());
        presum[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            presum[i]=presum[i-1]+nums[i];
        }
    }
    int sumRange(int left, int right){
        if(left==0){
            return presum[right];
        }
        return presum[right]-presum[left-1];
    }
};
