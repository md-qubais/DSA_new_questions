class Pair{
public:
	int val;
	int index;
	Pair(int val,int index){
		this->val=val;
		this->index=index;
	}
};
class Compare_max{
public:
	bool operator()(Pair *p1,Pair *p2){
		return p1->val < p2->val;
	}
};
class Compare_min{
public:
	bool operator()(Pair *p1,Pair *p2){
		return p1->val > p2->val;
	}
};
class Solution{
public:
	void balance(priority_queue<Pair*,vector<Pair*>,Compare_max>&left,priority_queue<Pair*,vector<Pair*>,Compare_min>&right,int&left_balance,int&right_balance,unordered_map<Pair*,pair<bool,int>>&freq,Pair *remove=nullptr){
		if(remove){
			if(freq[remove].second==0 and !freq[remove].first){
				left_balance--;
			}else if(freq[remove].second==1 and !freq[remove].first){
				right_balance--;
			}
			freq[remove].first=true;
		}
		while(!right.empty()  and freq[right.top()].first){
			right.pop();
		}
		while(!left.empty()  and freq[left.top()].first){
			left.pop();
		}
		int size=left_balance - right_balance;
		if(size>1){
			Pair *p=left.top();
			left.pop();
			right.push(p);
			freq[p].second=1;
			left_balance--;
			right_balance++;
		}
		size=right_balance - left_balance;
		if(size>1){
			Pair *p=right.top();
			right.pop();
			left.push(p);
			freq[p].second=0;
			left_balance++;
			right_balance--;
		}

		while(!right.empty()  and freq[right.top()].first){
			right.pop();
		}
		while(!left.empty()  and freq[left.top()].first){
			left.pop();
		}
	}
    vector<double> medianSlidingWindow(vector<int>& nums, int k){
    	priority_queue<Pair*,vector<Pair*>,Compare_max> left;
    	priority_queue<Pair*,vector<Pair*>,Compare_min> right;
    	vector<double> ans;
    	int left_balance=0;
    	int right_balance=0;
    	queue<Pair*> q;
    	unordered_map<Pair*,pair<bool,int>> freq;
    	int i=0;
    	for(;i<k;i++){
    		Pair *p=new Pair(nums[i],i);
    		q.push(p);
    		if(left_balance == 0){
    			left_balance++;
    			freq[p]=make_pair(false,0);
    			left.push(p);
    		}else if(left.top()->val < nums[i]){
    			right_balance++;
    			freq[p]=make_pair(false,1);
    			right.push(p);
    		}else{
    			left_balance++;
    			freq[p]=make_pair(false,0);
    			left.push(p);
    		}
    		balance(left,right,left_balance,right_balance,freq);
    	}
    	if(left_balance == right_balance){
    		double d=(((double)left.top()->val) +  ((double)right.top()->val) )/(double)2;
    		ans.push_back(d);
    	}else if(left_balance > right_balance){
    		ans.push_back((double)left.top()->val);
    	}else{
    		ans.push_back((double)right.top()->val);
    	}	
    	for(;i<nums.size();i++){
    		balance(left,right,left_balance,right_balance,freq,q.front());
    		q.pop();
    		Pair *p=new Pair(nums[i],i);
    		q.push(p);
    		if(left_balance == 0){
    
    			left_balance++;
    			freq[p]=make_pair(false,0);
    			left.push(p);
    		}else if(left.top()->val < nums[i]){
    			right_balance++;
    			freq[p]=make_pair(false,1);
    			right.push(p);
    		}else{
    			left_balance++;
    			freq[p]=make_pair(false,0);
    			left.push(p);
    		}
    		balance(left,right,left_balance,right_balance,freq);
    		if(left_balance == right_balance){
    			double d=(((double)left.top()->val) +  ((double)right.top()->val) )/(double)2;
    			ans.push_back(d);
    		}else if(left_balance > right_balance){
    			ans.push_back((double)left.top()->val);
    		}else{
    			ans.push_back((double)right.top()->val);
    		}
    	}
    	return ans;
    }
};