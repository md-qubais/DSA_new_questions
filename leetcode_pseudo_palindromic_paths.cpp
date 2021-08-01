class Solution{
public:
	int pseudo_count(TreeNode*root,unordered_map<int,bool> freq){
		if(!freq[root->val]){
			freq[root->val]=true;
		}else{
			freq.erase(root->val);
		}
		if(!root->left and !root->right){
			if(freq.size()==0 or freq.size()==1){
				return 1;
			}
			return 0;
		}
		if(!root->right){
			return pseudo_count(root->left,freq);
		}
		if(!root->left){
			return pseudo_count(root->right,freq);
		}
		int left=pseudo_count(root->left,freq);
		int right=pseudo_count(root->right,freq);
		return left+right;
	}
    int pseudoPalindromicPaths(TreeNode* root){
    	unordered_map<int,bool> freq;
    	return pseudo_count(root,freq);
    }
};