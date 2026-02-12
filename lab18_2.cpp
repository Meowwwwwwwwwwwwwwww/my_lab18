#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect* R1, Rect* R2){
    double x1_min = R1->x;
    double x1_max = R1->x + R1->w;
    double x2_min = R2->x;
    double x2_max = R2->x + R2->w;
    
    double y1_min = R1->y - R1->h;
    double y1_max = R1->y;
    double y2_min = R2->y - R2->h;
    double y2_max = R2->y;
    
    double inter_x_min = max(min(x1_min, x1_max), min(x2_min, x2_max));
    double inter_x_max = min(max(x1_min, x1_max), max(x2_min, x2_max));
    
    double inter_y_min = max(min(y1_min, y1_max), min(y2_min, y2_max));
    double inter_y_max = min(max(y1_min, y1_max), max(y2_min, y2_max));

    double overlap_w = inter_x_max - inter_x_min;
    double overlap_h = inter_y_max - inter_y_min;

    if (overlap_w <= 0 || overlap_h <= 0) {
        return 0;
    }

    return overlap_w * overlap_h;



}