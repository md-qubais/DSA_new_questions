class Solution{
public:
    vector<int> numberOfLines(vector<int>& widths, string s){
        int max_pixels=0;
        int count=1;
        for(int i=0;i<s.length();i++){
            if(widths[s[i]-'a']+max_pixels > 100){
                count++;
                max_pixels=widths[s[i]-'a'];
                continue;
            }
            max_pixels+=widths[s[i]-'a'];
        }
        vector<int> ans(2);
        ans[0]=count;
        ans[1]=max_pixels;
        return ans;
    }
};