#include<iostream>

using namespace std;

class Stack {
	private:
		int top;
		int size;
	  int data[100];

  public:

  Stack(){
    top = -1;
  }

  bool isEmpty(){
    return top < 0;
  }

  void print(){
    if(top == -1){
      cout << "Stack is empty";
      return;
    }

    for(int i = 0; i <= top; i++){
      cout << data[i] << " -> ";
    }
  }

  void push(int data){
    if(top > 99){
      cout << "Stack is full";
      return;
    }
    top++;
    this->data[top] = data;
  }

  int pop(){
    if(isEmpty()){
      cout << "Stack is empty";
      return 0;
    }

    int temp = data[top];
    data[top] = NULL;
    top--;
    return temp;
  }

  void peek(){
    if(top == -1){
      cout << "\nStack is empty";
      return;
    }

    cout << endl <<  data[top];
  }
};

int main(){
  Stack* s = new Stack();
  s->push(10);
  s->push(20);
  s->push(30);
  s->pop();
  // s->pop();
  s->print();
  s->peek();

  return 0;
}