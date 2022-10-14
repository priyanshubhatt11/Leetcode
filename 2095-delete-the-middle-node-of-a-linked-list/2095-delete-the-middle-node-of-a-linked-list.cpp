class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        long long n=0;
        if(head!=NULL)
        {
        struct  ListNode* temp=head;
        struct ListNode* h=head;

        while(temp!=NULL)
        {
            temp=temp->next;
            n++;
        }
        n=n/2;
        n--;    // humne n-- isliye kiya kyuki humko middle se phle rukna hai, fir h->next = h->next->next;
        
        if(n <0)return NULL;    // when size of list is 1
            
        long long x=0;
        while(x<n)
        {
            h=h->next;
            x++;
        }
        h->next=h->next->next;
        
       
     }
        return head;

    }
};