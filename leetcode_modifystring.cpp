class Solution{
public:
    string modifyString(string s){
        if(s.length()==1){
            if(s[0]=='?'){
                return "a";
            }
            return s;
        }
        for(int i=0;i<s.length();i++){
            if(s[i]=='?'){
                if(i==0){
                    for(char ch='a';ch<='z';ch++){
                        if(ch!=s[i+1]){
                            s[i]=ch;
                            break;
                        }
                    }
                }else if(i==s.length()-1){
                    for(char ch='a';ch<='z';ch++){
                        if(ch!=s[i-1]){
                            s[i]=ch;
                            break;
                        }
                    }
                }else{
                    for(char ch='a';ch<='z';ch++){
                        if(ch!=s[i-1] and ch!=s[i+1]){
                            s[i]=ch;
                            break;
                        }
                    }
                }
            }
        }
        return s;
    }
};