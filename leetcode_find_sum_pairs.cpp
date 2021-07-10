class FindSumPairs {
public:
    unordered_map<int,int> m;
    vector<int> n1;
    vector<int> n2;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2){
        for(auto&it:nums1){
            n1.push_back(it);
        }
        for(auto&it:nums2){
            n2.push_back(it);
        }
        for(auto&it:n2){
            m[it]++;
        }
    }

    void add(int index, int val) {
        int num=n2[index];
        m[num]--;
        n2[index]+=val;
        m[n2[index]]++;
    }
    
    int count(int tot) {
        int ans=0;
        for(auto&it:n1){
            ans+=m[tot-it];
        }
        return ans;
    }
};
