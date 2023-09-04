#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../include/point.h"


float distance(Point2D p1, Point2D p2) {
    float distx = p1.x-p2.x;
    float disty = p1.y-p2.y;
    return sqrt(distx * distx + disty * disty);  // Use sqrt from math.h
}
