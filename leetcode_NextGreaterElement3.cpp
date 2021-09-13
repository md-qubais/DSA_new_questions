class Solution {
public:

	int getDipIndex(vector<char>&arr){
		int dipIndex=-1;
		if(arr.size()==1){
			return dipIndex;
		}
		char val=arr[arr.size()-1];
		for(int i=arr.size()-2;i>=0;i--){
			if(val>arr[i]){
				dipIndex=i;
				break;
			}else{
				val=arr[i];
			}
		}
		return dipIndex;
	}

	int getCeilIndex(vector<char>&arr,int dipIndex){
		int index=arr.size()-1;
		while(index!=dipIndex and arr[dipIndex] >= arr[index] ){
			index--;
		}
		return index;
	}


	void swapNumbers(vector<char>&arr,int dipIndex,int ceilIndex){
		swap(arr[dipIndex],arr[ceilIndex]);
	}

	void reverse(vector<char>&arr,int i,int j){
		while(i<j){
			swap(arr[i++],arr[j--]);
		}
	}

	string NextGreaterElement(string s){
		vector<char> arr(s.length());
		for(int i=0;i<s.length();i++){
			arr[i]=s[i];
		}
		int dipIndex=getDipIndex(arr);
		if(dipIndex==-1){
			return "-1";
		}
		int ceilIndex=getCeilIndex(arr,dipIndex);
		swapNumbers(arr,dipIndex,ceilIndex);
		reverse(arr,dipIndex+1,arr.size()-1);
		string ans="";
		for(auto&it:arr){
			ans+=it;
		}
		return ans;
	}
	int nextGreaterElement(int n) {
		string ans=NextGreaterElement(to_string(n));
		if(ans=="-1"){
			return -1;
		}
		long long num=0;
		for(int i=0;i<ans.length();i++){
			int val=ans[i]-'0';
			if((num*10)+val >=INT_MAX){
				return -1;
			}
			num=num*10+val;
		}
		return (int)num;
	}
};