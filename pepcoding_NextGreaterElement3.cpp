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
int getDipIndex(vector<char>&arr){
	int dipIndex=-1;
	if(arr.size()==1){
		return dipIndex;
	}
	char val=arr[arr.size()-1];
	for(int i=arr.size()-2;i>=0;i--){
		if(val>arr[i]){
			dipIndex=i;
			break;
		}else{
			val=arr[i];
		}
	}
	return dipIndex;
}

int getCeilIndex(vector<char>&arr,int dipIndex){
	int index=arr.size()-1;
	while(index!=dipIndex and arr[dipIndex] >= arr[index] ){
		index--;
	}
	return index;
}


void swap(vector<char>&arr,int dipIndex,int ceilIndex){
	swap(arr[dipIndex],arr[ceilIndex]);
}

void reverse(vector<char>&arr,int i,int j){
	while(i<j){
		swap(arr[i++],arr[j--]);
	}
}

string NextGreaterElement(string s){
	vector<char> arr(s.length());
	for(int i=0;i<s.length();i++){
		arr[i]=s[i];
	}
	int dipIndex=getDipIndex(arr);
	if(dipIndex==-1){
		return "-1";
	}
	int ceilIndex=getCeilIndex(arr,dipIndex);
	swap(arr,dipIndex,ceilIndex);
	reverse(arr,dipIndex+1,arr.size()-1);
	string ans="";
	for(auto&it:arr){
		ans+=it;
	}
	return ans;
}
int32_t main(){
	qubais_judge;
	IOS;
	string s;
	cin>>s;
	cout<<NextGreaterElement(s)<<endl;
	return 0;
}