class Pair{
public:
    int index;
    int val;
    Pair(int index,int val){
        this->index=index;
        this->val=val;
    }
};
class Heap{
public:
    vector<Pair*> arr;
    int curr=0;
    bool isMin;
    Heap(int length,bool isMin=false){
        arr.resize(length+1);
        this->isMin=isMin;
        arr[0]=nullptr;
    }
    int empty(){
        return curr==0;
    }
    int size(){
        return curr;
    }
    void push(Pair *p,unordered_map<Pair*,pair<char,int>>&mapping){
        arr[++curr]=p;
        int index=curr;
        mapping[p].second=index;
        while(index>1){
            int parent=index/2;
            bool b=false;
            if(isMin){
                if(arr[parent]->val > arr[index]->val){
                    swap(mapping[arr[parent]],mapping[arr[index]]);
                    swap(arr[parent],arr[index]);
                    index=parent;
                    mapping[p].second=index;
                    b=true;
                }
            }else{
                if(arr[parent]->val < arr[index]->val ){
                    swap(mapping[arr[parent]],mapping[arr[index]]);
                    swap(arr[parent],arr[index]);
                    index=parent;
                    mapping[p].second=index;
                    b=true;
                }
            }
            if(!b){
                break;
            }
        }
     }
    void pop(int idx,unordered_map<Pair*,pair<char,int>>&mapping){
        if(curr==0){
            return;
        }
        swap(mapping[arr[idx]],mapping[arr[curr]]);
        swap(arr[idx],arr[curr]);
        curr--;
        int index=idx;
        while(index<=curr){
            int child=index*2;
            int max_index=index;
            if(isMin){
                if(child <= curr and arr[max_index]->val > arr[child]->val ){
                    max_index=child;
                }
                if(child+1 <= curr and arr[max_index]->val > arr[child+1]->val){
                    max_index=child+1;
                }
            }
            else{
                if(child <= curr and arr[max_index]->val < arr[child]->val ){
                    max_index=child;
                }
                if(child+1 <= curr and arr[max_index]->val < arr[child+1]->val){
                    max_index=child+1;
                }
            }
            if(max_index!=index){
                swap(mapping[arr[max_index]],mapping[arr[index]]);
                swap(arr[max_index],arr[index]);
                index=max_index;
            }else{
                break;
            }
        }
    }
    Pair* top(){
        if(curr!=0){
            return arr[1];
        }
        return nullptr;
    }
};
class Solution{
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        Heap left(k,false);
        Heap right(k,true);
        unordered_map<Pair*,pair<char,int>> mapping;
        int i=0;
        deque<Pair*> q;
        for(;i<k;i++){
            Pair *p=new Pair(i,nums[i]);
            q.push_back(p);
            if(left.empty()){
                mapping[p]=make_pair('l',-1);
                left.push(p,mapping);
            }else if(left.top()->val < nums[i]){
                mapping[p]=make_pair('r',-1);
                right.push(p,mapping);
            }else{
                mapping[p]=make_pair('l',-1);
                left.push(p,mapping);
            }
            if(left.empty() and !right.empty()){
                Pair*temp=right.top();
                right.pop(1,mapping);
                mapping[temp].first='l';
                left.push(temp,mapping);
            }
            if(left.empty() and !right.empty()){
                Pair*temp=right.top();
                right.pop(1,mapping);
                mapping[temp].first='l';
                left.push(temp,mapping);
            }
            int size=left.size() - right.size();
            if(size>1){
                Pair* temp=left.top();
                left.pop(1,mapping);
                mapping[temp].first='r';
                right.push(temp,mapping);
            }
            size=right.size()-left.size();
            if(size>1){
                Pair*temp=right.top();
                right.pop(1,mapping);
                mapping[temp].first='l';
                left.push(temp,mapping);
            }
        }
        if(left.size()==right.size()){
            ans.push_back((double) ( ((double) (left.top()->val) + (double)(right.top()->val) )/2));
        }
        else if(left.size()>right.size()){
            ans.push_back((double)left.top()->val);
        }else{
            ans.push_back((double)right.top()->val);
        }

        for(;i<nums.size();i++){
            if(mapping[q.front()].first=='r'){
                right.pop(mapping[q.front()].second,mapping);
            }else{
                left.pop(mapping[q.front()].second,mapping);
            }
            q.pop_front();
            int size= left.size() - right.size();
            if(size>1){
                Pair* temp=left.top();
                left.pop(1,mapping);
                mapping[temp].first='r';
                right.push(temp,mapping);
            }
            if(left.empty() and !right.empty()){
                Pair*temp=right.top();
                right.pop(1,mapping);
                mapping[temp].first='l';
                left.push(temp,mapping);
            }
            size=right.size()-left.size();
            if(size>1){
                Pair*temp=right.top();
                right.pop(1,mapping);
                mapping[temp].first='l';
                left.push(temp,mapping);
            }
            Pair *p=new Pair(i,nums[i]);
            q.push_back(p);
            if(left.empty()){
                mapping[p]=make_pair('l',-1);
                left.push(p,mapping);
            }else if(left.top()->val < nums[i]){
                mapping[p]=make_pair('r',-1);
                right.push(p,mapping);
            }else{
                mapping[p]=make_pair('l',-1);
                left.push(p,mapping);
            }
            //here we have to balance
            size= left.size() - right.size();
            if(size>1){
                Pair* temp=left.top();
                left.pop(1,mapping);
                mapping[temp].first='r';
                right.push(temp,mapping);
            }
            size=right.size()-left.size();
            if(size>1){
                Pair*temp=right.top();
                right.pop(1,mapping);
                mapping[temp].first='l';
                left.push(temp,mapping);
            }
            if(left.size()==right.size()){
                ans.push_back((double) ( ((double) (left.top()->val) + (double)(right.top()->val) )/(double)2));
            }
            else if(left.size()>right.size()){
                ans.push_back((double)left.top()->val);
            }else{
                ans.push_back((double)right.top()->val);
            }
        }
        return ans;
    }
};