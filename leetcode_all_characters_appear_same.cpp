class Solution {
public:
    bool areOccurrencesEqual(string s){
        int freq[27]={0};
        for(auto&it:s){
            freq[it-'a']++;
        }
        int num=freq[s[0]-'a'];
        for(int i=1;i<s.length();i++){
            if(freq[s[i]-'a']!=num){
                return false;
            }
        }
        return true;
    }
};