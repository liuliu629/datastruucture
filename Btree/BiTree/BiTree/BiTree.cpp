#include<iostream>
#include"BiTree.h"

using namespace std;

void main()
{
	char a[13] = {'a','b','c','d','e','g',NULL,NULL,NULL,'f',NULL,NULL,NULL};
	BiTree<char> tree1(a,13);
	cout<<"����������Ľڵ������� "<<tree1.BiTreeCount()<<endl;
	cout<<"�����������Ҷ�ӽڵ������� "<<tree1.BiTreeCountLeaf()<<endl;
	cout<<"�������������ȣ� "<<tree1.BiTreeDepth()<<endl;
	cout<<"�����������ǰ�������\n";
	tree1.BiTreePreOrder();
	cout<<endl;
	cout<<"����������Ĳ�α�����\n";
	tree1.BiTreeLevelOrder();
	cout<<endl;
	system("pause");

}