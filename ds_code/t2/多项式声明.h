typedef struct term {
    float coef; //系数
    int expn;   //指数
    struct term* next;
}Poly,*Link;

int LocateElem(Link p, Link s, Link& q); //定位排序
void CreatePolyn(Link& p, int m);        //创建多项式
void PrintPolyn(Link p);                 //打印多项式（表示）
int cmp(Link a, Link b);                 //比较最高次数
Link AddPolyn(Link pa, Link pb);         //多项式相加
Link SubPolyn(Link pa, Link pb);         //多项式相减
Link Reverse(Link p);                    //逆置多项式
Link MultiplyPolyn(Link A, Link B);      //多项式相乘
void Calculate(Link p, float x);         //多项式求值