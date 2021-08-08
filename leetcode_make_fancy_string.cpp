class Solution{
public:
    string makeFancyString(string s){
        int count=1;
        string ans="";
        ans+=s[0];
        for(int i=1;i<s.length();i++){
            if(ans[ans.length()-1]==s[i]){
                count++;
            }else{
                count=1;
                ans+=s[i];
                continue;
            }
            if(count==3){
                count--;
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};