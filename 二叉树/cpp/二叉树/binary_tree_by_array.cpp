#include <iostream>
using namespace std;
#define MAX_Tree_Size 256

//定义树节点存储数据的类型
typedef int Elemtype;

//定义树的节点类型 
struct TreeNode{
    Elemtype value;  
    bool isEmpty = true;
};

//定义树的结构
// struct Tree{
//     TreeNode nodes[MAX_Tree_Size];   
//     int num;
// }; 

int main(){
    //最简单的定义树，即节点类型的数组
    TreeNode tree[MAX_Tree_Size];

    for (int i = 0; i<MAX_Tree_Size; i++) {
        tree[i].value = i;
        //  cout << tree[i].value << endl; 
        tree[i].isEmpty = false; 
    }
     
     for (int i = 0; i<MAX_Tree_Size; i++) {
        cout << tree[i].value <<"--"<< tree[i].isEmpty<< endl; 
    }
}