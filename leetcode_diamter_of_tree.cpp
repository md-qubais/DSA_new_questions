class Solution {
public:
    int height(TreeNode*root){
        if(!root) return 0;
        return max(height(root->left),height(root->right))+1;
    }
    int diameter_01(TreeNode*root){
        if(!root) return 0;
        int ld=diameter_01(root->left);
        int rd=diameter_01(root->right);
        int lh=height(root->left);
        int rh=height(root->right);
        return max(max(ld,rd),lh+rh);
    }
    class Pair{
    public:
        int diameter;
        int height;
        Pair(){
            diameter=height=0;
        }
    };
    Pair diameter_02(TreeNode*root){
        Pair ans;
        if(!root){
            return ans;
        }
        Pair left=diameter_02(root->left);
        Pair right=diameter_02(root->right);
        ans.diameter=max(max(left.diameter,right.diameter),left.height+right.height);
        ans.height=max(left.height,right.height)+1;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root){
        return diameter_02(root).diameter;
    }
};

