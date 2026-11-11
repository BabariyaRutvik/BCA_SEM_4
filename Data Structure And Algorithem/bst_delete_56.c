/*
56. To implement a program to delete a node from a Binary Search Tree (leaf node, node with one child and node with two children).

Explanation:
- Deletion handles three cases:
  1. Leaf node (no children): free the node and return NULL.
  2. One child: bypass the node by returning its single non-NULL child and free it.
  3. Two children: find the inorder successor (minimum node in right subtree),
     copy its value to the current node, then delete the successor from right subtree.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

struct Node *findMin(struct Node *node) {
    while (node != NULL && node->left != NULL) {
        node = node->left;
    }
    return node;
}

struct Node *deleteNode(struct Node *root, int key) {
    struct Node *temp;
    if (root == NULL) {
        printf("Value %d not found in BST.\n", key);
        return NULL;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        /* Case 1: Leaf node */
        if (root->left == NULL && root->right == NULL) {
            printf("Deleting leaf node %d.\n", key);
            free(root);
            return NULL;
        }
        /* Case 2: One child */
        else if (root->left == NULL) {
            printf("Deleting node %d with one right child.\n", key);
            temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            printf("Deleting node %d with one left child.\n", key);
            temp = root->left;
            free(root);
            return temp;
        }
        /* Case 3: Two children */
        else {
            printf("Deleting node %d with two children.\n", key);
            temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
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

int main() {
    struct Node *root = NULL;
    int n, i, val, dels, key;

    printf("Enter number of initial BST nodes: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Initial In-order: ");
    inorder(root);
    printf("\n");

    printf("How many deletions to perform? ");
    scanf("%d", &dels);
    for (i = 0; i < dels; i++) {
        printf("Enter value to delete: ");
        scanf("%d", &key);
        root = deleteNode(root, key);
        printf("In-order after deletion: ");
        inorder(root);
        printf("\n");
    }

    return 0;
}

/*
Sample Input:
7
50 30 70 20 40 60 80
3
20
70
50

Sample Output:
Enter number of initial BST nodes: Enter 7 values:
Initial In-order: 20 30 40 50 60 70 80 
How many deletions to perform? Enter value to delete: Deleting leaf node 20.
In-order after deletion: 30 40 50 60 70 80 
Enter value to delete: Deleting node 70 with two children.
Deleting leaf node 80.
In-order after deletion: 30 40 50 60 80 
Enter value to delete: Deleting node 50 with two children.
Deleting leaf node 60.
In-order after deletion: 30 40 60 80
*/
