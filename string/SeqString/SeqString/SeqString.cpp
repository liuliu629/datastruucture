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

	//�������Ӻ���
	//cout<<"���Ӻ󳤶ȣ�"<<s1.GetLength()<<endl;
	//cout<<"���Ӻ�����Ԫ�أ�"<<endl;
	//for(int i = 0;i < s1.GetLength();i++)
	//{
	//	cout<<s1.GetData(i)<<" ";
	//
	//}
	//cout<<endl;

	//���Դ��ȽϺ���
	/*cout<<"'abcd'��'1234'�Ƚ�:"<<endl;
	cout<<s1.Strcmp(s2)<<endl;

	cout<<"'abcd'��'abcd'�Ƚ�:"<<endl;
	cout<<s1.Strcmp(s3)<<endl;

	cout<<"'abcd'��'abc'�Ƚ�:"<<endl;
	cout<<s1.Strcmp(s4)<<endl;

	cout<<"'abcd'��'abc12'�Ƚ�:"<<endl;
	cout<<s1.Strcmp(s5)<<endl;

	cout<<"'abcd'��'adc12'�Ƚ�:"<<endl;
	cout<<s1.Strcmp(s6)<<endl;*/

	//���Ը�ֵ���

	/*cout<<"'abcd'�滻Ϊ'ABCD':"<<endl;
	s1.Strcpy(s7);
	for(int i = 0;i < s1.GetLength();i++)
	{
		cout<<s1.GetData(i)<<" ";
	
	}
	cout<<endl;*/

	//���Դ���ƥ�亯��
	cout<<"bc��abcd�е�λ�ã�"<<s1.KMP(s4)<<endl;

	//���Դ���ƥ�亯��
	s1.Reverse();
	cout<<"abcd�ķ�ת��"<<endl;
	for(int i = 0;i < s1.GetLength();i++)
	{
		cout<<s1.GetData(i)<<" ";
	
	}
	cout<<endl;

	system("pause");

}

















/*------------------------------------------------
              ������Ժ���
----------------------------------------------------
void main()
{
	int a[4] = {1,2,3,4};
	SeqList<int> list1(a,4);
	SeqList<int> list2;

	//����GetLength����
	cout<<"list1����Ϊ��"<<endl;
	cout<<list1.GetLength()<<endl;

	//����GetData����
	cout<<"list1����Ϊ��"<<endl;
	for(int i = 0; i < list1.GetLength();i++)
	{
		cout<<list1.GetData(i)<<"  ";
	}
	cout<<endl;

	//����Insert����
	list1.Insert(1,3);
	cout<<"ִ�в���Insert(1,3)֮���list1��"<<endl;
		for(int i = 0; i < list1.GetLength();i++)
	{
		cout<<list1.GetData(i)<<"  ";
	}
	cout<<endl;
	cout<<"��list1ĩβ���룺"<<endl;
	list1.Insert(1,list1.GetLength()+1);
	for(int i = 0; i < list1.GetLength();i++)
	{
		cout<<list1.GetData(i)<<"  ";
	}
	cout<<endl;

	//����Delete����
	list1.Delete(1);
	cout<<"ɾ����һ��Ԫ�أ�"<<endl;
	for(int i = 0; i < list1.GetLength();i++)
	{
		cout<<list1.GetData(i)<<"  ";
	}
	cout<<endl;

    //�����滻Replace����
	list1.Replace(1,0);
	cout<<"�滻���е�1Ϊ0��"<<endl;
	for(int i = 0; i < list1.GetLength();i++)
	{
		cout<<list1.GetData(i)<<"  ";
	}
	cout<<endl;


	system("pause");
}
----------------------------------------------------*/