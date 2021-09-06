class Node{
public:
    char ch;
    bool isTerminal;
    string word;
    unordered_map<char,Node*> childs;
    Node(char ch='\0'){
        this->ch=ch;
        this->isTerminal=false;
        this->word="";
    }
};
class Trie{
public:
    Node*root;
    Trie(char ch='\0'){
        root=new Node(ch);
    }
    void insert(string key){
        Node*curr=root;
        for(int i=0;i<key.length();i++){
            if(curr->childs[key[i]]){
                curr=curr->childs[key[i]];
            }else{
                curr->childs[key[i]]=new Node(key[i]);
                curr=curr->childs[key[i]];
                curr->ch=key[i];
            }
        }
        curr->isTerminal=true;
        curr->word=key;
    }
    void find1(Node*curr,Node*temp,vector<string>&ans){
        if(curr->isTerminal and temp->isTerminal){
            curr->isTerminal=false;
            ans.push_back(curr->word);
        }
        if(temp->isTerminal){
            find1(curr,root,ans);
        }
        for(char ch='a';ch<='z'; ch++){
            if(curr->childs[ch] and temp->childs[ch]){
                find1(curr->childs[ch],temp->childs[ch],ans);
            }
        }
    }
    void find(Node*curr,vector<string>&ans){
        if(curr->isTerminal){
            find1(curr,root,ans);
        }
        for(char ch='a';ch<='z';ch++){
            if(curr->childs[ch]) find(curr->childs[ch],ans);
        }
    }
    vector<string> Words(){
        vector<string> ans;
        for(char ch='a';ch<='z';ch++){
            if(root->childs[ch]){
                find(root->childs[ch],ans);
            }
        }
        return ans;
    }
};
class Solution{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words){
        Trie *t=new Trie('\0');
        for(auto&it:words){
            if(it.length()>0)t->insert(it);
        }
        return t->Words();    
    }
};