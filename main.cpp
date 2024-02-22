#include "ddmin.h"
#include <cstring>
#include <string>

/**
* Function Returns false if there is a bug in the input
*/
bool check(std::vector<char> input)
{
  // Convert the input to a char array:
  std::string str{""};
  for(auto el : input)
  {
    str += el;
  }
  if(strstr(str.c_str(),"AB") && strstr(str.c_str(),"CD"))
  {
    return false;
  }
  return true;
}

int main()
{
  std::vector<char> input {'X', 'A', 'B', 'X', 'X', 'C', 'D', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'};
  auto reduced = ddmin::ddminMus(input, (ddmin::func_ptr<char>)check);
  for(auto b : reduced)
  {
    std::cout << "Reduced: " << b << std::endl;
  }
  
  return 0;
}
