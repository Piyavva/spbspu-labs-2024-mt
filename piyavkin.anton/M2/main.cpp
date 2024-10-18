#include <iostream>
#include <map>
#include <functional>
#include "circle.hpp"
#include "commands.hpp"

int main()
{
  using namespace piyavkin;
  std::map< std::string, Circle > mp;
  std::map< std::string, std::function< void(std::istream&) > > cmd;
  cmd["circle"] = std::bind(inputCircle, std::placeholders::_1, std::ref(mp));
  std::string name;
  while (std::cin >> name)
  {
    try
    {
      cmd.at(name)(std::cin);
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
  }
  std::cout << mp["abc"].center_.x << mp["abc"].center_.y << mp["abc"].radius_;
}
