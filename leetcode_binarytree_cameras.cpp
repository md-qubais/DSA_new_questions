class Pair{
public:
    int camera;
    int need;
    Pair(){
        this->camera=0;
        this->need=0;
    }
};
class Solution {
public:
    //1 deontes that node have the camera
    //0 deontes that node doesn't need the camera
    //-1 deontes that node need the camera
    Pair Camera_cover(TreeNode*root){
        Pair res;
        if(!root){
            return res;
        }
        Pair left=Camera_cover(root->left);
        Pair right=Camera_cover(root->right);
        if(left.need==-1 or right.need==-1){
            res.camera=left.camera+right.camera+1;
            res.need=1;
            return res;
        }
        if(left.need==0 and right.need==0){
            res.camera=left.camera+right.camera;
            res.need=-1;
            return res;
        }
        res.need=0;
        res.camera=left.camera+right.camera;
        return res;
    }
    int minCameraCover(TreeNode* root){
        if(!root->left and !root->right){
            return 1;
        }
        Pair ans=Camera_cover(root);
        if(ans.need==-1){
            ans.camera++;
        }
        return ans.camera;
    }
};