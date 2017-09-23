/*
 *date 2017-9-23
 *author 雨后de水滴
 *name c++双向链表
 */

#include "stdafx.h"
#include "Linklist2.h"

using namespace std;

int main()
{
	doubleLinkList *l = new doubleLinkList();
	int  length=12;
	for (int i = 0; i < length; i++)
	{
		l->push(i);
		cout <<l->get(i)<<" ";
	}

	putchar(10);
	l->push(66,-1);
	for (int i = 0; i < l->getLength(); i++)
	{
		cout << l->get(i) << " ";
	}
	putchar(10);
}
