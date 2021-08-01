class Solution{
public:
    int canBeTypedWords(string text, string brokenLetters){
        unordered_map<char,bool> broken;
        for(auto&it:brokenLetters){
            broken[it]=true;
        }
        int ans=0;
        string temp="";
        text+=" ";
        vector<string> arr;
        for(auto&it:text){
            if(it==' '){
                if(temp.length()>0){
                    arr.push_back(temp);
                }
                temp="";
                continue;
            }
            temp+=it;
        }
        for(auto&it:arr){
            bool b=false;
            for(auto&i:it){
                if(broken[i]){
                    b=true;
                   break; 
                }
            }
            if(!b) ans++;
        }
        return ans;
    }
};