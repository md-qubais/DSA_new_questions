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

class TreeNode{
public:
    int val;
    TreeNode*left,*right;
    TreeNode(int val){
        this->val=val;
        this->left=this->right=nullptr;
    }
};


class Solution{
public:
    TreeNode* get_rightMost(TreeNode*temp,TreeNode*curr){
        while(temp->right and temp->right!=curr){
            temp=temp->right;
        }
        return temp;
    }
    TreeNode * treeToDoublyList(TreeNode * root){
        if(!root ){
            return root;
        }
        if(!root->left and !root->right){
            root->left=root;
            root->right=root;
            return root;
        }
        TreeNode*dummy=new TreeNode(-1);
        TreeNode*prev=dummy;
        //morris traversal boiler template
        TreeNode*curr=root;
        while(curr){
            TreeNode*left=curr->left;
            if(!left){
                prev->right=curr;
                curr->left=prev;
                prev=prev->right;
                curr=curr->right;
            }else{
                TreeNode*right_most=get_rightMost(left,curr);
                if(!right_most->right){
                    right_most->right=curr;
                    curr=curr->left;
                }else{//breaking the thread
                    right_most->right=nullptr;
                    curr->left=prev;
                    prev->right=curr;
                    prev=prev->right;
                    curr=curr->right;
                }
            }
        }
        dummy=dummy->right;
        dummy->left=nullptr;
        prev->right=dummy;
        dummy->left=prev;
        return dummy;
    }
};



TreeNode* buildbst(TreeNode*root,int num){
    if(!root){
        return new TreeNode(num);
    }
    if(root->val<num){
        root->right=buildbst(root->right,num);
        return root;
    }
    root->left=buildbst(root->left,num);
    return root;
}
int32_t main(){
    qubais_judge;
    IOS;
    int n;
    cin>>n;
    TreeNode*root=nullptr;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        root=buildbst(root,num);
    }
    Solution s;
    root=s.treeToDoublyList(root);
    while(root){
        cout<<root->val<<" ";
        if(root->right) root=root->right;
        else break;
    }
    cout<<endl;
    while(root){
        cout<<root->val<<" ";
        root=root->left;
    }
    return 0;
}
