# Getting started with OpenCL on Arch
Steps will be provided to obtain a minimal and productive environment.

## Installation
First update your system. Open your favorite shell in your favorite terminal and run:

``` bash
sudo pacman -Syu
sudo pacman -S git cmake opencl-headers opencl-nvidia opencl-clhpp
```

these are the some relavent packages I had while testing, I'm not sure whether you need `cuda` for this!
- extra/cuda 12.2.0-1 [installed]
- extra/ocl-icd 2.3.2-1 [installed]
- extra/opencl-clhpp 2023.04.17-1 [installed]
- extra/opencl-headers 2:2023.04.17-2 [installed]
- extra/opencl-nvidia 535.104.05-1 [installed]
- extra/cmake 3.27.5-1 [installed]

## Building
```bash
git clone <repo>
mkdir build && cd build
cmake ..
make 
./HelloOpenCL
```
##### output
```bash
❯ make && ./HelloOpenCL
[100%] Built target HelloOpenCL
Number of openCL devices= 1
Device 0 :
Platform Name = NVIDIA CUDA, Platform Version = OpenCL 3.0 CUDA 12.2.138
```

you can perform `ccmake` to see all PATHS are valid!

## Additional reference
- [ubuntu guide](https://github.com/KhronosGroup/OpenCL-Guide/blob/main/chapters/getting_started_linux.md). 
- [nvidia-examples](https://developer.nvidia.com/opencl) - outdated examples!
- [Helloworld in using visual studio](https://github.com/ibrahimsenan/OpenCl-HelloWorld.git) 

