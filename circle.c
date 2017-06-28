#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define M_PI acos(-1.0)

// struct arc_point {
//    double start;
//    double end;
//};

//double arcLength(struct circle c, struct arc_point arc) {
//    double result = 2 * M_PI * c.radius * ( (arc.end - arc.start) / 360 );
//    return result;
//}

struct point {
    double x;
    double y;
};

struct circle {
    struct point origin;
    double radius;

};

struct arc_angle {
    double angle;
};

double arcLength(struct circle c, struct arc_angle arc) {
    double result = 2 * M_PI * c.radius * (arc.angle / 360);
    return result;
}

// Calculate the distance between two circle
double distance(struct circle c1, struct circle c2) {
    double d = sqrt(pow(c1.origin.x - c2.origin.x, 2) + pow(c1.origin.y - c2.origin.y, 2));
    return d;
}

int intersect(struct circle c1, struct circle c2) {
    double d, totalRadius;
    d = distance(c1, c2);
    totalRadius = c1.radius + c2.radius;

    if (d > totalRadius) {
        return 0;   // circles do not touch
    } else if (d == totalRadius) {
        return 1;   // one intersection
    } else {
        return 2;   // two intersection
    }
}


int main(void) {

    // Define Circle 1
    struct point pC1 = {0, 0};
    struct circle c1 = {pC1, 10};

    // Define Circle 2
    struct point pC2 = {5, 0};
    struct circle c2 = {pC2, 10};

    struct arc_angle aC1 = {360};
    printf("%f\n", arcLength(c1, aC1));

    int intersectPoint = intersect(c1, c2);
    switch (intersectPoint) {
        case 0:
            printf("Circles do not touch\n");
            break;
        case 1:
            printf("One intersection\n");
            break;
        case 2:
            printf("Two intersection\n");
            break;
    }

    return 0;
}