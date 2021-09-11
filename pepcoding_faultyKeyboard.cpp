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
bool isLongPressedName(string name, string typed){
	int i=0;
    int j=0;
    while(i<name.length() and j<typed.length()){
    	if(name[i]==typed[j]){
    		i++;
    		j++;
    	}else if(i>0 and name[i-1]==typed[j]){
    		while(name[i-1]==typed[j]){
    			j++;
    		}
    	}else{
    		return false;
    	}
    }
    while(name[i-1]==typed[j]){
    	j++;
    }
    if(i==name.length() and j==typed.length()){
    	return true;
    }
    return false;
}
int32_t main(){
	qubais_judge;
	IOS;
	string name;
	cin>>name;
	string typed;
	cin>>typed;
	if(isLongPressedName(name,typed)){
		cout<<"true"<<endl;
	}else{
		cout<<"false"<<endl;
	}
	return 0;
}