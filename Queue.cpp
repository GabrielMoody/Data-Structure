#include<iostream>
#include<vector>

using namespace std;

class Queue{
  private:
    vector<int> data;
  
  public:
    void push(int data){
      this->data.push_back(data);
    }

    void peek(){
      cout << data.back();
    }

    void pop(){
      this->data.pop_back();
    }

    void show(){
      for(int a : data){
        cout << a << " -> ";
      }
    }
};

int main(){
  Queue a;
  a.push(10);
  a.show();
  a.pop();
  a.show();
}