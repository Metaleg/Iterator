#ifndef ITERATORCLASSES_H
#define ITERATORCLASSES_H

#include <String>
#include <iostream>
#include <iomanip>
#include <io.h>

using namespace std;

class FileItem {
public:
	string fname; // Название файла
	bool isDir;   // 1 - Директория; 0 - Файл
	string fMask; // Путь к файлу или Директории
};

class Iterator {
	Iterator *it;
	FileItem *cache;
	string Mask;
	string name;
	intptr_t hFind;

	bool comparison(FileItem*); // Сравнение cash->fname и name, 1 - равны 0 - не равны
	FileItem* searchInDir(); // ищёт очередной файл/каталог внутри Mask (0 - файл, 1 - директория)
	FileItem* doSearch(); // ищет внутри Mask и подкатолагах очередной файл, удовлет.name

public:
	Iterator() : name("*"), it(NULL), hFind(NULL), cache(NULL) {}
	Iterator(string mask);
	~Iterator();

	bool hasMore();   // Есть ли файл по пути Mask
	FileItem* next();// Показывает и переходит к следущиму файлу с названием name по пути Mask

	void get();
};
#endif // ITERATORCLASSES_H
