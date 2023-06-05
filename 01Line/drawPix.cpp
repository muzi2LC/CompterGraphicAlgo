#include"drawPix.h"
#include"global.h"
#include<exception>
#include<glad/glad.h>
#include<glfw/glfw3.h>
//int Pix::PixSize = 8;
//int Pix::Width = 800;
//int Pix::Height = 800;
//int Pix::maxPix = 100;
//void Pix::init(int pixSize, int width)
//{
//    PixSize = pixSize;
//    Width = width;
//    Height = width;
//    maxPix = width / pixSize;
//}
//void Pix::draw(float r,float g, float b)
//{
//    if (x >= maxPix || y > maxPix)
//    {
//        throw "Error: pix is out of range";
//    }
//    int x0 = x * PixSize;
//    int y0 = y * PixSize;
//
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    glClear(GL_COLOR_BUFFER_BIT);
//
//
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(-Width/2, Width/2, Height/2, -Height/2, -1, 1);
//    // Set the color
//    glColor3f(r, g, b); // Red
//
//    // Draw a point
//    glBegin(GL_POINTS);
//    for (int i = 0; i < PixSize; i++)
//    {
//        for (int j = 0; j < PixSize; j++)
//        {
//            glVertex2i(x0 + i, y0 + j);
//        }
//    }
//    glEnd();
//}
//void Pix::drawRed()
//{
//    draw(1.0, 0.0, 0.0);
//}
//void Pix::drawBlack()
//{
//    draw(0.0, 0.0, 0.0);
//}
//void Pix::drawWhite()
//{
//    draw(1.0, 1.0, 1.0);
//}
void drawPixRGB_Boundary(int x, int y, float r, float g, float b)
{
    int x0 = x * PIX_SIZE;
    int y0 = y * PIX_SIZE;
    glColor3f(r, g, b);
    glBegin(GL_POINTS);
    for (int i = 0; i < PIX_SIZE; i++)
    {
        //glVertex2f((float)(x0 + i) + 0.5, float(y0 ) + 0.5);
        //glVertex2f((float)(x0 + i) + 0.5, float(y0 + PIX_SIZE - 1) + 0.5);
        glVertex2i(x0 + i, y0);
        glVertex2i(x0 + i, y0+PIX_SIZE-1);
    }
    for (int i = 1; i < PIX_SIZE - 1; i++)
    {
        //glVertex2f((float)(x0) + 0.5, float(y0 + i) + 0.5);
        //glVertex2f((float)(x0+PIX_SIZE-1) + 0.5, float(y0 + i) + 0.5);
        glVertex2i(x0 , y0+i);
        glVertex2i(x0 +PIX_SIZE-1, y0 + i);
    }
    glEnd();
}
void drawPixBlack_Boundary(int x, int y)
{
    drawPixRGB_Boundary(x, y, 0.0, 0.0, 0.0);
}

void drawPixRGB(int x, int y, float r, float g, float b)
{
    // Draw a point
    int x0 = x * PIX_SIZE;
    int y0 = y * PIX_SIZE;
    glColor3f(r, g, b);
    glBegin(GL_POINTS);
    for (int i = 0; i < PIX_SIZE; i++)
    {
        for (int j = 0; j < PIX_SIZE; j++)
        {
            //glVertex2f((float)(x0 + i) + 0.5, float(y0 + j) + 0.5);
            glVertex2i(x0 + i, y0 + j);
        }
    }
    glEnd();
}
void drawPixRed(int x, int y)
{
    drawPixRGB(x,y,1.0, 0.0, 0.0);
}
void drawPixWhite(int x, int y)
{
    drawPixRGB(x, y, 1.0, 1.0, 1.0);
}
void drawPixBlack(int x, int y)
{
    drawPixRGB(x, y, 0.0, 0.0, 0.0);
}

void drawBackGroundWhite()
{
    for (int x = MIN_PIX; x <= MAX_PIX ; x++)
    {
        for (int y = MIN_PIX; y <= MAX_PIX ; y++)
        {
            drawPixRGB(x, y, 1.0, 1.0, 1.0);
            drawPixBlack_Boundary(x, y);
        }
    }
}