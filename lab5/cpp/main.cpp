#include "Classes.h"

int main() {
	srand(time(NULL));
	
	TMatrix* arr[]{new SquareMatrix2Order(), new SquareMatrix3Order()};
	double sum = 0;

	for (auto elem : arr) {
		cout << "\nMatrix:\n";
		elem->printMatrix();
		cout << "\nMatrix determinant: " << elem->getDeterminant() << endl;
		cout << "Sum of elements: " << elem->getSumOfElements() << endl;
		sum += elem->getDeterminant();
		if (dynamic_cast<SquareMatrix3Order*>(elem)) {
			sum += elem->getSumOfElements();
		}
	}

	cout << "\n\nS = " << sum << endl;

	system("pause");
	return 0;
}