#include "main.h"

Position::Position(){
    latitude = 0;
    longtitude = 0;
}

Position::Position(float t_lat, float t_longt){
    latitude = t_lat;
    longtitude = t_longt;
}


float Position::getLatitude(){
    return latitude;
}

float Position::getLongtitude(){
    return longtitude;
}

void Position::setLatLongt(float t_lat, float t_longt){
    latitude = t_lat;
    longtitude = t_longt;
}

void Position::Geogr_To_Pixel(Position pmax, Position pmin){
    latitude = (500/(pmax.getLatitude()-pmin.getLatitude()))*(latitude-pmin.getLatitude());
    longtitude = (500/(pmax.getLongtitude()-pmin.getLongtitude()))*(longtitude-pmin.getLongtitude());
}

void Position::Pixel_To_Georg(Position pmax, Position pmin){
    latitude = latitude*(pmax.getLatitude()-pmin.getLatitude())/500+pmin.getLatitude();
    longtitude = longtitude*(pmax.getLongtitude()-pmin.getLongtitude())/500+pmin.getLongtitude();

}
