#include <stdio.h>
#include <stdlib.h>

// Structure for a node of the Binary Search Tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data); // Insert in the left subtree
    } else if (data > root->data) {
        root->right = insert(root->right, data); // Insert in the right subtree
    }
    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to search for an element in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);  // Search in the left subtree
    } else {
        return search(root->right, key); // Search in the right subtree
    }
}

// Main Function to drive the menu
int main() {
    struct Node* root = NULL;
    int choice, data, key;

    // List of integers to be inserted into the BST
    int values[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2};
    int n = sizeof(values) / sizeof(values[0]);

    // Inserting the integers into the BST
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    // Menu-driven program
    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Traverse Inorder\n");
        printf("2. Traverse Preorder\n");
        printf("3. Traverse Postorder\n");
        printf("4. Search for an Element\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 3:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 4:
                printf("Enter the element to search for: ");
                scanf("%d", &key);
                struct Node* result = search(root, key);
                if (result != NULL) {
                    printf("Element %d found in the BST.\n", key);
                } else {
                    printf("Element %d not found in the BST.\n", key);
                }
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}
