#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "vector.h"

Vector create_vector(int size) {
    Vector v;

    v.data = (float *) malloc(sizeof(float) * size);
    v.size = size;

    return v;
}

void free_vector(Vector *v) {
    free(v->data);
    v->size = 0;
}

void print_vector(Vector v) {
    printf("Vector: [");
    for (int i=0; i<v.size; i++) {
        if (i == v.size-1) {
            printf("%f", v.data[i]);
        } else {
            printf("%f, ", v.data[i]);
        }
    }
    printf("]\n");
}

float magnitude(Vector v) {
    float result = 0;

    float current_element;
    for (int i=0; i<v.size; i++) {
        current_element = v.data[i];
        result += current_element * current_element;
    }
    result = sqrt(result);
    return result;
}

float dot_product(Vector v1, Vector v2) {
    if (v1.size != v2.size) {
        printf("Error: vectors must be the same size\n");
        return 0;
    }

    float sum = 0;
    for (int i = 0; i < v1.size; ++i) {
        sum += v1.data[i] * v2.data[i];
    }

    return sum;
}
