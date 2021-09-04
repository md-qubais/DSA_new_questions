class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k){
        deque<int> dq;//for storing indices
        vector<int> presum(nums.size()+1);
        presum[0]=0;
        for(int i=1;i<nums.size()+1;i++){
            presum[i]=presum[i-1]+nums[i-1];
        }
        for(auto&it:presum){
            cout<<it<<" ";
        }
        cout<<endl;
        int size=INT_MAX;
        dq.push_back(0);
        for(int i=1;i<presum.size();i++){
            dq.push_back(i);
            while(!dq.empty() and   presum[i] - presum[dq.front()] >=k){
                int curr_size=i-dq.front();
                size=min(size,curr_size);
                dq.pop_front();
            }
        }
        return size==INT_MAX?-1:size;
    }
};