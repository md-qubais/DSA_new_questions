class Solution {
public:

    TreeNode* get_rightMost(TreeNode*temp,TreeNode*curr){
        while(temp->right and temp->right!=curr){
            temp=temp->right;
        }
        return temp;
    }
    int morris_inorder(TreeNode*root,int k){
        TreeNode*curr=root;
        int ans=-1;
        while(curr){
            TreeNode*left=curr->left;
            if(!left){
                //means we have traverse all the nodes of left subtree
                //or left subtree doesnt exists
                 if(--k==0){
                    ans=curr->val;
                 }
                 curr=curr->right;
            }else{
                TreeNode*right_most=get_rightMost(left,curr);
                if(right_most->right==nullptr){
                    //creating the thread
                    right_most->right=curr;
                    curr=curr->left;
                }else{
                    //breaking the thread
                    if(--k==0){
                        ans=curr->val;
                    }
                    right_most->right=nullptr;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        return morris_inorder(root,k);
    }
};