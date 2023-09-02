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

int main(){
    //创建一棵树
    TreeNode *root = new TreeNode(1);  
    TreeNode *leftChild = new TreeNode(2);
    TreeNode *rightChild = new TreeNode(3); 

    root->right = rightChild;
    root->left = leftChild; 
}

