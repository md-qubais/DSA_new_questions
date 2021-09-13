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
 //here we are using the left max and the right min
    //concept to get the chunks
    //if we take out the left max and the right min 
    //than we can consider and verify that when that max ended
    //ie till where that max contributed and till where the min
    //have been contributed
int maxChunksToSorted(vector<int>& arr) {
	vector<int> rightmin(arr.size());
	int chunks=0;
	rightmin[arr.size()-1]=arr[arr.size()-1];
        //storing the right min
	for(int i=arr.size()-2;i>=0;i--){
		rightmin[i]=min(rightmin[i+1],arr[i]);
	}
	int leftmax=INT_MIN;
	for(int i=0;i<arr.size()-1;i++){
		leftmax=max(leftmax,arr[i]);
		if(leftmax<=rightmin[i+1]){
			chunks++;
		}
	}
	return chunks+1;
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