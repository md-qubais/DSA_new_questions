class Solution {
public:
    
    //here we are using the left max and the right min
    //concept to get the chunks
    //if we take out the left max and the right min 
    //than we can consider and verify that when that max ended
    //ie till where that max contributed and till where the min
    //have been contributed
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> rightmin(arr.size());
        int chunks=0;
        rightmin[arr.size()-1]=arr[arr.size()-1];
        //storing the right min
        for(int i=arr.size()-2;i>=0;i--){
            rightmin[i]=min(rightmin[i+1],arr[i]);
        }
        int leftmax=INT_MIN;
        for(int i=0;i<arr.size()-1;i++){
            leftmax=max(leftmax,arr[i]);
            if(leftmax<=rightmin[i+1]){
                chunks++;
            }
        }
        return chunks+1;
    }
};