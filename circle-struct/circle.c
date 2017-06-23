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


struct arc {
    double start;
    double end;
    double angle;
};

double arcLength(struct circle c, struct arc arc1){
    
    double result = 2 * M_PI * c.radius * ( arc1.angle / 360);

    return result;
}

int main(void) {

    struct circle C = {0, 0, 10};
    struct arc A = {0, 0, 57};

    printf("%f", arcLength(C, A));


    return 0;

}