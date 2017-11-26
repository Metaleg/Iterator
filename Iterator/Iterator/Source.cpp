#include "iterator.h"

int main() {
	setlocale(LC_ALL, "rus");
	Iterator a;
	FileItem *b;

	a.get();

	while (a.hasMore()) {
		b = a.next();
		cout << setw(8) << left << b->fname << " :: " 
			<< setw(10) << left << b->fMask << endl;
		delete b;
	}

	system("pause");

	return 0;
}
