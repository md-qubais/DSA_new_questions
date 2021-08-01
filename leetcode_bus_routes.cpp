class Solution{
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target){
        if(source==target){
            return 0;
        }
        unordered_map<int,list<int>> mapping;
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                mapping[routes[i][j]].push_back(i);
            }
        }
        unordered_map<int,bool> visited;
        queue<int> q;
        q.push(source);
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int temp=q.front();
                q.pop();
                for(auto&stops:mapping[temp]){
                    if(visited[stops]){
                        continue;
                    }
                    for(auto&it:routes[stops]){
                        if(it==target){
                            return level+1;
                        }
                        if(it==temp or visited[it] or mapping[it].size()==1){
                            continue;
                        }
                        q.push(it);
                    }
                    visited[stops]=true;
                }
            }
            level++;
        }
        return -1;
    }
};