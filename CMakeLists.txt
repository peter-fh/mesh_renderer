cmake_minimum_required(VERSION 3.10)

project(LearnGL VERSION 1.0)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB LIB_SOURCES "lib/*.cpp")

add_executable(LearnGL src/main.cpp ${LIB_SOURCES})

include_directories(
	./include
	/opt/homebrew/Cellar/glew/2.2.0_1/include 
	/opt/homebrew/Cellar/glfw/3.4/include
	/opt/homebrew/Cellar/glm/1.0.1/include
	/opt/homebrew/Cellar/assimp/5.4.2/include
)

target_link_libraries(LearnGL
	/opt/homebrew/Cellar/glfw/3.4/lib/libglfw.dylib 
	/opt/homebrew/Cellar/glew/2.2.0_1/lib/libGLEW.dylib 
	/opt/homebrew/Cellar/glm/1.0.1/lib/libglm.dylib
	/opt/homebrew/Cellar/assimp/5.4.2/lib/libassimp.dylib
	/System/Library/Frameworks/OpenGL.framework
)
