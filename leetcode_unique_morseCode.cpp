vector<string> arr({".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."});
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& array){
        unordered_map<string,int> freq;
        for(auto&words:array){
            string temp="";
            for(int i=0;i<words.length();i++){
                temp+=arr[words[i]-'a'];
            }
            freq[temp]++;
        }
        return freq.size();
    }
};