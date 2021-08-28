class Solution {
public:
    string reorderSpaces(string text){
        if(text.length()==1){
            return text;
        }
        vector<string> arr;
        int space=0;
        string temp="";
        for(int i=0;i<text.length();i++){
            if(text[i]==' '){
                space++;
                if(temp!=""){
                    arr.push_back(temp);
                }
                temp="";
                continue;
            }
            temp+=text[i];
        }
        if(temp!=""){
            arr.push_back(temp);
        }
        if(arr.size()==1){
            return arr[0];
        }
        int spaces=space/(arr.size()-1);
        string ans="";
        for(int i=0;i<arr.size();i++){
            if(i==arr.size()-1){
                ans+=arr[i];
            }else{
                ans+=arr[i];
                for(int j=0;j<spaces;j++){
                    ans+=" ";
                }
            }
        }
        return ans;
    }
};