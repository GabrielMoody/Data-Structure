#include<iostream>

using namespace std;

struct Node{
  int data;
  Node* left, *right;
  int height;
};

Node* new_node(int data){
  Node* node = new Node();
  node->data = data;
  node->left = node->right = nullptr;
  node->height = 1;

  return node;
}

Node* in_order(Node* root){
  Node* curr = root;

  while(curr && curr->left != nullptr){
    curr = curr->left;
  }

  return curr;
}

int get_height(Node* N){
  if(N == nullptr){
    return 0;
  }

  return N->height;
}

int get_balance_factor(Node* N){
  if(N == nullptr){
    return 0;
  }

  return get_height(N->left) - get_height(N->right);
}

Node* left_rotate(Node* x){
  Node* y = x->right;
  Node* T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(get_height(x->left), get_height(x->right)) + 1;
  y->height = max(get_height(y->left), get_height(y->right)) + 1;

  return y;
}

Node* right_rotate(Node* y){
  Node* x = y->left;
  Node* T2 = x->right;

  x->right = y;
  y->left = T2;

  
  x->height = max(get_height(x->left), get_height(x->right)) + 1;
  y->height = max(get_height(y->left), get_height(y->right)) + 1;

  return x;
}

Node* insert(int data, Node* root){

  if(root == nullptr){
    return new_node(data);
  }

  if(data < root->data){
    root->left = insert(data, root->left);
  } else if (data > root->data){
    root->right = insert(data, root->right);
  } else {
    return root;
  }

  root->height = 1 + max(get_height(root->left), get_height(root->right));
  int balance_factor = get_balance_factor(root);

  if(balance_factor > 1){
    if(data < root->left->data){
      return right_rotate(root);
    } else if(data > root->left->data){
      root->left = left_rotate(root->left);
      return right_rotate(root);
    }
  } else if(balance_factor < -1){
    if(data > root->right->data){
      return left_rotate(root);
    } else if(data < root->right->data){
      root->right = right_rotate(root->right);
      return left_rotate(root);
    }
  }

  return root;
}

Node* remove(int data, Node* root){
  if(root == nullptr){
    return NULL;
  }

  if(data < root->data){
    root->left = remove(data, root->left);
  } else if (data > root->data){
    root->right = remove(data, root->right);
  } else {
    if(root->left == nullptr){
        Node* temp = root->right;
        delete root;
        return temp;
      } else if(root->right == nullptr){
        Node* temp = root->left;
        delete root;
        return temp;
      } else {
        Node* temp = in_order(root->right);

        root->data = temp->data;

        root->right = remove(data, root->right);
      }
  }

  root->height = 1 + max(get_height(root->left), get_height(root->right));
  int balance_factor = get_balance_factor(root);

  if(balance_factor > 1){
    if(data < root->left->data){
      return right_rotate(root);
    } else if(data > root->left->data){
      root->left = left_rotate(root->left);
      return right_rotate(root);
    }
  } else if(balance_factor < -1){
    if(data > root->right->data){
      return left_rotate(root);
    } else if(data < root->right->data){
      root->right = right_rotate(root->right);
      return left_rotate(root);
    }
  }

  return root;
}

void print(Node* root){
  if(root != nullptr){
    print(root->left);
    cout << root->data << " -> ";
    print(root->right);
  }
}

int main(){

  Node* root = NULL;

  root = insert(33, root);
  root = insert(13, root);
  root = insert(53, root);
  root = insert(9, root);
  root = insert(21, root);
  root = insert(61, root);
  root = insert(8, root);
  root = insert(11, root);
  print(root);

}