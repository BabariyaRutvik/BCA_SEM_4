/*
5. Write a program to perform in-order, pre-order, and post-order traversal of a BST.

Explanation:
- A Binary Search Tree (BST) keeps values smaller than the root in the left subtree
  and values greater than or equal to the root in the right subtree.
- In-order (Left, Root, Right) prints BST elements in sorted ascending order.
- Pre-order (Root, Left, Right) visits the root before its subtrees.
- Post-order (Left, Right, Root) visits both subtrees before the root.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

/* Allocate and initialize a new BST node */
struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Insert a value into the BST recursively */
struct Node *insert(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node *root = NULL;
    int n, i, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("In-order Traversal: ");
    inorder(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preorder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}

/*
Sample Input:
5
50 30 70 20 40

Sample Output:
Enter number of nodes: Enter 5 values:
In-order Traversal: 20 30 40 50 70 
Pre-order Traversal: 50 30 20 40 70 
Post-order Traversal: 20 40 30 70 50
*/
