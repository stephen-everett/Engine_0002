#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include "BusNode.h" 

class ResourceManager : public BusNode
{
    public:
        ResourceManager();
        ResourceManager(EventBus * bus);
        void createTexture(TextureRect * givenRect);
        void loadRect(TextureRect* givenRect);
        void update();
    protected:
        void onNotify(SDL_Event event);
    private:
        SDL_Texture * loadedTextures[TEXTURE_ARRAY_SIZE+1];
        std::vector<TextureRect *> loadedRectangles;
};


#endif
