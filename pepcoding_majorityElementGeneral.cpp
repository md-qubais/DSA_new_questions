#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define int long long
#define endl "\n"
#define pb push_back
#define p push
#define fori(n) for(int i=0;i<n;i++)
#define ford(n) for(int i=n-1;i>=0;i--)
#define fl(x,n) for(int i=x;i<n;i++)
#define Maxheap priority_queue<int>
#define Minheap priority_queue<int,vector<int>,greater<int>>
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;

bool isValid(vector<int>&arr,int val,int k){
	int count=0;
	for(auto&it:arr){
		if(it==val){
			count++;
		}
	}
	if(count> arr.size()/k){
		return true;
	}
	return false;
}

void MajorityElementGeneral2(vector<int>&arr,int k){
	vector<int> vals(k-1);
	vector<int> counts(k-1);
	counts[0]=1;
	for(int i=0;i<vals.size();i++){
		vals[i]=arr[0];
	}
	for(int i=1;i<counts.size();i++){
		counts[i]=0;
	}
	for(int i=1;i<arr.size();i++){
		bool b=false;
		for(int j=0;j<vals.size();j++){
			if(vals[j]==arr[i]){
				b=true;
				counts[j]++;
				break;
			}
		}
		//make fresh start or make it a pair of k
		if(!b){
			for(int j=0;j<vals.size();j++){
				//fresh start
				if(counts[j]==0){
					vals[j]=arr[i];
					counts[j]=1;
					b=true;
					break;
				}
			}
			//making a pair reducing the counts by 1
			if(!b){
				for(auto&it:counts){
					it--;
				}
			}
		}
	}
	set<int> s;
	for(auto&it:vals){
		s.insert(it);
	}
	vector<int> res;
	for(auto&it:s){
		if(isValid(arr,it,k)){
			res.push_back(it);
		}
	}
	if(res.size()==1){
		cout<<"["<<res[0]<<"]"<<endl;
	}else{
	for(int i=0;i<res.size();i++){
		if(i==0){
			cout<<"["<<res[i];
		}else if(i==res.size()-1){
            cout<<", "<<res[i]<<"]";
        }else{
        	cout<<", "<<res[i];
        }
    }
}
    cout<<endl;
}




void MajorityElementGeneral1(vector<int>&arr,int k){
	unordered_map<int,int> freq;
	for(auto&it:arr){
		freq[it]++;
	}
	vector<int> res;
	for(auto&it:freq){
		if(it.second > arr.size()/k){
			res.push_back(it.first);
		}
	}
	for(int i=0;i<res.size();i++){
		if(i==0){
			cout<<"["<<res[i];
		}else if(i==res.size()-1){
            cout<<","<<res[i]<<"]";
        }else{
        	cout<<","<<res[i];
        }
    }
    cout<<endl;
}
int32_t main(){
	qubais_judge;
	IOS;
	int size;
	cin>>size;
	vector<int> arr(size);
	for(auto&it:arr){
		cin>>it;
	}
	int k;
	cin>>k;
	// MajorityElementGeneral1(arr,k);
	MajorityElementGeneral2(arr,k);
	return 0;
}