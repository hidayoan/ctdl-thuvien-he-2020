void themTheDocGiaFile(TREE_READERTICKET &t, int x, ifstream& fileIn){
	if(t == NULL){
		TREE_READERTICKET p = new NODEREADERTICKET;
		p->data.idReader = x;
		fileIn.ignore();
		getline(fileIn, p->data.lastname,',');
		getline(fileIn, p->data.firstname, ',');
		getline(fileIn, p->data.sex, ',');
		fileIn >> p->data.status;
		fileIn.ignore();
		p->data.numberBookBorrow = 0;
		p->data.daysOverdueMax = 0;
		p->data.doublelist_borrowReturn.pHead = NULL;
		p->data.doublelist_borrowReturn.pTail = NULL;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else if(t->data.idReader > x){
		themTheDocGiaFile(t->pLeft, x, fileIn);
	}
	else{
		themTheDocGiaFile(t->pRight, x, fileIn);
	}
}

void loadTheDocGia(TREE_READERTICKET &t){
	int MaDocGia;
	ifstream FileIn;
	FileIn.open("docgia.txt", ios::in);
	string tam;
	while(true)
	{
		MaDocGia = 0;
		FileIn >> MaDocGia;
		if (MaDocGia == 0)
		{
			break;
		}
		randomArray[randomInt] = true;
		numberReaderTicket++;
		themTheDocGiaFile(t, MaDocGia, FileIn);
		if (FileIn.eof())
		{
			break;
		}
	}
	FileIn.close();
}

void loadDauSach(ARRAYBOOK &m){
	int n;
	string vitri;
	ifstream fileIn;
	fileIn.open("dausach.txt",ios::in);
	fileIn>>n;
	fileIn.ignore();
	for(int i = 0; i < n; i++){
		m.nodesBook[m.numberBook] = new BOOK;
		getline(fileIn, m.nodesBook[m.numberBook]->idBook,',');
		getline(fileIn, m.nodesBook[m.numberBook]->nameBook,',');
		fileIn>>m.nodesBook[m.numberBook]->numberPages;
		fileIn.ignore();
		getline(fileIn, m.nodesBook[m.numberBook]->actor,',');
		fileIn>>m.nodesBook[m.numberBook]->publishingYear;
		fileIn.ignore();
		getline(fileIn, m.nodesBook[m.numberBook]->type,',');
		fileIn>>m.nodesBook[m.numberBook]->numbersBook;
		fileIn.ignore();
		getline(fileIn,vitri);
		m.nodesBook[i]->numberBorrows = 0;
		m.nodesBook[m.numberBook]->listBL.pHead = NULL;
		m.nodesBook[m.numberBook]->listBL.pTail = NULL;
		for(int i = 1; i <= m.nodesBook[m.numberBook]->numbersBook;i++){
			addBookList(m, addIdBook(m.nodesBook[m.numberBook]->idBook, i),vitri);
		}
		m.numberBook++;
	}
	fileIn.close();
}


void ThemDanhSachSachMuonTraTuFile(TREE_READERTICKET& t, int x, ifstream& FileIn, ARRAYBOOK& DauS)
{
	if (t == NULL)
	{
		return;
	}
	else if (t->data.idReader == x)
	{
		NODEDOUBLE_BORROWRETURN* p = new NODEDOUBLE_BORROWRETURN;
		if (p == NULL)
		{
			cout << "\nCap phat that bai !";
			return;
		}
		getline(FileIn, p->data.idBookList, ',');
		FileIn >> p->data.dateBorrow.day;
		FileIn.ignore();
		//FileIn.seekg(1, ios::cur);
		FileIn >> p->data.dateBorrow.month;
		FileIn.ignore();
		//FileIn.seekg(1, ios::cur);
		FileIn >> p->data.dateBorrow.year;
		FileIn.ignore();
		//.seekg(1, ios::cur);
		FileIn >> p->data.dateReturn.day;
		FileIn.ignore();
		//FileIn.seekg(1, ios::cur);
		FileIn >> p->data.dateReturn.month;
		FileIn.ignore();
		//FileIn.seekg(1, ios::cur);
		FileIn >> p->data.dateReturn.year;
		FileIn.ignore();
		//FileIn.seekg(1, ios::cur);
		FileIn >> p->data.status;
		if (p->data.status == 0)
		{
			t->data.numberBookBorrow++;
		}
		else if (p->data.status == 3)
		{
			t->data.status = 0;
		}
		p->pNext = NULL;
		p->pPrev = NULL;

		for (int i = 0; i < DauS.numberBook; i++)
		{
			if (tachLayMaDauSach(p->data.idBookList) == DauS.nodesBook[i]->idBook)
			{
				for (NODE_BOOKLIST* k = DauS.nodesBook[i]->listBL.pHead; k != NULL; k = k->pNext)
				{
					if (p->data.idBookList == k->data.idBookList)
					{
						DauS.nodesBook[i]->numberBorrows++;
						if (p->data.status == 0) // dang muon
						{
							k->data.status = 1; //da co doc gia muon
						}
						else if(p->data.status == 1){
							k->data.status = 0;
						}
						else if (p->data.status == 2)// lam mat
						{
							k->data.status = 2; //da thanh li
						}
						break;
					}
				}
				break;
			}
		}
		
		if (t->data.doublelist_borrowReturn.pHead == NULL)
		{
			t->data.doublelist_borrowReturn.pHead = t->data.doublelist_borrowReturn.pTail = p;
		}
		else
		{
			t->data.doublelist_borrowReturn.pTail->pNext = p;
			p->pPrev = t->data.doublelist_borrowReturn.pTail;
			t->data.doublelist_borrowReturn.pTail = p;
		}
		return;
	}
	else if (t->data.idReader > x)
	{
		ThemDanhSachSachMuonTraTuFile(t->pLeft, x, FileIn, DauS);
	}
	else
	{
		ThemDanhSachSachMuonTraTuFile(t->pRight, x, FileIn, DauS);
	}
}

void LoadFileDanhSachSachMuonTra(TREE_READERTICKET& t, ARRAYBOOK& DauS)
{
	int x;
	ifstream FileIn;
	FileIn.open("danhsachmuon.txt", ios::in);
	while (1)
	{
		x = 0;
		FileIn >> x;
		FileIn.ignore();
		//FileIn.seekg(1, ios::cur);
		if (x == 0)
		{
			break;
		}
		ThemDanhSachSachMuonTraTuFile(t, x, FileIn, DauS);
		if (FileIn.eof())
		{
			break;
		}
	}
	FileIn.close();
}

void load(ARRAYBOOK &m, TREE_READERTICKET &t){
	loadDauSach(m);
	loadTheDocGia(t);
	LoadFileDanhSachSachMuonTra(t, m);
}


