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
    void mergeFirstAndLast(Node *root);

}; 
void linkedlist :: mergeFirstAndLast(Node * root)
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
    while(i<mid)
    {
        it = it->next;
        i++;
    }
   // cout<<"is reached : "<<i<<endl;
    Node * secondHalf = it->next;
    cout<<"end of first half"<<it->getData()<<endl;
    //it->next = nullptr;//breaking the first half end with null

    //reverse the second half

    Node *sd = reverseList(secondHalf);
    //cout<< sd->next->next->getData() <<endl;

    Node* firstHalf = root;
    Node *n1, *n2, *fn;
    while(firstHalf != nullptr && sd != nullptr)
    {
        n1 = firstHalf -> next;
        n2 = sd -> next;
        firstHalf->next = sd;
        firstHalf = n1;
        sd -> next = firstHalf;
        sd = n2;
    }
    //if(firstHalf == nullptr)
    cout<<sd->getData()<<endl;
    cout<<"final list"<<root->next->next->next->getData()<<endl;
}

Node* linkedlist:: createCopy()
{
    Node *it, *itresult;
    it = root;
    Node* newNode = new Node(it);
    
    Node* newroot = newNode;
    cout<<"root is"<<root<<"new root os"<<newroot<<endl;
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
    cout<<"copy is successful"<<endl;
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
int main()
{
    linkedlist ll;
    ll.createList();
    ll.printList();
    Node *newroot;
    newroot = ll.createCopy();
    ll.printList(newroot);
    //Node *reverseroot = ll.reverseList();
    //ll.printList(reverseroot);
    ll.mergeFirstAndLast(newroot);
    ll.printList();

    return 0;
}