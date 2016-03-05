#include <stdio.h>
#include <stdlib.h>



#define OK (1)
#define ERROR (0)
#define TRUE (1)
#define FALSE (0)

#define MAXVEX (9)
#define INFINITY (655325)/*���������Ϊ655325*/

typedef int Bool;
typedef char VertexType;/*���嶥������*/ 
typedef int EdgeType;/*�������Ȩֵ��������*/

/*����ͼ�ṹ*/
typedef struct
{
	VertexType vertexs[MAXVEX];/*�����*/
	EdgeType arc[MAXVEX][MAXVEX];/*������*/ 
	int numVertexs;/*������*/
	int numEdges;/*����*/
}MGraph;

/*����һ��ͼ*/
void GreateMGraph(MGraph *G)
{
	int i=0,j=0;
	
	G->numVertexs=9;
	G->numEdges=15;
	
	/*�趨�����*/
	G->vertexs[0]='A';
	G->vertexs[1]='B';
	G->vertexs[2]='C';
	G->vertexs[3]='D';
	G->vertexs[4]='E';
	G->vertexs[5]='F';
	G->vertexs[6]='G';
	G->vertexs[7]='H';
	G->vertexs[8]='I';
	
	for(i=0;i<G->numVertexs;i++)
	{
		for(j=0;j<G->numVertexs;j++)
		{
			G->arc[i][j]=INFINITY;/*���Ƚ��������и��ߵ�Ȩֵ����Ϊ�����*/	
		}	
	}
	
	G->arc[0][1]=1;
	G->arc[0][5]=1;

	G->arc[1][2]=1; 
	G->arc[1][8]=1; 
	G->arc[1][6]=1; 
	
	G->arc[2][3]=1; 
	G->arc[2][8]=1; 
	
	G->arc[3][4]=1;
	G->arc[3][7]=1;
	G->arc[3][6]=1;
	G->arc[3][8]=1;

	G->arc[4][5]=1;
	G->arc[4][7]=1;

	G->arc[5][6]=1; 
	
	G->arc[6][7]=1;
	
	
	for(i=0;i<G->numVertexs;i++)
	{
		for(j=i;j<G->numVertexs;j++)
		{
			G->arc[j][i]=G->arc[i][j];	
		}	
	}
}


Bool visited[MAXVEX];/*���ʱ�־��*/

/* �ڽӾ����������ȵݹ��㷨 */
void DFS(MGraph G,int i)
{
	int j=0;
	if(visited[i]!=TRUE)/*�����㻹δ�����ʹ�ʱ��ʼ���ʸö���*/
	{
		visited[i]=TRUE;/*�����ʱ�־��ΪTRUE*/
		printf("%c ",G.vertexs[i]);/*���з��ʲ���*/
		
		for(j=0;j<G.numVertexs;j++)
		{   /*������ö�����ӵĶ���*/
			if((G.arc[i][j]!=INFINITY)&&(visited[j]!=TRUE))
			{
				DFS(G,j);	
			}	
		}
			
	} 
}

/* �ڽӾ������ȱ������� */
void DFSTraverse(MGraph G)
{
	int i=0;
	
	for(i=0;i<G.numVertexs;i++)/*��ʼ�������ʱ�־����ΪFALSE*/
		visited[i]=FALSE;
		
	for(i=0;i<G.numVertexs;i++)
		DFS(G,i);
}

int main(int argc, char *argv[]) 
{
	MGraph G;
	GreateMGraph(&G);
	DFSTraverse(G);
	
	return 0;
}
