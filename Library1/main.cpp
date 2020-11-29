#include "Run.h"

int main(){
	ARRAYBOOK a;
	TREE_READERTICKET tree;
	a.numberBook=0;
	Khoitao(tree,a);
	while (true)
	{	
		runMenu(tree, a);
		Sleep(100);
	}
	return 0;
}
