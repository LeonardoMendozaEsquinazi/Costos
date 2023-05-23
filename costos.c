#include <stdio.h>

int min(int a, int b, int c) {
    int minimo = a;
    if (b < minimo) {
        minimo = b;
    }
    if (c < minimo) {
        minimo = c;
    }
    return minimo;
}

int CostoMinimo(int M, int N, int cost[M+1][N+1]) {
    int dp[M+1][N+1];

    dp[0][0] = cost[0][0];

    // Calcular los costos para la primera columna
    for (int i = 1; i <= M; i++) {
        dp[i][0] = dp[i-1][0] + cost[i][0];
    }

    // Calcular los costospara la primera fila
    for (int j = 1; j <= N; j++) {
        dp[0][j] = dp[0][j-1] + cost[0][j];
    }

    // Calcular los costos para el resto de las celdas
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = cost[i][j] + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }

    return dp[M][N];
}

int main() {
    int M, N;

    printf("Ingrese el tamaño de la matriz (M y N): ");
    scanf("%d %d", &M, &N);

    int cost[M+1][N+1];

    printf("Ingrese los costos de la matriz:\n");
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= N; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    int costoMinimo = CostoMinimo(M, N, cost);

    printf("El costo mínimo de la ruta es: %d\n", costoMinimo);

    return 0;
}
