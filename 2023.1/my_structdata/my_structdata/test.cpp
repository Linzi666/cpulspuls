#define _CRT_SECURE_NO_WARNINGS 1
#include"vector.h"
#include"list.h"
#include "AVLTree.h"
#include  "RBTree.h"

void vectorTest()
{
	//wyl::test1();
	wyl::test3();

}

void listTest()
{
	//wyl::listTest2();
	//wyl::listTest3();
	//wyl::listTest4();
	//wyl::listTest5();
	wyl::listTest6();

}

void AVLTest()
{
	wyl::AVLTest1();
}

void RBTTest()
{
	wyl::RBTTest1();
}
int main()
{
	//vectorTest();
	//listTest();
	//AVLTest();
	RBTTest();
}