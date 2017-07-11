#include "main.h"


int main()
{
   int house_number = -1;
    setlocale(LC_ALL, "");
    std::ifstream file("test.txt");
    string line;
    const char* temp;
    char *str1;
    int k = 0;
    std::vector<float> parametrs;
    if (file.is_open())
  {
    while ( file.good() )
    {
    house_number++;
    getline (file,line);
    temp = line.c_str();
    str1 = (char*)temp;
    char* pch = strtok (str1," ");
    while (pch != NULL)
    {
    parametrs.push_back(atof(pch));
      pch = strtok (NULL, " ");
      k++;
    }
    }
    file.close();
  }
  else cout << "Unable to open file";
    Map *Image;
    Image = new Map(parametrs[0], parametrs[1]);
    House house[house_number];
    Position temp_pos;
    Position pos[4];
    Position Min;
    Position Max;
    Min.setLatLongt(parametrs[2],parametrs[3]);
    Max.setLatLongt(parametrs[4],parametrs[5]);
    Image->setK(Max, Min);
    Image->assosiate(parametrs[2], parametrs[3], parametrs[4], parametrs[5]);
        for(int j=0; j<2; j++){
            house[j].num_corners=0;
            for(int i = 0; i < house_number*4; i++){
            temp_pos.setLatLongt(parametrs[8*j+2*i+6],parametrs[8*j+2*i+7]);
            house[j].add_Corner(temp_pos);
            pos[i] = temp_pos;
            }
        int Hhight = (pos[0].getLatitude()-pos[2].getLatitude())/Image->getK(2)*2;
        int Hwidth = (pos[1].getLongtitude()-pos[0].getLongtitude())/Image->getK(1)*2;
        house[j].setHight(Hhight);
        house[j].setWidth(Hwidth);
        int dist1 = (pos[2].getLongtitude()-Image->return_coord(2))/Image->getK(2);
        int dist2 = (pos[2].getLatitude()-Image->return_coord(1))/Image->getK(1);
        house[j].Draw(Image, dist1, dist2);
    }
    House horizon;
    int horizonHight = 400;
    horizon.setHight(2);horizon.setWidth(parametrs[0]);
    horizon.Draw(Image, horizonHight, 0);
    House Test;
    int Test_House_x=parametrs[22];
    int Test_House_y=parametrs[23];
    int Test_House_Hight = parametrs[24];
    int Test_House_Width = parametrs[25];
    Test.setHight(Test_House_Hight); Test.setWidth(Test_House_Width);
    Test.Draw(Image, Test_House_y, Test_House_x);
    Position Test_House[4];
    Position Pixel_Test_House[4];
    Pixel_Test_House[0].setLatLongt(Test_House_x,Test_House_y+Test_House_Hight);
    Pixel_Test_House[1].setLatLongt(Test_House_x+Test_House_Width,Test_House_y+Test_House_Hight);
    Pixel_Test_House[2].setLatLongt(Test_House_x+Test_House_Width,Test_House_y);
    Pixel_Test_House[3].setLatLongt(Test_House_x,Test_House_y);
    Position point;
    Position pixel_point;
    point.setLatLongt(55.8115722, 37.499870);
    Point nabl(point,parametrs[28]);
    pixel_point = point;
    pixel_point.Geogr_To_Pixel(Max, Min);
    nabl.set_dist(pixel_point.getLongtitude(),pixel_point.getLatitude());
    Image->drawPoint(nabl.dist_x,nabl.dist_y,1);
    for(int i=0;i<4;i++){
        printf("Point number %d\n",i);
        int dist = Image->calc_dist(pixel_point, Pixel_Test_House[i]);
        printf("Distance from observer is: %d\n",dist);
        Test_House[i]=Image->get_geogr(point,nabl.azimut,dist);
        Test.add_pixel_corner(Pixel_Test_House[i],i);
        Test.add_Corner(Test_House[i]);
        printf("Pixel coordinates of the point are: %f %f\n",Pixel_Test_House[i].getLatitude(),Pixel_Test_House[i].getLongtitude());
        Pixel_Test_House[i].Pixel_To_Georg(Max,Min);
        printf("Real coordinates of the point are: %f %f\n",Test_House[i].getLatitude(),Test_House[i].getLongtitude());
        printf("From the map knowledge coordinates are:  %f %f\n",Pixel_Test_House[i].getLatitude(),Pixel_Test_House[i].getLongtitude());
    }
    Image->save("Image.pnm");
    free(Image);
    return 0;

}
