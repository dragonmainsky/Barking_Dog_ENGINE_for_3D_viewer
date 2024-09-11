SRC := $(wildcard ../src/*.cpp ../include/shader/*.cpp ../src/glad.c ../include/imgui/*.cpp ../include/read_and_make_file/*.cpp)
OBJ := $(SRC:.cpp=.o)
OBJ := $(OBJ:../src/%.o=../src/%.o)  # Adjust paths to match directory structure
OBJ := $(OBJ:../include/shader/%.o=../include/shader/%.o)
OBJ := $(OBJ:../include/imgui/%.o=../include/imgui/%.o)
OBJ := $(OBJ:../include/read_and_make_file/%.o=../include/read_and_make_file/%.o)

CXX := g++
CXXFLAGS := -I../include --std=c++17 -L../lib -w
LIBS := -lglfw3dll -lopengl32  # Removed dll reference

.PHONY: all clean package

all: main

main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o Barking_Dog_ENGINE_for_3D_viewer.exe $^ $(LIBS)
	@if not exist "Resources\shader" mkdir Resources\shader
	@if not exist "Resources\skybox" mkdir Resources\skybox
	xcopy /E /I ..\src\Resources Resources
	@echo "Build successful!"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: main
	./Barking_Dog_ENGINE_for_3D_viewer.exe

clean:
	del /Q /F $(OBJ)

package: main
	@if not exist "Barking_Dog_ENGINE\shader" mkdir Barking_Dog_ENGINE\shader
	@if not exist "Barking_Dog_ENGINE\Resources" mkdir Barking_Dog_ENGINE\Resources
	copy Barking_Dog_ENGINE_for_3D_viewer.exe Barking_Dog_ENGINE
	copy ..\lib\*.dll Barking_Dog_ENGINE
	xcopy /E /I ..\src\Resources Barking_Dog_ENGINE\Resources
	@echo "Packaging successful!"


