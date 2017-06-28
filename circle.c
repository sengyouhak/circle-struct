#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define M_PI acos(-1.0)

struct point {
    double x;
    double y;
};

struct circle {
    double x;
    double y;
    double radius;
    
};


struct arc_point {
    double start;
    double end;
};

struct arc_angle {
    double angle;
};

double arcLength(struct circle c, struct arc_point arc1) {
    double result = 2 * M_PI * c.radius * ( (arc1.end - arc1.start) / 360 );
    return result;
}

double arcLength1(struct circle c, struct arc_angle arc){
    
    double result = 2 * M_PI * c.radius * ( arc.angle / 360);

    return result;
}

int main(void) {

    struct circle C = {0, 0, 10};
    struct arc_point A = {0, 360};
    struct arc_angle A1 = {360};
    
    printf("%f\n", arcLength(C, A));
    printf("%f", arcLength1(C, A1));


    return 0;

}