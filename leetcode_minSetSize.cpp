class Solution{
public:
    static bool compare(pair<int,int> p1,pair<int,int> p2){
        return p1.first> p2.first;
    }
    int minSetSize(vector<int>& a){
        unordered_map<int,int> freq;
        for(auto&it:a){
            freq[it]++;
        } 
        vector<pair<int,int>> arr;
        for(auto&it:freq){
            arr.push_back(make_pair(it.second,it.first));
        }
        sort(arr.begin(),arr.end(),compare);
        int count=0;
        int tot_size=0;
        for(int i=0;i<arr.size();i++){
            if((a.size()-(arr[i].first+tot_size))<=(a.size()/2)){
                count++;
                break;
            }else{
                tot_size+=arr[i].first;
                count++;
            }
        }
        return count;
    }
};