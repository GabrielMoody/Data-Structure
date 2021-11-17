#include"iostream"

using namespace std;

struct Node{
  int data;
  Node* next;
};

Node* head = NULL;

class List{
  private:

  public:

    bool isEmpty(){
      if(head == NULL){
        throw "Linked list is empty";
      }

      return head == NULL;
    }

    Node* push(int data, Node** node = &head){
      Node* temp = (Node*)malloc(sizeof(Node));

      temp->data = data;
      
      if(head == NULL){  
        head = temp;
        return temp;
      }

      Node* curr = *node;

      while(curr->next != NULL){
        curr = curr->next; 
      }

      curr->next = temp;

      return temp;
    }

    void pop(){
      if(head == NULL){
        cout << "Linked list is empty";
        return;
      }

      Node* curr = head;

      while(curr != NULL){
        curr = curr->next; 
      }
      
      free(curr);
    }

    // void traverse(Node** node = &head){
    //   Node* curr = *node;

    //   while(curr->next != NULL){
    //     cout << curr->data << " -> ";
    //     curr = curr->next;
    //   }
    // }
};

int main(){
  List c;
  c.push(10);
  c.push(20);
  c.push(30);
  c.push(40);
  c.push(50);
  // c.traverse();

  return 0;
}