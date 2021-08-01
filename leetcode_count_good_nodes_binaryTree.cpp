class Solution{
public:
    int goodNodes(TreeNode* root,int Max=INT_MIN){
        if(!root){
            return 0;
        }
        int val=max(Max,root->val);
        int left=goodNodes(root->left,val);
        int right=goodNodes(root->right,val);
        return root->val<Max?left+right:left+right+1;
    }
};