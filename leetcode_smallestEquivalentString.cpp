#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
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
unordered_map<char,char> leader;
char findLeader(char ch){
	if(ch==leader[ch]){
		return ch;
	}
	return leader[ch]=findLeader(leader[ch]);
}
void Union(char ch1,char ch2){
	char l1=findLeader(leader[ch1]);
	char l2=findLeader(leader[ch2]);
	if(l1==l2){
		return;
	}
	if(l1<l2){
		leader[l2]=l1;
	}else{
		leader[l1]=l2;
	}
}
string smallestEquivalentString(string s1,string s2,string base){
	//here we have ti use dsu
	for(int i=0;i<25;i++){
		leader[(char)('a'+i)]=(char)('a'+i);
	}
	int len=s1.length();
	string ans="";
	for(int i=0;i<len;i++){
		Union(s1[i],s2[i]);
	}
	for(int i=0;i<base.length();i++){
		ans+=findLeader(leader[base[i]]);
	}
	return ans;
}
int32_t main(){
	qubais_judge;
	IOS;
	string s1,s2,base;
	cin>>s1>>s2>>base;
	cout<<smallestEquivalentString(s1,s2,base)<<endl;
	return 0;
}
