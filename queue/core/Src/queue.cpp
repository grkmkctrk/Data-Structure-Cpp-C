#include "../Inc/queue.hpp"


std::string operator*(std::string const &s, std::size_t n){
  std::string r;
  r.reserve(n * s.size());
  for (std::size_t i = 0; i < n; ++i)
    r += s;
  return r;
}