#include "vPlayer_sdl2.h"



//main函数中的参数不能省略，不然会报错
int main(int args, char *argv[])
{
  
  char *filePath = "../data/Iron_Man-Trailer_HD.mp4";
  vPlayer_sdl2(filePath);

  return 0;
}
