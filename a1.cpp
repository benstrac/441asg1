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
  queue <char*> data;
  char* pch;
  
  fstream stream (FILENAME);
  //  outFile.open("output.html");
  
  if(stream.is_open()){
      cout << "open successful\n";

      stream.seekg(0, stream.end);
      int length = stream.tellg();
      stream.seekg(0, stream.beg);

      char* buffer = new char[length];
      
      stream.read(buffer, length);
      int tagL = strcspn(buffer, "<");
      //      cout << length << "\n";
      //      cout << buffer << "\n";
      char* lines = new char[stream.gcount()];
      for(int i=0;!stream.eof() && i<=stream.gcount();i++){
      int tagR = strcspn(buffer, ">");
	
      }
      
      delete[] buffer;
      
      /*
      inFile.getline(line, LENGTH);
      while(line[strlen(line)-1] != '\0'){
	pch = strtok(line, "<*>");
	cout << pch << "\n";
	for(int i=0;pch != NULL;i++){
	  data.push(pch);
	  printf("%s\n", data.front());
	  pch = strtok(NULL, "<>");
	}

	cout << data.front() << '\n';
	
	if(strcmp(data.front(), "<h1>")!=0 || strcmp(data.front(), "<h2>")!=0 || strcmp(data.front(), "<p>")!=0){
	  if(ERRORS != 0){
	    //get text between tags into line2
	    liner = data.front();
	    //	    cout << line << '\n';
	    data.pop();
	  }else
	    break;
	}
	inFile.getline(line, LENGTH);
      }
      */
      stream.close();
  }else
    cout << "open unsuccessful\n";  
  
  return 0;
}

