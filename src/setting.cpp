#include <cstdio>
#include <cstring>

#include <iostream>

#include "../headers/setting.h"

DIAGAMES::Setting::Setting(){

  DIAGAMES::Setting::win_width  = 1366;
  DIAGAMES::Setting::win_height = 768;

  DIAGAMES::Setting::fileName = (char*)"setting.txt";
}

DIAGAMES::Setting::Setting(char* fileN){

  DIAGAMES::Setting::fileName = fileN;
  char buffer[256];
  int bufferInt;
  int lineBuffer = 0;
  fpos_t pos;

  DIAGAMES::Setting::file = fopen(fileN, "r");

  while(1){
    ++lineBuffer;

    if(fscanf(DIAGAMES::Setting::file, "%s %d", buffer, &bufferInt) == EOF) break;
    
    if(strcmp(buffer, "width") == 0)
      DIAGAMES::Setting::win_width = bufferInt;
    else if(strcmp(buffer, "height") == 0)
      DIAGAMES::Setting::win_height = bufferInt;
    else
      std::cout << "[WARNING READ SETTING FILE line -> (" << lineBuffer << ")] Unknow argument" << std::endl; 
  }

  fclose(DIAGAMES::Setting::file);
}

char* DIAGAMES::Setting::getFileName(){
  return DIAGAMES::Setting::fileName;
}

void DIAGAMES::Setting::write(){
  DIAGAMES::Setting::file = fopen(DIAGAMES::Setting::fileName, "w");

  fprintf(DIAGAMES::Setting::file, "width %d\n", DIAGAMES::Setting::win_width);
  fprintf(DIAGAMES::Setting::file, "height %d\n", DIAGAMES::Setting::win_height);

  fclose(DIAGAMES::Setting::file);
}
