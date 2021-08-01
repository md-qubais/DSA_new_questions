class Graph{
public:
    unordered_map<int,int> leaders;
    int getLeader(int n){
        if(n==leaders[n]){
            return n;
        }
        return leaders[n]=getLeader(leaders[n]);
    }  
    int slashes(vector<string>&grid){
        int ans=1;
        int n=grid.size()+1;
        int m=grid[0].size()+1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or j==0 or i==n-1  or j==m-1){
                    leaders[i*m+j]=0;
                }else{
                    leaders[i*m+j]=i*m+j;
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='/' or grid[i][j]=='\\'){
                    int n1,n2;
                    if(grid[i][j]=='/'){
                        n1=i*m+(j+1);
                        n2=(i+1)*m+j;
                    }else{
                        n1=i*m+j;
                        n2=(i+1)*m+(j+1);
                    }
                    int l1=getLeader(leaders[n1]);
                    int l2=getLeader(leaders[n2]);
                    if(l1==l2){
                        ans++;
                    }
                    leaders[l2]=l1;
                }
            }
        }
        return ans;
    }
};
class Solution{
public:
    int regionsBySlashes(vector<string>& grid){
        Graph g;
        return g.slashes(grid);
    }
};