/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
        Node* p, *q;
        p = head;
        if(p == NULL) return head;
        p = p->next;
        q = head;
        int prev = head->data;
        while(p != NULL){
            if(p->data == prev){
                q->next = p->next;
                delete p;
                p = q->next;
                continue;
            }
            prev = p->data;
            q = p;
            p = p->next;
        }
        return head;
}
