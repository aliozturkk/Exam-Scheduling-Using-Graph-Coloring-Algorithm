#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include "graphLibrary.h"


void DFS(struct Graph* graph, int vertex) {
	
        struct node* adjList = graph->adjLists[vertex];
        struct node* temp = adjList;
        
        graph->visited[vertex] = 1;
        printf("\nVisited %d ", vertex);
    
        while(temp!=NULL) {
            int connectedVertex = temp->vertex;
        
            if(graph->visited[connectedVertex] == 0) {
                DFS(graph, connectedVertex);
            }
            temp = temp->next;
        }  
 		
}

struct node* createNode(int v,char data[42])
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
	strcpy(newNode->data,data);
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices)
{
	
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
		
    graph->adjLists = malloc(vertices * sizeof(struct node*));
    
    graph->visited = malloc(vertices * sizeof(int));
 
    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
 
void addEdge(struct Graph* graph, int src, int dest,char srcU[42],char srcV[42])
{
    // Add edge from src to dest
    struct node* newNode = createNode(dest,srcV);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

 
    // Add edge from dest to src
    newNode = createNode(src,srcU);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
 
void printGraph(struct Graph* graph,char lessonArray[numberOfVertex][10] )
{
		
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node* temp = graph->adjLists[v];
		
		
        printf("\n Adjacency list of vertex %s  : \n", lessonArray[v]);
		
        while (temp)
        {
            printf("%s -> ", temp->data);
					
            temp = temp->next;
			
        }
        printf("\n");
    }
	 printf("\n");
}

int controlEdge(struct Graph* graph,int v,int u){
	int result=1; 
   
        struct node* temp = graph->adjLists[v];
      
        while (temp)
        {
         
		   if(u==temp->vertex){
			   result=0;			   
		   }			   
            temp = temp->next;		
        }      
	return result;
}


void buildGraph(struct Graph* graph,lesson *lessonlist,int countLesson){
	
	int i;
	int j;
	for(i=0;i<countLesson;i++){     	
		for(j=i+1;strcmp(lessonlist[j].name, lessonlist[i].name)==0 ;j++){
			
			   int a= controlEdge(graph,lessonlist[i].vertexNumber,lessonlist[j].vertexNumber);
                if(a==1){
					addEdge(graph, lessonlist[i].vertexNumber, lessonlist[j].vertexNumber,lessonlist[i].lesson, lessonlist[j].lesson);
				}			
		}		
	}	
}


void coloringGraph(struct Graph* graph,char lessonArray[numberOfVertex][10]){
	
	int colorx[numberOfVertex];
	int i=0;
	for(i=0;i<numberOfVertex;i++){
		colorx[i]=0;
	}
	
	int v;
  
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node* temp = graph->adjLists[v];
			
        while (temp)
        {       
		   if(colorx[temp->vertex]==v){
				colorx[temp->vertex]=v+1;
			 }	
            temp = temp->next;	
        }      
    }
	printf("\n");
	int periodCount=-1;
	for(i=0;i<numberOfVertex;i++){
		
		printf("\nVertex %s color %d",lessonArray[i],colorx[i]);
		
		if(colorx[i]>periodCount){ // kac periyod gerekli oldugunu buluyorum
		periodCount=colorx[i];	
		}
	}
	printf("\n");
    printf("\n");
     int j;
    for(i=0;i<=periodCount;i++){
		printf("Period %d : ",i);
		for(j=0;j<numberOfVertex;j++){
		
		if(colorx[j]==i){
			
			printf("%s ",lessonArray[j]);
		}		
	    }
		printf("\n");
	}	
	
}





