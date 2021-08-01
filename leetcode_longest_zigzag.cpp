class Pair{
public:
    int max_path;
    int left_path;
    int right_path;
    Pair(){
        max_path=left_path=right_path=0;
    }
};
class Solution{
public:
    Pair longest(TreeNode*root){
        Pair res;
        if(!root){
            return res;
        }
        Pair left=longest(root->left);
        Pair right=longest(root->right);
        //no edge and no childs of current node
        if(!root->left and !root->right){
            return res;
        }
        //left and right child are present of current node
        if(root->right and root->left){
            res.left_path=left.right_path+1;
            res.right_path=right.left_path+1;
            res.max_path=max(max(left.max_path,right.max_path),max(res.left_path,res.right_path));     
            return res;
        }
        //only left child is present of the current node
        if(root->left){
            res.left_path=left.right_path+1;
            res.right_path=0;
            res.max_path=max(res.left_path,max(left.max_path,right.max_path));
            return res;
        }
        //only right child is present of the current node
        res.right_path=right.left_path+1;
        res.left_path=0;
        res.max_path=max(max(right.max_path,left.max_path),res.right_path);
        return res;
    }
    int longestZigZag(TreeNode* root){
        return longest(root).max_path;
    }
};