#pragma once
#include <string>
#include <iostream>
struct Tree
{
	std::string data;
	int key;
	Tree* r;
	Tree* l;
	unsigned height;
	Tree(int _key, std::string _data) :key(_key), data(_data), r(nullptr), l(nullptr), height(1) {};
};

class Map
{
private:
	Tree* root;
	unsigned Height(Tree* p);
	void Fix(Tree* p);
	int Balance_Factor(Tree* p);
	Tree* Balance(Tree* p);
	Tree* Left(Tree* p);
	Tree* Right(Tree* p);
	Tree* Min(Tree* p);
	Tree* Erase_Min(Tree* p);
	Tree* Erase_Element(Tree* p, int key);
	Tree* Insert(int key, std::string value, Tree* root);
	void Delete(Tree* p);
	void Print(Tree* p, int level) const;

public:
	Map();
	void print() const;
	bool insert(int key, std::string value);
	const std::string& find(int key) const;
	bool erase(int key);
	void del();
	~Map();
};