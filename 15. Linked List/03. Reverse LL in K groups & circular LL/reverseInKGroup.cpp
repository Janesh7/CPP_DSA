/****************************************************************
    Following is the Linked List node structure

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

Node *kReverse(Node *head, int k)
{
    // base call
    if (head == NULL)
    {
        return NULL;
    }

    // step1: reverse first k nodes
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;

    // IMP: curr!=NULL
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step2: Recursion will see the rest
    //  if the next node(fwd node) is not null ie there is remaining LL
    if (next != NULL)
    {
        // after reversing the k nodes the head will be at the part where we want to attach the output of the rest, head points to null as we r reversing it, but later upon the return of this function call it would connect the LL
        head->next = kReverse(next, k);
    }

    // step3: return head of reversed list
    return prev;
}