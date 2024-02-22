#ifndef DDMIN_H
#define DDMIN_H

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>

namespace ddmin
{
  template <class T>
  using func_ptr = bool(*)(std::vector<T>&);


template <class T>
std::vector<T> without(std::vector<bool> m, std::vector<T> &input, int from, int to)
{
  std::vector<T> out;
  for(uint32_t i = 0; i < from; i++)
  {
    if(m[i])
      out.push_back(input[i]);
  }
  for(uint32_t i = to; i < input.size(); i++)
  {
    if(m[i])
      out.push_back(input[i]);
  }
  return out;
}

void remove(std::vector<bool> &out, int from, int to);

template <class T>
std::vector<bool> ddminMus(std::vector<T> &s, func_ptr<T> check_func)
{
  std::uint32_t n_checks{0};
  const std::size_t size_s = s.size();
  // List of lines: false: line got removed 
  std::vector<bool> m; 
  for(uint32_t i = 0; i < size_s; i++)
  {
    m.push_back(true);
  }

  std::size_t w = s.size();
  while(s.size() != 0) // Corner Case for empty input
  {
    std::size_t n = (std::size_t)std::ceil(s.size() / (double)w);
    std::cout << "n=" << n << std::endl;
    // Loop through the subsets:
    for(uint32_t i = 0; i < n; i++)
    {
      auto m_without_sub = ddmin::without(m, s, i * w, i * w + w);
      n_checks++;
      // Skip if (M without Si) is empty
      if(!check_func(m_without_sub)) 
      {
        std::cout << "Remove: from " << (i*w) << " to " << (i*w+w) << std::endl;
        ddmin::remove(m, i * w, i * w + w);
      }
      std::cout << "m.size: " << m.size() << std::endl;
      std::cout << "n: " << n << std::endl;
      std::cout << "n_checks: " << n_checks << std::endl;
    }
    if (w == 1){break;}
    w = (std::size_t)std::ceil(w / 2.0);
  }
  std::cout << "n_checks" << n_checks << std::endl;
  return m;
}
}
#endif
