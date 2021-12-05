#include<stdio.h>
#include<stdlib.h>

#define null 0
#define Elemtype char
#define elemtype BiTree
#define maxsize 30
#define false 0
#define true 1
#define bool int
typedef struct BiNode{
    Elemtype data;
    struct BiNode *lchild,*rchild;
}BiNode,*BiTree;

typedef struct {
    elemtype data[maxsize];
    int top;
}sqstack;
//��ʼ��ջ
void initStack(sqstack *s){
    s->top = -1;
}
//�ж�ջ�� ���stack�ǿյ� �򷵻�true ���򷵻� false
bool empty_stack(sqstack s){
    if(s.top == -1){
        return true;
    }else{
        return false;
    }
}
//��ջ
void Push(sqstack *s,BiTree p){
        if(s->top == maxsize-1){
        printf("this stack is full");
    }
    else{
        s->data[++(s->top)]= p;
    }
}
//��ջ
void Pop(sqstack *s,BiTree *p){
    if(s->top == -1){
        printf("this stack is null!");
    }else{
        *p = s->data[(s->top)--];
    }
}
//��ȡջ��Ԫ��
void getTop(sqstack s,BiTree *p){
    *p = s.data[s.top];
}

void InitBiTree(BiTree *T){
    Elemtype ch;
    scanf("%c",&ch);

    if(ch == '#'){                       //��һ�����Ҫ���ַ��Ƚ�Ҫ�ӵ�����
        (*T) = null;
    }else{
        (*T) = (BiNode*)malloc(sizeof(BiNode));
//        if(!*T){
//            printf("defeat to allocation memory");
//        }
        (*T)->data = ch;
        InitBiTree(&((*T)->lchild));
        InitBiTree(&((*T)->rchild));
    }
}

//����visit����
void visit (BiTree T){
    printf("%c",T->data);
}


//�������ı��� ���ݹ������

    //����������ݹ鷽����
void PreOrder(BiTree T){
    if(T!=null){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
    // ����������ݹ鷽����
void InOrder(BiTree T){
    if(T!=null){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}
    //����������ݹ鷽����
void PostOrder(BiTree T){
    if(T!=null){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}




/***********�����Ƕ������ķǵݹ��㷨*****************/

//�������
void InOrder2(BiTree T){
    sqstack s;
    initStack(&s);
    BiTree p=T; //p�Ǳ���ָ��
    while(p||!empty_stack(s)){
        if(p){
            Push(&s,p);
            p=p->lchild;
        }
        else{
            Pop(&s,&p);
            visit(p);
            p=p->rchild;
        }
    }

}

//����������ǵݹ��㷨��
      //�������������ǰ�visit����������pushǰ��
void PreOrder2(BiTree T){
    sqstack s;
    initStack(&s);
    BiTree p=T; //p�Ǳ���ָ��
    while(p||!empty_stack(s)){
        if(p){
            visit(p);
            Push(&s,p);
            p=p->lchild;
        }
        else{
            Pop(&s,&p);
            p=p->rchild;
        }
    }

}

//����������ǵݹ��㷨��
void PostOrder2(BiTree T){
    sqstack s;
    initStack(&s);
    BiTree p = T;
    BiNode *r = null;   //rָ��Ϊ����ָ�룬�����ж�����ڵ��Ǵ��������������������ص�
    while(p||!empty_stack(s)){
        if(p){
            Push(&s,p);
            p = p->lchild;
        }
        else{
            getTop(s,&p);
            if(p->rchild && p->rchild!=r){
                p=p->rchild;
                Push(&s,p);
                p = p->lchild;
            }
            else{
                Pop(&s,&p);
                visit(p);
                r=p;
                p=null;
            }
        }//else
    }//while

}


int main(){
    BiTree T;
    InitBiTree(&T);

    //�ݹ����
    printf("���������");
    PreOrder(T);
    printf("\n");
    printf("���������");
    InOrder(T);
    printf("\n");
    printf("���������");
    PostOrder(T);
    printf("\n");

    printf("/********һ���Ƿǵݹ��㷨*********/\n");
    //�ǵݹ����
    printf("���������");
    InOrder2(T);
    printf("\n");
    printf("���������");
    PreOrder2(T);
    printf("\n");
    printf("���������");
    PostOrder2(T);
    printf("\n");
}


