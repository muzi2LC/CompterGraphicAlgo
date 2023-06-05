#include"drawLine.h"
#include"global.h"
#include"drawPix.h"
#include<glad/glad.h>
#include<glfw/glfw3.h>
#include<iostream>


int renderLine()
{

    glfwInit();

    //forbid screen size change
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnCG", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    int windowWidth, framebufferWidth;
    glfwGetWindowSize(window, &windowWidth, nullptr);
    glfwGetFramebufferSize(window, &framebufferWidth, nullptr);

    float pixelWidth = static_cast<float>(windowWidth) / static_cast<float>(framebufferWidth);

    while (!glfwWindowShouldClose(window))
    {
        //render loop
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        
        glOrtho(-SCR_WIDTH/ 2, SCR_WIDTH / 2, -SCR_HEIGHT / 2 , SCR_HEIGHT / 2, -1, 1);
        //don't why bias -4
        glMatrixMode(GL_MODELVIEW); 
        glLoadIdentity();
        glTranslatef(-4.0, -4.0, 0);


        drawBackGroundWhite();
        
        for (int i = -50; i <= 50; i++)
        {
            drawPixRed(i, i);
            drawPixRed(i, -i);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();

    return 0;
}