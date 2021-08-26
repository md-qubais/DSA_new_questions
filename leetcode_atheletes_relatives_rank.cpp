class Solution{
public:
    vector<string> findRelativeRanks(vector<int>& score){
        vector<int> copy=score;
        sort(score.begin(),score.end(),greater<int>{});
        unordered_map<int,string> mapping;
        for(int i=0;i<3 and i<score.size();i++){
            if(i==0){
                mapping[score[i]]="Gold Medal";
            }else if(i==1){
                mapping[score[i]]="Silver Medal";
            }else{
                mapping[score[i]]="Bronze Medal";
            }
        }
        for(int i=3;i<score.size();i++){
            mapping[score[i]]=to_string((i+1));
        }
        vector<string> ans;
        for(int i=0;i<copy.size();i++){
            ans.push_back(mapping[copy[i]]);
        }
        return ans;
    }
};