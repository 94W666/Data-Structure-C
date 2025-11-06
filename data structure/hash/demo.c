#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10
#define LOAD_FACTOR 0.7  // 负载因子，用于触发扩容

// 哈希节点结构体
typedef struct HashNode
{
    int key;
    char *val;
    struct HashNode *next;  // 用于处理哈希冲突
} HashNode;

// 哈希表结构体
typedef struct HashTable
{
    HashNode **buckets;     // 动态桶数组
                            // 内存布局：
                            // buckets → [指针0, 指针1, 指针2, ..., 指针n-1]
                            //             |      |      |           |
                            //             ↓      ↓      ↓           ↓
                            //          链表头  链表头  链表头     链表头
    int size;               // 当前大小
    int capacity;           // 总容量
} HashTable;

// 创建新的哈希表
HashTable *createHashTable()
{
    HashTable *table = (HashTable*)malloc(sizeof(HashTable));
    if (!table) return NULL;
    
    table->capacity = MAX_SIZE;
    table->size = 0;
    table->buckets = (HashNode**)calloc(table->capacity, sizeof(HashNode*));
    
    if (!table->buckets) {
        free(table);
        return NULL;
    }
    
    return table;
}

// 改进的哈希函数 - 使用乘法哈希减少冲突
int hashFunction(int key, int capacity)
{
    // 使用黄金比例相关的常数
    const double A = 0.6180339887; // (sqrt(5)-1)/2
    double product = key * A;
    double fractional = product - (int)product;
    
    return (int)(capacity * fractional);
}

// 另一种常用的哈希函数（可选）
int hashFunction2(int key, int capacity)
{
    // 使用位运算和质数
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = (key >> 16) ^ key;
    
    return abs(key) % capacity;
}

// 检查是否需要扩容
int needResize(HashTable *table)
{
    return (double)table->size / table->capacity > LOAD_FACTOR;
}

// 扩容哈希表
int resizeHashTable(HashTable *table)
{
    int oldCapacity = table->capacity;
    int newCapacity = oldCapacity * 2;
    
    HashNode **newBuckets = (HashNode**)calloc(newCapacity, sizeof(HashNode*));
    if (!newBuckets) return 0;
    
    // 重新哈希所有元素
    for (int i = 0; i < oldCapacity; i++) {
        HashNode *node = table->buckets[i];
        while (node) {
            HashNode *next = node->next;
            
            // 计算新的索引
            int newIndex = hashFunction(node->key, newCapacity);
            
            // 插入到新桶中
            node->next = newBuckets[newIndex];
            newBuckets[newIndex] = node;
            
            node = next;
        }
    }
    
    free(table->buckets);
    table->buckets = newBuckets;
    table->capacity = newCapacity;
    
    return 1;
}

// 插入键值对
int put(HashTable *table, int key, const char *val)
{
    if (!table) return 0;
    
    // 检查是否需要扩容
    if (needResize(table)) {
        if (!resizeHashTable(table)) {
            return 0; // 扩容失败
        }
    }
    
    int index = hashFunction(key, table->capacity);
    
    // 检查键是否已存在
    HashNode *current = table->buckets[index];
    while (current) {
        if (current->key == key) {
            // 更新已存在的键
            free(current->val);
            current->val = malloc(strlen(val) + 1);
            if (!current->val) return 0;
            strcpy(current->val, val);
            return 1;
        }
        current = current->next;
    }
    
    // 创建新节点
    HashNode *newNode = (HashNode*)malloc(sizeof(HashNode));
    if (!newNode) return 0;
    
    newNode->key = key;
    newNode->val = malloc(strlen(val) + 1);
    if (!newNode->val) {
        free(newNode);
        return 0;
    }
    strcpy(newNode->val, val);
    
    // 插入到链表头部
    newNode->next = table->buckets[index];
    table->buckets[index] = newNode;
    table->size++;
    
    return 1;
}

// 获取值
char* get(HashTable *table, int key)
{
    if (!table) return NULL;
    
    int index = hashFunction(key, table->capacity);
    HashNode *current = table->buckets[index];
    
    while (current) {
        if (current->key == key) {
            return current->val;
        }
        current = current->next;
    }
    
    return NULL;
}

// 删除键值对
int removeKey(HashTable *table, int key)
{
    if (!table) return 0;
    
    int index = hashFunction(key, table->capacity);
    HashNode *current = table->buckets[index];
    HashNode *prev = NULL;
    
    while (current) {
        if (current->key == key) {
            if (prev) {
                prev->next = current->next;
            } else {
                table->buckets[index] = current->next;
            }
            
            free(current->val);
            free(current);
            table->size--;
            return 1;
        }
        prev = current;
        current = current->next;
    }
    
    return 0;
}

// 获取哈希表大小
int getSize(HashTable *table)
{
    return table ? table->size : 0;
}

// 检查哈希表是否为空
int isEmpty(HashTable *table)
{
    return table ? table->size == 0 : 1;
}

// 打印哈希表（调试用）
void printHashTable(HashTable *table)
{
    if (!table) {
        printf("HashTable is NULL\n");
        return;
    }
    
    printf("HashTable (size: %d, capacity: %d):\n", table->size, table->capacity);
    for (int i = 0; i < table->capacity; i++) {
        printf("Bucket[%d]: ", i);
        HashNode *current = table->buckets[i];
        while (current) {
            printf("(%d: %s) -> ", current->key, current->val);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// 释放哈希表内存
void freeHashTable(HashTable *table)
{
    if (!table) return;
    
    for (int i = 0; i < table->capacity; i++) {
        HashNode *current = table->buckets[i];
        while (current) {
            HashNode *temp = current;
            current = current->next;
            free(temp->val);
            free(temp);
        }
    }
    
    free(table->buckets);
    free(table);
}

// 测试函数
int main()
{
    HashTable *table = createHashTable();
    
    // 测试插入
    put(table, 1, "Alice");
    put(table, 2, "Bob");
    put(table, 11, "Charlie"); // 可能产生哈希冲突
    put(table, 21, "David");   // 可能产生哈希冲突
    
    printf("After insertion:\n");
    printHashTable(table);
    
    // 测试查找
    printf("\nLookup tests:\n");
    printf("Key 1: %s\n", get(table, 1));
    printf("Key 11: %s\n", get(table, 11));
    printf("Key 100: %s\n", get(table, 100) ? get(table, 100) : "Not found");
    
    // 测试更新
    put(table, 1, "Alicia");
    printf("\nAfter updating key 1:\n");
    printf("Key 1: %s\n", get(table, 1));
    
    // 测试删除
    removeKey(table, 2);
    printf("\nAfter removing key 2:\n");
    printHashTable(table);
    
    // 测试扩容
    for (int i = 100; i < 115; i++) {
        char name[20];
        sprintf(name, "User%d", i);
        put(table, i, name);
    }
    
    printf("\nAfter adding more elements (should trigger resize):\n");
    printHashTable(table);
    
    freeHashTable(table);
    return 0;
}