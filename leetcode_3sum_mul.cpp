class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target){
        unordered_map<int,int> mapping;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            mapping[arr[i]]++;
        }
        int ans=0;
        for(int i=0;i<arr.size()-2;i++){
            int j=i+1;
            int k=arr.size()-1;
            while(i<k){
                
            }
        }
        return ans; 
    }
};