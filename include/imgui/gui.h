#ifndef GUI_CLASS_H
#define GUI_CLASS_H

#include <iostream>

#include <fstream> 
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "imfilebrowser.h"
#include <shader/Model.h>



class GUI
{
    public:
        const char *name;
        bool *draw;
        float *v;
        void window_ui(GLFWwindow* window);
        void title_box();
        void window_shutdown();
        void window_NewFrame();
        void Toolbox();
        void MenuBar();
        void RenderUI();
        void render_dockspace();
};

#endif