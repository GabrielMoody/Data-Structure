#include<iostream>
#include<vector>

using namespace std;

class Queue{
  private:
    vector<int> data;
  
  public:
    void swap(int* a, int* b){
      int temp = *a;
      *a = *b;
      *b = temp;
    }

    void heapify(vector<int> &hp, int i){
      int size = this->data.size();
      int largest = i;
      int left_child = 2 * i + 1;
      int right_child = 2 * i + 2;

      if (left_child < size && hp[left_child] > hp[largest])
        largest = left_child;
      else if (right_child < size && hp[right_child] > hp[largest])
        largest = right_child;

      if (largest != i){
        swap(&hp[i], &hp[largest]);
        heapify(hp, largest);
      }

    }

    void push(int data){
      int size = this->data.size();

      this->data.push_back(data);

      if (this->data.size() > 0){
        for(int i = size / 2 - 1; i >= 0; i--){
          heapify(this->data, i);
        }
      }

    }

    void peek(){
      cout << data.back();
    }

    void pop(){
      this->data.erase(data.begin());

      for(int i = this->data.size() / 2 - 1; i >= 0; i--){
        heapify(this->data, i);
      }
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
  a.push(2);
  a.push(1);
  a.push(30);
  a.push(23);
  cout << "Priority Queue data : ";
  a.show();
  a.pop();
  a.pop();
  cout << "\nPriority Queue after poping element : ";
  a.show();
}