/*
10. Create a program to perform depth-first traversal of a binary tree.

Explanation:
- Depth-first traversal of a general binary tree visits nodes deep into each subtree
  before backtracking, using Pre-order (Root-Left-Right), In-order (Left-Root-Right),
  or Post-order (Left-Right-Root).
- Here we build a binary tree recursively (enter -1 for NULL) and display all three
  depth-first traversals.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *buildTree() {
    int val;
    struct Node *newNode;

    scanf("%d", &val);
    if (val == -1) {
        return NULL;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;

    printf("Enter left child of %d (-1 for NULL): ", val);
    newNode->left = buildTree();

    printf("Enter right child of %d (-1 for NULL): ", val);
    newNode->right = buildTree();

    return newNode;
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
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

    printf("Enter root value (-1 for NULL): ");
    root = buildTree();

    printf("\nDepth-First Traversals:\n");
    printf("Pre-order: ");
    preorder(root);
    printf("\nIn-order: ");
    inorder(root);
    printf("\nPost-order: ");
    postorder(root);
    printf("\n");

    return 0;
}

/*
Sample Input:
1
2
-1
-1
3
-1
-1

Sample Output:
Enter root value (-1 for NULL): Enter left child of 1 (-1 for NULL): Enter left child of 2 (-1 for NULL): Enter right child of 2 (-1 for NULL): Enter right child of 1 (-1 for NULL): Enter left child of 3 (-1 for NULL): Enter right child of 3 (-1 for NULL): 
Depth-First Traversals:
Pre-order: 1 2 3 
In-order: 2 1 3 
Post-order: 2 3 1
*/
