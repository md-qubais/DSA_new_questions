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
    bool find1(){

    }

    bool find_word(Node*curr){
        if(curr->isTerminal){
            find1(curr,root);
        }
        for(char ch='a';ch<='z';ch++){
            if(curr->childs[ch]){
                return find_word(curr->childs[ch]);
            }
        }
        return false;
    }
    bool word_break(string s){
        Node*temp=root;
        if(find_word(temp->childs[s[0]],s.substr(1))){
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
        t->insert(s);
        return t->word_break(s);
    }
};