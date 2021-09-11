class Solution{
public:
    //check what will be the best possibility
    //ie reducing end or increasing start
    //if start is smaller increasing start is best choice
    //because if we got the next bigger element there may be
    //chance of increasing water if smaller then water may reduce
    //but when we reduce end incase of smaller start
    //not matter what on reducing the end we will get less water
    //because we are just comparing the water from the height of the 
    //smaller 
    int maxArea(vector<int>& height){
        int s=0;
        int e=height.size()-1;
        int water=INT_MIN;
        while(s<e){
            water=max(water,(e-s)*min(height[s],height[e]));
            if(height[s]<height[e]){
                s++;
            }else{
                e--;
            }
        }
        return water;
    }
};