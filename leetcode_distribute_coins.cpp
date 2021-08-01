class Pair{
public:
    int moves;
    int need;
    Pair(){
        this->moves=this->need=0;
    }
};
class Solution{
public:
    //1 indicates that node don't need any coin/coins
    //neqative indicates that subtree need a coin/coins
    //positive indicates that subtree has more coin/coins
    Pair Coins(TreeNode*root){
        Pair res;
        if(!root){
            return res;
        }
        Pair left=Coins(root->left);
        Pair right=Coins(root->right);
        res.moves=left.moves+right.moves+abs(left.need)+abs(right.need);
        res.need=left.need+right.need;
        //means the current node needs a coin
        if(root->val==0){
            res.need--;
        }
        //means that current node has more coins
        else if(root->val>1){
            res.need+=root->val-1;
        }
        return res;
    }
    int distributeCoins(TreeNode* root){
        return Coins(root).moves;
    }
};