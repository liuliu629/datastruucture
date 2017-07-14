#include<iostream>
#include"SeqString.h"
using namespace std;


void main()
{
	char a[4] ={'a','b','c','d'};
	char b[4] ={'1','2','3','4'};
	char c[4] ={'a','b','c','d'};
	char d[3] ={'b','c'};
	char e[5] ={'a','b','c','1','2'};
	char f[5] ={'a','d','c','1','2'};
	char g[4] = {'A','B','C','D'};

	SeqString s1(a,4);
	SeqString s2(b,4);

	SeqString s3(c,4);
	SeqString s4(d,2);

	SeqString s5(e,5);
	SeqString s6(f,5);
	SeqString s7(g,4);
	//s1.Strcat(s2);

	//测试连接函数
	//cout<<"连接后长度："<<s1.GetLength()<<endl;
	//cout<<"连接后所有元素："<<endl;
	//for(int i = 0;i < s1.GetLength();i++)
	//{
	//	cout<<s1.GetData(i)<<" ";
	//
	//}
	//cout<<endl;

	//测试串比较函数
	/*cout<<"'abcd'与'1234'比较:"<<endl;
	cout<<s1.Strcmp(s2)<<endl;

	cout<<"'abcd'与'abcd'比较:"<<endl;
	cout<<s1.Strcmp(s3)<<endl;

	cout<<"'abcd'与'abc'比较:"<<endl;
	cout<<s1.Strcmp(s4)<<endl;

	cout<<"'abcd'与'abc12'比较:"<<endl;
	cout<<s1.Strcmp(s5)<<endl;

	cout<<"'abcd'与'adc12'比较:"<<endl;
	cout<<s1.Strcmp(s6)<<endl;*/

	//测试赋值语句

	/*cout<<"'abcd'替换为'ABCD':"<<endl;
	s1.Strcpy(s7);
	for(int i = 0;i < s1.GetLength();i++)
	{
		cout<<s1.GetData(i)<<" ";
	
	}
	cout<<endl;*/

	//测试串的匹配函数
	cout<<"bc在abcd中的位置："<<s1.KMP(s4)<<endl;

	//测试串的匹配函数
	s1.Reverse();
	cout<<"abcd的反转："<<endl;
	for(int i = 0;i < s1.GetLength();i++)
	{
		cout<<s1.GetData(i)<<" ";
	
	}
	cout<<endl;

	system("pause");

}

















/*------------------------------------------------
              基类测试函数
----------------------------------------------------
void main()
{
	int a[4] = {1,2,3,4};
	SeqList<int> list1(a,4);
	SeqList<int> list2;

	//测试GetLength函数
	cout<<"list1长度为："<<endl;
	cout<<list1.GetLength()<<endl;

	//测试GetData函数
	cout<<"list1数组为："<<endl;
	for(int i = 0; i < list1.GetLength();i++)
	{
		cout<<list1.GetData(i)<<"  ";
	}
	cout<<endl;

	//测试Insert函数
	list1.Insert(1,3);
	cout<<"执行插入Insert(1,3)之后的list1："<<endl;
		for(int i = 0; i < list1.GetLength();i++)
	{
		cout<<list1.GetData(i)<<"  ";
	}
	cout<<endl;
	cout<<"在list1末尾插入："<<endl;
	list1.Insert(1,list1.GetLength()+1);
	for(int i = 0; i < list1.GetLength();i++)
	{
		cout<<list1.GetData(i)<<"  ";
	}
	cout<<endl;

	//测试Delete函数
	list1.Delete(1);
	cout<<"删除第一个元素："<<endl;
	for(int i = 0; i < list1.GetLength();i++)
	{
		cout<<list1.GetData(i)<<"  ";
	}
	cout<<endl;

    //测试替换Replace函数
	list1.Replace(1,0);
	cout<<"替换所有的1为0："<<endl;
	for(int i = 0; i < list1.GetLength();i++)
	{
		cout<<list1.GetData(i)<<"  ";
	}
	cout<<endl;


	system("pause");
}
----------------------------------------------------*/