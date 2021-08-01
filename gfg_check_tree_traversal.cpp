class Node{
public:
    int val;
    Node*left,*right;
    Node(int val){
        this->val=val;
        this->left=this->right=nullptr;
    }
};
class Solution{
    public:
    Node* buildtree(int preorder[],int inorder[],int&i,int s,int e,int n){
        if(s>e or i>=n){
            return nullptr;
        }
        Node*root=new Node(preorder[i++]);
        int mid=-1;
        for(int j=s;j<=e;j++){
            if(inorder[j]==root->val){
                mid=j;
                break;
            }
        }
        if(mid==-1){
            return root;
        }
        root->left=buildtree(preorder,inorder,i,s,mid-1,n);
        root->right=buildtree(preorder,inorder,i,mid+1,e,n);
        return root;
    }
    void verify_postorder(Node*root,vector<int>&arr){
        if(!root){
            return;
        }
        verify_postorder(root->left,arr);
        verify_postorder(root->right,arr);
        arr.push_back(root->val);
    }
    bool checktree(int preorder[], int inorder[], int postorder[], int n){
        int i=0;
        Node*root=buildtree(preorder,inorder,i,0,n-1,n);
        if(i<n){
            return false;
        }
        i=0;
        vector<int> post;
        verify_postorder(root,post);
        if(post.size()!=n){
            return false;
        }
        for(int k=0;k<n;k++){
            if(postorder[k]!=post[k]){
                return false;
            }
        }
        return true;
    } 
};