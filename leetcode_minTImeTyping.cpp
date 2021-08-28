class Solution{
public:
    int minTimeToType(string word){
        int time=0;
        char curr='a';
        for(auto&it:word){
            int curr_temp=curr-'a';
            int curr_char=it-'a';
            int clock=curr_temp - curr_char ;
            int anticlock= curr_char - (curr_temp + 26);
            if(curr=='z'){
                cout<<clock<<" "<<anticlock<<endl;
            }
            curr=it;
            if(clock < 0) clock=-clock;
            if(anticlock < 0) anticlock=-anticlock;
            if(clock < anticlock){
                time+=clock+1;
            }else{
                time+=anticlock+1;
            }
            cout<<time<<" "<<curr<<endl;
        }
        return time;
    }
};