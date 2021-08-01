
vector<long long> printFirstNegativeInteger(long long int arr[],long long int n, long long int k){
vector<long long> ans;
    queue<int> q;
    int i=0;
    for(;i<k;i++){
        if(arr[i]<0){
            q.push(i);
        }
    }
    if(q.empty()){
        ans.push_back(0);
    }else{
        ans.push_back(arr[q.front()]);
    }
    for(;i<n;i++){
        if(arr[i]<0){
            q.push(i);
        }
        while(!q.empty() and i-q.front()+1>k){
            q.pop();
        }
        if(q.empty()){
            ans.push_back(0);
        }else{
            ans.push_back(arr[q.front()]);
        }
    }
    return ans;
}