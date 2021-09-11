class Solution{
public:
    vector<int> sortedSquares(vector<int>& nums){
        int s=0;
        int e=nums.size()-1;
        vector<int> res(nums.size());
        int idx=e;
        //because we are going to fill from the last index
        //ie we are first filling the most greatest number
        //followed by the numbers
        //now the most greatest number will be either the least
        //negative one or the most positive one
        //so we start filling like below
        while(idx>=0){
            int square1=nums[s]*nums[s];
            int square2=nums[e]*nums[e];
            if(square1 > square2 ){
                res[idx--]=square1;
                s++;
            }else{
                res[idx--]=square2;
                e--;
            }
        }
        return res;
    }
};