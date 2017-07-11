#include "main.h"

Point::Point(Position t_p, int t_azimut){
    p = t_p;
    azimut = t_azimut;
}

int Point::get_azimut(){
    return azimut;
}

Position Point::get_position(){
    return p;
}

void Point::set_dist(int t_x, int t_y){
    dist_x = t_x;
    dist_y = t_y;
}
