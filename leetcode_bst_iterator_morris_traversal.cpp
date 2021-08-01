class BSTIterator {
public:
    TreeNode*curr=nullptr;
    TreeNode* get_rigthMost(TreeNode*temp,TreeNode*curr){
        while(temp->right and temp->right!=curr){
            temp=temp->right;
        }
        return temp;
    }
    BSTIterator(TreeNode* root){
        curr=root;
        while(curr->left){
            TreeNode*right_most=get_rigthMost(curr->left,curr);
            right_most->right=curr;
            curr=curr->left;
        }
    }

    int next(){
        int num=curr->val;
        curr=curr->right;
        while(curr and curr->left){
            TreeNode*right_most=get_rigthMost(curr->left,curr);
            if(!right_most->right){
                right_most->right=curr;
                curr=curr->left;
            }else{
                right_most->right=nullptr;
                break;
            }
        }
        return num;
    }
    
    bool hasNext() {
        return curr!=nullptr;
    }
};

