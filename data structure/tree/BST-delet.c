#include <stdio.h>

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
};

struct Node* FindMin(struct Node *root)
{
    if(root == NULL)
    {
        return root;
    }
    if(root->left == NULL)
    {
        return root;
    }
    return FindMin(root->left);
}

struct Node* delete(struct Node *root,int val)
{
    if(root == NULL)
    {
        return root;
    }
    if(val < root->val)
    {
        root->left = delete(root->left,val);
    }else if(val > root->val) {
        root->right = delete(root->right,val);
    }else{
        //注意：能走到这里的条件，是上一层递归传入的root->left,或者root->right。在下面的这些代码中，root就是上一层递归的左子节点或者右子节点
        //返回的root值目的就是为了在回溯中，达到更新上一层递归的左子树和右子树的节点


        //case1：no child
        if(root->left == NULL && root->right == NULL)
        {
            free(root);//先释放掉那块地址的内存
            root = NULL;//将
            return root;
        }
        
        //case2: one child
        if(root->left == NULL)
        {
            struct Node *temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else if(root->right == NULL)
        {
            struct Node *temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        //case3: two child
        else
        {
            //找到右子树的最小值，让它成为我要删除的当前这个节点，就是把我要删除的这个节点用这个最小值覆盖，达到删除的目的。
            //同时，再一次调用delete这个递归函数，删除重复的这个最小值的节点
            struct Node *temp = FindMin(root->right);
            root->val = temp->val;
            //下面这个代码在于我坚信delete算法能够删除节点这一个理念
            root->right = delete(root->right,temp->val);
        }
    }
}