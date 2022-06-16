#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};

class LinkedList{
public:
    LinkedList() { 
        head = NULL;
    }
    ~LinkedList() {}; 
    void addNode(int val);
    void display();
private:
    Node* head;
};


void LinkedList::addNode(int val) {
    Node* newnode = new Node();
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
    }
    else {
        Node* temp = head; 
        while (temp->next != NULL) { 
            temp = temp->next; 
        }
        temp->next = newnode; 
    }
}


void LinkedList::display() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
    }
    else {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    LinkedList* list = new LinkedList();
    list->addNode(100);
    list->addNode(200);
    list->addNode(300);
    list->addNode(400); 
    list->addNode(500);
 
    list->display();
    delete list;
    return 0;
}

