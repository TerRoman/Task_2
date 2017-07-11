#include "main.h"
Map::Map(int n, int m ){
    int i,j;
    x_max=m;
    y_max=n;
    p = (int*) malloc(n*m*sizeof(int));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
        *(p+i*m+j)=0;
    }
}

void Map::show(){
    int i,j;
    for(i=0;i<y_max;i++){
        for(j=0;j<x_max;j++){
            printf("%d", *(p+i*x_max+j));
        }
        printf("\n");
    }
}

void Map::save(char *fname){
    FILE *fp;
    fp=fopen(fname, "w");
    if(fp==NULL){
        printf("Cant open file");
        exit(1);
    }
    int i,j;
    fprintf(fp,"P1\n");
    fprintf(fp,"%d %d\n",(y_max),(x_max) );
    for(i=0;i<y_max;i++){
        for(j=0;j<x_max;j++){
            fprintf(fp, "%d", *(p+i*x_max+j));
    }
    fprintf(fp,"\n");
    }
    fclose(fp);
}

void Map::drawPoint(int x,int y, int color){
   *(p+(y_max-1-y)*x_max+x)=color;
}

void Map::assosiate(float t_lat1, float t_longt1, float t_lat2, float t_longt2){
    lat1 = t_lat1;
    lat2 = t_lat2;
    longt1 = t_longt1;
    longt2 = t_longt2;
}

float Map::return_coord(int t){
    switch (t){
    case 1:
        return lat1;
        break;
    case 2:
        return longt1;
        break;
    case 3:
        return lat2;
        break;
    case 4:
        return longt2;
        break;
    }
}

void Map::setK(Position p1, Position p4){
    Klat = (p1.getLatitude()-p4.getLatitude())/y_max;
    Klong = (p1.getLongtitude()-p4.getLongtitude())/x_max;
}

float Map::getK(int t){
    if (t=1)
        return Klong;
    else
        return Klat;
}

int Map::calc_dist(Position p1, Position p2){
    int result=0;
    result=sqrt((p2.getLatitude()-p1.getLatitude())*(p2.getLatitude()-p1.getLatitude())+(p2.getLongtitude()-p1.getLongtitude())*(p2.getLongtitude()-p1.getLongtitude()));
    return result;
}

Position Map::get_geogr(Position p1, int azimut, int dist){
    Position temp;
    float temp_latitude;
    float temp_longtitude;
    temp_latitude=p1.getLatitude()+dist*0.718*cos(azimut*3.14/180)/6371000*3,14/180;
    temp_longtitude = p1.getLongtitude()+dist*sin(azimut*3.14/180)/6371000*3,14/180;
    temp.setLatLongt(temp_latitude, temp_longtitude);
    return temp;
}

