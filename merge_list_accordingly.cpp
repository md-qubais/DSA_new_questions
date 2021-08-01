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

ListNode* buildList(int size){
    ListNode*head=new ListNode(-1);
    ListNode*tail=head;
    for(int i=0;i<size;i++){
        int num;
        cin>>num;
        tail->next=new ListNode(num);
        tail=tail->next;
    }
    return head->next;
}

void display(ListNode*head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
}

void merge_list(ListNode*first,ListNode*second){
    int count=0;
    ListNode*head=new ListNode(-1);
    ListNode*tail=head;
    while(tail){
        if(count==0){
            tail->next=first;
            if(first) first=first->next;
        }else{
            tail->next=second;
            if(second) second=second->next;
        }
        tail=tail->next;
        count=(count+1)%2;
        if(!second){
            tail->next=first;
            tail=nullptr;
        }
    }
    display(head->next);
    cout<<endl;
    if(second){
        display(second);
    }
}

int32_t main(){
    qubais_judge;
    IOS;
    int n;
    cin>>n;
    ListNode *first=buildList(n);
    cin>>n;
    ListNode *second=buildList(n);
    merge_list(first,second);
    return 0;
}