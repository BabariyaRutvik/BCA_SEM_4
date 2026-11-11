/*
58. To implement a program to perform insertion in an AVL tree with the required rotations (LL, RR, LR, RL).

Explanation:
- An AVL tree is a self-balancing BST where Balance Factor (BF) = height(left) - height(right)
  must stay in {-1, 0, +1} at every node.
- After inserting a node, update heights and rebalance if |BF| > 1:
  - LL case (BF > 1 and key < node->left->data): Right Rotation.
  - RR case (BF < -1 and key > node->right->data): Left Rotation.
  - LR case (BF > 1 and key > node->left->data): Left rotate left child, then Right rotate node.
  - RL case (BF < -1 and key < node->right->data): Right rotate right child, then Left rotate node.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

int maxInt(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(struct Node *n) {
    return (n == NULL) ? 0 : n->height;
}

int getBalance(struct Node *n) {
    return (n == NULL) ? 0 : getHeight(n->left) - getHeight(n->right);
}

struct Node *createNode(int key) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = maxInt(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = maxInt(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = maxInt(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = maxInt(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

struct Node *insertAVL(struct Node *node, int key) {
    int balance;

    if (node == NULL) {
        return createNode(key);
    }
    if (key < node->data) {
        node->left = insertAVL(node->left, key);
    } else if (key > node->data) {
        node->right = insertAVL(node->right, key);
    } else {
        return node;
    }

    node->height = 1 + maxInt(getHeight(node->left), getHeight(node->right));
    balance = getBalance(node);

    /* LL Rotation */
    if (balance > 1 && key < node->left->data) {
        printf("Performing LL (Right) Rotation at %d\n", node->data);
        return rightRotate(node);
    }
    /* RR Rotation */
    if (balance < -1 && key > node->right->data) {
        printf("Performing RR (Left) Rotation at %d\n", node->data);
        return leftRotate(node);
    }
    /* LR Rotation */
    if (balance > 1 && key > node->left->data) {
        printf("Performing LR (Left-Right) Rotation at %d\n", node->data);
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    /* RL Rotation */
    if (balance < -1 && key < node->right->data) {
        printf("Performing RL (Right-Left) Rotation at %d\n", node->data);
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d(h=%d) ", root->data, root->height);
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

int main() {
    struct Node *root = NULL;
    int n, i, val;

    printf("Enter number of elements to insert into AVL tree: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insertAVL(root, val);
    }

    printf("\nAVL Pre-order (with heights): ");
    preorder(root);
    printf("\nAVL In-order: ");
    inorder(root);
    printf("\n");

    return 0;
}

/*
Sample Input:
6
30 20 10 40 50 45

Sample Output:
Enter number of elements to insert into AVL tree: Enter 6 values:
Performing LL (Right) Rotation at 30
Performing RR (Left) Rotation at 30
Performing RR (Left) Rotation at 20

AVL Pre-order (with heights): 40(h=3) 20(h=2) 10(h=1) 30(h=1) 50(h=2) 45(h=1) 
AVL In-order: 10 20 30 40 45 50
*/
