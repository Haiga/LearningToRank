#pragma once
struct blocoDuplo
{
	int dado;
	blocoDuplo* proximo;
	blocoDuplo* anterior;
	bool isNull(blocoDuplo*);
	bool proxIsNull(blocoDuplo*);
	bool antIsNull(blocoDuplo*); 
};


