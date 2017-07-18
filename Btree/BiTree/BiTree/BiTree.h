#ifndef BITREE_H_
#define BITREE_H_
//#define MAXSIZE 1000;
const int MAXSIZE = 1000;
template<class T>
struct BiTreeNode
{
 T data;
 BiTreeNode<T> * lchild;
 BiTreeNode<T> * rchild;
};

template<class T>
class BiTree
{
private:
	//����������������R��ʾָ��data[i]Ԫ�صĶ�������ڵ��ָ�룬dataΪ��ȫ������˳��洢���飬n��ʾ��ȫ�������ܵĽڵ����
	//����ȫ������������ȫ��������ʽ˳��洢ʱ���սڵ���NULL��ʾ��������ڵ������С�
	void Create(BiTreeNode<T> * &R,T data[],int i,int n);//�������������ʱʹ��

	//�ͷŽڵ㣬���ڶ����������Ƕ�̬�洢���䣬�����Ҫ�Լ��ͷ����нڵ�
	//Ϊ�˷�ֹ�ڴ�й¶�����ܿأ���Ӧ�����ͷ��������������ͷŸ��ڵ�
	void Release(BiTreeNode<T> * &R);//��������������ʱʹ��

	int Count(BiTreeNode<T> * &R);//�����������Ľڵ�����

	int CountLeaf(BiTreeNode<T> * &R);//������������Ҷ�ӽڵ�����

	int Depth(BiTreeNode<T> * &R);//���������

	void PreOrder(BiTreeNode<T> * &R);//ǰ�����������������->��->��
public:
	BiTreeNode<T> * root;
	BiTree(T data[],int n);
	~BiTree();
	int BiTreeCount();//�Զ������������ڵ����
	int BiTreeCountLeaf();//������������Ҷ�ӽڵ�����
	int BiTreeDepth();//���������������
	//ǰ�����������������->��->�ң�������->��->�ң�������->��->��
	void BiTreePreOrder();
	void BiTreeLevelOrder();//��α���

};

#endif
/*-------------------------------------------------------------------------------
1���±ߵĶ�������������������һ���ľ�����
����Ҫ��������˳��洢�ṹ��һά���飬�������ǰ���ȫ���������б�ţ�
�޽ڵ��λ����NULL��ʾ��������ɿռ��˷�
2�����õ���ȫ�������ڵ�����ʣ�
����n���ڵ����ȫ��������������нڵ��1��ʼ��ţ����ڽڵ�i�У�
1)���i>0��i�ڵ��˫�׽ڵ�Ϊ[i/2]([]Ϊȡ������)��i=1��ʾ���ڵ㣬û��˫�ף�
2�����2*i>0,i�ڵ�û�����ӽڵ㣬����i�ڵ�Ϊ�ն˽ڵ㣬��Ҷ�ӽڵ㣩����֮��2*iΪ���ӽڵ���
3�����2*i+1>0,i�ڵ�û���Һ��ӽڵ㣬��֮��2*i+1Ϊ�Һ��ӽڵ���
���裺
�ڵ� ->�ýڵ������ ->�ýڵ���Һ���
--------------------------------------------------------------------------------*/
template<class T>
void BiTree<T>::Create(BiTreeNode<T> * &R,T data[],int i, int n)
{
	if(i <= n && data[i-1] != NULL)//ȥ��˳�������нڵ�ΪNULL�ĵ�
	//if(i <= n)
	{
	  R = new BiTreeNode<T>;
	  R ->data = data[i-1];
	  Create(R ->lchild,data,2*i,n);
	  Create(R ->rchild,data,2*i+1,n);	
	}
	else R = NULL;

}

template<class T>
BiTree<T>::BiTree(T data[],int n)
{
  Create(root,data,1,n);//��ʾrootָ��ָ��Ľڵ���data[i-1]��
}

template<class T>
void BiTree<T>::Release(BiTreeNode<T> * &R)
{
	if(R != NULL)
	{
		Release(R ->lchild);
		Release(R ->rchild);
		delete R;
	}

}

template<class T>
BiTree<T>::~BiTree()
{
 Release(root);
}

//�����������Ľڵ�����
template<class T>
int BiTree<T>::Count(BiTreeNode<T> * &R)
{
	
 if(R == NULL) return 0;
 else
 {
  int m = Count(R ->lchild);
  int n = Count(R ->rchild);
  return m+n+1;
 
 }

}

template<class T>
int BiTree<T>::BiTreeCount()
{
 return Count(root);
}

//������������Ҷ�ӽڵ�����
template<class T>
int BiTree<T>::CountLeaf(BiTreeNode<T> * & R)
{
	
	//if(R == NULL) return 0;
	if(R->lchild == NULL || R->rchild == NULL) return 1;
	else
	{
		int m = CountLeaf(R ->lchild);
		int n = CountLeaf(R ->rchild);
		return m+n;
	
	}
}

template<class T>
int BiTree<T>::BiTreeCountLeaf()
{
 return CountLeaf(root);

}

//���������������
template<class T>
int BiTree<T>::Depth(BiTreeNode<T> * &R)
{
 if(R == NULL) return 0;
 else
 {
	 int m = Depth(R ->lchild);
	 int n = Depth(R ->rchild);
	 return m >=n ? m+1:n+1;
 
 }
}

template<class T>
int BiTree<T>::BiTreeDepth()
{
	return Depth(root);
}

//ǰ�����������������->��->��
template<class T>
void BiTree<T>::PreOrder(BiTreeNode<T> * & R)
{
 
 if(R != NULL)
 {
	 cout<< R->data;//��ӡ���ڵ�
	 PreOrder(R ->lchild);//����
	 PreOrder(R ->rchild);//�Һ��� 

	 ////�������
	 //PreOrder(R ->lchild);//����
	 //cout<< R->data;//��ӡ���ڵ�
	 //PreOrder(R ->rchild);//�Һ��� 

	 ////�������
	 //PreOrder(R ->lchild);//����
	 //PreOrder(R ->rchild);//�Һ��� 
	 //cout<< R->data;//��ӡ���ڵ�


 }
}
template<class T>
void BiTree<T>::BiTreePreOrder()
{
	PreOrder(root);
}
//��α���
template<class T>
void BiTree<T>::BiTreeLevelOrder()
{
	BiTreeNode<T> * queue[MAXSIZE];//����ָ���������ڵ��ָ������
	int f=0,r=0;//����������е�ͷβָ��
	if(root!=NULL) queue[++r] = root;//���ڵ����
	while(f != r)//ֻҪ�����к��нڵ�
	{
	  BiTreeNode<T> * p = queue[++f];//ͷ������
	  cout<<p ->data;//��ӡͷ���
	  if(p ->lchild != NULL) queue[++r] = p ->lchild;//�������
	  if(p ->rchild != NULL) queue[++r] = p ->rchild;//�Һ������
	
	}

}