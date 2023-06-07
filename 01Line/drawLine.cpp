#include"drawLine.h"
#include"drawPix.h"
#include<glad/glad.h>
#include<glfw/glfw3.h>
#include<iostream>
#include<vector>

const int SCR_WIDTH = 808;
const int SCR_HEIGHT = 808;
const int PIX_SIZE = 8;
void MidPoint_algo(int x0, int y0, int x1, int y1);
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
        
        glOrtho(0, SCR_WIDTH , 0,SCR_HEIGHT , -1, 1);

        Pix::init(PIX_SIZE, SCR_WIDTH);
        for (int i = 0; i < SCR_WIDTH/PIX_SIZE; i++)
        {
            for (int j = 0; j < SCR_HEIGHT/PIX_SIZE; j++)
            {
                Pix pix(i, j);
                pix.drawWhite();
                pix.drawBlack_Boundary();
            }
        }
        for (int i = 0; i < SCR_WIDTH / PIX_SIZE; i++)
        {
            Pix pix(i, i);
            pix.drawRed();
        }
        MidPoint_algo(1,2, 7, 6);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();

    return 0;
}
double func(double x, double y, double x0, double y0, double x1, double y1)
{
    return (y0 - y1) * x + (x1 - x0) * y + x0 * y1 - x1 * y0;
}
void MidPoint_algo(int x0, int y0, int x1, int y1)
{
    double d = func(x0 + 1, y0 + 0.5, x0, y0, x1, y1);
    int y = y0;
    for (int x = x0; x <= x1; x++)
    {
        Pix pix(x, y);
        pix.drawRed();
        if (d < 0)
        {
            y = y + 1;
            d = d + (x1 - x0) + (y0 - y1);
        }
        else
        {
            d = d + (y0 - y1);
        }
    }
}