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
bool isValid(int val,vector<int>&arr){
	int count=0;
	for(auto&it:arr){
		if(it==val){
			count++;
		}
	}
	if(count>(arr.size())/2){
		return true;
	}
	return false;
}
int majorityElement(vector<int>& nums) {
	int val=nums[0];
    int count=1;
    for(int i=1;i<nums.size();i++){
        if(nums[i]==val){
            count++;
        }else{
            if(count>0){
                count--;
            }else{
                val=nums[i];
                count=1;
            }
        }
    }
    if(isValid(val,nums)){
    	cout<<val<<endl;
    }else{
    	cout<<"No Majority Element exist"<<endl;
    }
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
	majorityElement(arr);
	return 0;
}