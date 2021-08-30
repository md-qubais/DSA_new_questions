class Solution{
public:
    string longestNiceSubstring(string s){
        string ans="";
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                string temp="";
                unordered_map<char,bool> upper;
                unordered_map<char,bool> lower;    
                for(int k=i;k<=j;k++){
                    temp+=s[k];
                    if(s[k]>='A' and s[k]<='Z'){
                        upper[s[k]]=true;
                    }else{
                        lower[s[k]]=true;
                    }
                }
                bool b=false;
                    for(auto&it:upper){
                        if(!lower[it.first+32]){
                            b=true;
                            break;
                        }
                    }
                    for(auto&it:lower){
                        if(!upper[it.first-32]){
                            b=true;
                            break;
                        }
                    }
                    if(!b){
                        if(temp.length()>ans.length()){
                            ans=temp;
                        }
                    }
                }
            }
            return ans;
        }
    };