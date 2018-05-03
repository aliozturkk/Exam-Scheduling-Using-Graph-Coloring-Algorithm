/*Ali OZTURK - 150114061*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "generalLibrary.c"
#include "generalLibrary.h"
#include "graphLibrary.h"
#include "graphLibrary.c"

int main(){
	
	//raed file
	readFile("input.txt");
	
	//create a lesson array
	char lessonArray[numberOfVertex][10];
	int i;
	for(i=0;i<numberOfVertex;i++)
	{
		int j;
		for(j=0;j<countLesson;j++)
		{			
			if(less[j].vertexNumber==i)
			{
				strcpy(lessonArray[i],less[j].lesson);
				break;
			}				
		}			
	}
	
	
	// Create a Graph
	struct Graph* graph = createGraph(numberOfVertex);	
	buildGraph(graph,less,countLesson);
	
	printGraph(graph,lessonArray);
	
	printf("DFS for 4 :\n");
	DFS(graph, 4);
	printf("\n");
	
	coloringGraph(graph,lessonArray);
    printf("\n");
	
	
	return 0;
}