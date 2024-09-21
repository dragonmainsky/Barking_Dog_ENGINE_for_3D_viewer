# Barking Dog ENGINE 3D viewer (Early Access)

<br />
<div align="center">
    <img src="https://github-production-user-asset-6210df.s3.amazonaws.com/127975405/369618602-f5ee7a2c-9442-4280-89e7-3a88ac6ee64a.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAVCODYLSA53PQK4ZA%2F20240921%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20240921T123836Z&X-Amz-Expires=300&X-Amz-Signature=fb79b43950ff91f845e0d72f537488c8f3497da70ce50bfce2073a5358c8e590&X-Amz-SignedHeaders=host">
</div>


## Features

- **ImGui Integration:** UI for model importing, zooming, docking and etc.
- **Model Loading:** Load 3D models and textures with automatic texture management.
- **Skybox Rendering:** Render 3D environments using skyboxes.

## Requirements
- **OpenGL 4.6** or later

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/barking-dog-engine.git
    cd barking-dog-engine
    ```

3. Build the project:
      ```bash
      mingw32-make run
      ```

4. Run the application:
    ```bash
    ./main.exe
    ```


## Usage

1. **Loading Models:** 
   You can load models through the ImGui interface. (glTF)

3. **Zooming:**
   Use the scroll wheel or ImGui zoom controls to adjust the scene view.
   
**Features: animation, other Types of 3D File Formats and other features are being developed**


## Acknowledgments

- [GLFW](https://www.glfw.org/)
- [Dear ImGui](https://github.com/ocornut/imgui)
