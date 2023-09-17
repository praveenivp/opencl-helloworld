#include<CL/opencl.hpp>
#include<iostream>
//#include <fstream>
#include <vector>

int main() 
{
    std::vector<cl::Platform> platforms;
    cl::Platform::get(&platforms);

   for (auto platform:platforms)
   {
    std::vector<cl::Device> devices;
    platform.getDevices(CL_DEVICE_TYPE_ALL, &devices);
    std::cout<<"Number of openCL devices= "<<devices.size() <<std::endl;

    uint32_t currentDevice=0;
    for (auto device : devices)
    {
    std::cout<<"Device "<<currentDevice++ <<" :\n";
    bool bPassed = true;
    std::string sProfileString = "Platform Name = ";

    // Get OpenCL platform ID for NVIDIA if avaiable, otherwise default
    char cBuffer[1024];
    cl_platform_id clSelectedPlatformID = NULL; 
    cl_uint numPlat=0;

    cl_int ciErrNum = clGetPlatformIDs(1,&clSelectedPlatformID,&numPlat);

    // Get OpenCL platform name and version
    ciErrNum = clGetPlatformInfo (clSelectedPlatformID, CL_PLATFORM_NAME, sizeof(cBuffer), cBuffer, NULL);
    if (ciErrNum == CL_SUCCESS)
    {
        sProfileString += cBuffer;
    } 
    bPassed=bPassed & (ciErrNum==CL_SUCCESS);
    sProfileString += ", Platform Version = ";
    ciErrNum = clGetPlatformInfo (clSelectedPlatformID, CL_PLATFORM_VERSION, sizeof(cBuffer), cBuffer, NULL);
    if (ciErrNum == CL_SUCCESS)
    {
        sProfileString += cBuffer;
    } 
    bPassed=bPassed & (ciErrNum==CL_SUCCESS);
    std::cout<<(bPassed?sProfileString:"Some error occured")<<std::endl;
    }//device loop
   }//platforms loop


    // test small vector addition
}