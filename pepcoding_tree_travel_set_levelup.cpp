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
//based on morris traversal
//inorder and preorder
class TreeNode{
public:
	int val;
	TreeNode*left,*right;
	TreeNode(){
		left=right=nullptr;
	}
	TreeNode(int val){
		this->val=val;
		left=right=nullptr;
	}
};

TreeNode* buildtree(vector<int>&arr,int&i){
	if(arr[i]==-1){
		i++;
		return NULL;
	}
	TreeNode*root=new TreeNode(arr[i++]);
	root->left=buildtree(arr,i);
	root->right=buildtree(arr,i);
	return root;
}

TreeNode* get_rightMost(TreeNode*temp,TreeNode*curr){
	while(temp->right and temp->right!=curr){
		temp=temp->right;
	}
	return temp;
}

vector<int> morris_inorder(TreeNode*root){
	vector<int> ans;
	TreeNode*curr=root;
	while(curr){
		TreeNode*left=curr->left;
		if(!left){
			//means we have traverse all the nodes of left subtree
			ans.push_back(curr->val);
			curr=curr->right;
		}else{
			TreeNode*right_most=get_rightMost(left,curr);
			if(right_most->right==nullptr){
				//creating the thread
				right_most->right=curr;
				curr=curr->left;
			}else{
				ans.push_back(curr->val);
				//breaking the thread
				right_most->right=nullptr;
				curr=curr->right;
			}
		}
	}
	return ans;
}

vector<int> morris_preorder(TreeNode*root){
	vector<int> ans;
	TreeNode*curr=root;
	while(curr){

		TreeNode*left=curr->left;
		if(!left){
			ans.push_back(curr->val);
			//means we have traverse all the nodes of left subtree
			curr=curr->right;
		}else{
			TreeNode*right_most=get_rightMost(left,curr);
			if(right_most->right==nullptr){
				ans.push_back(curr->val);
				//creating the thread
				right_most->right=curr;
				curr=curr->left;
			}else{
				//breaking the thread
				right_most->right=nullptr;
				curr=curr->right;
			}
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
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		if(s=="n"){
			arr[i]=-1;
		}else{
			stringstream num(s);
			int n;
			num>>n;
			arr[i]=n;
		}
	}
	int i=0;
	TreeNode*root=buildtree(arr,i);
	vector<int> ans=morris_preorder(root);
	for(auto&it:ans){
		cout<<it<<" ";
	}
	cout<<endl;
	return 0;
}