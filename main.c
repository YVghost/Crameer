#include <stdio.h>

int main() {
    int mat_a[3][3];
    int mat_b[3];
    
    printf("Ingrese los elementos de la mat_a:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &mat_a[i][j]);
        }
    }
    
    printf("Ingrese los elementos del mat_b:\n");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &mat_b[i]);
    }
    
    int determinante = calcular_det(mat_a);
    
    printf("La determinante de la mat_a es: %d\n", determinante);
    
    calcular_pos(mat_a, mat_b);
    
    return 0;
}