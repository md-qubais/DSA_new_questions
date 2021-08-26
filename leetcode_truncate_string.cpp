class Solution{
public:
    string truncateSentence(string s, int k){
        vector<string> arr;
        string temp="";
        s+=" ";
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                count++;
                if(count==k){
                    arr.push_back(temp);
                    break;
                }else{
                    arr.push_back(temp+" ");
                }
                temp="";
                continue;
            }
            temp+=s[i];
        }
        string ans="";
        for(auto&it:arr){
            ans+=it;
        }
        return ans;
    }
};