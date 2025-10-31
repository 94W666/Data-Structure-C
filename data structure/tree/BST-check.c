#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

bool isBst(struct Node *root,int minVal,int maxVal)
{
    if(root == NULL)
        return true;
    if(root->data < maxVal && root->data > minVal && isBst(root->left,minVal,root->data) && isBst(root->right,root->data,maxVal))
        return true;
    else
        return false;
}
/*
    上面代码的核心思想在于二叉搜索树的定义是，左子树的所有节点都要小于我，右子树的所有节点都要大于我。一般的检查方法有一个障碍就是，我不光要将该节点与我的父节点比较，还要与我的祖先进行比较，耗费的成本
    太高了，而上面这种方法直接通过限制大小区间来判断，比我小那肯定在数学里面翻译过来就是最大值就是我，每一个的递归，我都不断压缩这个大小区间，就实现了一种不直接和祖先比但是又做到了和祖先比的需求
*/

int isBinarySearchTree(struct Node *root)
{
    if(isBst(root,INT_MIN,INT_MAX))
        return true;
    return false;
}