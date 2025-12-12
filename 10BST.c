#include <stdio.h>
#include <stdlib.h>

/* Structure of a BST node */
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node* NodePtr;

/* Create a new node */
NodePtr createNode() {
    NodePtr node = (NodePtr)malloc(sizeof(struct Node));
    if (!node) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter value: ");
    scanf("%d", &node->data);

    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Insert a node into BST */
void insertNode(NodePtr root, NodePtr newNode) {
    if (newNode->data < root->data) {
        if (root->left == NULL)
            root->left = newNode;
        else
            insertNode(root->left, newNode);
    } 
    else if (newNode->data > root->data) {
        if (root->right == NULL)
            root->right = newNode;
        else
            insertNode(root->right, newNode);
    }
}

/* Traversals */
void inorder(NodePtr root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(NodePtr root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NodePtr root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/* Search for a value */
void searchNode(NodePtr root) {
    if (root == NULL) {
        printf("BST is empty.\n");
        return;
    }

    int key;
    printf("Enter value to search: ");
    scanf("%d", &key);

    NodePtr current = root;

    while (current != NULL) {
        if (current->data == key) {
            printf("Value FOUND in BST.\n");
            return;
        }

        current = (key < current->data) ? current->left : current->right;
    }

    printf("Value NOT FOUND in BST.\n");
}

/* Main menu */
int main() {
    int choice, count, i;
    NodePtr root = NULL;

    while (1) {
        printf("\n------ BST MENU ------\n");
        printf("1. Create BST\n");
        printf("2. Display Traversals\n");
        printf("3. Search Value\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("How many elements? ");
                scanf("%d", &count);

                for (i = 0; i < count; i++) {
                    NodePtr newNode = createNode();

                    if (root == NULL)
                        root = newNode;
                    else
                        insertNode(root, newNode);
                }
                break;
            }

            case 2:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Preorder: ");
                    preorder(root);

                    printf("\nInorder: ");
                    inorder(root);

                    printf("\nPostorder: ");
                    postorder(root);

                    printf("\n");
                }
                break;

            case 3:
                searchNode(root);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
