class Pair{
public:
    int a;
    int b;
    Pair(){
        this->a=this->b=0;
    }
};
class Solution{
public:
    bool is_vowel(char ch){
        if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u'){
            return true;
        }
        if(ch=='A' or ch=='E' or ch=='I' or ch=='O' or ch=='U'){
            return true;
        }
        return false;
    }
    Pair vowels(string s){
        int half=s.length()/2;
        Pair p;
        for(int i=0;i<half;i++){
            if(is_vowel(s[i])){
                p.a++;
            }
        }
        for(int i=half;i<s.length();i++){
            if(is_vowel(s[i])){
                p.b++;
            }
        }
        return p;
    }
    bool halvesAreAlike(string s){
        Pair vowel=vowels(s);
        return vowel.a==vowel.b;
    }
};