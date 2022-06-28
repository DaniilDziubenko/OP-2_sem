import classes

listMatrix = [classes.SquareMatrix2Order(), classes.SquareMatrix3Order()]
s = 0

for elem in listMatrix:
    print("\nMatrix:")
    elem.printMatrix()
    print(f"\nMatrix determinant: {elem.getDeterminant()}")
    s += elem.getDeterminant()
    print(f"Sum of elements Matrix: {elem.getSumOfElements()}")
    if isinstance(elem, classes.SquareMatrix3Order):
        s += elem.getSumOfElements()

print(f"\nS = {s}")
