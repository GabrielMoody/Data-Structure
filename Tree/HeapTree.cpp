#include<iostream>
#include<vector>

using namespace std;

void swap(int* a, int* b){
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(vector<int> &hp, int i){
  int size = hp.size();
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

void insert(vector<int> &hp, int data){
  int size = hp.size();

  hp.push_back(data);
  
  if(size > 0){
    for(int i = size / 2 - 1; i >= 0; i--){
      heapify(hp, i);
    }
  }
}

void remove(vector<int> &hp, int data){
  int size = hp.size();

  for(int i = 0; i < size; i++){
    if(hp[i] == data){
      swap(&hp[i], &hp[size - 1]);
      break;
    }
  }

  hp.pop_back();

  for(int i = size / 2 - 1; i >= 0;i--){
    heapify(hp, i);
  }  
}

void print(vector<int> &hp){
  for(auto a : hp){
    cout << a << " ";
  }
}

int main(){
  vector<int> heap;

  insert(heap, 10);
  insert(heap, 40);
  insert(heap, 9);
  insert(heap, 4);
  insert(heap, 20);
  insert(heap, 30);
  // remove(heap, 20);
  
  print(heap);
  return 0;
}