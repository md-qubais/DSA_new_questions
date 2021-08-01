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

class node{
public:
	int data;
	node*right,*left;
	node(){
	}
	node(int data){
		this->data=data;
		this->right=this->left=NULL;
	}
};
node* buildtree(vector<int>&arr,int&i){
	if(arr[i]==-1){
		i++;
		return NULL;
	}
	node*root=new node(arr[i++]);
	root->left=buildtree(arr,i);
	root->right=buildtree(arr,i);
	return root;
}
int ans=0;
	void zigzag(node*root,bool dir,int asf){
    	if(!root){
    		return;
    	}
        ans=max(ans,asf);
    	if(dir){
    		zigzag(root->left,false,asf+1);
    		zigzag(root->right,true,1);
    	}else{
    		zigzag(root->right,true,asf+1);
    		zigzag(root->left,false,1);
    	}
    	return;
    }
int32_t main(){
	qubais_judge;
	IOS;
	string s;
	getline(cin,s);
	s+=" ";
	vector<int> arr;
	string temp="";
	for(int i=0;i<s.length();i++){
		if(s[i]==' '){
			if(temp.length()>0){
				stringstream str(temp);
				int n;
				str>>n;
				arr.push_back(n);
			}
			temp="";
			continue;
		}
		temp+=s[i];
	}
	int i=0;
	node*root=buildtree(arr,i);
	int num=0;
	zigzag(root,true,0);
    zigzag(root,false,0);
    cout<<ans<<endl;
	return 0;
}