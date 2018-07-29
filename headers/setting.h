#include <cstdio>

namespace DIAGAMES{

  class Setting{

    private:
      FILE *file;
      char* fileName;

      void read();

    public:
      Setting();
      Setting(char* fileN);

      unsigned int win_height;
      unsigned int win_width;

      char* getFileName();
      void  setFileName(char* fileN);

      void write();
  };
}
