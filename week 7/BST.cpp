#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root == NULL){  //check whether the root is empty
    return;
  }
  //if root contains a value
  traverseInOrder(root->left); //traverse the left subtree of the root recursively
 
  cout << root->key << " "; 
 
  traverseInOrder(root->right); //traverse the right subtree of the root recursiely
}

// Insert a node
struct node *insertNode(struct node *node, int key) {

    if (node == nullptr) { //check wehther the root is null
        
      struct node *temp = new struct node; //if the root is null create a new node
 
      temp->key = key;
 
      temp->left = NULL;
      temp->right = NULL;
 
      return temp;
    }
    if (key < node->key) { //check whether the value is less than the root value
        node->left = insertNode(node->left, key);  //then traverse the left sub tree to find the correct position to insert the node
    }
    
    else { 
        node->right = insertNode(node->right, key); //then traverse the right sub tree to find the correct position to insert the node
    }
 
    return node;
}
struct node* minValNode(struct node* node) //return the node with minimum key value found in that tree
{
	struct node* curNode = node;
	while (curNode && curNode->left != NULL) //loop down to find the leftmost leaf 
		curNode = curNode->left;

	return curNode;
}


struct node* deleteNode(struct node* root, int key)
{
	
	if (root == NULL) //check whether the root is null
		return root;

	if (key < root->key) //if the key is less than the root look for the left sub tree to find the item to be deleted
		root->left = deleteNode(root->left, key);

	else if (key > root->key) //if the key is greater than the root look for the left sub tree to find the item to be deleted
		root->right = deleteNode(root->right, key);

	else { //if the root has the data that needs to be deleted
		
		if (root->left == NULL and root->right == NULL) //root has no children
			return NULL;

		
		else if (root->left == NULL) { //root has elements only in the right subtree
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) { //root has elements only in the left subtree
			struct node* temp = root->left;
			free(root);
			return temp;
		}


		struct node* successor = minValNode(root->right); // node with two children , Get the inorder successor

		root->key = successor->key;

		
		root->right = deleteNode(root->right, successor->key); // Delete the inorder successor
	}
	return root;
}


// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}