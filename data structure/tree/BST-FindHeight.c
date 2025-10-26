#include <stdio.h>

typedef struct Node
{
    int data;
    BstNode *left;
    BstNode *right;
}BstNode;

int FindHeight(BstNode *root)
{
    if(root == NULL)
    {
        return -1;
    }
    return max(FindHeight(root->left),FindHeight(root->right)) + 1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
}

