#include <stdio.h>

int calcular_det(int mat_a[3][3]) {
    int det;
    
    det = (mat_a[0][0] * mat_a[1][1] * mat_a[2][2]) +
          (mat_a[0][1] * mat_a[1][2] * mat_a[2][0]) +
          (mat_a[0][2] * mat_a[1][0] * mat_a[2][1]) -
          (mat_a[0][2] * mat_a[1][1] * mat_a[2][0]) -
          (mat_a[0][1] * mat_a[1][0] * mat_a[2][2]) -
          (mat_a[0][0] * mat_a[1][2] * mat_a[2][1]);
    
    return det;
}

void calcular_pos(int mat_a[3][3], int mat_b[3]) {
    int det_matriz = calcular_det(mat_a);
    
    if (det_matriz == 0) {
        printf("El sistema de ecuaciones no tiene solución única.\n");
        return;
    }

    int det_x[3][3] = {
        {mat_b[0], mat_a[0][1], mat_a[0][2]},
        {mat_b[1], mat_a[1][1], mat_a[1][2]},
        {mat_b[2], mat_a[2][1], mat_a[2][2]}
    };
    
    int det_y[3][3] = {
        {mat_a[0][0], mat_b[0], mat_a[0][2]},
        {mat_a[1][0], mat_b[1], mat_a[1][2]},
        {mat_a[2][0], mat_b[2], mat_a[2][2]}
    };
    
    int det_z[3][3] = {
        {mat_a[0][0], mat_a[0][1], mat_b[0]},
        {mat_a[1][0], mat_a[1][1], mat_b[1]},
        {mat_a[2][0], mat_a[2][1], mat_b[2]}
    };
    
    int det_x_val = calcular_det(det_x);
    int det_y_val = calcular_det(det_y);
    int det_z_val = calcular_det(det_z);
    
    int x = det_x_val / det_matriz;
    int y = det_y_val / det_matriz;
    int z = det_z_val / det_matriz;
    
    printf("Las posiciones son:\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);
}