#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int d) {
        this -> data = d;
        this -> next = NULL;
    }
    ~Node() {
        int value = this -> data;
        if (this -> next != NULL ) {
            delete next;
            next = NULL; 
        }
    cout << "The memory is freed for : " << value << endl;
    }
};

void insert(Node* &tail, int element, int d) {
    //default case i.e. tail = null
    if (tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else {
        Node* curr = tail;
        
        while( curr-> data != element){
            curr = curr -> next;
        }
        Node* newNode = new Node(d);
        newNode -> next = curr -> next;
        curr -> next =  newNode;
    }
}

void print(Node* tail){
    
    if(tail == NULL){
        cout << "the list is empty !!! " << endl;
        return;
    }
    
    Node* temp = tail;
    do {
        cout << tail-> data << "  ";
        tail = tail -> next;
    } while(tail != temp);
    cout << endl;
}

void deleteNode(Node* &tail, int value){
    if(tail == NULL){
        cout << "The list is empty !!! " << endl;
        return;
    }
    else {
        //non empty
        Node* prev = tail;
        Node* curr = tail -> next;
        
        while(curr -> data != value){
            prev = curr;
            curr = curr -> next;
        }
        
        //1 node list
        if(prev == curr){
            tail ==  NULL;
        }
        //>=2 node list
        else if(tail == curr) {
            tail = prev;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int main() {
    
    Node* tail = NULL;
    
    insert (tail, 5, 65);
    print(tail);
    
    insert (tail, 65, 45);
    print(tail);
    
    insert (tail, 45, 325);
    print(tail);
    
    deleteNode(tail, 45);
    print(tail);

    return 0;
}