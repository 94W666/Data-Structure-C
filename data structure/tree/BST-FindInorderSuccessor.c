#include <stdio.h>

struct Node 
{
    int val;
    struct Node *left;
    struct Node *right;
};

struct Node* Find(struct Node *root,int val)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->val == val)
    {
        return root;
    }
    if(val < root->val)
    {
       return Find(root->left,val);
    }else {
        return Find(root->right,val);
    }
}

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

struct Node* GetInorderSuccessor(struct Node *root, int val)
{
    // 第一步：先找到目标节点
    // 🔍 在树中搜索值为val的节点
    struct Node *current = Find(root, val);
    if(current == NULL) {
        return NULL;  // 没找到这个节点，直接返回NULL
    }
    
    // 第二步：分两种情况处理
    
    // 📌 情况1：当前节点有右子树
    // 例子：找节点5的后继，5有右子树7
    //     5
    //    / \
    //   3   7  ← 右子树
    //      / \
    //     6   8
    // 中序遍历：3→5→6→7→8
    // 5的后继是右子树的最小值，即6
    if(current->right != NULL) {
       return FindMin(current->right);  // 找到右子树中的最小节点
    }
    
    // 📌 情况2：当前节点没有右子树（这是难点！）
    // 例子：找节点4的后继，4没有右子树
    //     5
    //    / \
    //   3   7
    //  / \
    // 2   4  ← 没有右子树
    // 中序遍历：2→3→4→5→7
    // 4的后继是5，因为5是第一个比4大的祖先
    else {
        struct Node *successor = NULL;   // 用来记录候选后继
        struct Node *ancestor = root;    // 从根节点开始找
        
        // 🎯 核心逻辑：从根节点往下找，记录"最后一个向左拐的节点"
        // 为什么？因为向左拐意味着当前节点比目标节点大，可能是后继
        while(ancestor != current) {  // 还没找到目标节点就继续
            if(current->val < ancestor->val) {
                // 💡 关键理解：向左拐了！当前ancestor比目标节点大
                // 这个ancestor可能是后继，先记下来
                // 但还要继续向左找，看看有没有更接近的候选
                successor = ancestor;        // 记录候选后继
                ancestor = ancestor->left;   // 向左子树继续找
            } else {
                // 向右拐：当前ancestor比目标节点小
                // 这个ancestor不可能是后继，直接向右找
                ancestor = ancestor->right;  // 向右子树继续找
            }
        }
        
        // 🎉 返回找到的后继（可能是NULL，说明目标节点是最大值）
        return successor;
    }
}

/*
🌟 无右子树情况的详细例子 🌟

树结构：
      8
     / \
    5   12
   / \  /
  3  7 10
 / \   \
2   4   9

查找节点7的后继：

步骤1：从根8开始
  7 < 8 → 向左拐，记录8为候选，去左子树5

步骤2：在节点5
  7 > 5 → 向右拐，不记录候选，去右子树7

步骤3：找到节点7，返回候选8

中序遍历验证：2→3→4→5→7→8→9→10→12
7的后继确实是8！

查找节点4的后继：

步骤1：从根8开始
  4 < 8 → 向左拐，记录8为候选，去左子树5

步骤2：在节点5
  4 < 5 → 向左拐，记录5为候选（覆盖8），去左子树3

步骤3：在节点3
  4 > 3 → 向右拐，不记录候选，去右子树4

步骤4：找到节点4，返回候选5

中序遍历验证：2→3→4→5→7→8→9→10→12
4的后继确实是5！

💡 核心记忆口诀：
"有右找最小，无右向上找；
 向左要记录，向右直接跑；
 找到就返回，没找到拉倒"
*/