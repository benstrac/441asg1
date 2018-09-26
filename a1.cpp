/*******************************************************************/
/**/


#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

#define DOCLEN 999999
#define LENGTH 100
#define FILENAME "test.html"
#define ERRORS 3

void shiftBuffer(char*, int);

int main(){
  int errsInserted = 0;
  vector <char*> lines = {""};
  vector <int> content;
    
  fstream stream (FILENAME);
  //  outFile.open("output.html");
  
  if(stream.is_open()){
      cout << "open successful\n";

      // find doc length
      stream.seekg(0, stream.end);
      int length = stream.tellg();
      stream.seekg(0, stream.beg);

      // init buffer for doc
      char* buffer = new char[length];
      stream.read(buffer, length);

      // PARSE LOOP
      while(strlen(buffer)>0){
	int tagL = strcspn(buffer, "<");
	int newL = strcspn(buffer, "\n");
	char temp[strlen(buffer)];
	
	// parse to next '<'
	if(tagL == 0){
	  int tagR = strcspn(buffer, ">")+1;
	  strncpy(temp, buffer, tagR);
	  cout << temp << "\n";
	  temp[tagR] = '\0';
	  lines.push_back(temp);
	  
	  shiftBuffer(buffer, tagR);

	// parse if next char'\n'
	}else if(newL == 0){
	  strncpy(temp, buffer, 1);
	  temp[1] = '\0';
	  lines.push_back(temp);
	  shiftBuffer(buffer, 1);

	// parse content to '\n'
	}else if(newL < tagL){
	  strncpy(temp, buffer, newL);
	  temp[newL] = '\0';
	  cout << temp << "\n";
	  lines.push_back(temp);
	  shiftBuffer(buffer, newL);
	
	// parse content
	}else{
	  strncpy(temp, buffer, tagL);
	  temp[tagL] = '\0';
	  cout << temp << "\n";
	  lines.push_back(temp);	
	  shiftBuffer(buffer, tagL);

	  /* add line num to content vector*/
	}
	//	cout << temp;
	//	cout << lines[ ];
	//      cout << lines.back(); 
	//      cout << lines.size();
      }
      //	cout << lines[0];
      while(lines.size()>0){
	cout << lines.back();
	lines.pop_back();
	cout << lines.size();
      }

      delete[] buffer;
      
      //      cout << "here\n";

      stream.close();
  }else
    cout << "open unsuccessful\n";  
  
  return 0;
}

void shiftBuffer(char* buffer, int shift){
  for(int i=0;i<strlen(buffer)-shift;i++){
    buffer[i] = buffer[i+shift];
  }
  buffer[strlen(buffer)-shift] = '\0';
  return;
}
