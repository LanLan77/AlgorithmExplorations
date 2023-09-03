#include <cstddef>
#include <iostream>
using namespace std;

typedef int Elemtype;   //定义树节点储存类型


typedef struct BinarySearchTree{    //定义树的节点类型
    int value;  //数据域
    BinarySearchTree *left, *right; //指针域，左孩子节点，右孩子节点

    //构造器，初始化节点值
    BinarySearchTree(int value):
    value(value),left(NULL),right(NULL){
    }
}TreeNode; 

/* 
    二叉排序树操作： 查找
        1. 判断要查找的关键字值与当前节点值是否相同，若相同，直接返回。
        2. 若查找关键字 < 当前节点值，向左子树查找
    
    复杂度分析：
        空间复杂度: O(1)
        时间复杂度: O(logN)
 */

TreeNode * SearchByRecursion(TreeNode *tree, int key){
     TreeNode *node = tree; //拷贝一份地址
     if(node == NULL){
        return NULL;
     } 
     if(key == node->value){
          return node;
     }else if(key < node->value){
          return SearchByRecursion(node->left, key);
     }else {
        return SearchByRecursion(node->right, key);
     }

}



TreeNode* Search(TreeNode *tree, int key){
    TreeNode *node = tree; //拷贝一份地址
    while (node != NULL) {
        // 1. 判断要查找的关键字是否与当前的节点值是否相同，若值相同就返回 
        if(key == node->value){
            return node;
        }else if(key < node->value){
             node = node->left;
        }else{
             node = node->right;
        }
    }
    return NULL;
}

/* 
    往二叉排序树中插入新的节点
        1. 查找插入的位置
        2. 新建节点，执行插入动作 
        3. 返回插入节点0，说明节点已存在。如果是1，插入成功 
 */

 int Insert(TreeNode *tree, int key){
    TreeNode *node = new TreeNode(key);
    if(node == NULL){
        tree = node;  // 空树，新插入值为root
        return 1; 
     }   
    // 1. 查找插入的位置
    TreeNode *pos = tree, *parent = NULL; 
    while (pos != NULL) {
         parent = pos; 
         if(key < pos->value){
            pos = pos->left; 
         } else if(key > pos->value){
            pos = pos->right ; 
         }else{
            return 0;
         }
    }
    // 2. 新建节点，执行插入动作
    if(key < parent->value){
        parent->left = node; 
    } else{
        parent->right = node; 
    }
    // 3. 返回插入节点0，说明节点已存在。如果是1，插入成功
    return 1;
 }



 /* 
    删除节点
 */
 int Delete(TreeNode *tree, int key){
    return 1;
 }



//中序遍历： 左 --> 根 --> 右
void inOrder(TreeNode *node){
    //节点为空，什么都不做
    if(node != NULL){
        //递归访问左子树
        inOrder(node->left);
        //访问节点数据
        cout << node->value << "->";
        //递归访问右子树 
        inOrder(node->right);
    } 
}



  int main(){
    /* 
                          10
                    7              13
                5      9      11       18
              3  6   8          12

     */

     TreeNode child10(10),
     child7(7),child13(13),
     child5(5),child9(9),child11(11),child18(18),
     child3(3),child6(6),child8(8),child12(12);

     child10.left = &child7;
     child10.right = &child13;

     child7.left = &child5;
     child7.right = &child9;

     child5.left = &child3;
     child5.right = &child6;

     child9.left = &child8;
    
     child13.left = &child11;
     child13.right = &child18;

     child11.right = &child12;

     cout << "中序遍历："<< endl;
     inOrder(&child10);
     cout << endl;

    //TreeNode *result = Search(&child10,12);
    TreeNode *result = SearchByRecursion(&child10,12);
    if(result == NULL){
        cout << "NULL" << endl; 
    }else {
        cout<< result->value  << endl; 
    }


    int x = Insert(&child10, 14);
    if(x == 0){
        cout << "节点已存在" << endl;
    }else {
        cout << "插入成功" << endl;
    } 

    cout << "中序遍历："<< endl;
     inOrder(&child10);
     cout << endl;
 
} 
