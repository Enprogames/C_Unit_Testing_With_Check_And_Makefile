
#ifndef POINT_H
#define POINT_H

/// @brief Stores a 2-dimensional coordinate value in space.
typedef struct {
    float x;
    float y;
} Point2D;

/// @brief Find the cartesian distance between two points
/// @param p1 
/// @param p2 
/// @return Cartesian distance between p1 and p2
float distance(Point2D p1, Point2D p2);

#endif // POINT_H
