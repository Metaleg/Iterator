#ifndef ITERATOR_H
#define ITERATOR_H
#include "iteratorClasses.h"

//------------------CONSTRUCTORS------------------------------------

Iterator::Iterator(string mask) : Mask(mask), name("*"), it(NULL),
hFind(NULL), cache(NULL) {}

Iterator::~Iterator() {
	if (it != NULL)
		delete it;
	if ((hFind != NULL) || (hFind != -1))
		_findclose(hFind);
	if (cache != NULL)
		delete cache;
}

//--------------------METHODS----------------------------------------

bool Iterator::comparison(FileItem* a) {
	return 0;
}

FileItem* Iterator::searchInDir() {

	return 0;
}

FileItem* Iterator::doSearch() {
	return 0;
}

bool Iterator::hasMore() {
	return 0;
}

FileItem* Iterator::next() {
	return 0;
}

void Iterator::get() {
	cout << "Enter directory: ";	cin >> Mask; }
#endif // ITERATOR_H