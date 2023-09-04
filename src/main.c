#include <stdlib.h>
#include <stdio.h>

#include "point.h"
#include "vector.h"


int main() {

    Point2D points[2];

    points[0].x = 1;
    points[0].y = 2;

    points[1].x = 5;
    points[1].y = 10;

    for (int i = 0; i < 2; ++i) {
        printf("Point %d: (%f, %f)\n", i, points[i].x, points[i].y);
    }

    // distance between two points
    float dist = distance(points[0], points[1]);
    printf("Distance between points 1 and 2: %f\n", dist);

    Vector v1, v2;
    v1 = create_vector(3);
    v2 = create_vector(3);

    v1.data[0] = 5;
    v1.data[1] = 3;
    v1.data[2] = 4;

    v2.data[0] = 3;
    v2.data[1] = 8;
    v2.data[2] = 2.5;

    print_vector(v1);
    print_vector(v2);

    printf("Magnitude of v2: %f\n", magnitude(v1));
    printf("Dot product v1 * v2: %f\n", dot_product(v1, v2));
}
