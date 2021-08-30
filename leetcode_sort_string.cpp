class Solution{
public:
    string sortString(string s){
        unordered_map<char,int> freq;
        for(auto&it:s){
            freq[it]++;
        }
        string ans="";
        while(true){
            for(char ch='a';ch<='z';ch++){
                if(freq[ch]>0){
                    freq[ch]--;
                    ans+=ch;
                }else{
                    freq.erase(ch);
                }
            }
            for(char ch='z';ch>='a';ch--){
                if(freq[ch]>0){
                    freq[ch]--;
                    ans+=ch;
                }else{
                    freq.erase(ch);
                }
            }
            if(freq.size()==0){
                break;
            }
        }
        return ans;
    }
};
