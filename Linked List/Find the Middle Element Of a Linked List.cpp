class Solution {
public:
    ListNode* middleNode(ListNode* head) {
             ListNode * t = head;
             ListNode * r= head->next;
             while(r!=NULL && r->next!=NULL)
             {
                 t=t->next;
                 r=r->next;
                 r=r->next;
             }
        
        if(r==NULL)
            return t;
        return t->next;
        
    }
};
