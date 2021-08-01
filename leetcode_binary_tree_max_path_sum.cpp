class Solution{
public:

    //O(N^2)
    int ans=INT_MIN;
    void get_max(TreeNode*root,int&res,int sum=0){
        if(!root){
            return;
        }
        res=max(res,sum+root->val);
        get_max(root->left,res,sum+root->val);
        get_max(root->right,res,sum+root->val);
        return;
    }
    int maxPathSum(TreeNode* root){
        if(!root){
            return ans;
        }
        maxPathSum(root->left);
        maxPathSum(root->right);
        int sum=INT_MIN;
        get_max(root->left,sum);
        int left=sum;
        sum=INT_MIN;
        get_max(root->right,sum);
        int right=sum;
        if(!root->left and !root->right){
            return ans=max(ans,root->val);
        }
        if(root->left and root->right){
            ans=max(ans,max(left,max(right,max(root->val+left,max(root->val+right,max(root->val,root->val+left+right))))));
            return ans;
        }
        if(root->left){
            ans=max(ans,max(left,max(root->val+left,root->val)));
            return ans;
        }
        ans=max(ans,max(right,max(root->val+right,root->val)));
        return ans;
    }
};