#include<iostream>
#include"BiTree.h"

using namespace std;

void main()
{
	char a[13] = {'a','b','c','d','e','g',NULL,NULL,NULL,'f',NULL,NULL,NULL};
	BiTree<char> tree1(a,13);
	cout<<"二叉树链表的节点总数： "<<tree1.BiTreeCount()<<endl;
	cout<<"二叉树链表的叶子节点总数： "<<tree1.BiTreeCountLeaf()<<endl;
	cout<<"二叉树链表的深度： "<<tree1.BiTreeDepth()<<endl;
	cout<<"二叉树链表的前序遍历：\n";
	tree1.BiTreePreOrder();
	cout<<endl;
	cout<<"二叉树链表的层次遍历：\n";
	tree1.BiTreeLevelOrder();
	cout<<endl;
	system("pause");

}