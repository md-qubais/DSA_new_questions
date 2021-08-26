class Solution{
public:
    void reverse(vector<int>&arr){
        int i=0;
        int j=arr.size()-1;
        while(i<j){
            swap(arr[i++],arr[j--]);
        }
    }
    void flip(vector<int>&arr){
        for(auto&it:arr){
            if(it){
                it=0;
            }else{
                it=1;
            }
        }
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image){
        for(int i=0;i<image.size();i++){
            reverse(image[i]);
            flip(image[i]);
        }
        return image;
    }
};