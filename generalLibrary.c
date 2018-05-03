/*Ali OZTURK - 150114061*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include "generalLibrary.h"

int countLesson;
lesson *less;

int numberOfVertex;

void preProccesing(char fileName[42]){
	
	FILE *file;
	FILE *file2;
	file = fopen(fileName,"r");
	file2 = fopen("input2.txt","a");
		
	countLesson=0;
    char dataBox[120];
    while(fscanf(file,"%s",dataBox)!=EOF)
	{   	     		
	        int i;
			for(i=0;dataBox[i]!=0;i++)
			{								
				if( (dataBox[i]==58 || dataBox[i]==44))
				{					
				dataBox[i]=32;
				countLesson++;				
				}						
			}				
            fprintf(file2," %s",dataBox);
	}		
	
		fclose(file);
		fclose(file2);
				
}

void readFile(char fileName[42]){
	
	
	preProccesing(fileName);
	
	FILE *file;
	file = fopen("input2.txt","r");
	lesson lessonlist[countLesson];
		
	char dataBox[40];
	char studentName[42];
	int lessonCounter=0; // for augment lessonlist
	int otherStudent=1; // for determine be time for another student
	
    while(fscanf(file,"%s",dataBox)!=EOF)
	{   
	     		
	        int i;					
			int choice=0; //databox equal name? or lesson?
			
			for(i=0;dataBox[i]!=0;i++)	
			{
				if(48<=dataBox[i] && 57>=dataBox[i]){ // if databox contain a number , it is lesson
									
					choice=1;
					break;
				}							
			}
								
			 if(choice==0)  { 
			 			   
					if(otherStudent==1)
					{
					strcpy(studentName,dataBox);
                    otherStudent=0;	
                  	
					}else{
					strcat(studentName,dataBox);
					}
										
	        }else{
					strcpy(lessonlist[lessonCounter].name,studentName);
					strcpy(lessonlist[lessonCounter].lesson,dataBox);
					lessonlist[lessonCounter].vertexNumber=-1;
					lessonCounter++;
					otherStudent=1;
				otherStudent=1;
			}		
          
	}					
		fclose(file);
	
	remove("input2.txt");
	
    addVertexNumber(lessonlist);
	less=lessonlist;
	
}

void addVertexNumber(lesson *lessonlist){
	
	int i;
	int j;
	int a=-1;
	int count;
	for(i=0;i<countLesson;i++)
	{	

       if(lessonlist[i].vertexNumber==-1){
		   a++;
		   
	   }
		for(j=0;j<countLesson;j++){
			
			if(strcmp(lessonlist[i].lesson,lessonlist[j].lesson)==0 && lessonlist[j].vertexNumber==-1){
		    lessonlist[j].vertexNumber=a;
				
			}	
		}
		
	}
	numberOfVertex = a+1;
	
	
}






