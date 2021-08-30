class Solution{
public:
    bool is_palindrome(string s){
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
    void partitions(string s, vector<vector<string>>&ans,vector<string> count){
        if(s.length()==0){
            if(count.size()>0){
                ans.push_back(count);
            }
            return;
        }
        string temp="";
        for(int i=0;i<s.length();i++){
            temp+=s[i];
            if(is_palindrome(temp)){
                count.push_back(temp);
                partitions(s.substr(i+1),ans,count);
                count.erase(count.end()-1);
            }
        }
    }
    vector<vector<string>> partition(string s){
        vector<string> count;
        vector<vector<string>> ans;
        partitions(s,ans,count);
        return ans;
    }
};