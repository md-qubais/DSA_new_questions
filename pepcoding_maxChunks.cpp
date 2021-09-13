#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define int long long
#define endl "\n"
#define pb push_back
#define p push
#define fori(n) for(int i=0;i<n;i++)
#define ford(n) for(int i=n-1;i>=0;i--)
#define fl(x,n) for(int i=x;i<n;i++)
#define Maxheap priority_queue<int>
#define Minheap priority_queue<int,vector<int>,greater<int>>
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
int maxChunksToSorted(vector<int>& arr){
    int chunks=0;
    int Max=0;
    for(int i=0;i<arr.size();i++){
        Max=max(Max,arr[i]);
        if(Max==i){
            chunks++;
        }
    }
    return chunks;
}
int32_t main(){
    qubais_judge;
    IOS;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto&it:arr){
        cin>>it;
    }
    cout<<maxChunksToSorted(arr)<<endl;
    return 0;
}