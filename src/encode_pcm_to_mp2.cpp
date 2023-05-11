#include "../include/encode_pcm_to_mp2.h"

/* check that a given sample format is supported by the encoder */
static int check_sample_fmt(const AVCodec *pCodec, enum AVSampleFormat sample_fmt)
{

}

/* just pick the highest supported samplerate */
static int select_sample_rate(const AVCodec *pCodec)
{

}

/* select layout with the highest channel count */
static int select_channel_layout(const AVCodec *codec)
{

}

static void encode(AVCodecContext* pCodecCtx, AVFrame *pFrame, AVPacket* pPacket, FILE* p_output_f)
{

}

int encode_pcm_to_mp2(const char* output_filepath)
{
    
}
