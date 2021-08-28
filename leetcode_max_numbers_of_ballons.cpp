class Solution{
public:
    int maxNumberOfBalloons(string text){
        unordered_map<char,int> freq;
        int count=0;
        string balloon="balloon";
        for(auto&it:text){
            freq[it]++;
        }
        while(true){
            for(auto&it:balloon){
                if(freq[it]==0){
                    return count;
                }
                freq[it]--;
            }
            count++;
        }
        return count;
    }
};