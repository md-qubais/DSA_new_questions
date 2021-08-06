class Solution{
public:
    //just use simple floyd warshall
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold){
        vector<vector<long long int>> mat(n);
        for(auto&it:mat){
            it.resize(n);
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                mat[i][j]=INT_MAX;
            }
        }
        for(int i=0;i<edges.size();i++){
            for(int j=0;j<edges[i].size();j++){
                mat[edges[i][0]][edges[i][1]]=edges[i][2];
                mat[edges[i][1]][edges[i][0]]=edges[i][2];
            }
        }
        for(int i=0;i<mat.size();i++){
            mat[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int u=0;u<n;u++){
                for(int v=0;v<n;v++){
                    mat[u][v]=min(mat[u][v],mat[u][k]+mat[k][v]);
                }
            }
        }
        int ans=-1;
        int max_val=INT_MAX;
        for(int i=0;i<mat.size();i++){
            int count=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count <= max_val){
                max_val=count;
                ans=i;
            }
        }
        return ans;
    }
};