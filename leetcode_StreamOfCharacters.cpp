class Node{
public:
    deque<char> chars;
    char ch;
    bool isTerminal;
    unordered_map<char,Node*> childs;
    Node(char ch='\0'){
        this->ch=ch;
        this->isTerminal=false;
    }
};

class Trie{
public:
    Node*root;
    unordered_map<string,bool> dp;
    Trie(char ch='\0'){
        root=new Node(ch);
    }
    void insert(string key){
        reverse(key.begin(),key.end());
        Node*temp=root;
        for(int i=0;i<key.length();i++){
            if(temp->childs[key[i]]){
                temp=temp->childs[key[i]];
            }else{
                temp->childs[key[i]]=new Node(key[i]);
                temp=temp->childs[key[i]];
            }
        }
        temp->isTerminal=true;
    }

    bool find(char ch){
        Node*temp=root;
        root->chars.push_back(ch);
        int i=root->chars.size()-1;
        for(;i>=0;i--){
            if(temp->childs[root->chars[i]]){
                temp=temp->childs[root->chars[i]];
                if(temp->isTerminal){
                    return true;
                }
            }else{
                return false;
            }
        }
        if(temp->isTerminal){
            return true;
        }
        return false;
    }
};

class StreamChecker{
public:
    Trie *t;
    StreamChecker(vector<string>& words){   
        t=new Trie('\0');
        for(auto&it:words){
            t->insert(it);
        }
    }
    bool query(char letter){
        return t->find(letter);
    }
};