//using articulation point and bridges
//in this problem we are using articulation points
//the articulation point specifies if the vertex is removed
//if its an articulation point than it specifies that 
//there will me more than one component
//we just need to take count and every time the current node
//is in articulation point than we have to increase count
//count==1 means that there are 2 components and count==2 means
//there are 3 components here goes by increasing

//for root we have to calculate the articulation point
//differently and we have to see if calls from root is one 
//than there is always only one component
//if the calls are more than one than calculate components on 
//the basis of articulation point

class Graph{
public:
    vector<list<int>> l;
    vector<int> lowest;
    vector<int> discovery;
    int time=0;
    void add_edge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void dfs(int src,unordered_map<int,bool>&visited,vector<vector<int>>&ans,int parent=-1){
        discovery[src]=lowest[src]=time++;
        visited[src]=true;
        for(auto&it:l[src]){
        
                //condition for articulation edge/bridge
                //this condition means that the discovery time of 
                //the source is before and it is discovered before it neighbour
                //and even our neighbour didnt get any edge/vertex that has lesser discovery
                //time than source means the neighbour does not have any backup edge
                //which is present before the source that may or may not have any backup edge
                //which means that it leads to the increment of the component of the graph
                if(discovery[src]<lowest[it]){//if(lowest[it]==discovery[it]){ also accepted            vector<int> temp;
                    temp.push_back(src);
                    temp.push_back(it);
                    ans.push_back(temp);
                }
                lowest[src]=min(lowest[src],lowest[it]);
            }else if(it!=parent){
                lowest[src]=min(lowest[src],discovery[it]);
            }
        }
    }
    //articulation point works for vertex
    //articulation bridge works for edges
    vector<vector<int>> articulationPoint_and_Bridges(int n){
        lowest.resize(n+1);
        discovery.resize(n+1);
        unordered_map<int,bool> visited;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,ans);
            }
        }
        return ans;
    }
};

class Solution{
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
        Graph g;
        g.l.resize(n+1);
        for(int i=0;i<connections.size();i++){
            g.add_edge(connections[i][0],connections[i][1]);
        }
        return g.articulationPoint_and_Bridges(n);
    }
};