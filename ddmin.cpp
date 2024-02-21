#include "ddmin.h"



void ddmin::remove(std::vector<bool> &out, int from, int to)
{
  for(uint32_t i = from; i < to; i++)
  {
    if(i < out.size())
    {
      out[i] = false;
    }
  }
}

