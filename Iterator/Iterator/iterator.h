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
	string str1 = "*";
	if (name == str1)
		return 1;
	if (a->fname == name)
		return 1;
	return 0;
}

FileItem* Iterator::searchInDir() {
	FileItem *a = NULL;
	struct _finddata_t file;
	string str = Mask + "\\*", str1 = ".", str2 = "..";
	bool i = false;

	if (hFind == NULL) {
		if ((hFind = _findfirst(str.c_str(), &file)) == -1L)
			return NULL;
	}
	else if ((_findnext(hFind, &file)) != 0)
		return NULL;

	a = new FileItem;

	if (file.attrib & _A_SUBDIR)
		i = true;

	a->fname = file.name;
	a->fMask = Mask;
	a->isDir = i;

	if ((a->fname == str1) || (a->fname == str2)) {
		delete a;
		a = searchInDir();
	}
	return a;
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
