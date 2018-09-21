/*******************************************************************/
/**/


#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;

#define DOCLEN 999999
#define LENGTH 100
#define FILENAME "test.html"
#define ERRORS 3

int main(){
  int errsInserted = 0;
  char* line;
  queue <char*> data;
  char* pch;
  ifstream inFile;
  ofstream outFile;
  
  inFile.clear();
  inFile.open(FILENAME);
  outFile.open("output.html");
  
  if(inFile.is_open()){
    //      cout << "open successful\n";

      inFile.getline(line, LENGTH);
      while(line[strlen(line)-1] != '\0'){
	pch = strtok(line, "<>");

	for(int i=0;pch != NULL;i++){
	  data.push(pch);
	  printf("%s\n", data.front());
	  pch = strtok(NULL, "<>");
	}

	//	cout << data.front() << '\n';
	
	if(strcmp(data.front(), "<h1>")!=0 || strcmp(data.front(), "<h2>")!=0 || strcmp(data.front(), "<p>")!=0){
	  if(ERRORS != 0){
	    //get text between tags into line2
	    line = data.front();
	    //	    cout << line << '\n';
	    data.pop();
	  }else
	    break;
	}
	inFile.getline(line, LENGTH);
      }
      inFile.close();
  }else
    cout << "open unsuccessful\n";  

  return 0;
}

