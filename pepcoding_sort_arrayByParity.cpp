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
void sortArray(vector<int>&arr){
	int i=0;
	int j=0;
	while(i<arr.size()){
		if(arr[i]%2!=0){
			i++;
		}else{
			swap(arr[i],arr[j]);
			j++;
			i++;
		}
	}
}
int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<arr.size();i++){
		cin>>arr[i];
	}
	sortArray(arr);
	for(auto&it:arr){
		cout<<it<<" ";
	}
	cout<<endl;
	return 0;
}