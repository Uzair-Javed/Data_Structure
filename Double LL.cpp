#include <iostream>

using namespace std;

class DoublyLinkedList
{

private:
  struct node{
    int data;
    node* next;
    node* prev; 
  };
  typedef node* nodePtr;
   nodePtr head,tail,curr,temp,trailcurr;
   int count;
 
public: nodePtr curr1;
  void InitializeList();
  int isEmpty();
  void PrintList();
  int Search(int searchData);
  void InsertNode(int InsertData);
  void PopulateList();
  
};
void DoublyLinkedList::InitializeList(){
   head = NULL;
   tail = NULL;
   curr = NULL;
   trailcurr=NULL;
  count=0 ;
}//
int DoublyLinkedList::isEmpty(){
  if(head==NULL)
  return -1;
}


void DoublyLinkedList::PrintList(){
  if(head==NULL){
 
   }
 else{ 
    curr=head;
    while(curr!=NULL){
      cout<<curr->data<<" ";
      curr=curr->next; 
    }
   
  }
  
}

void DoublyLinkedList::InsertNode(int InsertData){
    nodePtr inode = new node;  
    inode->data = InsertData; 
    inode->next = NULL;
    inode->prev = NULL;
     bool found ; 
  
  if(head==NULL)
  {
    head = inode;
     tail = inode;
     count++;
  }
  else {
    curr=head;
    found = false;
   while(curr!=NULL && found != true) 
    { 
     if(curr->data >= InsertData){
       found = true;
     }
     else {
        trailcurr=curr;
          curr=curr->next;          
      }
  }
    
    if(curr==head){ 
       head->prev=inode;
        inode->next = head;
         head = inode;
          count++;
    }
    else { 
      
      if(curr!=NULL)
      {
        trailcurr->next = inode;
          inode->prev = trailcurr;
           inode->next = curr;
            curr->prev = inode;
       count ++ ;
      }
       else 
      { 
        trailcurr->next=inode;
         inode->prev = trailcurr;
         
           tail=inode; 
         count++;
      } }       
  }
    }


void DoublyLinkedList::PopulateList(){
  

  InsertNode(100);
  InsertNode(200);
  InsertNode(300);
  InsertNode(400);
  InsertNode(500);
}


int main()
{ 
  DoublyLinkedList Dlist;

  Dlist.InitializeList();
  Dlist.PopulateList();
  Dlist.PrintList();cout<<endl;

 
 return 0;
}


