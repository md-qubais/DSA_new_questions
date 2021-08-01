class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum){
        if(!root) return  false;
        if(!root->left and !root->right){
            if(targetSum - root->val==0){
                return true;
            }
            return false;
        }
        if(root->left and hasPathSum(root->left,targetSum-root->val)){
            return true;
        }
        if(root->right and hasPathSum(root->right,targetSum-root->val)){
            return true;
        }
        return false;
    }
};