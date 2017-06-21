#include <stdlib.h>
#include <stdio.h>

struct point {
    double x;
    double y;
    double radius;
};

float slopeOf(struct point A, struct point B) {
    return (B.y - A.y) / (B.x - A.x);
}

int main(void) {
    struct pint A = {3, 5};
    struct pint B = {0, 6};
    struct pint C = {3, -5};

    printf("slope between A and B is : %f\n", slopeOf(A, B));
    printf("slope between A and C is : %f\n", slopeOf(A, C));

    return 0;

}