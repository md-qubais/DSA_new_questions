class Solution{
public:
    int minimumJumps(vector<int>& f, int a, int b, int x){
        unordered_map<int,bool> forbidden;
        for(auto&it:f){
            forbidden[it]=true;
        }
        int jumps=0;
        queue<pair<long long int,string>> q;
        q.push({0,"forward"});
        while(!q.empty()){
            int size=q.size();
            while(size--){
                pair<int,string> temp=q.front();
                q.pop();
                if(temp.first==x){
                    return jumps;
                }
                if(forbidden[temp.first] or temp.first>=INT_MAX){
                    continue;
                }
                forbidden[temp.first]=true;
                //we can jump forward and backward
                if(temp.second=="forward"){
                    if(!forbidden[temp.first+a]){
                        q.push({temp.first+a,"forward"});
                    }
                    if((temp.first-b)>0 and !forbidden[temp.first-b]){
                        q.push({temp.first-b,"backward"});
                    }
                }//we can jump only forward
                else{
                    if(!forbidden[temp.first+a]){
                        q.push({temp.first+a,"forward"});
                    }
                }
            }
            jumps++;
        }
        return -1;
    }
};