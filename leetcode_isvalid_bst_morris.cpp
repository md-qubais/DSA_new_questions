class Solution {
public:
    TreeNode* get_rightMost(TreeNode*temp,TreeNode*curr){
        while(temp->right and temp->right!=curr){
            temp=temp->right;
        }
        return temp;
    }
    bool morris_inorder(TreeNode*root){
        int prev=INT_MIN;
        TreeNode*curr=root;
        bool b=true;
        while(curr){
            TreeNode*left=curr->left;
            if(!left){
                //means we have traverse all the nodes of left subtree
                //or left subtree doesnt exists
                if(prev>=curr->val){
                    b=false;
                }
                if(b) prev=curr->val;
                curr=curr->right;
            }else{
                TreeNode*right_most=get_rightMost(left,curr);
                if(right_most->right==nullptr){
                    //creating the thread
                    right_most->right=curr;
                    curr=curr->left;
                }else{
                    if(prev>=curr->val){
                        b=false;
                    }
                    if(b) prev=curr->val;
                    //breaking the thread
                    right_most->right=nullptr;
                    curr=curr->right;
                }
            }
        }
        return b;
    }
    bool isValidBST(TreeNode* root) {
        return morris_inorder(root);
    }
};