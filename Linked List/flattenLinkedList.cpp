/*  Function which returns the  root of 
    the flattened linked list. */
Node *mergeList(Node *l1, Node *l2){
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;
    Node* newHead = new Node(0);
    Node* temp = newHead;
    while(l1!=nullptr && l2!=nullptr){
        if(l1->data<l2->data){
            temp->bottom=l1;
            l1=l1->bottom;
        }else{
            temp->bottom=l2;
            l2=l2->bottom;
        }
        temp=temp->bottom;
    }
    while(l1!=nullptr){
        temp->bottom=l1;
            l1=l1->bottom;
            temp=temp->bottom;
    }
    while(l2!=nullptr){
        temp->bottom=l2;
            l2=l2->bottom;
            temp=temp->bottom;
    }
    return newHead->bottom;
}
Node *flatten(Node *root)
{
   // Your code here
   if(root == nullptr) return nullptr;
   Node*previousMerge = flatten(root->next);
   return mergeList(root,previousMerge);
}
//-----------------------Optimisation by taking advantage of LL---------
Node *mergeList(Node *l1, Node *l2){
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;
    Node* newHead = new Node(0);
    Node* temp = newHead;
    while(l1!=nullptr && l2!=nullptr){
        if(l1->data<l2->data){
            temp->bottom=l1;
            l1=l1->bottom;
        }else{
            temp->bottom=l2;
            l2=l2->bottom;
        }
        temp=temp->bottom;
    }
    if(l1!=nullptr){
        temp->bottom=l1;
    }
    if(l2!=nullptr){
        temp->bottom=l2;
    }
    return newHead->bottom;
}
Node *flatten(Node *root)
{
   // Your code here
   if(root == nullptr ||root->next == nullptr) return root;
   Node*previousMerge = flatten(root->next);
   return mergeList(root,previousMerge);
}
