#include "main.h"

House::House()
{
    num_corners = 0;
    hight = 0;
    width = 0;
    for(int i = 0; i<4; i++)
    {
        p[i].setLatLongt(0,0);

    }

}

void House::Draw(Map *p, int dist1, int dist2)
{
    int i,j;
    for(i=0; i<hight; i++)
        for(j=0; j<width; j++)
            p->drawPoint(dist2+j,dist1+i,1);




}

void House::add_Corner(Position t_p)
{
    p[num_corners] = t_p;
    num_corners++;
}

void House::setHight(int t_hight)
{
    hight = t_hight;
}

void House::setWidth(int t_width)
{
    width = t_width;
}

void House::DrawLine(float tx1, float ty1, float tx2, float ty2, float max_x, float max_y, Map *p){
    double k = (ty2 - ty1)/(tx2 - tx1);
    double b = (tx2*ty1 - tx1*ty2)/(tx2 - tx1);
    for(int i=0; i<max_y; i++)
        for(int j=0; j<max_x; j++)
            if(i=k*j+b){
                p->drawPoint(j,i,1);
            }
}

void House::add_pixel_corner(Position t_p, int t_num){
    pixel_p[t_num]=t_p;
}
