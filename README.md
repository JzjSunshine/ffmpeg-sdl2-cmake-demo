# ffmpeg-cmake-cpp

Simple empty project with a CMake config for using the FFmpeg library. Copypasta from:

https://github.com/AlmasB/SDL2-Demo/

https://github.com/katajakasa/SDL_kitchensink

# ubuntu

```bash
# ffmpeg 相关包安装
sudo apt install libavcodec-dev libavdevice-dev libavfilter-dev libavformat-dev libavresample-dev libavutil-dev

# sdl2 相关包安装
sudo apt-get install libsdl2-dev
```

with cmake

```bash
mkdir build
cd build
cmake ../
make
```

# demo分支
为空工程，仅验证 SDL2 和 ffmpeg安装和导入的正确性