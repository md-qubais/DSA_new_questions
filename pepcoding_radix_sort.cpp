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

vector<int> count_sort(vector<int>&arr,int exp){
	vector<int> freq(10,0);
	for(auto&it:arr){
		freq[it/exp%10]++;
	}
	freq[0]--;
	for(int i=1;i<freq.size();i++){
		freq[i]+=freq[i-1];
	}
	vector<int> ans(freq[freq.size()-1]+1);
	for(auto&it:arr){
		ans[freq[it/exp%10]--]=it;
	}
	return ans;
}


int32_t main(){
	qubais_judge;
	IOS;
	//sort all the place i means what will be the max
	//place of ones twos or threes or so on
	//of the max number
	return 0;
}