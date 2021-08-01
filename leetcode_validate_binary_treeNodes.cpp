class Graph{
public:
    vector<int> leaders;
    int getLeaders(int n){
        if(n==leaders[n]){
            return n;
        }
        return leaders[n]=getLeaders(leaders[n]);
    }
    bool validate(int n,vector<int>&leftChild,vector<int>&rightChild){
        leaders.resize(n);
        for(int i=0;i<n;i++){
            leaders[i]=i;
        }
        for(int i=0;i<leftChild.size();i++){
            if(leftChild[i]!=-1){
                int l1=getLeaders(leaders[i]);
                int l2=getLeaders(leaders[leftChild[i]]);
                if(l1==l2 or leftChild[i]!=leaders[l2]){
                    return false;
                }
                n--;
                leaders[l2]=l1;
            }
            if(rightChild[i]!=-1){
                int l1=getLeaders(leaders[i]);
                int l2=getLeaders(leaders[rightChild[i]]);
                if(l1==l2 or rightChild[i]!=leaders[l2]){
                    return false;
                }
                n--;
                leaders[l2]=l1;   
            }
        }
        if(n>1 or n<=0){
            return false;
        }
        return true;
    }
};
class Solution{
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        Graph g;
        return g.validate(n,leftChild,rightChild);
    }
};