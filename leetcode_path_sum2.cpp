class Solution {
public:
    void pathSum(TreeNode*root,int targetSum,vector<vector<int>>&ans,vector<int> temp){
        if(!root){
            return;
        }
        temp.push_back(root->val);
        if(!root->left and !root->right){
            if(targetSum-root->val==0){
                ans.push_back(temp);
            }
            return;
        }
        pathSum(root->left,targetSum-root->val,ans,temp);
        pathSum(root->right,targetSum-root->val,ans,temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum){
        vector<vector<int>> ans;
        vector<int> temp;
        pathSum(root,targetSum,ans,temp);
        return ans;
    }
};