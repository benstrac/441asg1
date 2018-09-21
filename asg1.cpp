/*******************************************************************/
/**/


#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define LENGTH 100
#define FILENAME "test.html"
#define NUMERR 3

char* parseTag(char* tag, char* data);
int parseText(char*);
char* editText(char*);
 
int main(){
  int errsInserted = 0;
  char data[LENGTH];
  char* pch;
  fstream myFile;
  
  myFile.open(FILENAME);
  
  if(myFile.is_open()){
      cout << "open successful\n";

      int j = 0;
      while(true){
	
	char data1[LENGTH];
	char data2[LENGTH];

	//get line from html file
	//	myFile.getline(data1, LENGTH);

	
	//check if at eof
	if(data1[j] == '\0')
	  break;	  
	/*
	else if(data1[j] == '<'){
	  parseTag(tag, data1);
	  cout << tag;
	}
	else
	  if(parseText(data1) == 1)
	    errsInserted++;
	*/
	
	if(strcmp(tag, "<h1>")!=0 || strcmp(tag, "<h2>")!=0 || strcmp(tag, "<p>")!=0){
	  if(NUMERR != 0){
	    //get text between tags into data2
	    for(int i=0;data1[j]!='<';i++,j++){
	      data2[i] = data1[j];
	    }
	    //
	    
	  } 
	}
	//end of while loop
      }
      myFile.close();
  }
  
  return 0;
}


char* parseTag(char* tag, char* data){

}

int parseText(char* data){

}

char* editText(char* data){

}
