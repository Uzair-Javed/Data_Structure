#include <iostream>
using namespace std;

typedef struct Node Node;

struct Node {
   int data;
    Node *next;
};
 Node* head = NULL;
void insert(int new_data) {
    Node* new_node = ( Node*) malloc(sizeof( Node));
   new_node->data = new_data;
   new_node->next = head;
   head = new_node;
}
void display() {
    Node* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}

void populate()
{
   insert(500);
   insert(400);
   insert(300);
   insert(200);
   insert(100);
}
int main() {
   
   populate();
   display();
   return 0;
}