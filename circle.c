#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846264338327950288

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

// Function that find the intersection point of the two circle
int intersect(struct circle c1, struct circle c2) {
    double d, totalRadius;
    d = distance(c1, c2);
    totalRadius = c1.radius + c2.radius;

    if (d > totalRadius) {
        return 0;   // circles do not tangible
    } else if (d == totalRadius) {
        return 1;   // one intersection
    } else {
        return 2;   // two intersection
    }
}


int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    FILE *fpInput, *fpOutput;

    // Check the input file if there is any error when read
    if (!(fpInput = fopen(argv[1], "r"))) {
        printf("Can't open %s\n", argv[1]);
        exit(2);
    }

    // Check the output file if there is any error when write
    if (!(fpOutput = fopen(argv[2], "w"))) {
        printf("Can't open %s\n", argv[2]);
        exit(3);
    }

    // Define c1 and c2
    struct circle c1, c2;
    struct arc_angle arcAngle1, arcAngle2;

    // Read from File input line by line
    while (fscanf(fpInput, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf", &c1.origin.x, &c1.origin.y, &c1.radius, &c2.origin.x, &c2.origin.y,
                  &c2.radius, &arcAngle1.angle, &arcAngle2.angle) != EOF) {

        // Find the archLength of the two circles
        double arcLength1 = arcLength(c1, arcAngle1);
        double arcLength2 = arcLength(c2, arcAngle2);

        // Find the intersection point of the two circles
        double intersection = intersect(c1, c2);

        // Print result into File Output
        fprintf(fpOutput, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n", c1.origin.x, c1.origin.y, c1.radius, c2.origin.x,
                c2.origin.y, c2.radius, arcAngle1.angle, arcAngle2.angle, arcLength1, arcLength2, intersection);
    }

    // Check if there is an error on the last read
    if (ferror(fpInput)) {
        printf("Error on the last read file %s\n", argv[1]);
        exit(4);
    }

    // Close Files
    if (fclose(fpInput) != 0) {
        printf("Error in closing file %s\n", argv[1]);
        exit(5);
    }

    if (fclose(fpOutput) != 0) {
        printf("Error in closing file %s\n", argv[2]);
        exit(6);
    }

    return 0;
}