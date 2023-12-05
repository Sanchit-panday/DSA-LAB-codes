// implement preorder traversal of a tree
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
};
struct Node *createNode(int data)
{
    struct Node *n;                                 // creating a node pointer
    n = (struct Node *)malloc(sizeof(struct Node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL
    return n;                                       // Finally returning the created node
}
void preorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        // Display(root->data)
        printf("%d ", root->data);
        // Preorder(root->lchild)
        preorderTraversal(root->left);
        // Preorder(root->rchild)
        preorderTraversal(root->right);
    }
    return;
}
int main()
{
    struct Node *p = createNode(4);
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(5);
    struct Node *p4 = createNode(2);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // Function call
    printf("Preorder traversal of binary tree is: \n");
    preorderTraversal(p);
    return 0;
}