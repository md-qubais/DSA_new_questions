class Solution{
public:
    int minSubArrayLen(int target, vector<int>& nums){
        int size=INT_MAX;
        int count=0;
        queue<int> q;
        for(int i=0;i<nums.size();i++){
            count+=nums[i];
            q.push(nums[i]);
            while(count>=target and !q.empty()){
                int curr_size=q.size();
                size=min(size,curr_size);
                count-=q.front();
                q.pop();
            }
        }
        while(count==target and !q.empty()){
            int curr_size=q.size();
            size=min(size,curr_size);
            count-=q.front();
            q.pop();
        }
        return size==INT_MAX?0:size;
    }
};