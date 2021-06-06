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
class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

ListNode *midNode(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


void printList(ListNode *node)
{
    ListNode *curr = node;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode* reverse(ListNode*head){
    ListNode*prev=NULL;
    ListNode*curr=head;
    head=head->next;
    while(head){
        curr->next=prev;
        prev=curr;
        curr=head;
        head=head->next;
    }
    curr->next=prev;
    return curr;
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
    ListNode*ans=NULL;
    ListNode*tail=NULL;
    l1=reverse(l1);
    l2=reverse(l2);
    int rem=0;
    while(l1 and l2){
        int temp=rem+l1->val+l2->val;
        if(!ans){
            ans=new ListNode(temp%10);
            tail=ans;
        }else{
            ListNode*t=new ListNode(temp%10);
            tail->next=t;
            tail=t;
        }
        rem=temp/10;
        l1=l1->next;
        l2=l2->next;
    }
    while(l1){
        int temp=rem+l1->val;
        ListNode*t=new ListNode(temp%10);
        tail->next=t;
        tail=t;
        rem=temp/10;
        l1=l1->next;
    }
    while(l2){
        int temp=rem+l2->val;
        ListNode*t=new ListNode(temp%10);
        tail->next=t;
        tail=t;
        rem=temp/10;
        l2=l2->next;
    }
    return reverse(ans);
}

ListNode *makeList(int n)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }
    return dummy->next;
}

int32_t main(){
    qubais_judge;
    IOS;    
    int n;
    cin >> n;
    ListNode *head1 = makeList(n);
    int m;
    cin >> m;
    ListNode *head2 = makeList(m);
    ListNode *head = addTwoNumbers(head1, head2);
    printList(head);
    return 0;
}
