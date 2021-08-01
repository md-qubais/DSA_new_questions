class Solution {
public:
    unordered_map<int,list<int>> cities_buses;
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target){
        if(source==target){
            return 0;
        }
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                cities_buses[routes[i][j]].push_back(i);
            }
        }
        int level=0;
        deque<int> q;
        unordered_map<int,bool> visited;
        q.push(source);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int temp=q.front();
                q.pop();
                if(visited[temp]){
                    continue;
                }
                visited[temp]=true;
                for(auto&it:cities_buses[temp]){
                    for(auto&i:routes[it]){
                        if(i==target){
                            return level+1;
                        }
                        if(i==temp){
                            continue;
                        }
                        if(cities_buses[i].size()==1){
                            visited[i]=true;
                            continue;
                        }
                        if() q.push(routes[it][0]);
                    }
                }


            }
            level++;
        }
        return -1;
    }
};