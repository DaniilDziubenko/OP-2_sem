import classes

matrixA = classes.SquareMatrix3Order()
matrixB = classes.SquareMatrix2Order()

print("\nMatrix A:")
matrixA.printMatrix()
print("\nMatrix B:")
matrixB.printMatrix()

a = matrixA.getDeterminant()
b = matrixB.getDeterminant()
sumA = matrixA.getSumOfElements()
s = a + b + sumA

print(f"\nDeterminant Matrix A = {a}")
print(f"Determinant Matrix B = {b}")
print(f"Sum of elements Matrix A: {sumA}")
print(f"\nS = {s}")
