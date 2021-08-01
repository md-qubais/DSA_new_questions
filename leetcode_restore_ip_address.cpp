class Solution {
public:
    void restore(string&s,vector<string>&ans,int i=0,string path="",string asf="",int parts=0){
        if(parts==4 and i<s.length()){
            return;
        }
        if(path.length()>1){
            if(path[0]=='0'){
                return;
            }
            stringstream str(path);
            int n;
            str>>n;
            if(n>255){
                return;
            }
        }
        if(i>=s.length()){
            if(parts==4){
                asf+="."+path;
                ans.push_back(asf);
            }
            return;
        }
        if(asf.length()==0){
            asf+=path;
        }else{
            asf+="."+path;
        }
        string temp="";
        for(int j=0;j<=3;j++){
            if(i+j<s.length()){
                temp+=s[i+j];
                restore(s,ans,i+j+1,temp,asf,parts+1);
                continue;
            }
            return;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if(s.length()>12){
            return ans;
        }
        restore(s,ans);
        return ans;
    }
};