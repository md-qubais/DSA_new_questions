class Solution{
public:
    bool is_startsWith(string word,string prefix){
        int iword=0;
        int iprefix=0;
        while(iword<word.length() and iprefix<prefix.length()){
            if(word[iword]==prefix[iprefix]){
                iword++;
                iprefix++;
            }else{
                return false;
            }
        }
        if(iprefix<prefix.length()){
            return false;
        }
        return true;
    }
    int isPrefixOfWord(string sentence, string searchWord){
        vector<string> words;
        sentence+=" ";
        string temp="";
        for(int i=0;i<sentence.length();i++){
            if(sentence[i]==' '){
                words.push_back(temp);
                temp="";
                continue;
            }
            temp+=sentence[i];
        }
        for(int i=0;i<words.size();i++){
            if(is_startsWith(words[i],searchWord)){
                return i+1;
            }
        }
        return -1;
    }
};