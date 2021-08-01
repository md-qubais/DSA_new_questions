class Pair{
public:
    int with_robbery;
    int without_robbery;
    Pair(){
        this->with_robbery=0;
        this->without_robbery=0;
    }
};
class Solution{
public:
    Pair robbery(TreeNode*root){
        Pair res;
        if(!root){
            return res;
        }
        Pair left=robbery(root->left);
        Pair right=robbery(root->right);
        res.with_robbery=left.without_robbery+right.without_robbery+root->val;
        res.without_robbery=max(left.with_robbery,left.without_robbery)+max(right.with_robbery,right.without_robbery);
        return res;
    }
    int rob(TreeNode* root){
        Pair ans=robbery(root);
        return max(ans.with_robbery,ans.without_robbery);
    }
};