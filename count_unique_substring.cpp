#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
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
int findSubstrings(string s){
    int i=0;
    int j=0;
    unordered_map<int,int> freq;
    int ans=0;
    while(j<s.length()){
        if(i==j){
            freq[s[j++]]++;
            ans++;
            continue;
        }
        if(freq[s[j]]==0){
            freq[s[j]]
        }

    }
}
int32_t main(){
    qubais_judge;
    IOS;
    string s;
    cin>>s;
    cout<<findSubstrings(s);
    return 0;
}