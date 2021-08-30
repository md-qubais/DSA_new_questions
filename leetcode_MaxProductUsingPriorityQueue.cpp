class Solution{
public:
    //if we want to get k max elements use min Heap
    //if we want to get k min elements use max Heap
    int maxProduct(vector<int>& nums){
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            if(pq.size()==2){
                if(nums[i] > pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }else pq.push(nums[i]);
        }
        int val1=pq.top();
        pq.pop();
        int val2=pq.top();
        pq.pop();
        return (--val1)*(--val2);
    }
};