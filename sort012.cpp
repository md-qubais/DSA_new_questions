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
#define Minheap priority_queue<inwt,vector<int>,greater<int>>
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
void sort012(vector<int>&arr){
	int i=0;
	int j=0;
	int k=arr.size()-1;
	//i means the number is unkown may be three possibility
	//if zero than swap with j 
	//because 0-j index there only will be zeroes
	//increment i and j
	//if i==1 then i++ do nothing
	//because j-i index there is only will be ones
	//if i==2 then swap i and k and decrement k
	//and dont increase i becase the one that we have replaced
	//is not revealed yet , and we have to decide what we will
	//do with that and what number is actually that unrevealed one
	while(i<k){
		if(arr[i]==0){
			swap(arr[i],arr[j]);
			i++;
			j++;
		}else if(arr[i]==1){
			i++;
		}else{
			swap(arr[i],arr[k]);
			k--;
		}
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
	sort012(arr);
	for(auto&it:arr){
		cout<<it<<" ";
	}
	cout<<endl;
	return 0;
}