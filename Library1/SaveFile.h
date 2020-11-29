void saveDauSach(ARRAYBOOK m){
	ofstream fileOut;
	fileOut.open("dausach.txt", ios::out);
	fileOut<< m.numberBook <<endl;
	for(int i = 0; i< m.numberBook; i++){
		fileOut<< m.nodesBook[i]->idBook<<",";
		fileOut<< m.nodesBook[i]->nameBook<<",";
		fileOut<< m.nodesBook[i]->numberPages<<",";
		fileOut<< m.nodesBook[i]->actor<<",";
		fileOut<< m.nodesBook[i]->publishingYear<<",";
		fileOut<< m.nodesBook[i]->type<<",";
		fileOut<< m.nodesBook[i]->numbersBook<<",";
		fileOut<< m.nodesBook[i]->listBL.pHead->data.locate<<endl;
	}
	fileOut.close();
}
void saveDanhSachDocGia_MuonTra(TREE_READERTICKET t, ofstream& fileOut, ofstream &fileOut1){
	if(t == NULL){
		return;
	}
	else{
		fileOut << t->data.idReader<<",";
		fileOut << t->data.lastname << ",";
		fileOut << t->data.firstname << ",";
		fileOut << t->data.sex << ",";
		fileOut << t->data.status << endl;
		for(NODEDOUBLE_BORROWRETURN* k = t->data.doublelist_borrowReturn.pHead; k!=NULL; k = k->pNext){
			fileOut1 << t->data.idReader <<","<<k->data.idBookList<<",";
			fileOut1 << k->data.dateBorrow.day << "/" << k->data.dateBorrow.month << "/" << k->data.dateBorrow.year << ",";
			fileOut1 << k->data.dateReturn.day << "/" << k->data.dateReturn.month << "/" << k->data.dateReturn.year << ",";
			fileOut1 << k->data.status<< endl;
		}
		saveDanhSachDocGia_MuonTra(t->pLeft,fileOut,fileOut1);
		saveDanhSachDocGia_MuonTra(t->pRight,fileOut, fileOut1);
	}
}

void save(TREE_READERTICKET t, ARRAYBOOK m){
	saveDauSach(m);
	ofstream fileOut, fileOut1;
	fileOut.open("docgia.txt",ios::out);
	fileOut1.open("danhsachmuon.txt",ios::out);
	saveDanhSachDocGia_MuonTra(t, fileOut, fileOut1);
	fileOut.close();
	fileOut1.close();
}
