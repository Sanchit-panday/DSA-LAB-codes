// Create a binary search tree
#include <stdio.h>
struct Node
{
    int data;
    struct Node *left, *right;
};
void create(struct Node *root, int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i==0)
        {
            root->data = arr[i];
        }
        
        
    }
    
}
int main()
{
    struct Node *root;
    root->left = NULL;
    root->right = NULL;
    int arr[9] = {9, 14, 6, 20, 12, 3, 18, 4, 8};
    int size = 9;
    create(root, arr, size);
     return 0;
}