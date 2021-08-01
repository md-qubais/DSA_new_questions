bool compare(pair<int,pair<int,int>>&p1,pair<int,pair<int,int>>&p2){
    if(p1.second.first==p2.second.first){
        return p1.second.second<p2.second.second;
    }
    return p1.second.first<p2.second.first;
}

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend){
        vector<pair<int,pair<int,int>>> arr;
        for(int i=0;i<times.size();i++){
            arr.push_back({i,{times[i][0],times[i][1]}});
        }
        sort(arr.begin(),arr.end(),compare);
        int chair=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i].first==targetFriend){
                chair=i;
                break;
            }
        }
        int temp=chair;
        while(chair>0 and arr[chair].second.first<=arr[temp].second.first){
            chair--;
        }
        return chair;
    }
};