#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode *PtrToAVLNode;
struct AVLNode{
    int Data;
    PtrToAVLNode Left;
    PtrToAVLNode Right;
    int Height;
};
typedef PtrToAVLNode AVLTree;

AVLTree Insert ( int Key, AVLTree T );

int Max(int a, int b) {
    return a > b ? a : b;
}
int GetHeight(AVLTree A) {
    if (A == NULL)
        return 0;
    return A->Height;
}
AVLTree LeftRotation(AVLTree T)
{
    AVLTree TR = T->Right;
    T->Right = TR->Left;
    TR->Left = T;
    T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
    TR->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
    return TR;
}
AVLTree RightRotation(AVLTree T)
{
    AVLTree TL = T->Left;
    T->Left = TL->Right;
    TL->Right = T;
    T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
    TL->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
    return TL;
}
AVLTree LeftRightRotation(AVLTree T)
{
    if(T->Left)
        T->Left = LeftRotation(T->Left);
    return RightRotation(T);
}
AVLTree RightLeftRotation(AVLTree T)
{
    if(T->Right) 
        T->Right = RightRotation(T->Right);
    return LeftRotation(T);
}
AVLTree Insert(int Key, AVLTree T)
{
    if (!T) {
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Data = Key;
        T->Height = 1;
        T->Left = T->Right = NULL;
        return T;
    }
    if (T->Data > Key) {
        T->Left = Insert(Key, T->Left);
        if (GetHeight(T->Left) - GetHeight(T->Right) > 1) {
            if (Key < T->Left->Data)
                T = RightRotation(T);
            else
                T = LeftRightRotation(T);
        }
    }       
    else if(T->Data < Key) {
        T->Right = Insert(Key, T->Right);
        if (GetHeight(T->Right) - GetHeight(T->Left) > 1) {
            if (Key > T->Right->Data)
                T = LeftRotation(T);
            else
                T = RightLeftRotation(T);
        }
    }
    T->Height = Max(GetHeight(T->Left), GetHeight(T->Right))+1;
    return T;
}
//把a的值赋给b
void Deliver(AVLTree a, AVLTree b)             
{
    b->Data = a->Data;
    b->Height = a->Height;
}
//返回子树最大结点的父节点，需要注意的是无子节点时返回它本身
AVLTree FindMaxParent(AVLTree T)
{
    while (T && T->Right && T->Right->Right)
    {
        T = T->Right;
    }
    return T;
}
//返回子树最小结点的父节点，需要注意的是无子节点时返回它本身
AVLTree FindMinParent(AVLTree T)
{
    while (T && T->Left && T->Left->Left)
    {
        T = T->Left;
    }
    return T;
}
AVLTree Delete(string Key, AVLTree T)
{
    if (T->Data > Key) {
        T->Left = Delete(Key, T->Left);
        if (GetHeight(T->Right) - GetHeight(T->Left) > 1) {
            if (GetHeight(T->Right->Right) > GetHeight(T->Right->Left))
                T = LeftRotation(T);
            else
                T = RightLeftRotation(T);
        }
        T->Height = max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
        return T;
    }
    else if (T->Data < Key) {
        T->Right = Delete(Key, T->Right);
        if (GetHeight(T->Left) - GetHeight(T->Right) > 1) {
            if (GetHeight(T->Left->Right) < GetHeight(T->Left->Left))
                T = RightRotation(T);
            else
                T = LeftRightRotation(T);
        }
        T->Height = max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
        return T;
    }
    else {
        if (T->Left && T->Right) {
            AVLTree temp = FindMaxParent(T->Left);
            AVLTree pre = temp->Right? temp->Right : temp;
            Deliver(pre, T);
            delete pre;
            temp->Right = NULL;
        }
        else if (T->Left && !T->Right) {
            Deliver(T->Left, T);
            AVLTree d = T->Left;
            delete d;
            T->Left = NULL;
        }
        else if (!T->Left && T->Right) {
            Deliver(T->Right, T);
            AVLTree d = T->Right;
            delete d;
            T->Right = NULL;
        }
        else {
            delete T;
            T = NULL;
        }
        return T;
    }
    return T;
}