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
//初始化栈
void initStack(sqstack *s){
    s->top = -1;
}
//判断栈空 如果stack是空的 则返回true 否则返回 false
bool empty_stack(sqstack s){
    if(s.top == -1){
        return true;
    }else{
        return false;
    }
}
//入栈
void Push(sqstack *s,BiTree p){
        if(s->top == maxsize-1){
        printf("this stack is full");
    }
    else{
        s->data[++(s->top)]= p;
    }
}
//出栈
void Pop(sqstack *s,BiTree *p){
    if(s->top == -1){
        printf("this stack is null!");
    }else{
        *p = s->data[(s->top)--];
    }
}
//获取栈顶元素
void getTop(sqstack s,BiTree *p){
    *p = s.data[s.top];
}

void InitBiTree(BiTree *T){
    Elemtype ch;
    scanf("%c",&ch);

    if(ch == '#'){                       //这一点很重要，字符比较要加单引号
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

//定义visit函数
void visit (BiTree T){
    printf("%c",T->data);
}


//二叉树的遍历 （递归遍历）

    //先序遍历（递归方法）
void PreOrder(BiTree T){
    if(T!=null){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
    // 中序遍历（递归方法）
void InOrder(BiTree T){
    if(T!=null){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}
    //后序遍历（递归方法）
void PostOrder(BiTree T){
    if(T!=null){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}




/***********以下是二叉树的非递归算法*****************/

//中序遍历
void InOrder2(BiTree T){
    sqstack s;
    initStack(&s);
    BiTree p=T; //p是遍历指针
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

//先序遍历（非递归算法）
      //与中序的区别就是把visit操作放在了push前面
void PreOrder2(BiTree T){
    sqstack s;
    initStack(&s);
    BiTree p=T; //p是遍历指针
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

//后序遍历（非递归算法）
void PostOrder2(BiTree T){
    sqstack s;
    initStack(&s);
    BiTree p = T;
    BiNode *r = null;   //r指针为辅助指针，用来判断这个节点是从左子树还是右子树返回的
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

    //递归遍历
    printf("先序遍历：");
    PreOrder(T);
    printf("\n");
    printf("中序遍历：");
    InOrder(T);
    printf("\n");
    printf("后序遍历：");
    PostOrder(T);
    printf("\n");

    printf("/********一下是非递归算法*********/\n");
    //非递归遍历
    printf("中序遍历：");
    InOrder2(T);
    printf("\n");
    printf("先序遍历：");
    PreOrder2(T);
    printf("\n");
    printf("后序遍历：");
    PostOrder2(T);
    printf("\n");
}


