#define MaxSize 10
typedef int DataType;

// 二叉树存储结构 二叉链式
typedef struct BiTNode {
	DataType data;  //数据域
	struct BiTNode* lchild;
	struct BiTNode* rchild;
} BiTNode, * BiTree; //重命名

typedef BiTree ElemType;


//==============================================辅助队列

//存储结构循环队列
typedef struct {
	ElemType data[MaxSize];
	int front;          //队头
	int rear;           //队尾
} SqQueue;

//初始化
void InitQueue(SqQueue& q);
//队列空否
bool QueueEmpty(SqQueue q);
//入队
bool EnQueue(SqQueue& q, ElemType x);
//出队
bool DeQueue(SqQueue& q, ElemType& x);

//==============================================判定方法
bool IsComplete1(BiTree T);
bool IsComplete2(BiTree T);