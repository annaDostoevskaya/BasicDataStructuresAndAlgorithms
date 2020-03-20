def square_matrix_multiply_recursive(A, B):
    n = len(A);
    
    C = [[0]*n]*n;
    
    return C;
    
A = [
    [4,6,7],
    [3,8,7],
    [1,2,3]
]

B = [
    [4,3,7],
    [5,7,9],
    [6,7,2]
]
    
qwerty = square_matrix_multiply_recursive(A, B);

print(qwerty);