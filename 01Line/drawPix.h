#ifndef DRAW_PIX_CG_H
#define DRAW_PIX_CG_H

class Pix {
    int x, y;
public:
    static int PixSize;
    static int Width;       //Width == Height
    static int Height;
    static int maxPix;
    static void init(int pixSize,int width);
    void draw(float r,float g,float b);
    Pix(int x0, int y0) :x(x0), y(y0) {}
    void drawRed();
    void drawWhite();
    void drawBlack();
    void drawRGB_Boundary(float r, float g, float b);
    void drawWhite_Boundary();
    void drawBlack_Boundary();
};

//void drawPixRGB(int x, int y, float r, float g, float b);
//void drawPixRGB_Boundary(int x, int y, float r, float g, float b);
//void drawPixRed(int x, int y);
//void drawPixWhite(int x, int y);
//void drawPixBlack(int x, int y);
//void drawPixBlack_Boundary(int x, int y);
//void drawBackGroundWhite();


#endif // !DRAW_PIX_CG_H
