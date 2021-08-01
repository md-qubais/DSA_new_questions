class Codec {
public:
    string serialize(TreeNode* root){
        string res="";
        if(!root){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        res+=to_string(root->val)+" ";
        while(!q.empty()){
            int size=q.size();
            while(size--){
                TreeNode*temp=q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    res+=to_string(temp->left->val)+" ";
                }else res+="N ";
                if(temp->right){
                    q.push(temp->right);
                    res+=to_string(temp->right->val)+" ";
                }else res+="N ";
            }
        }
        return res;
    }

    TreeNode* deserialize(string data){
        if(data.length()==0){
            return nullptr;
        }
        vector<string> arr;
        string temp="";
        for(int i=0;i<data.length();i++){
            if(data[i]==' '){
                if(temp.length()>0){
                    arr.push_back(temp);
                }
                temp="";
                continue;
            }
            temp+=data[i];
        }
        int i=0;
        stringstream str(arr[i++]);
        int num;
        str>>num;
        TreeNode*root=new TreeNode(num);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                TreeNode*temp=q.front();
                q.pop();
                if(i<arr.size()){
                    if(arr[i]!="N"){
                        stringstream s(arr[i]);
                        int n;
                        s>>n;
                        TreeNode*t=new TreeNode(n);
                        temp->left=t;
                        q.push(t);
                    }
                    i++;
                }else{
                    return root;
                }
                if(i<arr.size()){
                    if(arr[i]!="N"){
                        stringstream s(arr[i]);
                        int n;
                        s>>n;
                        TreeNode*t=new TreeNode(n);
                        temp->right=t;
                        q.push(t);   
                    }
                    i++;
                }else{
                    return root;
                }
            }
        }
        return root;//root;
    }
};