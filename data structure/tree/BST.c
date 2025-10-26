/*二叉搜索树*/
#include <stdio.h>
#include <stdlib.h>

struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};
struct BstNode* GetNewNode(int data)
{
    struct BstNode *newNode = (struct BstNode*) malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct BstNode* Insert(struct BstNode *root,int data)
{
    if(root == NULL){
        root = GetNewNode(data);
    }else if(data <= root->data){
        root->left = Insert(root->left,data);
    }else{
        root->right = Insert(root->right,data);
    }
    return root;
}
int Search(struct BstNode *root,int data)
{
    if(root == NULL)
    {
        return 1;
    }
    else if(data == root->data)
    {
        return 0;
    }
    else if(data <= root->data)
    {
        return Search(root->left,data);
    }
    else
    {
        return Search(root->right,data);
    }
}
int main(void)
{
    struct BstNode *root;
    root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,9);
    root = Insert(root,20);
    root = Insert(root,7);

    int number;
    printf("Enter the number be searches\n");
    scanf("%d",&number);
    if(Search(root,number) == 1)
    {
        printf("Not found\n");
    }else{
        printf("Found it\n");
    }
}