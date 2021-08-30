class Solution{
public:
    string restoreString(string s, vector<int>& indices){
        if(s.length()==0){
            return s;
        }
        vector<pair<int,char>> arr;
        for(int i=0;i<indices.size();i++){
            arr.push_back(make_pair(indices[i],s[i]));
        }
        sort(arr.begin(),arr.end());
        string ans="";
        for(int i=0;i<arr.size();i++){
            ans+=arr[i].second;
        }
        return ans;
    }
};