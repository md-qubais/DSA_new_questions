class Solution{
public:
    //can be solved using chaining technique
    //moore's voting algorithm
    //pairing of the two distinct values
    //and the last value will be the majority element
    //if majority exists
    int majorityElement(vector<int>& nums) {
        int val=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==val){
                count++;
            }else{
                if(count>0){
                    count--;
                }else{
                    val=nums[i];
                    count=1;
                }
            }
        }
        return val;
    }
};