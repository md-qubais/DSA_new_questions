class Solution{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<int> prev(n+1);
        for(auto&it:prev){
            it=INT_MAX;
        }
        prev[src]=0;
        //perfoming atmax how many edges or stops 
        //or nodes that we can use
        for(int i=1;i<=k+1;i++){
            bool anyupdates=false;//this is for
            //negative detection of the cycle
            //if any changes performed after checking all
            //the valid edges if we get anypath
            //that is agin min than current path while
            //all n-1 edges are covered than there is 
            //negative cycle using bellman_ford

            //here we making a copy of prev array
            //to maintain the minimum if we get any minimum
            //we will change it
            vector<int> curr=prev;
            for(auto&it:flights){
                int u=it[0],v=it[1],w=it[2];
                if(prev[u]!=INT_MAX and prev[u]+w < curr[v]){
                    curr[v]=prev[u]+w;
                    anyupdates=true;
                }
            }
            if(i==(k+1) and anyupdates){
                //cout<<"here negative cycle detected"<<endl;
            }
            prev=curr;
        }
        return prev[dst]==INT_MAX?-1:prev[dst];
    }
};
