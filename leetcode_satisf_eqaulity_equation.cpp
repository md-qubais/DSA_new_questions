class Solution {
public:
    unordered_map<char,char> leader;
    char findParent(char ch){
        if(ch==leader[ch]){
            return ch;
        }
        return leader[ch]=findParent(leader[ch]);
    }
    bool equationsPossible(vector<string>& equations){
        for(int i=0;i<26;i++){
            leader[(char)('a'+i)]=(char)('a'+i);
        }
        for(auto&it:equations){
            char ch1=it[1];
            char p1=findParent(it[0]);
            char p2=findParent(it[3]);
            if(ch1=='=' and p1!=p2){
                leader[p2]=p1;
            }
        }
        for(auto&it:equations){
            char ch1=it[1];
            char p1=findParent(it[0]);
            char p2=findParent(it[3]);
            if(ch1=='!' and p1==p2){
                return false;
            }
        }
        return true;
    }
};