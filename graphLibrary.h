
/*
Ali Ozturk - 150114061
*/

#ifndef graphLibrary
#define graphLibrary

struct node
{
    int vertex;
	char data[42];
    struct node* next;
};

struct node* createNode(int v,char *);

struct Graph
{
    int numVertices;
    int* visited;
	struct node *vertx;
    struct node** adjLists; // we need int** to store a two dimensional array. Similary, we need struct node** to store an array of Linked lists
 
};

struct Graph* createGraph(int );
void addEdge(struct Graph*, int, int,char *,char *);
void printGraph(struct Graph*,char lessonArray[numberOfVertex][10]);
void DFS(struct Graph*, int);
int controlEdge(struct Graph* ,int ,int );
void buildGraph(struct Graph* graph,lesson *lessonlist,int countLesson);
void colorGraph(struct Graph* graph,char lessonArray[numberOfVertex][10]);
#endif