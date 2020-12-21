#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    printf("%d -> ", root->key);

    // Traverse right
    inorder(root->right);
  }
}

// Insert a node
struct node *insert(struct node *node, int key) {

  if (node == NULL) return newNode(key);


  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// pre order Traversal
void preorder(struct node *root) {
  if (root != NULL) {
    // Traverse root
    printf("%d -> ", root->key);

    // Traverse left
    inorder(root->left);


    // Traverse right
    inorder(root->right);
  }
}

// post order Traversal
void postorder(struct node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse right
    inorder(root->right);

     // Traverse root
    printf("%d -> ", root->key);

  }
}
int main() {
  struct node *root = NULL;
  root = insert(root, 9);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 8);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 2);

  printf("\nInorder\n  ");
  inorder(root);

  printf("\nPre order\n  ");
  preorder(root);

  printf("\nPost order\n  ");
  postorder(root);

}
