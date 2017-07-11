#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <vector>
#include <fstream>

using namespace std;



class Position{
public:
    float latitude;
    float longtitude;
public:
    Position();
    Position(float t_lat, float t_long);
    float getLatitude();
    float getLongtitude();
    void setLatLongt(float t_lat, float t_longt);
    void Geogr_To_Pixel(Position pmax, Position pmin);
    void Pixel_To_Georg(Position pmax, Position pmin);
};

class Point{
public:
    Position p;
    int azimut;
    int dist_x;
    int dist_y;
public:
    Point(Position t_p, int t_azimut);
    int get_azimut();
    Position get_position();
    void set_dist(int t_x, int t_y);
};

class Map{
    int *p;
    int x_max,y_max;
    float lat1;
    float lat2;
    float longt1;
    float longt2;
    Position corners[4];
    float Klat;
    float Klong;
public:
    Map(int n, int m);
    void drawPoint(int x, int y, int color);
    void assosiate(float t_lat1, float t_longt1, float t_lat2, float t_longt2);
    void show();
    void save(char *fname);
    float return_coord(int t);
    void setK(Position p1, Position p4);
    float getK(int t);
    int calc_dist(Position p1, Position p2);
    Position get_geogr(Position p1, int azimut, int dist);
};


class House{
    public:
    int hight;
    int width;
    int num_corners;
    Position p[4];
    Position pixel_p[4];
public:
    void setHight(int t_hight);
    void setWidth(int t_width);
    House();
    void Draw(Map *m, int dist1, int dist2);
    void add_Corner(Position p);
    void add_pixel_corner(Position t_p, int t_num);
    void DrawLine(float tx1, float ty1, float tx2, float ty2, float max_x, float max_y, Map *p);
};


