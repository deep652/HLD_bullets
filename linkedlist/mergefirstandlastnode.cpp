#include<iostream>
using namespace std;

class Node
{
    int data;
    
    public:
    class Node *next;
    Node(int data):data(data),next(nullptr){}
    Node(){}
    // Node*& getNext()
    // {
    //     return next;
    // }

    void setNext(Node *newnode)
    {
        next = newnode;
    }
    int getData()
    {
        return data;
    }
    void setData(int data)
    {
        this->data = data;
    }
    Node(Node * newNode)
    {
        //Deep copy this node
        this->setData( newNode->getData());
        this->next = nullptr;
    }
   
};


class linkedlist
{
    Node *root;
    public:
    void printList();
    void printList(Node *root);
    void createList();
    Node* createCopy();
    Node * getRoot(){
        return root;
    }
    Node* reverseList(Node* root); 
    Node * mergeFirstAndLast(Node *root);
    Node* mergeKnodeAtAtime(Node *root, int k);
    Node * mergek(Node *root, int k);

}; 
Node * linkedlist :: mergeFirstAndLast(Node * root)
{
    int length = 0;
    Node* it = root;
    Node *prev = root;
    while(it != nullptr)
    {
        length++;
        it = it -> next;
    }
    int mid = length/2;
    int i=1;
    it = root;
    while(i<=mid)
    {
        it = it->next;
        i++;
    }
   // cout<<"is reached : "<<i<<endl;
    Node * secondHalf = it->next;
    cout<<"end of first half"<<it->getData()<<endl;
    it->next = nullptr;//breaking the first half end with null

    //reverse the second half

    Node *sd = reverseList(secondHalf);
    //cout<< sd->next->next->getData() <<endl;

    Node* firstHalf = root;
    Node *n1, *n2, *fn;
    while(sd != nullptr)
    {
        n1 = firstHalf -> next;
        n2 = sd -> next;
        firstHalf->next = sd;
        sd -> next = n1;
        
        firstHalf = n1;
        sd = n2;
    }
    //if(firstHalf == nullptr)
    //cout<<sd->getData()<<endl;
    //cout<<"final list"<<root->next->getData()<<endl;
    it = root;
    while(it!=nullptr)
    {
        cout<<it->getData()<<"\t";
        it = it -> next;
    }
    cout<<endl;

    return root;
}

Node* linkedlist:: createCopy()
{
    Node *it, *itresult;
    it = root;
    Node* newNode = new Node(it);
    
    Node* newroot = newNode;
    //cout<<"root is"<<root<<"new root os"<<newroot<<endl;
    itresult = newroot;
    it = it->next;
    while(it != nullptr)
    {
        Node* newnode1 =  new Node(it);
        //cout<<"old node is"<<it<<"new node is "<<newnode1<<endl;
        itresult->next = newnode1;
        itresult = itresult->next;
        it = it->next;
    }
    //cout<<newroot->next->next->getData()<<endl;
    //cout<<newroot<<endl;
   // cout<<"copy is successful"<<endl;
    return newroot;
    
}
void linkedlist:: createList()
{
    Node *newnode = new Node(1);
    root = newnode;
    Node *it;
    it = root;
    newnode = new Node(2);
    it->setNext(newnode);
    it = it->next;
    newnode = new Node(3);
    it->setNext(newnode);
    it = it->next;
    newnode = new Node(4);
    it->setNext(newnode);
    it = it->next;
    newnode = new Node(5);
    it->setNext(newnode);
    it = it->next;
    newnode = new Node(6);
    it->setNext(newnode);
    it = it->next;

    cout<< root<<endl;
}
void linkedlist :: printList()
{
    Node *it;
    it = root;
    while(it != nullptr)
    {
        cout<< it->getData()<<endl;
        it = it -> next;
    }
}

void linkedlist :: printList(Node *proot)
{
    Node *it;
    it = proot;
    while(it != nullptr)
    {
        cout<< it->getData()<<endl;
        it = it -> next;
    }
}
Node* linkedlist:: reverseList(Node *root)
{
    Node *curr, *prev, *next;
    curr = root;
    prev = nullptr;
    while(curr != nullptr)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node * linkedlist:: mergeKnodeAtAtime(Node *root, int k)
{
    int i = 0;
    Node *head = root;
    Node *curr = root;
    Node *prev = nullptr;
    Node *it = root;
    Node *nextListRoot = nullptr;
    if(root == nullptr || k==1)
    {
        return root;
    }
    while(it!=nullptr && i<k)
    {
        it = it->next;
        i++;
    }
    if(it)
    {
        nextListRoot = it->next;
        it ->next = nullptr;
    }
    
    Node * reversedhead = reverseList(head);
    root -> next = mergeKnodeAtAtime(nextListRoot, k);

    return reversedhead;

    //1 2 3 4 5 6
    //3 2 1 6 5 4

}
Node * linkedlist::mergek(Node *root, int k)
{
    //reverse the first k node
    //
    Node *curr, *prev, *next;
    curr = root;
    prev = nullptr;
    int i = 0;
    if(root == nullptr || k == 1)
        return curr;

    while(curr != nullptr && i<k)
    {
        next = curr -> next;
        curr->next = prev;
        prev = curr;
        curr = next;
        i++;
    }

    root->next = mergek(curr, k); //this will not be prev, as we already have reached till 3rd node, we want to reconnect 1 -> next revesesed
    // node in the list

    return prev;
}
int main()
{
    linkedlist ll;
    ll.createList();
    ll.printList();
    Node *newroot;
    newroot = ll.createCopy();
    Node *root_copy = ll.createCopy();
    //ll.printList(newroot);
    //Node *reverseroot = ll.reverseList();
    //ll.printList(reverseroot);
    //ll.mergeFirstAndLast(newroot);
    //Node *mergedroot = ll.mergeKnodeAtAtime(newroot, 3);
    //ll.printList(mergedroot);
    ll.printList(root_copy);
    cout<<"merged k new list"<<endl;

    //Node *mergeknew = ll.mergek(root_copy, 3);
    //ll.printList(mergeknew);
    Node *mergedroot = ll.mergeKnodeAtAtime(newroot, 3);
    ll.printList(mergedroot);
    

    return 0;
}