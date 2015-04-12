#ifndef PARSER_HPP
#define PARSER_HPP

#include<vector>
#include<string>
using namespace std;

class Square;

string const TO_LEVEL_FOLDER="../dat/levels/";


class Parser
/*
  Singleton used in order to load data from a file. One main method is read(file).
*/
{
public:
  virtual ~Parser();
  static Parser* getInstance(); 
  void createLevelFrom(string path,vector<Square*>* v, int* w, int* h);

protected:
  Parser();
  static Parser* m_self;
};

#endif // PARSER_HPP
