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
int maximumProduct(vector<int>& nums) {
	int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN;
	int min1=INT_MAX,min2=INT_MAX;
	for(int i=0;i<nums.size();i++){
		if(nums[i] > max1){
			max3=max2;
			max2=max1;
			max1=nums[i];
		}else if(nums[i] > max2){
			max3=max2;
			max2=nums[i];
		}else if(nums[i]>max3){
			max3=nums[i];
		}
		if(nums[i]<min1){
			min2=min1;
			min1=nums[i];
		}else if(nums[i]<min2){
			min2=nums[i];
		}
	}
	return max(max1*max2*max3,max1*min1*min2);
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
	cout<<maximumProduct(arr)<<endl;
	return 0;
}