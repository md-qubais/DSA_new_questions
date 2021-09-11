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
    vector<int> sortedSquares(vector<int>& nums){
        int s=0;
        int e=nums.size()-1;
        vector<int> res(nums.size());
        int idx=e;
        //because we are going to fill from the last index
        //ie we are first filling the most greatest number
        //followed by the numbers
        //now the most greatest number will be either the least
        //negative one or the most positive one
        //so we start filling like below
        while(idx>=0){
            int square1=nums[s]*nums[s];
            int square2=nums[e]*nums[e];
            if(square1 > square2 ){
                res[idx--]=square1;
                s++;
            }else{
                res[idx--]=square2;
                e--;
            }
        }
        return res;
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
	vector<int> ans=sortedSquares(arr);
	for(auto&it:ans){
		cout<<it<<" ";
	}
	cout<<endl;
	return 0;
}