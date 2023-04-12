#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include "BusNode.h"

class ResourceManager : public BusNode
{
    public:
        ResourceManager();
        ResourceManager(EventBus * bus);
        void update();
    protected:
        void onNotify(SDL_Event event);
        void flushRect();
        void setTexture(TextureRect* event);
        void saveTexture(TextureRect* event);
    private:
        SDL_Texture * loadedTextures[TEXTURE_ARRAY_SIZE+1];
        std::vector<TextureRect *> loadedRectangles;
};


#endif
