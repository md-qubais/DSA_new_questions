class Pair{
public:
    //here if we take just long in java it will
    //pass all the test cases
    //if we use just long long in c++
    //it wont pass the large test cases
    //so we must have to use unsigned long long int in c++
    unsigned long long int index;
    TreeNode*root;
    Pair(long long int index,TreeNode*root){
        this->index=index;
        this->root=root;
    }
};
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root){
        int ans=0;
        deque<Pair> q;
        q.push_back(Pair(1,root));
        while(!q.empty()){
            int size=q.size();
            int compare=q.back().index-q.front().index+1;
            ans=max(ans,compare);
            while(size--){
                Pair temp=q.front();
                q.pop_front();
                if(temp.root->left){
                    q.push_back(Pair((2*temp.index),temp.root->left));
                }
                if(temp.root->right){
                    q.push_back(Pair((2*temp.index+1),temp.root->right));
                }
            }
        }
        return ans;
    }
};