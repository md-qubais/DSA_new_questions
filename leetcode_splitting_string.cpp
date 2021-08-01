class Solution{
public:
    bool split_string(string s,long long int prev=-1,unsigned long long int temp=0){
        if(s.length()==0){
            if(prev==-1) return false;
            if(temp+1!=prev){
                return false;
            }
            return true;
        }
        if(prev==-1){
            prev=temp;
        }else if(temp+1!=prev){
            return false;
        }
        prev=temp;
        temp=0;
        for(int i=0;i<s.length();i++){
            if(temp*10+s[i]-'0'>=LONG_MAX){
                return false;
            }
            temp=temp*10+s[i]-'0';
            if(split_string(s.substr(i+1),prev,temp)){
                return true;
            }
        }
        return false;
    }
    bool splitString(string s){
        unsigned long long int num=0;
        for(int i=0;i<s.length();i++){
            if(num*10+(s[i]-'0')>=LONG_MAX){
                return false;
            }
            num=num*10+(s[i]-'0');
            if(split_string(s.substr(i+1),-1,num)){
                return true;
            }
        }
        return false;
    }
};