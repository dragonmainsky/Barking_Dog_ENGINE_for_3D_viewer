#include "camera.h"
bool isIsometric_move = false;
Camera::Camera(int width, int height, glm::vec3 position)
    : width(width), height(height), Position(position) {}

void Camera::UpdateMatrix(float nearPlane, float farPlane, bool isIsometric) {
    glm::mat4 view = glm::lookAt(Position, Position + Orientation, Up);
    glm::mat4 projection;

    if (isIsometric) {
        float scale = Fov / (float)std::min(width, height);
        projection = glm::ortho(-width * scale, width * scale, -height * scale, height * scale, -1000.0f, 1000.0f);
        isIsometric_move = true;
    } else {
        projection = glm::perspective(glm::radians(Fov), static_cast<float>(width) / height, nearPlane, farPlane);
        isIsometric_move = false;
    }

    cameraMatrix = projection * view;
}

void Camera::Matrix(Shader& shader, const char* uniform)
{
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
}

void Camera::Inputs(GLFWwindow* window)
{
    // Handle key inputs for movement
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
         if (isIsometric_move) {
            Position += speed * Up;
         }
         else {
            Position += speed * Orientation;
         }
         
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        Position += speed * -glm::normalize(glm::cross(Orientation, Up));
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        if (isIsometric_move) {
            Position += speed * -Up;
        }
        else {
            Position += speed * -Orientation;
        }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        Position += speed * glm::normalize(glm::cross(Orientation, Up));
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        Position += speed * Up;
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
        Position += speed * -Up;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        speed = 0.04f;
    else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
        speed = 0.01f;

    // Handle mouse inputs for looking around
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

        if (firstClick)
        {
            glfwSetCursorPos(window, width / 2, height / 2);
            firstClick = false;
        }

        double mouseX, mouseY;
        glfwGetCursorPos(window, &mouseX, &mouseY);

        float rotX = sensitivity * static_cast<float>(mouseY - height / 2) / height;
        float rotY = sensitivity * static_cast<float>(mouseX - width / 2) / width;

        yaw += rotY;
        pitch -= rotX;

        // Constrain pitch
        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;

        updateOrientation();

        glfwSetCursorPos(window, width / 2, height / 2);
    }
    else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        firstClick = true;
    }
}

void Camera::updateOrientation()
{
    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    Orientation = glm::normalize(front);
}
void Camera::ProcessScroll(float yoffset) {
    Fov -= yoffset * zoomSpeed;
    if (Fov < 1.0f)
        Fov = 1.0f;
    if (Fov > 45.0f)
        Fov = 45.0f;
}
