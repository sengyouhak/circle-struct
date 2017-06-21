#include <stdlib.h>
#include <stdio.h>

struct circle {
    double x;
    double y;
    double radius;
};

struct arc {
    double a;
    double b;
};

double arcLength(struct circle c, struct arc arc1){

    double result = 2 * 3.14 * c.radius * ( (arc1.b - arc1.a ) / 360);

    return result;
}

int main(void) {

    struct circle A = {0, 0, 10};
    struct arc a = {0, 90};

    printf("%f", arcLength(A, a));


    return 0;

}