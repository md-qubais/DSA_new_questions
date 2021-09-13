class Solution{
public:
    //chaining technique
    int maxChunksToSorted(vector<int>& arr){
        int chunks=0;
        int Max=0;
        for(int i=0;i<arr.size();i++){
            Max=max(Max,arr[i]);
            if(Max==i){
                chunks++;
            }
        }
        return chunks;
    }
};