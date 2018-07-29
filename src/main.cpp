#include <iostream>

#include "../headers/setting.h"

/*
 * Examples usage
 */

int main(){ 

  DIAGAMES::Setting setting((char*)"setting.txt");

  std::cout << "width " << setting.win_width << std::endl;
  std::cout << "height " << setting.win_height << std::endl;

  setting.win_width = 1366;
  setting.win_height = 768;

  setting.write();

  return 0;
}
