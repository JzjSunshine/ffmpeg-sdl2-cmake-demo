#include "output_log.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define __STDC_CONSTANT_MACROS
extern "C"
{
  #include <libavcodec/avcodec.h>
  #include <libavutil/opt.h>
  #include <libavutil/imgutils.h>
}
static void encode(AVCodecContext* pCodecCtx, AVFrame *pFrame, AVPacket* pPacket, FILE* p_output_f);

//codec_name="libx264"
int encode_yuv_to_h264(const char* output_filePath);

