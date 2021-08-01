class Solution{
public:
    unordered_map<int,int> leader;
    int getLeader(int num){
        if(num==leader[num]){
            return num;
        }
        return leader[num]=getLeader(leader[num]);
    }
    bool Union(int n1,int n2){
        int l1=getLeader(n1);
        int l2=getLeader(n2);
        if(l1==l2){
            return true;
        }
        leader[l2]=l1;
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        int n=edges.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            leader[i]=i;
        }
        for(int i=0;i<edges.size();i++){
            if(Union(edges[i][0],edges[i][1])){
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
            }
        }
        return ans;
    }
};