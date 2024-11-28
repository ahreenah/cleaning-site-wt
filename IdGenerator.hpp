#pragma once
class IdGenerator{
  static int currentId;
  public:
  static int getId(){
    IdGenerator::currentId ++;
    return IdGenerator::currentId;
  }
};
int IdGenerator::currentId = 0;
