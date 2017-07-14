#ifndef SEQSTRING_H_
#define SEQSTRING_H_
#include<iostream>
using namespace std;

/*--------------------------------------------------------
                 SeqList����ģ������
-----------------------------------------------------------*/
const int SeqenceSize = 1024;
template<class T>
class SeqList
{
public:
	SeqList(){SeqListLength = 0;};//�޲ι��캯������˳���
	SeqList(T a[],int n);//�вι��캯��
	void Insert(T x,int i);//��λ��i����Ԫ��x
	T Delete(int i);//ɾ��λ��i��Ԫ��
	void Replace(T x,T y);//�滻������ֵΪy��Ԫ��Ϊx
	T GetData(int i);//��ȡλ��i��listԪ��
	int GetLength(){return SeqListLength;};//����list�ĳ���
	void IndexReplace(T x,int i);//��λ��i�ϵ�Ԫ���滻Ϊx
private:
	T data[SeqenceSize];//listģ���������
	int SeqListLength;//��¼����
};
/*------------------------------------------------------------
                     SeqString����������
-------------------------------------------------------------*/

class SeqString:public SeqList<char>
{
public:
	SeqString(char data[],int n):SeqList(data,n){};//�����๹�캯��
	void Strcat(SeqString & s);//��������
	int Strcmp(SeqString & s);//���ıȽ�
	void Strcpy(SeqString & s);//���ĸ�ֵ
	int Index(SeqString & s);//����ƥ�䣬������s��ԭ���е�λ��
	void GetNextArray(SeqString & s,int * & next);//����ģʽ�Ӵ���
	int KMP(SeqString & s); //����ģʽƥ�䣬��ԭ����Ѱ���Ӵ�
	void Reverse();//���ķ�ת
};

#endif




/*-------------------------------------------
          SeqListģ����ĳ�Ա����
----------------------------------------------*/

template<class T>
SeqList<T>::SeqList(T a[],int n)//ʵ�������ʼ��list
{ SeqListLength = 0;
  if(n >= SeqenceSize)throw"����";
  for(int i = 0; i < n; i++)
  {
   data[i] = a[i];
   SeqListLength ++;
  }
}

template<class T>
void SeqList<T>::Insert(T x,int i)//����
{
  if(i < 1 || i > SeqListLength+1)throw"����λ�ô���";//+1��ʵ����listĩβ����
  for(int j = SeqListLength; j >= i  ; j--)
  {
    data[j] = data[j-1];//i-1֮������ݺ���һλ
  }
  data[i-1] = x;
  SeqListLength ++;
}

template<class T>
T SeqList<T>::Delete(int i)//ɾ��
{
 if(i < 1 || i > SeqenceSize)throw"ɾ��λ�ô���";
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
void SeqList<T>::Replace(T y,T x)//�滻
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
  if(num == 0) cout<<"˳�����û�з����滻��";
}

template<class T>
T SeqList<T>::GetData(int i)
{
 if(i < 0 || i >= SeqListLength) throw"����λ�ô���";
 return data[i];
}

template<class T>
void SeqList<T>::IndexReplace(T x,int i)
{
 if(i < 0 || i > SeqListLength)throw"�滻λ�ô���";
 data[i] = x;
}


/*-------------------------------------------
          SeqString������ĳ�Ա����
----------------------------------------------*/
void SeqString::Strcat(SeqString & s)//��������
{
	if(GetLength()+s.GetLength() >= SeqenceSize) throw"����";
	for(int j = 0; j < s.GetLength();j++)
	{
		Insert(s.GetData(j),GetLength()+1);
	}

}


int SeqString::Strcmp(SeqString & s)//���ıȽ�
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

void SeqString::Strcpy(SeqString & s)//���ĸ�ֵ
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

int SeqString::Index(SeqString & s)//����ƥ��
{
 /*-------BF����ģʽƥ���㷨-------------*/
	int i = 1,j = 1;//��ʼ������������±�
	while(i <= GetLength() && j <= s.GetLength())
	{
		if(GetData(i-1) == s.GetData(j-1)){i++;j++;}
		else{i += 2-j;j=1;}//����
	
	}
	if(j > s.GetLength()) return i+1-j;
	else return -1;//����ʧ��

}
void SeqString::GetNextArray(SeqString & s,int * & next)
{
	next = new int[s.GetLength() + 1];
	next[1] = 0;
	next[2] = 1;
	int j ,p =1;//p�洢next[j-i]
	for(j = 3;j <= s.GetLength();++j)
	{
		while(p > 1 && (s.GetData(p-1) != s.GetData(j-2)))
			p = next[p];
		if(s.GetData(p-1) == s.GetData(j-2))
			++p;
		next[j] = p;
	
	}

}


int SeqString::KMP(SeqString & s)//ģʽ��ƥ��
{
 int * next;
 GetNextArray(s,next);
 int i =1,j=1;
 while(i <= GetLength() && j <= s.GetLength())
 {
	 if(GetData(i-1) == s.GetData(j-1))
	 {
	  i++;
	  j++;
	 }
	 else if(!next[j]){++i;j = 1;}
	 else {j = next[j];}
 }
 delete [] next;
 if(j > s.GetLength()) return i+1-j;
 else return -1;

}
void SeqString::Reverse()//ʵ�ִ��ķ�ת
{
	int i=0,j=GetLength()-1;
 while(i <= j)
 {
   char tem;
   tem = GetData(i);
   IndexReplace(GetData(j),i);
   IndexReplace(tem,j);
   ++i;
   --j;
 }
}