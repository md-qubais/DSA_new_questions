class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u' or ch=='A' or ch=='E' or ch=='I' or ch=='O' or ch=='U'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s){
        int left=0;
        int right=s.length()-1;
        while(left < right){
            while(left < right and !isVowel(s[left])){
                left++;
            }
            while(left < right and !isVowel(s[right])){
                right--;
            }
            if(left<right){
                swap(s[left++],s[right--]);
            }
        }
        return s;
    }
};