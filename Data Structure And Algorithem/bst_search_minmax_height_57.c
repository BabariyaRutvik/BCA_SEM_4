/*
57. To implement a program to search an element in a BST and find the minimum and maximum values and the height of the tree.

Explanation:
- Search: compare key with root->data; move left if smaller, right if larger.
- Minimum value: follow left pointers until left == NULL.
- Maximum value: follow right pointers until right == NULL.
- Height (edges/nodes): here height is counted in number of nodes along longest root-to-leaf path
  (empty tree = 0, single node = 1): 1 + max(height(left), height(right)).
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

int searchBST(struct Node *root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;
    if (key < root->data) return searchBST(root->left, key);
    return searchBST(root->right, key);
}

int findMin(struct Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int findMax(struct Node *root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

int treeHeight(struct Node *root) {
    int lh, rh;
    if (root == NULL) return 0;
    lh = treeHeight(root->left);
    rh = treeHeight(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int main() {
    struct Node *root = NULL;
    int n, i, val, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    if (root == NULL) {
        printf("BST is empty.\n");
        return 0;
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    if (searchBST(root, key)) {
        printf("Element %d FOUND in BST.\n", key);
    } else {
        printf("Element %d NOT found in BST.\n", key);
    }

    printf("Minimum value in BST: %d\n", findMin(root));
    printf("Maximum value in BST: %d\n", findMax(root));
    printf("Height of BST (node count): %d\n", treeHeight(root));

    return 0;
}

/*
Sample Input:
6
50 30 70 20 40 80
40

Sample Output:
Enter number of nodes: Enter 6 values:
Enter element to search: Element 40 FOUND in BST.
Minimum value in BST: 20
Maximum value in BST: 80
Height of BST (node count): 3
*/
