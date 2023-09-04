
#ifndef VECTOR_H
#define VECTOR_H

/// @brief Immutable vector type. Stores the size and an array
///        of floats for the vector values.
typedef struct {
    float *data;
    int size;
} Vector;

/// @brief Based on a given size, allocate enough memory for that many
///        float values in the data array.
/// @param size
/// @return A Vector struct instance with the given size.
Vector create_vector(int size);

/// @brief Free up the data array. After calling this, it is probably a
///        good idea to point the variable to NULL;
/// @param v
void free_vector(Vector *v);

void print_vector(Vector v);

/// @brief A measure of the length or size of a vector.
/// @param v
/// @return The sum of squares of all vector elements.
float magnitude(Vector v);

/// @brief 
/// @param v1 
/// @param v2 
/// @return 
float dot_product(Vector v1, Vector v2);

#endif // VECTOR_H
