class Solution{
public:
    vector<string> removeSubfolders(vector<string>& folder){
        sort(folder.begin(),folder.end());
        vector<string> ans;
        for(int i=0;i<folder.size();i++){
            if(ans.size()==0){
                ans.push_back(folder[i]);
                continue;
            }
            string temp="";
            bool b=false;
            string s=folder[i];
            for(int j=0;j<s.length();j++){
                if(s[j]!='/'){
                    while(j<s.length() and s[j]!='/'){
                        temp+=s[j++];
                    }
                    j--;
                }else temp+=s[j];
                if(temp==ans[ans.size()-1]){
                    b=true;
                }
            }
            if(b){
                continue;
            }
            ans.push_back(folder[i]);
        }
        return ans;
    }
};