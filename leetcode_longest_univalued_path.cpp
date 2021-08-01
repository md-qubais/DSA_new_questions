class Pair{
public:
    int tot;
    int max_path;
    int val;
    Pair(){
        tot=max_path=val=0;
    }
};
class Solution {
public:
    Pair longest_path(TreeNode*root){
        Pair res;
        if(!root){
            return res;
        }
        Pair left=longest_path(root->left);
        Pair right=longest_path(root->right);
        //left and right child not present
        if(!root->left and !root->right){
            res.tot=1;
            res.max_path=0;
            res.val=root->val;
            return res;
        }
        //left and right child is present
        if(root->left and root->right){
            if(root->val==left.val and root->val==right.val){
                res.tot=max(left.tot,right.tot)+1;
                res.max_path=max(left.max_path,max(right.max_path,right.tot+left.tot));
            }else if(root->val==left.val){
                res.tot=left.tot+1;
                res.max_path=max(left.max_path,max(right.max_path,res.tot-1));
            }else if(root->val==right.val){
                res.tot=right.tot+1;
                res.max_path=max(left.max_path,max(right.max_path,res.tot-1));
            }else{
                res.tot=1;
                res.max_path=max(left.max_path,right.max_path);
            }
            res.val=root->val;
            return res;
        }
        //only left child is present
        if(root->left){
            if(left.val==root->val){
                res.tot=left.tot+1;
                res.max_path=max(left.max_path,res.tot-1);
            }else{
                res.max_path=left.max_path;
                res.tot=1;
            }
            res.val=root->val;
            return res;
        }
        //only right child is present
        if(right.val==root->val){
            res.tot=right.tot+1;
            res.max_path=max(right.max_path,res.tot-1);
        }else{
            res.max_path=right.max_path;
            res.tot=1;
        }
        res.val=root->val;
        return res;
    }
    int longestUnivaluePath(TreeNode* root) {
        return longest_path(root).max_path;
    }
};