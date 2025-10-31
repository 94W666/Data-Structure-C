/*二叉搜索树*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

//创建一个节点
struct BstNode* GetNewNode(int data)
{
    struct BstNode *newNode = (struct BstNode*) malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//插入一个节点
struct BstNode* Insert(struct BstNode *root,int data)
{
    if(root == NULL){
        root = GetNewNode(data);
    }else if(data <= root->data){
        root->left = Insert(root->left,data);//这是一个不断进入左子树的过程
    }else{
        root->right = Insert(root->right,data);//不断进入右子树
    }
    return root;//返回的节点与传入的节点一样，保证了本身节点的不变性
}

//寻找一个节点
bool Search(struct BstNode *root,int data)
{
    if(root == NULL)
    {
        return false;
    }
    else if(data == root->data)
    {
        return true;
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
    if(Search(root,number))
    {
        printf("Found\n");
    }else{
        printf("Not Found it\n");
    }
}