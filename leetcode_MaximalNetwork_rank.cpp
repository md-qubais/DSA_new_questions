class Graph{
public:
    int maximal_network(int n, vector<vector<int>>& roads){
        vector<int> degree(n);
        bool connected[1000][1000]={false};
        for(auto&it:roads){
            degree[it[0]]++;
            degree[it[1]]++;
            connected[it[0]][it[1]]=true;//if they both are connected
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int size=degree[i]+degree[j];
                if(connected[i][j] or connected[j][i]){
                    size--;
                }
                ans=max(ans,size);
            }
        }
        return ans;
    }
};
class Solution{
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads){
        Graph g;
        return g.maximal_network(n,roads);
    }
};