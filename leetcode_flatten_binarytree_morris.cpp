class Solution{
public:
    TreeNode* get_rightMost(TreeNode*temp,TreeNode*curr){
        while((temp->right) and (temp->right!=curr)){
            temp=temp->right;
        }     
        return temp;
    }
    void flatten(TreeNode* root){
        TreeNode*curr=root;
        while(curr){
            TreeNode*left=curr->left;
            if(!left){
                curr=curr->right;
            }else{
                TreeNode*right_most=get_rightMost(left,curr);
                if(!right_most->right){
                    //creating the thread
                    right_most->right=curr;
                    curr=curr->left;
                }else{
                    //breaking the thread
                    TreeNode*preserve=curr->right;
                    right_most->left=right_most->right=nullptr;
                    right_most->right=preserve;
                    curr->right=curr->left;
                    curr->left=nullptr;
                    curr=curr->right;
                }
            }
        }
    }
};