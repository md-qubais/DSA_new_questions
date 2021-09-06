class Node{
public:
    int sum;
    char ch;
    unordered_map<char,Node*> childs;
    Node(char ch='\0'){
        this->ch=ch;
        this->sum=0;
    }
};
class Trie{
public:
    Node*root;
    unordered_map<string,int> mapping;
    Trie(char ch='\0'){
        root=new Node(ch);
    }
    void insert(string key,int val){
        int subs;
        if(mapping.find(key)==mapping.end()){
            subs=0;
        }else{
            subs=mapping[key];
        }
        mapping[key]=val;
        Node*temp=root;
        for(int i=0;i<key.length();i++){
            if(temp->childs[key[i]]){
                temp=temp->childs[key[i]];
                temp->sum+=val-subs;
            }else{
                temp->childs[key[i]]=new Node(key[i]);
                temp=temp->childs[key[i]];
                temp->sum=val-subs;
            }
        }
    }
    int sum(string key){
        int ans=0;
        Node*temp=root;
        for(int i=0;i<key.length();i++){
            if(temp->childs[key[i]]){
                temp=temp->childs[key[i]];
                ans=temp->sum;
            }else{
                return 0;
            }
        }
        return ans;
    }
};
class MapSum {
public:
    Trie *t;
    MapSum() {
        t=new Trie('\0');
    }
    
    void insert(string key, int val) {
        t->insert(key,val);
    }
    
    int sum(string prefix) {
        return t->sum(prefix);
    }
};
