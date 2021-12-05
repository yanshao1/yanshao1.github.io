#include <stdio.h>

#define MAXVALUE 32767
typedef struct{						//���������ṹ��
	int weight;                       //����Ȩֵ
	int parent,lchild,rchild;        //˫�׽ڵ㣬���ӣ��Һ���
}HNodeType;
typedef struct{					//����������ṹ��
	int bit[8];					//��ŵ�ǰ���Ĺ���������
	int start;						//bit[start]-bit[8[��Ź���������
}HCodeType;
HNodeType HuffNode[8];		//����ȫ�ֱ�������HuffNode��Ź�������
HCodeType HuffCode[8];		//����ȫ�ֱ�������HuffCode��Ź���������
int n;							//����ȫ�ֱ���n��ʾҶ�ӽ�����
void	CreateHuffTree(void);			//�����������
void	PrintHuffTree(void);			//�����������
void	CreateHuffCode(void);			//�������������
void	PrintHuffcode(void);			//���ÿ��Ҷ�ӽ��Ĺ���������
void CreateHuffTree(void){		//�����������
	int i,j,a,b,x1,x2;
	scanf("%d",&n);        //����Ҷ�ӽڵ����
	for(i=1;i<2*n;i++) //HuffNode ��ʼ�� 
	{
		HuffNode[i].weight=0;
		HuffNode[i].parent=-1;
		HuffNode[i].lchild=-1;
		HuffNode[i].rchild=-1;
	}
	printf("����%d���ڵ��Ȩֵ\n",n);
	for(i=1;i<=n;i++)
	scanf("%d",& HuffNode[i].weight);//����N��Ҷ�ӽڵ��Ȩֵ
		for(i=1;i<n;i++){   //����������� 
			a=MAXVALUE;
			b=MAXVALUE;
			x1=0;
			x2=0;
				for(j=1;j<n+i;j++){        //ѡȡ��С�ʹ�С����Ȩֵ
					if(HuffNode[j].parent==-1&&HuffNode[j].weight<a){
						b=a;
						x2=x1;
						a=HuffNode[j].weight;
						x1=j;
					}
				else
					if(HuffNode[j].parent==-1&&HuffNode[j].weight<b){
						b=HuffNode[j].weight;
						x2=j;
					}
				}
			HuffNode[x1].parent=n+i;
			HuffNode[x2].parent=n+i;
			HuffNode[n+i].weight=HuffNode[x1].weight+HuffNode[x2].weight;
			HuffNode[n+i].lchild=x1;
			HuffNode[n+i].rchild=x2;
		}
}
void PrintHuffTree()	{			//�����������
	int i;
    printf("\n�������������������±���ʾ:\n");
	printf("        ���i weight parent    lchid    rchild\n");
	for(i=1;i<2*n;i++)
		printf("\t%d\t%d\t%d\t%d\t%d\n",i,HuffNode[i].weight,HuffNode[i].parent,
		       HuffNode[i].lchild,HuffNode[i].rchild);
	printf("\n");
}
void CreateHuffCode(void){		//�������������
	HCodeType cd;
	int i,j,c,p;
 
	for(i=1;i<=n;i++){
		cd.start=n;
		c=i;
		p=HuffNode[c].parent;
			while(p!=-1){
				if(HuffNode[p].lchild==c)
					cd.bit[cd.start]=0;
				else
					cd.bit[cd.start]=1;
				cd.start--;
				c=p;
				p=HuffNode[c].parent;
			}
		for(j=cd.start+1;j<=n;j++)
			HuffCode[i].bit[j]=cd.bit[j];
		HuffCode[i].start=cd.start;
		}	
}
void PrintHuffcode(void){		//���ÿ��Ҷ�ӽ��Ĺ���������
	int i,j;
	printf("ÿ��Ҷ�ӽ��Ĺ���������Ϊ:\n");
	for(i=1;i<=n;i++)
	{	for(j=HuffCode[i].start+1;j<=n;j++)
			printf("%d",HuffCode[i].bit[j]);
	printf("\n");
	}
}
int main(void){
	printf("����Ҷ�ӽڵ����\n"); 
	CreateHuffTree();			//�����������
	PrintHuffTree();				//�����������
	CreateHuffCode();			//�������������
	PrintHuffcode();				//���ÿ��Ҷ�ӽ��Ĺ���������
	return 0;
}
