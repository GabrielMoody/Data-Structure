#include<iostream>

using namespace std;

struct Node{
  int data;
  Node* right, *left;
};

Node* new_node(int data){
  Node* temp = new Node();
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

Node* insert(int data, Node* root){
  return new_node(data);
}

void in_order(Node* root){
  if(root != NULL){
    in_order(root->left);
    cout << root->data << " -> ";
    in_order(root->right);
  }
}

Node* min_value(Node* root){
  Node* temp = root;

  while(temp->left != NULL){
    temp = temp->left;
  }

  return temp;
}

Node* remove(int data, Node* root){
  if(root == NULL){
    return root;
  }

  // Find the node to be deleted
  if(root->data != data){
    root->left = remove(data, root->left);
    root->right = remove(data, root->right);
  } else {

    // Condition if node has 1 or no children
    if(root->left == NULL){
      Node* temp = root->right;
      delete root;
      return temp;
    } else if(root->right == NULL){
      Node* temp = root->left;
      delete root;
      return temp;
    } else {
      // When the node has 2 children
      // Find the inorder successor
      Node* min = min_value(root->right);

      // Copy value of inorder successor to current node
      root->data = min->data;

      // Delete the inorder successor node
      root->right = remove(min->data, root->right);
    }

  }
  return root;

}

int main(){
  Node* root = NULL;

  root = insert(10, root);
  root->left = insert(20, root);
  root->left->right = insert(30, root);
  root->right = insert(40, root);
  root->right->left = insert(50, root);
  root = remove(10, root);
  in_order(root);
}