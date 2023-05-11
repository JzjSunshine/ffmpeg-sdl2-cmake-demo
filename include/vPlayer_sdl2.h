extern "C" {
  #include <stdio.h>
  #include "libavcodec/avcodec.h"
  #include "libavformat/avformat.h"
  #include "libswscale/swscale.h"
  #include <libavutil/imgutils.h>
  #include <libswresample/swresample.h>
  #include <libavutil/mathematics.h>
  #include <libavutil/timestamp.h>

}
#include "SDL.h"

typedef struct FFmpeg_V_Param_T
{
  AVFormatContext *pFormatCtx;
  AVCodecContext *pCodecCtx;
  SwsContext *pSwsCtx;
  int video_index;
  int audio_index;
}FFmpeg_V_Param;

typedef struct SDL_Param_T
{
  SDL_Window *p_sdl_window;     // 窗口
  SDL_Renderer *p_sdl_renderer; // 渲染器
  SDL_Texture *p_sdl_texture;   // 
  SDL_Rect sdl_rect;            // 矩形
  SDL_Thread *p_sdl_thread;     // 刷新线程
}SDL_Param;


static int g_frame_rate = 1; // 每隔多长时间刷新一次
static int g_sfp_refresh_thread_exit = 0;  //退出开关
static int g_sfp_refresh_thread_pause = 0; //暂停播放开关

#define SFM_REFRESH_EVENT (SDL_USEREVENT+1)
#define SFM_BREAK_EVENT (SDL_USEREVENT+2)

int init_ffmpeg(FFmpeg_V_Param *p_ffmpeg_param, char *filePath);
/*
  return value:zero(success) non-zero(failure)
*/
int release_ffmpeg(FFmpeg_V_Param *p_ffmpeg_param);
/*
刷新线程
*/
int sfp_refresh_thread(void *opaque);

int init_sdl2(SDL_Param_T *p_sdl_param, int screen_w, int screen_h);

int release_sdl2(SDL_Param_T *p_sdl_param);

int vPlayer_sdl2(char *filePath);

