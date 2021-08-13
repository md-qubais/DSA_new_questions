vector<int> order;
bool compare(string s1,string s2){
    for(int i=0;i<s1.length() and i<s2.length();i++ ){
        if(s1[i]==s2[i]){
            continue;
        }
        else{
            if(order[s1[i]-'a'] > order[s2[i]-'a']){
                return false;
            }else{
                return true;
            }
        }
    }
    if(s1.length()>s2.length()){
        return false;
    }
    return true;
}
class Solution{
public:
    bool isAlienSorted(vector<string>& words, string str){
        int i=0;
        vector<string> words1;
        order.resize(26);
        for(auto&it:str){
            order[it-'a']=(i++);
        }
        for(auto&it:words){
            words1.push_back(it);
        }
        sort(words1.begin(),words1.end(),compare);
        for(int i=0;i<words1.size();i++){
            if(words1[i]!=words[i]){
                order.clear();
                return false;
            }
        }
        order.clear();
        return true;
    }
};