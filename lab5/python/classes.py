from random import randint


class TMatrix:

    _matr = []

    def __init__(self, n, m):
        self._n = n
        self._m = m
        for i in range(n):
            line = []
            for j in range(m):
                line.append(randint(-50, 50))
            self._matr.append(line)

    def getSumOfElements(self):
        sumElem = 0
        for i in range(self._n):
            for j in range(self._m):
                sumElem += self._matr[i][j]
        return sumElem

    def printMatrix(self):
        for i in range(self._n):
            for j in range(self._m):
                print('{:4d}'.format(self._matr[i][j]), end=' ')
            print()

    def getDeterminant(self):
        raise NotImplementedError("In subclass method getDeterminant() must be redefine!")


class SquareMatrix2Order(TMatrix):
    def __init__(self):
        super().__init__(2, 2)

    def getDeterminant(self):
        return super()._matr[0][0] * super()._matr[1][1] - super()._matr[0][1] * super()._matr[1][0]


class SquareMatrix3Order(TMatrix):
    def __init__(self):
        super().__init__(3, 3)

    def getDeterminant(self):
        return super()._matr[0][0] * super()._matr[1][1] * super()._matr[2][2] + super()._matr[0][1] * super()._matr[1][2] * super()._matr[2][0] + super()._matr[0][2] * super()._matr[1][0] * super()._matr[2][1] - super()._matr[0][2] * super()._matr[1][1] * super()._matr[2][0] - super()._matr[0][1] * super()._matr[1][0] * super()._matr[2][2] - super()._matr[0][0] * super()._matr[1][2] * super()._matr[2][1]