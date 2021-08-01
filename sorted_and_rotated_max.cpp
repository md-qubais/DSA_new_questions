class Solution {
public:

int search(vector<int>&arr,int n){
  int s=0;
  int e=n-1;
  int ans=-1;
  while(s<=e){
    int mid=(s+e)/2;
    if(arr[s]<=arr[mid] and arr[mid]<=arr[e]){
      return arr[s];
    }
    else{
      if(arr[s]<=arr[mid]){
        if(ans==-1) ans=s;
        else if(arr[ans]>=arr[mid]){
          ans=s;
        }
        s=mid+1;
      }else{
        if(ans==-1) ans=mid;
        else if(arr[ans]>=arr[mid]){
          ans=mid;
        }
        e=mid-1;
      }
    }
  }
  return arr[ans];
}
    int findMin(vector<int>& nums) {
    return search(nums,nums.size());   
    }
};