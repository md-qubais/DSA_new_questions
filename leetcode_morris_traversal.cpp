class Solution{
public:
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
    vector<int> inorderTraversal(TreeNode* root){
        return morris_inorder(root);
    }
};