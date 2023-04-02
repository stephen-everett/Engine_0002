#OBJS specifies which files to compile as part of the project
#OBJS = 02_getting_an_image_on_the_screen.cpp
#OBJS =	./src/Main.cpp ./src/RenderSystem.cpp
OBJS = ./src/Main.cpp ./src/EventBus.cpp ./src/BusNode.cpp ./src/RenderSystem.cpp ./src/Map.cpp ./src/Entity.cpp ./src/ResourceManager.cpp ./src/Button.cpp
#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -I/home/l0fi/Documents/SDL2/Engine_0002/includes/

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image

#OBJ_NAME specifies the name of our exectuable
#OBJ_NAME = tutorial
OBJ_NAME = ./bin/Main.exe

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
