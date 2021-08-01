class Solution{
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches){
        deque<int> st;
        deque<int> sand;
        for(auto&it:students){
            st.push_back(it);
        }
        for(auto&it:sandwiches){
            sand.push_back(it);
        }
        int ans=0;
        while(!st.empty() and !sand.empty()){
            int size=st.size();
            int count=0;
            while(st.front()!=sand.front()){
                st.push_back(st.front());
                st.pop_front();
                count++;
                if(count==size){
                    break;
                }
            }
            if(st.front()==sand.front()){
                st.pop_front();
                sand.pop_front();
            }
            if(st.size()==size){
                return st.size();
            }
        }
        return ans;
    }
};