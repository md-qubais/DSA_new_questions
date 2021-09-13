class Solution{
public:
    void sortArray(vector<int>&arr){
        int i=0;
        int j=0;
        while(i<arr.size()){
            if(arr[i]%2!=0){
                i++;e
            }else{
                swap(arr[i],arr[j]);
                j++;
                i++;
            }
        }
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        sortArray(nums);
        return nums;
    }
};