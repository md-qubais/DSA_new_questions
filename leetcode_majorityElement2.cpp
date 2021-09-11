class Solution {
public:
    bool isMajority(vector<int>&arr,int val){
        int count=0;
        for(auto&it:arr){
            if(it==val){
                count++;
            }
        }
        if(count>(arr.size())/3){
            return true;
        }
        return false;
    }
    //Moore's voters algorithm 
    //same as majority element 1
    //how many element will have exactly n/3 frequency possible
    //x*n/3=n  which implies=>x==3

    //for more than n/3 frequency
    //that implies x<3 means there are less than 3 elements
    //that are more than n/3 means either 0,1,2 elements
    //will have more than n/3 frequency
    vector<int> majorityElement(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int val1=nums[0];
        int count1=1;
        int val2=nums[0];
        int count2=0;
        for(int i=1;i<nums.size();i++){
            if(val1==nums[i]){
                count1++;
            }else if(val2==nums[i]){
                count2++;
            }else{
                //may be triplet or a fresh start
                if(count1==0){
                    val1=nums[i];
                    count1=1;
                }else if(count2==0){
                    val2=nums[i];
                    count2=1;
                }else{
                    count1--;
                    count2--;
                }
            }
        }
        vector<int> ans;
        if(isMajority(nums,val1)){
            ans.push_back(val1);
        }
        if(val2!=val1 and isMajority(nums,val2)){
            ans.push_back(val2);
        }
        return ans;
    }
};