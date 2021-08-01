class Pair{
public:
    int good_nodes;
    vector<int> arr;
    Pair(){
        good_nodes=0;
    }
};
class Solution{
public:
    Pair count_pairs(TreeNode*root,int distance){
        Pair res;
        if(!root){
            return res;
        }
        Pair left=count_pairs(root->left,distance);
        Pair right=count_pairs(root->right,distance);
        if(!root->left and !root->right){
            res.arr.push_back(0);
            return res;
        }
        if(root->left and root->right){
            for(int i=0;i<left.arr.size();i++){
                left.arr[i]++;
            }
            for(int i=0;i<right.arr.size();i++){
                right.arr[i]++;
            }
            res.arr=left.arr;
            for(auto&it:right.arr){
                res.arr.push_back(it);
            }
            res.good_nodes+=left.good_nodes+right.good_nodes;
            for(int i=0;i<left.arr.size();i++){
                for(int j=0;j<right.arr.size();j++){
                    if(left.arr[i]+right.arr[j]<=distance){
                        res.good_nodes++;
                    }
                }
            }
            return res;
        }
        if(root->left){
            for(int i=0;i<left.arr.size();i++){
                left.arr[i]++;
            }
            res.arr=left.arr;
            res.good_nodes=left.good_nodes;
            return res;
        }
        for(int i=0;i<right.arr.size();i++){
            right.arr[i]++;
        }
        res.arr=right.arr;
        res.good_nodes=right.good_nodes;
        return res;
    }
    int countPairs(TreeNode* root, int distance){
        return count_pairs(root,distance).good_nodes;
    }
};