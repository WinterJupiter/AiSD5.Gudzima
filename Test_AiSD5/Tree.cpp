#include "Tree.h"
#include <iostream>


unsigned Map::Height(Tree* p)
{
	return p ? p->height : 0;
}

void Map::Fix(Tree* p)
{
	unsigned  h_l = Height(p->l);
	unsigned  h_r = Height(p->r);
	if (h_l > h_r)
		p->height = h_l + 1;
	else
		p->height = h_r + 1;
}

int Map::Balance_Factor(Tree* p)
{
	return Height(p->r) - Height(p->l);
}

Tree* Map::Balance(Tree* p)
{
	Fix(p);
	if (Balance_Factor(p) == 2)
	{
		if (Balance_Factor(p->r) < 0)
			p->r = Right(p->r);
		return Left(p);
	}
	if (Balance_Factor(p) == -2)
	{
		if (Balance_Factor(p->l) > 0)
			p->l = Left(p->l);
		return Right(p);
	}
	return p;
}

Tree* Map::Left(Tree* q)
{
	Tree* p = q->r;
	q->r = p->l;
	p->l = q;
	Fix(q);
	Fix(p);
	return p;
}

Tree* Map::Right(Tree* p)
{
	Tree* q = p->l;
	p->l = q->r;
	q->r = p;
	Fix(p);
	Fix(q);
	return q;
}

Tree* Map::Min(Tree* p)
{
	return p->l ? Min(p->l) : p;
}

Tree* Map::Erase_Min(Tree* p)
{
	if (p->l == 0)
		return p->r;
	p->l = Erase_Min(p->l);
	return Balance(p);
}

Tree* Map::Erase_Element(Tree* p, int key)
{
	if (!p) return nullptr;
	if (key < p->key)
		p->l = Erase_Element(p->l, key);
	else if (key > p->key)
		p->r = Erase_Element(p->r, key);
	else
	{
		Tree* t_l = p->l;
		Tree* t_r = p->r;
		delete p;
		if (!t_r) return t_l;
		Tree* min = Min(t_r);
		min->r = Erase_Min(t_r);
		min->l = t_l;
		return Balance(min);
	}
	return Balance(p);
}

Tree* Map::Insert(int key, std::string value, Tree* p)
{
	if (p == nullptr)
		p = new Tree(key, value);
	else if (key < p->key)
		p->l = Insert(key, value, p->l);
	else if (key > p->key)
		p->r = Insert(key, value, p->r);
	else  throw "Already exist\n";
	return Balance(p);
}

void Map::Delete(Tree* p)
{
	if (p)
	{
		Delete(p->l);
		Delete(p->r);
		delete p;
	}
}

void Map::Print(Tree* p, int level) const
{
	if (p)
	{
		Print(p->r, level + 1);
		for (int i = 0; i < level; i++)
			std::cout << "   ";
		std::cout << p->key << std::endl;
		Print(p->l, level + 1);
	}
}

Map::Map()
{
	root = nullptr;
}

void Map::print() const
{
	if (root == nullptr)
		std::cout << "Tree is empty\n";
	else Print(root, 0);
}

bool Map::insert(int key, std::string value)
{
	root = Insert(key, value, root);
	return true;
}

const std::string& Map::find(int key) const
{
	Tree* t = root;
	while (t != nullptr)
	{
		if (key == t->key)
			return t->data;
		if (key > t->key)
			t = t->r;
		else if (key < t->key)
			t = t->l;
	}
	throw "Not found\n";
}

bool Map::erase(int key)
{
	root = Erase_Element(root, key);
	return true;
}

Map::~Map()
{
	Delete(root);
	root = nullptr;
}

void Map::del()
{
	Delete(root);
	root = nullptr;
}