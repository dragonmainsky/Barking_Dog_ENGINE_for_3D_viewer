#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <shader/shaderClass.h>

class Camera
{
public:

    glm::vec3 Position;
    glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::mat4 cameraMatrix = glm::mat4(1.0f);

    int width;
    int height;

    bool firstClick = true;

    float speed = 0.01f;
    float sensitivity = 100.0f;
    float yaw = -90.0f;
    float pitch = 0.0f;
    float Fov = 45.0f; // Field of View
    float zoomSpeed = 1.0f; // Speed of zoom

    Camera(int width, int height, glm::vec3 position);

    void UpdateMatrix(float nearPlane, float farPlane, bool isIsometric);
    void Matrix(Shader& shader, const char* uniform);
    void Inputs(GLFWwindow* window);
    void ProcessScroll(float yoffset);
private:
    void updateOrientation();
};

#endif
