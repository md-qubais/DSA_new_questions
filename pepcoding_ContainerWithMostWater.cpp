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
int maxArea(vector<int>& height){
	int s=0;
	int e=height.size()-1;
	int water=INT_MIN;
	while(s<e){
		water=max(water,(e-s)*min(height[s],height[e]));
		if(height[s]<height[e]){
			s++;
		}else{
            e--;
        }
    }
    return water;
}
int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	vector<int> height(n);
	for(auto&it:height){
		cin>>it;
	}
	cout<<maxArea(height)<<endl;
	return 0;
}