class Solution{
public:
    //using path compression concept
    vector<int> arr;
    int get_informTIme(int emp,vector<int>&manager,vector<int>&informTime){
        if(manager[emp]==-1){ 
           return arr[emp]=informTime[emp];
        }
        if(arr[emp]!=-1){
            return arr[emp];
        }
        return arr[emp]=get_informTIme(manager[emp],manager,informTime)+informTime[emp];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime){
        arr.resize(n);
        for(auto&it:arr){
            it=-1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,get_informTIme(i,manager,informTime));
        }
        return ans;
    }
};
