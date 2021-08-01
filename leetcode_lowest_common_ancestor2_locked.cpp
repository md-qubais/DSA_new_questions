class Solution {
public:
    int count=0;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return nullptr;
        }
        TreeNode*left=lowestCommonAncestor(root->left,p,q);
        TreeNode*right=lowestCommonAncestor(root->right,p,q);
        if(root==p or root==q){
            count++;
            return root;
        }
        if(left and right){
            return root;
        }
        if(left){
            return left;
        }
        if(right){
            return right;
        }
        return nullptr;
    }
    TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B){
        TreeNode*ans=lowestCommonAncestor(root,A,B);
        if(ans and count==2){
            return ans;
        }
        return nullptr;
    }
};