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
    unordered_map<string,bool> mapping;
    Node*root=nullptr;
    Trie(char ch='\0'){
        root=new Node(ch);
    }
    void insert(string word){
        Node*temp=root;
        mapping[word]=true;
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
    bool word_break(string s,Node*temp,int i){
        if(i==s.length() ){
            if(temp->isTerminal){
                return true;
            }
            return false;
        }
        if(temp==nullptr) temp=root;
        if(temp->childs.count(s[i])==0){
            return false;
        }
        if(word_break(s,temp->childs[s[i]],i+1)){
            return true;
        }
        if(!temp->childs[s[i]]->isTerminal){
            return false;
        }
        if(word_break(s,nullptr,i+1)){
            return true;
        }
        return false;
    }
};
class Solution{
public:
    bool wordBreak(string s, vector<string>& wordDict){
        Trie *t=new Trie();
        for(auto&it:wordDict){
            t->insert(it);
        }
        return t->word_break(s,nullptr,0);
    }
};