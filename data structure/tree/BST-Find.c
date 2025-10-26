#include <stdio.h>

typedef struct Node {
    int data;
    BstNode *left;
    BstNode *right;
}BstNode;

int FindMin(BstNode *root)
{
    if(root == NULL)
    {
        prinf("The is empty!");
        return -1;
    }
    BstNode *current = root;
    //二叉搜索树的定义就是左边永远小于等于右边
    while(current->left != NULL)
    {
        current  = current->left;
    }
    return current->data;
}
// int FindMax(BstNode *root)
// {
//     if(root == NULL)
//     {
//         prinf("The tree is empty!");
//         return -1;
//     }
//     BstNode *current = root;
//     while(current->right != NULL)
//     {
//         current = current->right;
//     }
//     return current->data;
// }

int FindMin(BstNode *root)
{
    if(root == NULL)
    {
        printf("The tree is empty!");
        return -1;
    }
    if(root->left == NULL)
    {
        return root->data;
    }
    return FindMin(root->left);
}

int FindMax(BstNode *root)
{
    if(root == NULL)
    {
        printf("The tree is empty!");
        return -1;
    }
    if(root->right == NULL)
    {
        return root->data;
    }
    return FindMax(root->right);
}