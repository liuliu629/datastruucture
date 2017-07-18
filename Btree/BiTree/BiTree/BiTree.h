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
	//创建二叉链表树，R表示指向data[i]元素的二叉链表节点的指针，data为完全二叉树顺序存储数组，n表示完全二叉树总的节点个数
	//非完全二叉树，按完全二叉树形式顺序存储时，空节点用NULL表示，并计入节点总数中。
	void Create(BiTreeNode<T> * &R,T data[],int i,int n);//构造二叉树链表时使用

	//释放节点，由于二叉树链表是动态存储分配，因此需要自己释放所有节点
	//为了防止内存泄露（不受控），应该先释放左右子树，在释放根节点
	void Release(BiTreeNode<T> * &R);//析构二叉树链表时使用

	int Count(BiTreeNode<T> * &R);//求二叉树链表的节点总数

	int CountLeaf(BiTreeNode<T> * &R);//求二叉树链表的叶子节点总数

	int Depth(BiTreeNode<T> * &R);//求树的深度

	void PreOrder(BiTreeNode<T> * &R);//前序遍历二叉树链表，父->左->右
public:
	BiTreeNode<T> * root;
	BiTree(T data[],int n);
	~BiTree();
	int BiTreeCount();//对二叉树链表计算节点个数
	int BiTreeCountLeaf();//求二叉树链表的叶子节点总数
	int BiTreeDepth();//求二叉树链表的深度
	//前序遍历二叉树链表，父->左->右，中序：左->父->右，后序：左->右->父
	void BiTreePreOrder();
	void BiTreeLevelOrder();//层次遍历

};

#endif
/*-------------------------------------------------------------------------------
1）下边的二叉树链表创建方法具有一定的局限性
它需要数据是以顺序存储结构的一维数组，该数组是按完全二叉树进行编号，
无节点的位置用NULL表示，可能造成空间浪费
2）利用到完全二叉树节点的性质：
具有n个节点的完全有序二叉树，所有节点从1开始编号，对于节点i有：
1)如果i>0，i节点的双亲节点为[i/2]([]为取整符号)，i=1表示根节点，没有双亲；
2）如果2*i>0,i节点没有左孩子节点，（该i节点为终端节点，及叶子节点），反之，2*i为左孩子节点编号
3）如果2*i+1>0,i节点没有右孩子节点，反之，2*i+1为右孩子节点编号
步骤：
节点 ->该节点的左孩子 ->该节点的右孩子
--------------------------------------------------------------------------------*/
template<class T>
void BiTree<T>::Create(BiTreeNode<T> * &R,T data[],int i, int n)
{
	if(i <= n && data[i-1] != NULL)//去掉顺序数组中节点为NULL的点
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
  Create(root,data,1,n);//表示root指针指向的节点在data[i-1]中
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

//求二叉树链表的节点总数
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

//求二叉树链表的叶子节点总数
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

//求二叉树链表的深度
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

//前序遍历二叉树链表，父->左->右
template<class T>
void BiTree<T>::PreOrder(BiTreeNode<T> * & R)
{
 
 if(R != NULL)
 {
	 cout<< R->data;//打印父节点
	 PreOrder(R ->lchild);//左孩子
	 PreOrder(R ->rchild);//右孩子 

	 ////中序遍历
	 //PreOrder(R ->lchild);//左孩子
	 //cout<< R->data;//打印父节点
	 //PreOrder(R ->rchild);//右孩子 

	 ////后序遍历
	 //PreOrder(R ->lchild);//左孩子
	 //PreOrder(R ->rchild);//右孩子 
	 //cout<< R->data;//打印父节点


 }
}
template<class T>
void BiTree<T>::BiTreePreOrder()
{
	PreOrder(root);
}
//层次遍历
template<class T>
void BiTree<T>::BiTreeLevelOrder()
{
	BiTreeNode<T> * queue[MAXSIZE];//定义指向二叉链表节点的指针数组
	int f=0,r=0;//定义数组队列的头尾指针
	if(root!=NULL) queue[++r] = root;//根节点入队
	while(f != r)//只要队列中含有节点
	{
	  BiTreeNode<T> * p = queue[++f];//头结点出队
	  cout<<p ->data;//打印头结点
	  if(p ->lchild != NULL) queue[++r] = p ->lchild;//左孩子入队
	  if(p ->rchild != NULL) queue[++r] = p ->rchild;//右孩子入队
	
	}

}