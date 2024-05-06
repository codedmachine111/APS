#include <stdio.h>
#include <stdlib.h>

struct tree{
    int data;
    struct tree* left;
    struct tree* right;
};
typedef struct tree TREE;

TREE *insert_bst(TREE* root, int val){
    TREE *newNode = (struct tree*)(malloc(sizeof(struct tree)));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        return root;
    }
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    if(root==NULL){
        root = newNode;
        return root;
    }
    TREE *cur = root;
    while(cur!=NULL){
        if(val > cur->data){
            if(cur->right != NULL){
                cur = cur->right;
            }else{
                cur->right = newNode;
                break;
            }
        }else{
            if(cur->left != NULL){
                cur = cur->left;
            }else{
                cur->left = newNode;
                break;
            }
        }
    }
    return root;
}

TREE *delete_bst(TREE* root, int val){
    return NULL;
}

void inorder(TREE *root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}

int main(){

    TREE *root = NULL;
    root = insert_bst(root, 1);
    root = insert_bst(root, 2);

    int c;
    while (1)
    {
        printf("Enter option: \n\n");
        scanf(" %d", &c);

        switch (c)
        {
        case 1:
            printf("Enter node value to insert: \n");
            int val;
            scanf("%d", &val);
            root = insert_bst(root, val);
            break;
        case 2:
            printf("Inorder: \n");
            inorder(root);
            break;
        case 3:
            printf("Enter node value to delete: \n");
            int val1;
            scanf("%d", &val1);
            root = delete_bst(root, val1);
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    }
    return 0;
}