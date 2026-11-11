/*
55. To implement a program to create a Binary Search Tree (BST) and perform insertion of nodes.

Explanation:
- Starting from an empty root (NULL), each new key is inserted recursively:
  - If root == NULL, allocate a new node.
  - If key < root->data, insert into left subtree.
  - If key > root->data, insert into right subtree.
- In-order traversal verifies the BST property by printing values in ascending order.
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
    if (root == NULL) {
        return createNode(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    } else {
        printf("Duplicate value %d ignored.\n", val);
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
    int choice, val;

    while (1) {
        printf("\n1. Insert Node  2. Display In-order  3. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            root = insert(root, val);
        } else if (choice == 2) {
            printf("BST In-order: ");
            inorder(root);
            printf("\n");
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}

/*
Sample Input:
1
40
1
20
1
60
1
10
2
3

Sample Output:

1. Insert Node  2. Display In-order  3. Exit
Choice: Enter value to insert: 
1. Insert Node  2. Display In-order  3. Exit
Choice: Enter value to insert: 
1. Insert Node  2. Display In-order  3. Exit
Choice: Enter value to insert: 
1. Insert Node  2. Display In-order  3. Exit
Choice: Enter value to insert: 
1. Insert Node  2. Display In-order  3. Exit
Choice: BST In-order: 10 20 40 60 

1. Insert Node  2. Display In-order  3. Exit
Choice:
*/
