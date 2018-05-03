/*Ali Ozturk - 150114061*/

#ifndef generalLibrary
#define generalLibrary

typedef struct lesson
{
    char name[42];
	char lesson[42];
    int vertexNumber;	
}lesson;


void preProccesing(char fileName[42]);
int controlName(char data[42]);
void readFile(char fileName[42]);
void addVertexNumber(lesson *);


#endif