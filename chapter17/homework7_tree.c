// 树的支持函数
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "homework7_tree.h"

// 局部数据类型
typedef struct pair {
    Trnode * parent;
    Trnode * child;
} Pair;

// 局部函数的原型
static Trnode *MakeNode(const Item *pi);
static bool ToLeft(const Item *i1, const Item *i2);
static bool ToRight(const Item *i1, const Item *i2);
static void AddNode(Trnode *new_node, Trnode *root);
static void InOrder(const Trnode *root, void (*pfun)(Item item));
static Pair SeekItem(const Item *pi, const Tree *ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode *root);

// 函数定义
void InitializeTree(Tree * ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree)
{
    if (ptree->root == NULL)
        return true;
    else
        return false;
}

bool TreeIsFull(const Tree * ptree)
{
    if (ptree->size == MAXITEMS)
        return true;
    else
        return false;
}

int TreeItemCount(const Tree * ptree)
{
    return ptree->size;
}

bool AddItem(const Item * pi, Tree * ptree)
{
    Trnode *new_node;
    Pair look;

    if (TreeIsFull(ptree))
    {
        fprintf(stderr, "Tree is full\n");
        return false;   // 提前返回
    }
    if (SeekItem(pi, ptree).child != NULL)
    {
        look = SeekItem(pi, ptree);
        look.child->item.times++;
        return true;
    }
    new_node = MakeNode(pi);    // 指向新节点
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false;
    }
    ptree->size++;

    if (ptree->root == NULL)    // 情况1，树为空
        ptree->root = new_node; // 新节点为树的根节点
    else
        AddNode(new_node, ptree->root);     // 在树中添加新节点

    return true;
}

bool InTree(const Item * pi, const Tree * ptree)
{
    return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item * pi, Tree * ptree)
{
    Pair look;

    look = SeekItem(pi, ptree);
    if (look.child == NULL)
        return false;
    
    if (look.parent == NULL)
        DeleteNode(&ptree->root);
    else if (look.parent->left == look.child)
        DeleteNode(&look.parent->left);
    else
        DeleteNode(&look.parent->right);
    ptree->size--;

    return true;
}

void Traverse(const Tree * ptree, void(*pfun)(Item item))
{
    if (ptree != NULL)
        InOrder(ptree->root, pfun);
}

void DeleteAll(Tree * ptree)
{
    if (ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}


// 局部函数
static void InOrder(const Trnode *root, void (*pfun)(Item item))
{
    if (root != NULL)
    {
        InOrder(root->left, pfun);
        (*pfun)(root->item);
        InOrder(root->right, pfun);
    }
}

static void DeleteAllNodes(Trnode *root)
{
    Trnode *pright;

    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

static void AddNode(Trnode * new_node, Trnode * root)
{
    if (ToLeft(&new_node->item, &root->item))
    {
        if (root->left == NULL) // 空子数
            root->left = new_node;  // 把节点添加到此处
        else
            AddNode(new_node, root->left);  // 否则处理该子树
    }
    else if (ToRight(&new_node->item, &root->item))
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    }
    else    // 不允许有重复项
    {
        fprintf(stderr, "location error in AddNode()\n");
        exit(1);
    }
}

static bool ToLeft(const Item * i1, const Item * i2)
{
    int comp1;

    if ((comp1 = strcmp(i1->word, i2->word)) < 0)
        return true;
    else
        return false;
}

static bool ToRight(const Item * i1, const Item * i2)
{
    int comp1;

    if ((comp1 = strcmp(i1->word, i2->word)) > 0)
        return true;
    else
        return false;
}

static Trnode * MakeNode(const Item *pi)
{
    Trnode *new_node;

    new_node = (Trnode *)malloc(sizeof(Trnode));
    if (new_node != NULL)
    {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }

    return new_node;
}

static Pair SeekItem(const Item *pi, const Tree *ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;

    if (look.child == NULL)
        return look;    // 提前返回
    
    while (look.child != NULL)
    {
        if (ToLeft(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else        // 如果前两种情况都不满足，则必定是相等的情况
            break;  // look.child 目标项的节点
    }

    return look;    // 成功返回
}

static void DeleteNode(Trnode **ptr)
// ptr指向该node的指针的指针，*ptr是指向该node的指针，**ptr是要被删除的node
// 因为被删除的node的父节点通过指针指向这个被删除的节点，所以删除过后需要对*ptr重新赋值避免子树的丢失
{
    Trnode *temp;

    if ((*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if ((*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else    // 被删除的节点有两个子节点
    {
        // 找到重新链接右子树的位置
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
}

void find_word(const Tree * pt)
{
    Item temp;
    Pair pair;
    int t;

    printf("Enter the word you search:\n");
    scanf("%s", temp.word);
    while (getchar() != '\n')
        continue;
    pair = SeekItem(&temp, pt);
    if (pair.child == NULL)
        printf("No entries!\n");
    else
    {
        t = pair.child->item.times;
        printf("%s appears %d times\n", temp.word, t);
    }
}