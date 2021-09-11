class Solution {
public:
    bool isLongPressedName(string name, string typed){
        if(name.length()>typed.length()){
            return false;
        }
        int i=0;
        int j=0;
        while(i<name.length() and j<typed.length()){
            if(name[i]==typed[j]){
                i++;
                j++;
            }else if(i>0 and name[i-1]==typed[j]){
                while(name[i-1]==typed[j]){
                    j++;
                }
            }else{
                return false;
            }
        }
        while(name[i-1]==typed[j]){
            j++;
        }
        if(i==name.length() and j==typed.length()){
            return true;
        }
        return false;
    }
};