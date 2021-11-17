#include<iostream>
#include<list>
#include<iterator>

using namespace std;

class HashTable{    
  private:
    string key[100];
    list<int> data[100];
  
  public:

    int hash(int key){
      return key % 100;
    }

    void push(string key, int data){
      int index = hash(key[0]);
      this->key[index] = key;
      this->data[index].push_back(data);
    }

    void remove(string key){
      int index = hash(key[0]);

      list<int>::iterator it = data[index].begin();
      advance(it, index);
      ++it;

      key[index] = NULL;
      it = data[index].erase(it);
    }

    void show(string key = ""){
      list<int>::iterator it;
      
      if(key == ""){

        for(int i = 0; i < 100; i++){
          if(this->key[i] == ""){
            continue;
          }

          cout << "[" << this->key[i] << "] ";
          
          for(it = data[i].begin(); it != data[i].end(); ++it){
            cout << *it << " -> ";
          }

          cout << endl;
          }
        } else {
          int index = hash(key[0]);

          cout << "[" << this->key[index] << "]";

          for(it = data[index].begin(); it != data[index].end(); ++it){
            cout << *it << " -> ";
          }
        }
    }
};


int main(){
  HashTable a;
  a.push("abc", 12);
  a.push("cba", 11);
  a.push("dsa", 20);
  a.push("dsa", 30);
  a.remove("abc");
  a.show();

  return 0;
}

