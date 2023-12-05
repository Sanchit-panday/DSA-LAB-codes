#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

void iterativeInorderTraversal(struct Node *root)
{
    struct Node *stack[100];
    int top = -1;
    struct Node *current = root;

    while (current != NULL || top != -1)
    {
        while (current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);

        current = current->right;
    }
}

struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void menu(struct Node *root)
{
    int choice, value;
    do
    {
        printf("\nchoice-> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;

        case 2:
            if (root == NULL)
            {
                printf("\nTree is empty.\n");
                break;
            }
            printf("Iterative Inorder Traversal: ");
            iterativeInorderTraversal(root);
            printf("\n");
            break;

        case 3:
            if (root == NULL)
            {
                printf("\nTree is empty.\n");
                break;
            }
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            struct Node *temp  = root;
            root = deleteNode(root, value);
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 4);
}

int main()
{
    struct Node *root = NULL;
    printf("\n1. Insert into BST");
    printf("\n2. Iterative Inorder Traversal");
    printf("\n3. Delete from BST");
    printf("\n4. Exit\n");
    menu(root);
    return 0;
}