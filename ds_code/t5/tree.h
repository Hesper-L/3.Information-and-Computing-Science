#define MaxSize 10
typedef int DataType;

// �������洢�ṹ ������ʽ
typedef struct BiTNode {
	DataType data;  //������
	struct BiTNode* lchild;
	struct BiTNode* rchild;
} BiTNode, * BiTree; //������

typedef BiTree ElemType;


//==============================================��������

//�洢�ṹѭ������
typedef struct {
	ElemType data[MaxSize];
	int front;          //��ͷ
	int rear;           //��β
} SqQueue;

//��ʼ��
void InitQueue(SqQueue& q);
//���пշ�
bool QueueEmpty(SqQueue q);
//���
bool EnQueue(SqQueue& q, ElemType x);
//����
bool DeQueue(SqQueue& q, ElemType& x);

//==============================================�ж�����
bool IsComplete1(BiTree T);
bool IsComplete2(BiTree T);