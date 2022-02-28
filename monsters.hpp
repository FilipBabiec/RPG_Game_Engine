#ifndef monsters_hpp
#define monsters_hpp
#include "templates.hpp"

using namespace std;

class Monster : public Template
{
public:
  int drop;
  Monster(string save);
  Monster(string save, string boss);
  ~Monster();
};

#endif