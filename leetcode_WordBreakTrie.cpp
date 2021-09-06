class Node{
public:
    
    char ch;
    unordered_map<char,Node*> childs;
    bool isTerminal;
    
    Node(char ch){
        this->ch=ch;
        isTerminal=false;
    }
};

class Trie{
public:

    Node*root=nullptr;
    
    Trie(char ch='\0'){
        root=new Node(ch);
    }
    
    void insert(string word){
        Node*temp=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(temp->childs.count(ch)!=0){
                temp=temp->childs[ch];
            }else{
                Node*t=new Node(ch);
                temp->childs[ch]=t;
                temp=temp->childs[ch];
            }
        }
        temp->isTerminal=true;
    }

    bool word_break(string s){
        Node*temp=root;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(temp->childs.count(ch)==0){
                if(root->childs.count(ch)==0){
                    return false;
                }
                temp=root;
            }
            temp=temp->childs[ch];
        }
        if(temp->isTerminal){
            return true;
        }
        return false;
    }

};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict){
        Trie *t=new Trie();
        for(auto&it:wordDict){
            t->insert(it);
        }
        return t->word_break(s);
    }
};