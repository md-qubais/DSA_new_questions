class Solution{
public:
    vector<int> morris_inorder(TreeNode*root){
        vector<int> ans;
        if(!root){
            return ans;
        }
        TreeNode*curr=root;
        TreeNode*left=root->left;
        while(curr){
            if(!left){
                ans.push_back(curr->val);
                curr=curr->right;
                if(curr) left=curr->left;
            }else{
                TreeNode*right_most=left;
                bool b=false;
                while(right_most->right){
                    if(right_most->right==curr){
                        ans.push_back(curr->val);
                        right_most->right=nullptr;
                        curr=curr->right;
                        if(curr) left=curr->left;
                        b=true;
                        break;
                    }
                    right_most=right_most->right;
                }
                if(!b){
                    right_most->right=curr;
                    curr=curr->left;
                    left=curr->left;
                }
            }
        }
        return ans;
    }
    vector<int> inorderTraversal(TreeNode* root){
        return morris_inorder(root);
    }
};