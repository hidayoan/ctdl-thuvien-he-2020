void xoaDauList(LIST_BOOKLIST &l){
	if(l.pHead == NULL){
		return;
	}
	NODE_BOOKLIST* p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;	
}
void xoaDauDoubleList(LISTDOUBLE_BORROWRETURN &l){
	if(l.pHead == NULL){
		return;
	}
	else{
		NODEDOUBLE_BORROWRETURN* p = l.pHead;
		if(l.pHead->pNext == NULL){
			l.pHead = NULL;
		}
		else {
			l.pHead = l.pHead->pNext;
			l.pHead->pPrev = NULL;
		}
		delete p;
	}
}

void deleteTree(TREE_READERTICKET &t){
	if(t == NULL){
		return;
	}
	else {
		deleteTree(t->pLeft);
		deleteTree(t->pRight);
		while(t->data.doublelist_borrowReturn.pHead!=NULL){
			xoaDauDoubleList(t->data.doublelist_borrowReturn);
		}
	}
}

void deleteMemory(TREE_READERTICKET &t, ARRAYBOOK &m){
	delete[] randomArray;
	
	deleteTree(t);
	for(int i = 0; i< m.numberBook; i++){
		while(m.nodesBook[i]->listBL.pHead != NULL){
			xoaDauList(m.nodesBook[i]->listBL);
		}
		delete m.nodesBook[i];
	}

}
