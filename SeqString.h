#ifndef SEQSTRING_H_
#define SEQSTRING_H_
#include<iostream>
using namespace std;

/*--------------------------------------------------------
                 SeqList基类模板声明
-----------------------------------------------------------*/
const int SeqenceSize = 1024;
template<class T>
class SeqList
{
public:
	SeqList(){SeqListLength = 0;};//无参构造函数，空顺序表
	SeqList(T a[],int n);//有参构造函数
	void Insert(T x,int i);//在位置i插入元素x
	T Delete(int i);//删除位置i的元素
	void Replace(T x,T y);//替换链表中值为y的元素为x
	T GetData(int i);//获取位置i的list元素
	int GetLength(){return SeqListLength;};//返回list的长度
	void IndexReplace(T x,int i);//在位置i上的元素替换为x
private:
	T data[SeqenceSize];//list模板类的数据
	int SeqListLength;//记录长度
};
/*------------------------------------------------------------
                     SeqString派生类声明
-------------------------------------------------------------*/

class SeqString:public SeqList<char>
{
public:
	SeqString(char data[],int n):SeqList(data,n){};//派生类构造函数
	void Strcat(SeqString & s);//串的连接
	int Strcmp(SeqString & s);//串的比较
	void Strcpy(SeqString & s);//串的赋值
	int Index(SeqString & s);//串的匹配，即查找s在原串中的位置
};


#endif




/*-------------------------------------------
          SeqList模板类的成员函数
----------------------------------------------*/

template<class T>
SeqList<T>::SeqList(T a[],int n)//实现数组初始化list
{ SeqListLength = 0;
  if(n >= SeqenceSize)throw"上溢";
  for(int i = 0; i < n; i++)
  {
   data[i] = a[i];
   SeqListLength ++;
  }
}

template<class T>
void SeqList<T>::Insert(T x,int i)//插入
{
  if(i < 1 || i > SeqListLength+1)throw"插入位置错误";//+1可实现在list末尾插入
  for(int j = SeqListLength; j >= i  ; j--)
  {
    data[j] = data[j-1];//i-1之后的数据后移一位
  }
  data[i-1] = x;
  SeqListLength ++;
}

template<class T>
T SeqList<T>::Delete(int i)//删除
{
 if(i < 1 || i > SeqenceSize)throw"删除位置错误";
 T x;
 x = data[i-1];
 for(int j = i;j < SeqListLength;j++)
 {
   data[j-1] =data[j];
 }
  SeqListLength --;
 return x;
}

template<class T>
void SeqList<T>::Replace(T y,T x)//替换
{
int num = 0;
  for(int i = 0;i < SeqListLength; i++)
  {  
     if(data[i] == y) 
	{
			 data[i] = x;
			 num ++;
	 }
  }
  if(num == 0) cout<<"顺序表中没有发生替换！";
}

template<class T>
T SeqList<T>::GetData(int i)
{
 if(i < 0 || i >= SeqListLength) throw"索引位置错误";
 return data[i];
}

template<class T>
void SeqList<T>::IndexReplace(T x,int i)
{
 if(i < 0 || i > SeqListLength)throw"替换位置错误";
 data[i] = x;
}

/*-------------------------------------------
          SeqString派生类的成员函数
----------------------------------------------*/
void SeqString::Strcat(SeqString & s)//串的连接
{
	if(GetLength()+s.GetLength() >= SeqenceSize) throw"上溢";
	for(int j = 0; j < s.GetLength();j++)
	{
		Insert(s.GetData(j),GetLength()+1);
	}

}


int SeqString::Strcmp(SeqString & s)//串的比较
{
	if(GetLength() == s.GetLength() )
	{
	  for(int i = 0; i < GetLength();i++)
	  {
		  if(GetData(i) > s.GetData(i)) return 1;
		  else if(GetData(i) < s.GetData(i)) return -1;
	  }
	 return 0;
	}
	if(GetLength() > s.GetLength())
	{
		for(int i = 0; i < s.GetLength();i++)
		{
			if(GetData(i) > s.GetData(i)) return 1;
			else if(GetData(i) < s.GetData(i)) return -1;
		}
	   return 1;
	}
	if(GetLength() < s.GetLength())
	{
	  for(int i = 0; i < GetLength();i++)
	  {
	    if(GetData(i) > s.GetData(i)) return 1;
	    else if(GetData(i) < s.GetData(i)) return -1;
	  
	  }

	return -1;
	}

}

void SeqString::Strcpy(SeqString & s)//串的赋值
{
	if(GetLength() == s.GetLength())
	{
		for(int i = 0; i <s.GetLength();i++)
		{
			IndexReplace(s.GetData(i),i);
		}
	  
	}
	if(GetLength() > s.GetLength())
	{
	 for(int i = 0; i <GetLength();i++)
		{
			if(i < s.GetLength()) IndexReplace(s.GetData(i),i);
			else Delete(i);
	     }	
	}
	if(GetLength() < s.GetLength())
		for(int i = 0; i <s.GetLength();i++)
		{
			if(i < GetLength()) IndexReplace(s.GetData(i),i);
			else Insert(s.GetData(i),i);
	     }	
}

int SeqString::Index(SeqString & s)//串的匹配
{
 /*-------BF朴素模式匹配算法-------------*/
	int i = 1,j = 1;//初始化两个数组的下标
	while(i <= GetLength() && j <= s.GetLength())
	{
		if(GetData(i-1) == s.GetData(j-1)){i++;j++;}
		else{i += 2-j;j=1;}//回溯
	
	}
	if(j > s.GetLength()) return i+1-j;
	else return -1;//查找失败

}