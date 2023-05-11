#include "output_log.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern "C"
{
  #include <libavcodec/avcodec.h>
  #include <libavutil/channel_layout.h>
  #include <libavutil/common.h>
  #include <libavutil/frame.h>
  #include <libavutil/samplefmt.h>
}
/* check that a given sample format is supported by the encoder */
static int check_sample_fmt(const AVCodec *pCodec, enum AVSampleFormat sample_fmt);

/* just pick the highest supported samplerate */
static int select_sample_rate(const AVCodec *pCodec);

/* select layout with the highest channel count */
static int select_channel_layout(const AVCodec *codec);

static void encode(AVCodecContext* pCodecCtx, AVFrame *pFrame, AVPacket* pPacket, FILE* p_output_f);

int encode_pcm_to_mp2(const char* output_filepath);

