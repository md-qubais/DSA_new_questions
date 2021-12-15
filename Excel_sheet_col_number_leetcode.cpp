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
int titleToNumber(string columnTitle){
	unordered_map<char,int> mapping;
	int count=0;
	for(char ch='A';ch<='Z';ch++){
		mapping[ch]=++count;
	}
	if(columnTitle.length()==1){
		return mapping[columnTitle[0]];
	}
	int i=0;
	int ans=mapping[columnTitle[i]]*26+mapping[columnTitle[i+1]];
	i++;
	while(i<(columnTitle.length()-1)){
		ans=(ans*26+mapping[columnTitle[i+1]]);
		i++;
	}
	return ans;
}
int32_t main(){
	qubais_judge;
	IOS;
	cout<<titleToNumber("FXSHRXW");
	return 0;
}