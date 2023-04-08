#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include "BusNode.h"
#include "Entity.h"
#include <unordered_map>

class ResourceManager : public BusNode
{
    public:
        ResourceManager();
        ResourceManager(EventBus * bus);
        void createTexture(TextureRect * givenRect);
        void loadRect(TextureRect* givenRect);
        void addTexture(TextureRect* rectangle);
        void update();
        void loadEntities(int level);
    protected:
        void onNotify(SDL_Event event);
        void flushRect();
    private:
        SDL_Texture * loadedTextures[TEXTURE_ARRAY_SIZE+1];
        std::vector<TextureRect *> loadedRectangles;
        std::vector<Entity> entities;
};


#endif
