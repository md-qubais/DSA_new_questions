class LockingTree{
public:
    unordered_map<int,int> locked;
    unordered_map<int,list<int>> childs;
    unordered_map<int,int> parents;
    LockingTree(vector<int>& parent) {
        for(int i=0;i<parent.size();i++){
            locked[i]=-1;
        }
        for(int i=0;i<parent.size();i++){
            parents[i]=parent[i];
            childs[parent[i]].push_back(i);
        }
    }
    bool lock(int num, int user){
        if(locked[num]==-1){
            locked[num]=user;
            return true;
        }
        return false;
    }
    bool unlock(int num, int user){
        if(locked[num]==-1){
            return false;
        }
        if(locked[num]==user){
            locked[num]=-1;
            return true;
        }
        return false;
    }
    bool no_locked_ancestors(int num){
        if(locked[num]!=-1){
            cout<<num<<endl;
            return true;
        }
        if(parents[num]==-1){
            return false;
        }
        return no_locked_ancestors(parents[num]);
    }
    vector<int> arr;
    bool b=false;
    void get_Descendants(int num){
        for(auto&it: childs[num]){
            get_Descendants(it);
        }
        if(locked[num]!=-1){
            b=true;
        }
        arr.push_back(num);
    }
    bool upgrade(int num, int user){
        if(locked[num]==-1){
            arr.clear();
            b=false;
            get_Descendants(num);
            if(!b){
                return false;
            }
            if(!no_locked_ancestors(num)){
                for(auto&it:arr){
                    locked[it]=-1;
                }
                locked[num]=user;
                return true;
            }
        }
        return false;
    }
};