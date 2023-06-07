#include"drawPix.h"
#include"global.h"
#include<exception>
#include<glad/glad.h>
#include<glfw/glfw3.h>
int Pix::PixSize = 8;
int Pix::Width = 800;
int Pix::Height = 800;
int Pix::maxPix = 100;
void Pix::init(int pixSize, int width)
{
    PixSize = pixSize;
    Width = width;
    Height = width;
    maxPix = width / pixSize;
    if (maxPix * PixSize != width)
    {
        throw "Error: pixSize and width is wrong";
    }
}
void Pix::draw(float r,float g, float b)
{
    if (x >= maxPix || y >= maxPix)
    {
        throw "Error: pix is out of range";
    }
    int x0 = x * PixSize;
    int y0 = y * PixSize;

    // Set the color
    glColor3f(r, g, b); 

    // Draw  points
    glBegin(GL_POINTS);
    for (int i = 0; i < PixSize; i++)
    {
        for (int j = 0; j < PixSize; j++)
        {
            glVertex2f(float(x0 + i)+0.5f, float(y0 + j)+0.5f);
        }
    }
    glEnd();
}
void Pix::drawRed()
{
    draw(1.0, 0.0, 0.0);
}
void Pix::drawBlack()
{
    draw(0.0, 0.0, 0.0);
}
void Pix::drawWhite()
{
    draw(1.0, 1.0, 1.0);
}
void Pix::drawRGB_Boundary(float r, float g, float b)
{
    int x0 = x * PIX_SIZE;
    int y0 = y * PIX_SIZE;
    glColor3f(r, g, b);
    glBegin(GL_POINTS);
    for (int i = 0; i < PIX_SIZE; i++)
    {
        glVertex2f((float)(x0 + i) + 0.5, float(y0 ) + 0.5);
        glVertex2f((float)(x0 + i) + 0.5, float(y0 + PIX_SIZE - 1) + 0.5);
        //glVertex2i(x0 + i, y0);
        //glVertex2i(x0 + i, y0 + PIX_SIZE - 1);
    }
    for (int i = 1; i < PIX_SIZE - 1; i++)
    {
        glVertex2f((float)(x0) + 0.5, float(y0 + i) + 0.5);
        glVertex2f((float)(x0+PIX_SIZE-1) + 0.5, float(y0 + i) + 0.5);
        //glVertex2i(x0, y0 + i);
        //glVertex2i(x0 + PIX_SIZE - 1, y0 + i);
    }
    glEnd();
}
void Pix::drawBlack_Boundary()
{
    drawRGB_Boundary(0.0, 0.0, 0.0);
}
void Pix::drawWhite_Boundary()
{
    drawRGB_Boundary(1.0, 1.0, 1.0);
}
