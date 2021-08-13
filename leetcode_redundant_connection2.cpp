class Solution{
public:
    int findParent(int n,vector<int>&arr){
        if(n==arr[n]){
            return n;
        }
        return arr[n]=findParent(arr[n],arr);
    }
    bool FindCycle(int n,vector<vector<int>>&edges,int idx=-1){
        vector<int> arr(n+1);
        for(int i=1;i<arr.size();i++){
            arr[i]=i;
        }
        for(int i=0;i<edges.size();i++){
            if(i==idx){
                continue;
            }
            int u=edges[i][0];
            int v=edges[i][1];
            int p1=findParent(arr[u],arr);
            int p2=findParent(arr[v],arr);
            if(p1==p2){
                return true;
            }
            arr[p2]=p1;
        }
        return false;
    }
    vector<int> find_cycle(int n,vector<vector<int>>&edges){
        vector<int> arr(n+1);
        for(int i=1;i<arr.size();i++){
            arr[i]=i;
        }
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int p1=findParent(arr[u],arr);
            int p2=findParent(arr[v],arr);
            if(p1==p2){
                ans.push_back(u);
                ans.push_back(v);
                break;
            }
            arr[p2]=p1;
        }
        return ans;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges){
        int n=edges.size();
        vector<vector<int>> arr(n+1);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            arr[v].push_back(i);
        }
        bool b=false;
        int ind=-1;
        for(int i=1;i<arr.size();i++){
            if(arr[i].size()>1){
                b=true;
                ind=i;
                break;
            }
        }
        //here there is only one cycle
        //we are sure if there is only one cycle exits
        //in the graph then we can say DSU to find that graph
        vector<int> ans;
        if(b==false){
            return find_cycle(n,edges);
        }
        //if we kmow surely there is only one cycle in the 
        //directed graph then we can use DSU to find that cycle
        //here surely we get the answer if cycle or not
        //because this violates the rule
        //and these are the two indices that has to be answer
        else{
            int idx1=arr[ind][0];
            int idx2=arr[ind][1];
            bool cycle1=false;
            bool cycle2=false;
            cycle1=FindCycle(n,edges,idx1);
            cycle2=FindCycle(n,edges,idx2);
            if(!cycle1 and !cycle2){
                return edges[idx2];
            }
            if(!cycle1){
                return edges[idx1];
            }
            return edges[idx2];
        }
        return ans;
    }
};