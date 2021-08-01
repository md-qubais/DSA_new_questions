class Pair{
public:
    int maxLeaves;
    int maxSum;
    Pair(){
        this->maxLeaves=INT_MIN;
        this->maxSum=0;
    }
};
class Solution {
public:
    Pair max_sum(Node*root){
        Pair ans;
        if(!root){
            return ans;
        }
        if(!root->left and !root->right){
            ans.maxSum=root->data;
            return ans;
        }
        Pair left=max_sum(root->left);
        Pair right=max_sum(root->right);
        ans.maxLeaves=max(max(left.maxLeaves,right.maxLeaves),left.maxSum+right.maxSum+root->data);
        ans.maxSum=max(left.maxSum+root->data,right.maxSum+root->data);
        return ans;
    }
    int maxPathSum(Node* root){
        return max_sum(root).maxLeaves;
    }
}; 

