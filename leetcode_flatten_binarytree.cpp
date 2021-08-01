class Pair{
public:
    TreeNode*head;
    TreeNode*tail;
    Pair(){
        head=tail=nullptr;
    }
};
class Solution {
public:

    Pair flatten_it(TreeNode*root){
        Pair ans;
        if(!root){
            return ans;
        }
        Pair left=flatten_it(root->left);
        Pair right=flatten_it(root->right);
        if(!left.head and !right.head){
            ans.head=root;
            ans.tail=root;
            root->left=root->right=nullptr;
            return ans;
        }
        if(!left.head){
            ans.head=root;
            root->left=nullptr;
            root->right=right.head;
            ans.tail=right.tail;
            return ans;
        }
        if(!right.head){
            ans.head=root;
            root->left=nullptr;
            root->right=left.head;
            ans.tail=left.tail;
            return ans;
        }
        left.tail->right=right.head;
        ans.head=root;
        ans.head->right=left.head;
        ans.tail=right.tail;
        ans.head->left=nullptr;
        return ans;
    }

    void flatten(TreeNode* root){
        flatten_it(root);
    }
};