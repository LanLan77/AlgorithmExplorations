#include <cstddef>
#include <iostream>
using namespace std;
#define MAX_Tree_Size 256

//定义树节点存储数据的类型
typedef int Elemtype;

//定义树的节点类型 
typedef struct TreeNode{
    //数据域
    Elemtype value;  
    //指针域，左孩子节点，右孩子节点
    TreeNode *left,*right; 
    // bool isEmpty = true;

    //构造器，初始化每个字段
    TreeNode(int value):
        value(value),left(NULL),right(NULL){
        }
}Node;


//先序遍历： 根 --> 左 --> 右
void preOrder(TreeNode *node){
    //节点为空，什么都不做
    if(node != NULL){

        //访问节点数据
        cout << node->value << "->";
        //递归访问左子树
        preOrder(node->left);
        //递归访问右子树 
        preOrder(node->right);
    }

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

//后序遍历： 左 --> 右 --> 根
void postOrder(TreeNode *node){
    //节点为空，什么都不做
    if(node != NULL){
        //递归访问左子树
        postOrder(node->left);
        //递归访问右子树 
        postOrder(node->right);
        //访问节点数据
        cout << node->value << "->";
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


     cout << "前序遍历："<< endl;
     preOrder(&child10);
     cout << endl;

     cout << "中序遍历："<< endl;
     inOrder(&child10);
     cout << endl;

     cout << "后序遍历："<< endl;
     postOrder(&child10);
     cout << endl;
 
}
