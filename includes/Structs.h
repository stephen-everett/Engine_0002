#ifndef STRUCTS_H
#define STRUCTS_H

#include <vector>

struct staticAsset
{
    int h;
    int w;
    int x;
    int y;
    const char* path;
};
struct dynamicAsset
{
    int h;
    int w;
    int x;
    int y;
    const char* path;
};
struct level
{
    const char* name;
    //std::vector<staticAsset> staticAssets;
   // std::vector<dynamicAsset> dynamicAssets;
    staticAsset background;
    int h;
    int w;

};
#endif
