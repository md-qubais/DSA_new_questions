bool compare(vector<int>&arr1,vector<int>&arr2){
    if(arr1[0]==3){
        return arr1[0]>arr2[0];
    }
    if(arr2[0]==3){
        return arr1[0]>arr2[0];
    }
    return arr1[0]<arr2[0];
}
class Solution{
public:
    int find(int n,vector<int>&parent){
        if(n==parent[n]){
            return n;
        }
        return parent[n]=find(parent[n],parent);
    }
    bool Union(int u,int v,vector<int>&parent,vector<int>&size){
        int p1=find(parent[u],parent);
        int p2=find(parent[v],parent);
        if(p1!=p2){
            if(size[p1]>=size[p2]){
                parent[p2]=p1;
                size[p1]+=size[p2];
            }else{
                size[p2]+=size[p1];
                parent[p1]=p2;
            }
            return true;
        }
        return false;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges){
        vector<int> alice(n+1);
        vector<int> sizea(n+1);
        vector<int> bob(n+1);
        vector<int> sizeb(n+1);
        sort(edges.begin(),edges.end(),compare);
        int mergea=n;
        int mergeb=n;
        int remove=0;
        for(int i=1;i<=n;i++){
            alice[i]=i;
            bob[i]=i;
            sizea[i]=1;
            sizeb[i]=1;
        }
        for(int i=0;i<edges.size();i++){
            int type=edges[i][0];
            int u=edges[i][1];
            int v=edges[i][2];
            if(type==3){
                bool typea=Union(u,v,alice,sizea);
                bool typeb=Union(u,v,bob,sizeb);
                if(typea){
                    mergea--;
                }
                if(typeb){
                    mergeb--;
                }
                if(!typea and !typeb){
                    remove++;
                }
            }else if(type==1){
                bool typea=Union(u,v,alice,sizea);
                if(typea){
                    mergea--;
                }else{
                    remove++;
                }
            }else{
                bool typeb=Union(u,v,bob,sizeb);
                if(typeb){
                    mergeb--;
                }else{
                    remove++;
                }
            }
        }
        if(mergea!=1 or mergeb!=1){
            return -1;
        }
        return remove;
    }
};