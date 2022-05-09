#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
using namespace std;

const string BASE_PATH = "E:\\programs\\MinGW\\lib\\gcc\\x86_64-w64-mingw32\\8.1.0\\include\\c++\\";
void printFileContent(string, int);

int main() {
  printFileContent("string", 1);
  return 0;
}

void printFileContent(string path, int deep_time = 0) {
  ifstream fs(BASE_PATH + path);
  char line[256];
  string lineStr;
  regex includeReg("#include <(.*?)>.*?");
  smatch matchResult;

  if(deep_time == 0) {
    cout<<"end!"<<endl;
    return;
  }

  if (!fs.is_open()) {
    cout<<"file open failed!"<<endl;
    return;
  }

  while (!fs.eof())
  {
    fs.getline(line, 100);
    lineStr = string(line);
    if (regex_match(lineStr, matchResult, includeReg)) {
      if (deep_time <= 0) {
        cout<<"file name: "<<matchResult[1]<<endl;
      } else {
        cout<<"========open file: "<<matchResult[1]<<"============="<<endl;
        printFileContent(matchResult[1], deep_time - 1);
        cout<<"====================================================="<<endl;
      }
    } else {
      cout<<lineStr<<endl;
    }
  }
}
