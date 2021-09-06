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

class Pair{
public:
	int val;
	int index;
	Pair(int val,int index){
		this->val=val;
		this->index=index;
	}
};

bool compare(Pair p1,Pair p2){
	return p1.val < p2.val;
}

int min_swaps(vector<int>&temp){
	int n=temp.size();
	vector<Pair> arr;
	int ans=0;
	for(int i=0;i<n;i++){
		arr.push_back(Pair(temp[i],i));
	}
	sort(arr.begin(),arr.end(),compare);
	for(auto&it:arr){
		cout<<it.val<<" "<<it.index<<endl;
	}
	cout<<endl;
	unordered_map<int,bool> visited;
	for (int i = 0; i < temp.size(); i++) {
		if (visited[i] == true || arr[i].index == i) {
        continue;
      } else {
        int cycle = 0;
        int j = i;
        while (!visited[j]) {
          visited[j] = true;
          cycle++;
          j = arr[j].index;
        }
        ans += (cycle - 1);
      }
    }
    return ans;
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
	cout<<min_swaps(arr)<<endl;
	return 0;
}