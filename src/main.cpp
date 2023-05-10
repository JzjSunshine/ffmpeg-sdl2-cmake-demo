#include <SDL.h>

extern "C"
{
#include <libavformat/avformat.h>
}

void printHelpMenu(const char *name)
{
    printf("Invalid arguments.\n");
    printf("Usage: %s path-to-media-file. \n", name);
}

int main()
{
    // if (!(argc > 1))
    // {
    //     printHelpMenu(argv[0]);
    //     return -1;
    // }

    const char *filename = "/home/jzj/home/localWork/cppWordDir/ffmpeg-video-player/Iron_Man-Trailer_HD.mp4";
    printf("Opening file %s\n", filename);

    // need this for ffmpeg 3.x
    av_register_all();

    AVFormatContext *pFormatCtx = NULL;
    int ret = avformat_open_input(&pFormatCtx, filename, NULL, NULL);
    if (ret < 0)
    {
        printf("Could not open file %s.\n", filename);
        return -1;
    }

    printf("Opened the file!!!!\n");
    return 0;
}