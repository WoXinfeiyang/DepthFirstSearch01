#include <stdio.h>
#include <stdlib.h>



#define OK (1)
#define ERROR (0)
#define TRUE (1)
#define FALSE (0)

#define MAXVEX (9)
#define INFINITY (655325)/*将无穷大定义为655325*/

typedef int Bool;
typedef char VertexType;/*定义顶点类型*/ 
typedef int EdgeType;/*定义边上权值类型类型*/

/*定义图结构*/
typedef struct
{
	VertexType vertexs[MAXVEX];/*顶点表*/
	EdgeType arc[MAXVEX][MAXVEX];/*领结矩阵*/ 
	int numVertexs;/*顶点数*/
	int numEdges;/*边数*/
}MGraph;

/*创建一个图*/
void GreateMGraph(MGraph *G)
{
	int i=0,j=0;
	
	G->numVertexs=9;
	G->numEdges=15;
	
	/*设定顶点表*/
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
			G->arc[i][j]=INFINITY;/*首先将领结矩阵中各边的权值设置为无穷大*/	
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


Bool visited[MAXVEX];/*访问标志组*/

/* 邻接矩阵的深度优先递归算法 */
void DFS(MGraph G,int i)
{
	int j=0;
	if(visited[i]!=TRUE)/*当顶点还未被访问过时开始访问该顶点*/
	{
		visited[i]=TRUE;/*将访问标志置为TRUE*/
		printf("%c ",G.vertexs[i]);/*进行访问操作*/
		
		for(j=0;j<G.numVertexs;j++)
		{   /*访问与该顶点领接的顶点*/
			if((G.arc[i][j]!=INFINITY)&&(visited[j]!=TRUE))
			{
				DFS(G,j);	
			}	
		}
			
	} 
}

/* 邻接矩阵的深度遍历操作 */
void DFSTraverse(MGraph G)
{
	int i=0;
	
	for(i=0;i<G.numVertexs;i++)/*初始化将访问标志组置为FALSE*/
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
