#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
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
class ListNode{
public:
	int val;
	ListNode*prev,*next;
	ListNode(int val){
		this->val=val;
		prev=next=nullptr;
	}
};

void insert(ListNode*&head,ListNode*&tail,int num){
	if(head==nullptr){
		head=tail=new ListNode(num);
	}else{
		tail->next=new ListNode(num);
		tail=tail->next;
	}
}

ListNode*head1=nullptr;
void add(ListNode*head,int size=1){
	if(!head){
		return;
	}
	add(head->next,size+1);
	int mid=size/2;
	if(mid<=1){
		return;
	}
	head1->val+=head->val;
	head->val=head1->val;
	head1=head1->next;
}


int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	ListNode*head=nullptr,*tail=nullptr;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		insert(head,tail,num);
	}
	head1=head;
	add(head);
	while(head){
		cout<<head->val<<" ";
		head=head->next;
	}
	return 0;
}

