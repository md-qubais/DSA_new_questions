class Solution {
public:
    int longestMountain(vector<int>& arr){
        int ans=0;
        if(arr.size()<3){
            return ans;
        }
        int i=0;
        int j=0;
        bool up=false;
        bool down=false;
        while(j<arr.size()){
            if(i==j){
                j++;
                continue;
            }
            if(arr[j-1]==arr[j]){
                if(up and down) ans=max(ans,j-i);
                i=j;
                up=false;
                down=false;
                j++;
                continue;
            }
            if(arr[j-1]<arr[j]){
                if(down){
                    ans=max(ans,j-i);
                    i=j-1;
                    down=false;
                }
                if(!up){
                    up=true;
                }
            }
            if(arr[j-1]>arr[j]){
                if(!up){
                    i=j;
                }else{
                    down=true;
                }
            }
            j++;
        }
        if(up and down) ans=max(ans,j-i);
        return ans;
    }
};