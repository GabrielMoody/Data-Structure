#include<iostream>

using namespace std;

struct Node{
  int data;
  Node* left, *right;
};

Node* newnode(int data){
  Node* temp = (Node*)malloc(sizeof(Node));
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

Node* insert(int data, Node* node){
  if(node == NULL){
    return newnode(data);
  }

  if(data < node->data){
    node->left = insert(data, node->left);
  } else {
    node->right = insert(data, node->right);
  }

  return node;
}

void in_order(Node* node){
  if(node != NULL){
    in_order(node->left);
    cout << node->data << " -> ";
    in_order(node->right); 
  }
}

Node* search(int data, Node* node){
  if(node->data == data){
    return node;
  }

  if(data < node->data){
    node->left = search(data, node->left);
  } else {
    node->right = search(data, node->right);
  }

  return node;
}

Node* min_value(Node* root){
  Node* curr = root;
  
  while(curr && curr->left != NULL){
    curr = curr->left;
  }

  return curr;
}

Node* remove(int data, Node* node){
  if(node == NULL){
    return node;
  }

  if(data < node->data){
    node->left = remove(data, node->left);
  } else if(data > node->data) {
    node->right = remove(data, node->right);
  } else {
    
    // Delete node if node has 1 or no children
    if(node->left == NULL){
      Node* temp = node->right;
      free(node);
      return temp;
    } else if(node->right == NULL){
      Node* temp = node->left;
      free(node);
      return temp;
    }

    // Delete node that has 2 children
    // Find the inorder successor
    Node* temp = min_value(node->right);

    // Copy the value of inorder successor to current node
    node->data = temp->data;

    // Delete the inorder successor node
    node->right = remove(temp->data, node->right);  
  }
  return node;
}

int main(){
  Node* root = NULL;
  root = insert(10, root);
  root = insert(20, root);
  root = insert(25, root);
  root = insert(22, root);
  root = insert(15, root);
  root = insert(30, root);
  root = insert(40, root);
  root = remove(30, root);
  in_order(root);

  return 0;
}
