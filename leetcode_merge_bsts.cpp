class Solution {
public:
    unordered_map<int,TreeNode*> mapping;
    bool bst=true;
    TreeNode* merge(TreeNode*root,TreeNode*actual_root,int left=INT_MIN,int right=INT_MAX){
        if(!root){
            return nullptr;
        }
        if(!bst){
            return root;
        }
        if(root->val<=left or root->val>=right){
            bst=false;
            return root;
        }
        root->left=merge(root->left,actual_root,left,root->val);
        root->right=merge(root->right,actual_root,root->val,right);
        if(!root->left and !root->right){
            if(mapping.find(root->val)!=mapping.end() and mapping.at(root->val)!=root and mapping.at(root->val)!=actual_root){
                root=mapping[root->val];
                mapping.erase(root->val);
                return merge(root,actual_root,left,right);
            }
            
        }
        return root;
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        for(auto&it:trees){
            mapping[it->val]=it;
        }
        TreeNode*ans=nullptr;
        for(auto&it:mapping){
            merge(it.second,it.second);
            ans=it.second;
            if(!bst){
                return nullptr;
            }
        }
        if(mapping.size()>1){
            return nullptr;
        }
        return ans;
    }
};