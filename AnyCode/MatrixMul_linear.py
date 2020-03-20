def square_matrix_multiply(A, B):
    n = len(A);
    C = [x for x in range(n)];
    C = [C, C, C];

    for i in range(n):
        for j in range(n):
            C[i][j] = 0;
            for k in range(n):
                print(C[i][j], "=", A[i][k], "*", B[k][j]);
                C[i][j] = C[i][j] + A[i][k]*B[k][j];
    
    return C;
    
A = [
    [1, 3, 3,],
    [54, 7, 154,],
    [67,5912,73],
];

B = [
    [1, 3, 3,],
    [54, 7, 154,],
    [67,5912,73],
];

C = square_matrix_multiply(A, B);

print(C);