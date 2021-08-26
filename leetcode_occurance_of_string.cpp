class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second){
        vector<string> tokens;
        vector<string> ans;
        string temp="";
        text+=" ";
        for(int i=0;i<text.length();i++){
            if(text[i]==' '){
                tokens.push_back(temp);
                temp="";
                continue;
            }
            temp+=text[i];
        }
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]==first){
                if(i+1<tokens.size()){
                    if(tokens[i+1]==second){
                        if(i+2<tokens.size()){
                            ans.push_back(tokens[i+2]);
                        }else{
                            break;
                        }
                    }
                }else{
                    break;
                }
            }
        }
        return ans;
    }
};