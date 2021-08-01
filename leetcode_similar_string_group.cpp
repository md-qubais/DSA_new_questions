class Solution {
public:
    unordered_map<int,int> leader;
    bool isSimilar(string s1,string s2){
        int count=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i] and ++count>2){
                return false;
            }
        }
        return true;
    }
    int getLeader(int num){
        if(num==leader[num]){
            return num;
        }
        return leader[num]=getLeader(leader[num]);
    }
    void Union(int n1,int n2){
        leader[n2]=n1;
    }
    int numSimilarGroups(vector<string>& str) {
        int groups=str.size();
        for(int i=0;i<groups;i++){
            leader[i]=i;
        }
        for(int i=0;i<str.size();i++){
            for(int j=i+1;j<str.size();j++){
                if(isSimilar(str[i],str[j])){
                    int p1=getLeader(i);
                    int p2=getLeader(j);
                    if(p1!=p2){
                        groups--;
                        Union(p1,p2);
                    }
                }
            }
        }
        return groups;
    }
};