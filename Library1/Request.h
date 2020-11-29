//a them xoa sua
// **** chua xoa ky tu nhap sai
// them
bool inputInfoReader(string &firstname, string &lastname, string &sex ){
	//giao dien
	cin.ignore();
	VeHCN(80,10,30,2,4);
	VeHCN(80,13,30,2,14);
	VeHCN(80,16,30,2,14);
	VeHCN(80,19,30,2,14);
	gotoXY(60,11);cout<<"MA THE DOC GIA :";
	gotoXY(60,14);cout<<"HO VA TEN LOT  :";
	gotoXY(60,17);cout<<"TEN            :";
	gotoXY(60,20);cout<<"GIOI TINH      :";
	//nhap ho
	gotoXY(82,14); getline(cin, lastname); 
	while(lastname.empty()){
		gotoXY(115, 14); cout<<"Ho va ten lot khong duoc de trong";
		Sleep(750);
		gotoXY(115, 14); cout<<"                                 ";
		gotoXY(82,14); cout<< "               ";
		gotoXY(82,14); getline(cin, lastname);
	}
	//cin.ignore();
	gotoXY(82,17); getline(cin, firstname);
	while(firstname.empty()){
		gotoXY(115, 17); cout<<"Ten khong duoc de trong";
		Sleep(750);
		gotoXY(115, 17); cout<<"                                 ";
		gotoXY(82,17); cout<< "               ";
		gotoXY(82,17); getline(cin, firstname);
	}
	gotoXY(82,20); getline(cin, sex);
	while(sex.empty() || !(sex == "nu" || sex == "nam")){
		gotoXY(115, 20); cout<<"Sai dinh dang cho phep";
		Sleep(750);
		gotoXY(115, 20); cout<<"                                 ";
		gotoXY(82,20); cout<< "               ";
		gotoXY(82,20); getline(cin, sex);
	}
	//box xac nhan
	ToMauHCN(70, 20, 50, 10, 240);
	textcolor(240);
	gotoXY(83, 23);
	cout << "Ban Co Chac Chan Muon Them";
	gotoXY(87, 25);
	cout << "Enter De Tiep Tuc ";
	gotoXY(90, 26);
	cout << "ECS De Huy ";
	textcolor(7);
	while(true){
		char c = getch();
		if(c == ENTER){
			DinhDangChuoi(lastname);
			DinhDangChuoi(firstname);
			return true;
			// dinh dang lai input dung chuan
		}
		else if(c == ESC){
			textcolor(7);
			system("cls");
			return false;
		}
	}
}

void addReader(TREE_READERTICKET &t,int x){
	if(t == NULL){
		if(numberReaderTicket == randomInt){
			return;
		}
		system("cls");
		DeMuc("THEM DOC GIA");
		NODEREADERTICKET* p = new NODEREADERTICKET;
		p->data.idReader = x; //in id random
		gotoXY(82,11);cout<< x;
		if(!inputInfoReader(p->data.firstname, p->data.lastname, p->data.sex)){
			return; //neu Enter thi xuong lenh duoi, ESC thi thoat chuc nang
		}
		//khoi tao gia tri ban dau cho doc gia
		numberReaderTicket++;
		p->data.numberBookBorrow = 0;
		p->data.daysOverdueMax = 0;
		p->data.status = 1;
		p->data.doublelist_borrowReturn.pHead = NULL;
		p->data.doublelist_borrowReturn.pTail = NULL;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
		GiaoDienThongBaoThanhCong("Dang Ki Thanh Cong");
	}
	// sap xep doc gia moi them vao vao cay doc gia
	else{
		if(t->data.idReader > x){
			addReader(t->pLeft, x);
		}
		else if(t->data.idReader < x){
			addReader(t->pRight, x);
		}
	}
	
}

// sua
// de quy lay thong tin doc gia
void getInfoReader(TREE_READERTICKET t, int idReader,TREE_READERTICKET& temp){
	if(t == NULL){
		return;
	}
	else if(t->data.idReader == idReader){
		temp = t;
		return;
	}
	else if(idReader > t->data.idReader){
		getInfoReader(t->pRight, idReader, temp);
	}
	else {
		getInfoReader(t->pLeft, idReader, temp);
	}
}
//sua thong tin doc gia
void updateInfoReader(TREE_READERTICKET &t){
	cin.ignore();
	system("cls");
	DeMuc("CAP NHAT THONG TIN DOC GIA");
	int id;
	xuLyNhapMaDocGia(id, t, 70,10,"layHet");
	if(id == -999){
		return;
	}
	system("cls");
	TREE_READERTICKET tempTree = NULL;//tao 1 cay tam luu tru du lieu moi cua doc gia
	getInfoReader(t, id, tempTree);
	string tempL, tempF, tempSex;
	tempL = tempTree->data.lastname;
	tempF = tempTree->data.firstname;
	tempSex = tempTree->data.sex;
	
	cin.ignore();
	VeHCN(60,10,30,2,4);
	VeHCN(60,13,30,2,14);
	VeHCN(60,16,30,2,14);
	VeHCN(60,19,30,2,14);

	VeHCN(95,13,30,2,4);
	VeHCN(95,16,30,2,4);
	VeHCN(95,19,30,2,4);
	
	gotoXY(40,11);cout<<"MA THE DOC GIA :";
	gotoXY(40,14);cout<<"HO VA TEN LOT  :";
	gotoXY(40,17);cout<<"TEN            :";
	gotoXY(40,20);cout<<"GIOI TINH      :";
	
	gotoXY(62,11);cout<<tempTree->data.idReader;
	gotoXY(97,14);cout<<tempTree->data.lastname;
	gotoXY(97,17);cout<<tempTree->data.firstname;
	gotoXY(97,20);cout<<tempTree->data.sex;
	
	gotoXY(62,14); getline(cin, tempTree->data.lastname);
	while(tempTree->data.lastname.empty()){
		gotoXY(127, 14); cout<<"Ho va ten lot khong duoc de trong";
		Sleep(750);
		gotoXY(127, 14); cout<<"                                 ";
		gotoXY(62,14); cout<< "                ";
		gotoXY(62,14); getline(cin, tempTree->data.lastname);
	}
	gotoXY(62,17); getline(cin, tempTree->data.firstname);
	while(tempTree->data.firstname.empty()){
		gotoXY(127, 17); cout<<"Ten khong duoc de trong";
		Sleep(750);
		gotoXY(127, 17); cout<<"                                 ";
		gotoXY(62,17); cout<< "                ";
		gotoXY(62,17); getline(cin, tempTree->data.firstname);
	}
	gotoXY(62,20); getline(cin, tempTree->data.sex);
	while(tempTree->data.sex.empty() || !(tempTree->data.sex == "nu" || tempTree->data.sex == "nam")){
		gotoXY(127, 20); cout<<"Sai dinh dang cho phep";
		Sleep(750);
		gotoXY(127, 20); cout<<"                                 ";
		gotoXY(62,20); cout<< "                ";
		gotoXY(62,20); getline(cin, tempTree->data.sex);
	}
	ToMauHCN(70, 20, 50, 10, 240);
	textcolor(240);
	gotoXY(83, 23);
	cout << "Ban Co Chac Chan Muon Them";
	gotoXY(87, 25);
	cout << "Enter De Tiep Tuc ";
	gotoXY(90, 26);
	cout << "ECS De Huy ";
	textcolor(7);
	while(true){
		char c = getch();
		if(c == ENTER){
			DinhDangChuoi(tempTree->data.lastname);
			DinhDangChuoi(tempTree->data.firstname);
			GiaoDienThongBaoThanhCong("Dang Ki Thanh Cong");
			return;
		}
		else if(c == ESC){
			textcolor(7);
		 	tempTree->data.lastname = tempL;
			tempTree->data.firstname = tempF;
			tempTree->data.sex = tempSex;	
			system("cls");
			return ;
		}
	}
}

// xoa 

TREE_READERTICKET removeReader(TREE_READERTICKET t, int x){
	if(t == NULL){
		return NULL;
	}
	if(t->data.idReader == x){
		if(t->pLeft == NULL && t->pRight == NULL){
			return NULL;
		}
		if(t->pLeft != NULL && t->pRight != NULL){
			TREE_READERTICKET temp = t->pRight;	
			while(temp->pLeft != NULL){
				temp = temp->pLeft;
			}
			t->data = temp->data;
			removeReader(t->pRight, temp->data.idReader);
			return t;
		}
		if(t->pLeft != NULL){
			return t->pLeft;
		}
		if(t->pRight != NULL){
			return t->pRight;
		}
	}
	if(x > t->data.idReader){
		t->pRight = removeReader(t->pRight, x);
	}
	else{
		t->pLeft = removeReader(t->pLeft, x);
	}
	return t;
}
//in thong tin 1 doc gia
void printReader(TREE_READERTICKET t, int toadoX,int toadoY){
	gotoXY(toadoX + 1, toadoY+5);
	cout<< CanDeuChuoi(ChuyenSoSangString(t->data.idReader), 8);
	gotoXY(toadoX + 11, toadoY+5);
	cout << CanDeuChuoi(t->data.lastname + " " + t->data.firstname, 28);
	gotoXY(toadoX + 41, toadoY+5);
	cout << CanDeuChuoi(t->data.sex, 14);
	gotoXY(toadoX + 56, toadoY+5);
	cout << CanDeuChuoi(TrangThaiDocGia(t->data.status), 14);
	gotoXY(toadoX + 71, toadoY+5);
	cout << CanDeuChuoi(ChuyenSoSangString(t->data.numberBookBorrow), 14);
	gotoXY(toadoX + 86, toadoY+5);
	cout << CanDeuChuoi(ChuyenSoSangString(t->data.daysOverdueMax), 14);
}
//xoa doc gia
void deleteReader(TREE_READERTICKET &t){
	system("cls");
xoa:DeMuc("XOA THONG TIN DOC GIA");
	int id = 0;
	xuLyNhapMaDocGia(id , t, 70, 10, "xoa");
	if(id == -999){
		return;
	}
	TREE_READERTICKET tempTree = NULL;
	getInfoReader(t, id, tempTree);
	system("cls");
	gotoXY(75, 11);cout << "Thong Tin Doc Gia";
	printReaderUI(30,15);
	//in doc gia vua chon
	printReader(tempTree,30,15);
	Pause("");
	ToMauHCN(70, 20, 50, 10, 240);
	textcolor(240);
	gotoXY(83, 23);
	cout << "Ban Co Chac Chan Muon Xoa";
	gotoXY(87, 25);
	cout << "Enter De Tiep Tuc ";
	gotoXY(90, 26);
	cout << "ECS De Huy ";
	textcolor(7);
	while(true){
		char c = getch();
		if(c == ENTER){
			t = removeReader(t,tempTree->data.idReader);
			numberReaderTicket--;
			GiaoDienThongBaoThanhCong("Xoa Thanh Cong");
			return;
		}
		else if(c == ESC){
			system("cls");
			goto xoa;
			return ;
		}
	}
}

// cau b

void printListReader(READERTICKET t,int toadoX, int toadoY){
	gotoXY(toadoX + 1, toadoY+5);
	cout<< CanDeuChuoi(ChuyenSoSangString(t.idReader), 8);
	gotoXY(toadoX + 11, toadoY+5);
	cout << CanDeuChuoi(t.lastname + " " + t.firstname, 28);
	gotoXY(toadoX + 41, toadoY+5);
	cout << CanDeuChuoi(t.sex, 14);
	gotoXY(toadoX + 56, toadoY+5);
	cout << CanDeuChuoi(TrangThaiDocGia(t.status), 14);
	gotoXY(toadoX + 71, toadoY+5);
	cout << CanDeuChuoi(ChuyenSoSangString(t.numberBookBorrow), 14);
	gotoXY(toadoX + 86, toadoY+5);
	cout << CanDeuChuoi(ChuyenSoSangString(t.daysOverdueMax), 14);
}

void printPage(READERTICKET t[], int n){
	int pageNumber = 0;
	int surplus = 0;
	int page = 1;
	giaoDienXuatDanhSachDocGia();
	if(n == 0){
		ToMauHCN(75,18,50,4,240);
		textcolor(240);
		cout << "Khong Co Doc Gia Nao !!!";
		textcolor(7);
		Pause("");
		system("cls");
	}
	else {
		if(n <= 10){
			for(int i = 0; i < n;i++){
				printListReader(t[i], 30, i + 15 - (page - 1)*10);
			}
			gotoXY(78,35);cout<<"1/1";
		}
		else {
			if(n % 10 != 0){
				pageNumber = n / 10 + 1;
			}
			else{
				pageNumber = n / 10;
			}
			gotoXY(78,35);cout<<"1/"<<pageNumber;
			for(int i = 0; i < 10;i++){
				printListReader(t[i], 30, i + 15 - (page - 1)*10);
			}
		}
		while(true){
			if(kbhit()){
				char c = getch();
				if(c == -32 && n > 10){
					c = getch();
					if(c == 77  && n > 10){ // sang phai
						if(page < pageNumber){
							page++;
							int tam;
							if(page*10 < n){
								tam = page*10;
							}
							else{
								tam = n;
							}
							XoaManHinhTuyChon(31,15,101,23);
							giaoDienXuatDanhSachDocGia();
							for(int i = page*10-10;i< tam; i++){
								printListReader(t[i],30,i +15 - (page-1)*10);
							}
							gotoXY(98,35);
							cout<< page << "/" << pageNumber;
						}
						else{
							XoaManHinhTuyChon(31,15,101,23);
							giaoDienXuatDanhSachDocGia();
							page = 1;
							for(int i = page*10-10;i< page*10; i++){
								printListReader(t[i],30,i +15 - (page-1)*10);
							}
							gotoXY(98,35);
							cout<< page << "/" << pageNumber;
						}
					}
					else if(c == 75 && n > 10){ //qua trai
						if(page > 1){
							XoaManHinhTuyChon(31,15,101,23);
							giaoDienXuatDanhSachDocGia();
							page--;
							for(int i = page*10-10;i< page*10; i++){
								printListReader(t[i],30,i +15 - (page-1)*10);
							}
							gotoXY(98,35);
							cout<< page << "/" << pageNumber;
						}
						else{
							XoaManHinhTuyChon(31,15,101,23);
							giaoDienXuatDanhSachDocGia();
							page = pageNumber;
							for(int i = page*10-10;i< n; i++){
								printListReader(t[i],30,i +15 - (page-1)*10);
							}
							gotoXY(98,35);
							cout<< pageNumber << "/" << pageNumber;
						}
					}
				}
				else if(c == ESC){
					system("cls");
					return;
				}
			}
		}
	}
}

void printByName(TREE_READERTICKET t){
	READERTICKET *arr = new READERTICKET[numberReaderTicket];
	int n;
	sortByName(t, arr, n);
	printPage(arr, n);
}

void printByID(TREE_READERTICKET t){
	READERTICKET *arr = new READERTICKET[numberReaderTicket];
	int n;
	treeToArray(t, arr, n);
	printPage(arr, n);
}

void printReaderTicket(TREE_READERTICKET t){
	system("cls");
	DeMuc("DANH SACH DOC GIA");
	char c;
	int pointY = 15;
	while(true){
		ShowCur(0);
		VeHCN(65,13,50,4,15);
		VeHCN(65,18,50,4,15);
		gotoXY(80,15);cout<<"Sap Xep Theo Ho Ten";
		gotoXY(80,20);cout<<"Sap Xep Theo Ma The";
		textcolor(7);
		if(kbhit()){
			c = getch();
			if(c == -32){
				c= getch();
				if(c == 80 || c == 72){
					if(pointY == 15){
						pointY = 20;
					}
					else pointY = 15;
				}
			}
			else if(c == ENTER){
				switch(pointY){
					case 15:{//sap xep theo ten
						XoaManHinhTuyChon(41,15,111,23);
						textcolor(14);gotoXY(85,18);cout<<"Danh Sach Doc Gia Theo Ho Ten";
						printByName(t);
						break;
					}
					case 20:{
						XoaManHinhTuyChon(41,15,111,23);
						textcolor(14);gotoXY(85,18);cout<<"Danh Sach Doc Gia Theo Ma The";
						printByID(t);
						break;
					}
				}
			}
			else if(c == ESC){
				return;
			}
		}
		gotoXY(80, pointY);
		textcolor(14);
		if(pointY == 15){
			gotoXY(80,pointY);cout<<"Sap Xep Theo Ho Ten";
			VeHCN(65,13,50,4,4);
		}
		else if(pointY == 20){
			gotoXY(80,pointY);cout<<"Sap Xep Theo Ma The";
			VeHCN(65,18,50,4,4);
		}
		textcolor(7);
		Sleep(100);
	}
}

//cau c

bool checkBookID(ARRAYBOOK m, string idBook){
	bool check = true;
	for(int i = 0 ;i <  m.numberBook; i++){
		if(m.nodesBook[i]->idBook == idBook){
			check = false;
			break;
		}
	}
	return check;
}

bool inputBook(ARRAYBOOK &m, string &locate){
	system("cls");
	cin.ignore();
	string temp;
	ShowCur(1);
	giaoDienNhapDauSach();
	m.nodesBook[m.numberBook]->numberBorrows = 0;
	//idBook
	gotoXY(72,9);getline(cin, temp);
	while(temp.empty() || temp.length() != 6 || !checkBookID(m, upper(temp) ) ){
		gotoXY(122,9); cout<<"Khong duoc de trong hoac qua 6 ki tu";
		Sleep(750);
		gotoXY(122,9); cout<<"                                    ";
		gotoXY(72,9);cout<<"                                      ";
		gotoXY(72,9);getline(cin, temp);
	}
	m.nodesBook[m.numberBook]->idBook = temp;
	//bookname
	gotoXY(72,12);getline(cin, m.nodesBook[m.numberBook]->nameBook);
	while(m.nodesBook[m.numberBook]->nameBook.empty() || m.nodesBook[m.numberBook]->nameBook.length() > 20){
		gotoXY(122,12); cout<<"Khong duoc de trong hoac qua 20 ki tu";
		Sleep(750);
		gotoXY(122,12); cout<<"                                    ";
		gotoXY(72,12);cout<<"                                     ";
		gotoXY(72,12);getline(cin, m.nodesBook[m.numberBook]->nameBook);
	}
	//numberPages
	gotoXY(72,15);getline(cin, temp);
	while(temp.empty() || atoi(temp.c_str()) == 0){
		gotoXY(122,15); cout<<"Sai dinh dang";
		Sleep(750);
		gotoXY(122,15); cout<<"                                    ";
		gotoXY(72,15);cout<<"                                     ";
		gotoXY(72,15);getline(cin, temp);
	}
	m.nodesBook[m.numberBook]->numberPages = atoi(temp.c_str());
	//actor
	gotoXY(72,18);getline(cin, m.nodesBook[m.numberBook]->actor);
	while(m.nodesBook[m.numberBook]->actor.empty() || m.nodesBook[m.numberBook]->actor.length() > 20){
		gotoXY(122,18); cout<<"Khong de trong hoac qua 20 ki tu";
		Sleep(750);
		gotoXY(122,18); cout<<"                                    ";
		gotoXY(72,18);cout<<"                                     ";
		gotoXY(72,18);getline(cin, m.nodesBook[m.numberBook]->actor);
	}
	//year publishing
	gotoXY(72,21);getline(cin, temp);
	while(temp.empty() || atoi(temp.c_str()) == 0 || atoi(temp.c_str()) < 1800 || atoi(temp.c_str()) > 2020){
		gotoXY(122,21); cout<<"Sai dinh dang";
		Sleep(750);
		gotoXY(122,21); cout<<"                                    ";
		gotoXY(72,21);cout<<"                                     ";
		gotoXY(72,21);getline(cin, temp);
	}
	m.nodesBook[m.numberBook]->publishingYear = atoi(temp.c_str());
	//type
	gotoXY(72,24);getline(cin, m.nodesBook[m.numberBook]->type);
	while(m.nodesBook[m.numberBook]->type.empty() || m.nodesBook[m.numberBook]->type.length() > 20){
		gotoXY(122,24); cout<<"Khong de trong hoac qua 20 ki tu";
		Sleep(750);
		gotoXY(122,24); cout<<"                                    ";
		gotoXY(72,24);cout<<"                                     ";
		gotoXY(72,24);getline(cin, m.nodesBook[m.numberBook]->type);
	}
	//locate
	gotoXY(72,27);getline(cin, locate);
	while(locate.empty() || locate.length() > 20){
		gotoXY(122,27); cout<<"Khong de trong hoac qua 20 ki tu";
		Sleep(750);
		gotoXY(122,27); cout<<"                                    ";
		gotoXY(72,27);cout<<"                                     ";
		gotoXY(72,27);getline(cin, locate);
	}
	//number of book
	gotoXY(72,30);getline(cin, temp);
	while(temp.empty() || atoi(temp.c_str()) == 0){
		gotoXY(122,30); cout<<"Sai dinh dang";
		Sleep(750);
		gotoXY(122,30); cout<<"                                    ";
		gotoXY(72,30);cout<<"                                     ";
		gotoXY(72,30);getline(cin, temp);
	}
	m.nodesBook[m.numberBook]->numbersBook = atoi(temp.c_str());
	
	ToMauHCN(70, 20, 50, 10, 240);
	textcolor(240);
	gotoXY(83, 23);
	cout << "Ban Co Chac Chan Muon Them";
	gotoXY(87, 25);
	cout << "Enter De Tiep Tuc ";
	gotoXY(90, 26);
	cout << "ECS De Huy ";
	textcolor(7);
	while(true){
		char c = getch();
		if(c == ENTER){
			DinhDangChuoi(m.nodesBook[m.numberBook]->actor);
			DinhDangChuoi(m.nodesBook[m.numberBook]->nameBook);
			DinhDangChuoi(m.nodesBook[m.numberBook]->type);
			m.nodesBook[m.numberBook]->idBook = upper(m.nodesBook[m.numberBook]->idBook);
			DinhDangChuoi(locate);
			return true;
		}
		else if(c == ESC){
			textcolor(7);
			system("cls");
			return false;
		}
	}
}

void addBookList(ARRAYBOOK &m, string maSach, string viTri){
	NODE_BOOKLIST* p = new NODE_BOOKLIST;
	if(p == NULL){
		cout<<"\nCap Nhat That Bai";
	}
	p->data.idBookList = maSach;
	p->data.status = 0;
	p->data.locate = viTri;
	p->pNext = NULL;
	if(m.nodesBook[m.numberBook]->listBL.pHead == NULL){ // chua co ptu nao
		m.nodesBook[m.numberBook]->listBL.pHead = m.nodesBook[m.numberBook]->listBL.pTail = p;
	}
	else{
		m.nodesBook[m.numberBook]->listBL.pTail->pNext = p;
		m.nodesBook[m.numberBook]->listBL.pTail = p;
	}
}

void addBook(ARRAYBOOK &m){
	if(m.numberBook == 1000){
		ToMauHCN(50, 10, 100, 10, 240);
		textcolor(240);
		gotoXY(95,15);
		cout<<"FULL DAU SACH";
		Pause("");
		textcolor(7);
		return;
	}
	string locate;
	m.nodesBook[m.numberBook] = new Book;
	if(!inputBook(m, locate)){
		delete m.nodesBook[m.numberBook];
		return;
	}
	m.nodesBook[m.numberBook]->listBL.pHead = NULL;
	m.nodesBook[m.numberBook]->listBL.pTail = NULL;
	for(int i = 0; i <= m.numberBook; i++){
		addBookList(m, addIdBook(m.nodesBook[m.numberBook]->idBook,i), locate);
	}
	m.numberBook++;
	GiaoDienThongBaoThanhCong("Them Dau Sach Thanh Cong");
}


// **  xoa dau sach
void addBookIdToArray(TREE_READERTICKET t, string arrId[], int &n){
	if(t == NULL){
		return;
	}
	else{
		addBookIdToArray(t->pLeft, arrId,n);
		for(NODEDOUBLE_BORROWRETURN* k = t->data.doublelist_borrowReturn.pHead; k!=NULL; k = k->pNext){
			bool check = true;
			for(int i =0 ;i < n;i++){
				if(tachLayMaDauSach(k->data.idBookList) == arrId[i]){
					check = false;
					break;
				}
				else check = true;
			}
			if(check){
				arrId[n++] = tachLayMaDauSach(k->data.idBookList);
			}
		}
		addBookIdToArray(t->pRight, arrId,n);
	}
}
bool checkBookIdDelete(TREE_READERTICKET t, string id){
	string* arrId = new string[50];
	int n;
	addBookIdToArray(t, arrId, n);
	for(int i = 0; i< n; i++){
		if(arrId[i] == id){
			return true;
		}
	}
	return false;
}

bool checkBookIdArray(ARRAYBOOK m, string id)
{
	for (int i = 0; i < m.numberBook; i++)
	{
		if (m.nodesBook[i]->idBook == id)
		{
			return false;
		}
	}
	return true;
}

void xoaSach(ARRAYBOOK &m,TREE_READERTICKET t){
	system("cls");
	cin.ignore();
	if(m.numberBook == 0){
		return;
	}
	VeHCN(50,5,50,10,14);
	gotoXY(70,7); cout<< "XOA DAU SACH";
	gotoXY(55,10); cout<< "Nhap ma sach can xoa :";
	VeHCN(80,9,16,2,14);
	gotoXY(60,14); cout<< "ENTER: xoa          ESC: cancel";
	string temp;
	gotoXY(82,10); getline(cin, temp);
	if(checkBookIdDelete(t, temp) || temp.empty() || checkBookIdArray(m, temp)){
		gotoXY(55,12); cout<< "Ma Sach Nay Da Duoc Muon Hoac Ko Co That";
		Pause("");
		return;
	}
	
	ToMauHCN(70, 20, 50, 10, 240);
	textcolor(240);
	gotoXY(83, 23);
	cout << "Ban Co Chac Chan Muon Xoa";
	gotoXY(87, 25);
	cout << "Enter De Tiep Tuc ";
	gotoXY(90, 26);
	cout << "ECS De Huy ";
	textcolor(7);
	while(true){
		char c = getch();
		if(c == ENTER){
			int pos;
			for(int i = 0; i < m.numberBook; i++){
				if(m.nodesBook[i]->idBook == temp){
					pos = i;
				}	
			}
			for(int i = pos; i < m.numberBook; i++){
				m.nodesBook[i] = m.nodesBook[i+1];
			}
			m.numberBook--;
			GiaoDienThongBaoThanhCong("Xoa Dau Sach Thanh Cong");
			return;
		}
		else if(c == ESC){
			textcolor(7);	
			ShowCur(1);
			break;
		}
	}
}

// cau d

void sortByBookname(ARRAYBOOK &m){
	Book* temp;
	for(int i=0;i < m.numberBook - 1; i++){
		for(int j= i+1;j < m.numberBook;j++){
			if(m.nodesBook[i]->nameBook > m.nodesBook[j]->nameBook){
				temp = m.nodesBook[i];
				m.nodesBook[i] = m.nodesBook[j];
				m.nodesBook[j] = temp;
			}
		}
	}
}

void print1book(Book* t,int toadoX, int toadoY){
	gotoXY(toadoX + 1,toadoY);
	cout<<CanDeuChuoi(t->idBook,8);
	gotoXY(toadoX + 11,toadoY);
	cout<<CanDeuChuoi(t->nameBook,13);
	gotoXY(toadoX + 26,toadoY);
	cout<<CanDeuChuoi(ChuyenSoSangString(t->numberPages),8);
	gotoXY(toadoX + 36,toadoY);
	cout<<CanDeuChuoi(t->actor,13);
	gotoXY(toadoX + 51,toadoY);
	cout<<CanDeuChuoi(ChuyenSoSangString(t->publishingYear),8);
	gotoXY(toadoX + 61,toadoY);
	cout<<CanDeuChuoi(t->type,13);
	gotoXY(toadoX + 76,toadoY);
	cout<<CanDeuChuoi(t->listBL.pTail->data.locate,13);
	gotoXY(toadoX + 91,toadoY);
	cout<<CanDeuChuoi(ChuyenSoSangString(t->numbersBook),8);
}

void printPageBook(Book* list[], int n){
	int soTrang = 0;
	int sodu = 0;
	int trang = 1;
	
	int pageNumber = 0;
	int surplus = 0;
	int page = 1;
	
	giaoDienXuatDauSach();
	if(n == 0){
		ToMauHCN(35,18,50,4,240);
		textcolor(240);
		gotoXY(63,20);
		cout << "Khong Co Doc Gia Nao !!!";
		textcolor(7);
		Pause("");
		XoaManHinhTuyChon(21,15,111,23);
	}
	else {
		if(n <= 10){
			for(int i =0; i < n; i++){
				print1book(list[i],30,i +20 - (page-1)*10);
			}
			gotoXY(78,35);
			cout<< "1/1";
		}
		else{
			if(n % 10 != 0){
				pageNumber = n / 10 + 1;
				
			}
			else{
				pageNumber = n / 10;
			}
			gotoXY(78,35);
			cout<< "1/" << pageNumber;
			for(int i = 0; i<10;i++){
				print1book(list[i],30,i +20 - (page-1)*10);
			}
		}
		while(true){
			if(kbhit()){
				char c = getch();
				if(c == -32){
					c = getch();
					if(c == 77 && n > 10){
						if(page < pageNumber){
							page++;
							int tam;
							if(page*10 < n){
								tam = page*10;
							}
							else{
								tam = n;
							}
							XoaManHinhTuyChon(21,15,111,23);
							giaoDienXuatDauSach();
							for(int i = page*10-10;i< tam; i++){
								print1book(list[i],30,i +20 - (page-1)*10);
							}
							gotoXY(78,35);
							cout<< page << "/" << pageNumber;
						}
						else{
							XoaManHinhTuyChon(21,15,111,23);
							giaoDienXuatDauSach();
							trang = 1;
							for(int i = page*10-10;i< page*10; i++){
								print1book(list[i],30,i +20 - (page-1)*10);
							}
							gotoXY(78,35);
							cout<< page << "/" << pageNumber;
						}
					}
					else if(c == 75 && n > 10){
						if(trang > 1){
							XoaManHinhTuyChon(21,15,111,23);
							giaoDienXuatDauSach();
							page--;
							for(int i = page*10-10;i< page*10; i++){
								print1book(list[i],30,i +20 - (page-1)*10);
							}
							gotoXY(78,35);
							cout<< page << "/" << pageNumber;
						}
						else{
							XoaManHinhTuyChon(21,15,111,23);
							giaoDienXuatDauSach();
							page = pageNumber;
							for(int i = page*10-10;i< n; i++){
								print1book(list[i],30,i +20 - (page-1)*10);
							}
							gotoXY(78,35);
							cout<< pageNumber << "/" << pageNumber;
						}
					}
				}
				else if(c == ESC){
					XoaManHinhTuyChon(21,15,111,23);
					return;
				}
			}
		}
	}
}

void printBook(ARRAYBOOK m, string type){
	giaoDienXuatDauSach();
	Book* list[100];
	int h = 0;
	chuyenDauSachSangMang(m, list, h, type);
	printPageBook(list, h);
}

void chooseBookType(ARRAYBOOK m){
	system("cls");
	DeMuc("Danh Muc Cac The Loai Sach");
	string a[MAX];
	int n;
	sortByBookname(m);
	filterType(m, a, n);
	
	string input;
	for(int i = 0; i < n; i++){
		gotoXY(75, i*3+10);
		cout<< i+1 <<". "<<a[i];
	}
	while(true){
		ShowCur(0);
		for(int i = 0; i < n; i++){
			gotoXY(75, i*3+10);
			cout<< i+1 <<". "<<a[i];
		}		
		gotoXY(50,n*3+12); cout<< "Nhap Ma So Cua The Loai :";
		VeHCN(80,n*3 + 11,15,2,14);
		bool check = true;
		ShowCur(1);
		gotoXY(82, n*3 + 12);getline(cin, input);
		while(check){
			
			if(atoi(input.c_str()) > n || atoi(input.c_str()) <= 0 ){
				check = true;
			}
			else check = false;
			
			if(check == true){
				gotoXY(60,n*3 + 13);
				cout<<"Kiem Tra Lai!!!";
				ShowCur(1);
				gotoXY(82, n*3 + 12);cout<<"          ";
				gotoXY(82, n*3 + 12);
				getline(cin, input);
			}
		}
		for(int i = 0; i< n; i++){
			if(atoi(input.c_str()) - 1 == i){
				XoaManHinhTuyChon(41,9,111,29);
				printBook(m, a[atoi(input.c_str()) - 1]);
			}
		}
		
		char c = getch();
		if(c == ESC){
			return;
		}
		Sleep(100);
		
	}
}

// cau e

void printBookByKey(ARRAYBOOK m, string input){
	Book* temp[MAX];
	int h = 0;
	XoaManHinhTuyChon(41,15,111,23);
	for(int i = 0; i< m.numberBook; i++){
		if(m.nodesBook[i]->nameBook.find(input) != string::npos){
			temp[h] = m.nodesBook[i];
			h++;
		} 
	}
	printPageBook(temp, h);
}

void findBookByKey(ARRAYBOOK m){
	system("cls");
	cin.ignore();
	DeMuc("TIM KIEM SACH");
	gotoXY(57,12); cout<<"Nhap tu khoa can tim : ";
	VeHCN(80,11,20,2,14);
	string InPut;
	int toadoX = 82;
	int toadoY = 12;
	int LenghtMax = 10;
	int toadoXtam;
	char c;
	gotoXY(82,12);
	ShowCur(1);
	while(true){
		char c = _getch();
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) && InPut.length() < LenghtMax) // A-Z a-z
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);// them ki tu vua nhap vo chuoi input
			if ((whereX() - toadoX) < InPut.length() - 1)	//neu chuoi dai bang max length thi xu ly
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "        ";// xoa het ky tu
				gotoXY(toadoX, whereY());
				cout << InPut;												// in lai chuoi
				gotoXY(toadoXtam, whereY());								  // dua con tro lai cuoi chuoi~
			}
			else
				cout << c;		// neu chua maxt thi in bth
			
		}
		else if (c == 8 && whereX() > toadoX)  // xoa
		{
			InPut.erase(InPut.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "        ";
			gotoXY(toadoX, whereY());
			cout << InPut;
			gotoXY(toadoXtam, whereY());
			
		}
		else if (c == SPACEBAR && InPut.length() < LenghtMax && InPut.length() != 0 && InPut[whereX() - toadoX - 1] != ' ') //dau cach, kiem tra be hon max, khoang trong, ki tu dau
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), ' ');
			if ((whereX() - toadoX) < InPut.length() - 1) 
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "        ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
			
		}
		else if (c == ENTER && InPut.length() > 0)//enter thi` thoat ham nhap
		{
			printBookByKey(m,InPut);
			gotoXY(toadoX + InPut.length(), toadoY);
		}
		else if (c == -32) // cac phim len xuong
		{
			c = getch();
			if (c == 75 && whereX() > toadoX) //  qua trai
			{
				cout << "\b";
				gotoXY(whereX() - 1, whereY());
				
			}
			else if (c == 77 && whereX() < toadoX + InPut.length()) // qua phai
			{
				gotoXY(whereX() + 1, whereY());
			}
		}
		else if(c == ESC){
			return;
		}
	}
}

// cau f

void saveBookBorrow(TREE_READERTICKET &t, Book* tempBook, NODE_BOOKLIST* tempBookList, Date borrowDate){
	t->data.numberBookBorrow++;
	tempBookList->data.status = 1;
	tempBook->numberBorrows++;
	NODEDOUBLE_BORROWRETURN* p = new NODEDOUBLE_BORROWRETURN;
	if(p == NULL){
		cout << "\nCap phat that bai !";
		return;
	}
	p->data.idBookList = tempBookList->data.idBookList;
	p->data.dateBorrow = borrowDate;
	p->data.dateReturn.day = 0;
	p->data.dateReturn.month = 0;
	p->data.dateReturn.year = 0;
	p->data.status = 0;
	p->pNext = NULL;
	p->pPrev = NULL;
	
	if(t->data.doublelist_borrowReturn.pHead == NULL){
		t->data.doublelist_borrowReturn.pHead = p;
		t->data.doublelist_borrowReturn.pTail = p;	
	}
	else{
		t->data.doublelist_borrowReturn.pTail->pNext = p;
		p->pPrev = t->data.doublelist_borrowReturn.pTail;
		t->data.doublelist_borrowReturn.pTail = p;
	}
}

void printBookBorrow(ARRAYBOOK m, TREE_READERTICKET t, int toadoX, int toadoY){
	int j = 0;
	for(NODEDOUBLE_BORROWRETURN* k = t->data.doublelist_borrowReturn.pHead; k!=NULL; k = k->pNext){
		if(k->data.status == 0){
			gotoXY(toadoX + 2, toadoY +3 +j);
			cout<< CanDeuChuoi(k->data.idBookList,18);
			gotoXY(toadoX + 22, toadoY +3 +j);
			cout<< CanDeuChuoi(layTenSach(m, k->data.idBookList),38);
			gotoXY(toadoX + 62, toadoY +3 +j);
			cout<< CanDeuChuoi(trangThaiMuonTra(k->data.status),18);
			gotoXY(toadoX + 82, toadoY +3 +j);
			cout<< CanDeuChuoi(formatDate(k->data.dateBorrow.day, k->data.dateBorrow.month, k->data.dateBorrow.year),18);
			j++;
		}
	}
}

void printBookReturn(ARRAYBOOK m, TREE_READERTICKET t, int toadoX, int toadoY){
	int j = 0;
	for(NODEDOUBLE_BORROWRETURN* k = t->data.doublelist_borrowReturn.pHead; k!=NULL; k = k->pNext){
		if(k->data.status != 1){
			gotoXY(toadoX + 2, toadoY +3 +j);
			cout<< CanDeuChuoi(k->data.idBookList,18);
			gotoXY(toadoX + 22, toadoY +3 +j);
			cout<< CanDeuChuoi(layTenSach(m, k->data.idBookList),38);
			gotoXY(toadoX + 62, toadoY +3 +j);
			cout<< CanDeuChuoi(trangThaiMuonTra(k->data.status),18);
			gotoXY(toadoX + 82, toadoY +3 +j);
			cout<< CanDeuChuoi(formatDate(k->data.dateBorrow.day, k->data.dateBorrow.month, k->data.dateBorrow.year),18);
			j++;
		}
	}
}

void borrowBook(TREE_READERTICKET &t, ARRAYBOOK &m){
	system("cls");
	Date now;
	LayNgayHienTai(now);
	
	if(m.numberBook == 0){
		GiaoDienThongBaoThanhCong("Khong Co Sach Nao");
		return;
	}
	
	int idReader = 0;
	string idBookList;
	TREE_READERTICKET tempReader;
	Book* tempBook = NULL;
	NODE_BOOKLIST* tempBookList;
	Date dateBorrow;
	LayNgayHienTai(dateBorrow);
	DeMuc("MUON SACH");
t:	xuLyNhapMaDocGia(idReader, t, 70, 10, "muon" );
	if(idReader == -999){ //ESC thi tra ve id nay
		return;
	}
	cin.ignore();
	getInfoReader(t,idReader, tempReader);
a:	if(tempReader->data.numberBookBorrow >= 3){	
		ShowCur(0);
		ToMauHCN(35,14,50,9,240);
		textcolor(240);
		gotoXY(68,18);cout<<"Doc Gia Da Muon 3 cuon";
		textcolor(7);
		Pause("");
		XoaManHinhTuyChon(21,10,111,26);
		goto t;
	}
	idBookList = "";
	XoaManHinhTuyChon(21,10,111,23);
	giaoDienMuonSach();
	printBookBorrow(m, tempReader,30,27);
	
	gotoXY(102,20);cout<<dateBorrow.day;
	gotoXY(113,20);cout<<dateBorrow.month;
	gotoXY(124,20);cout<<dateBorrow.year;
	gotoXY(47,11); textcolor(4); cout<< tempReader->data.idReader;
	gotoXY(47,14); textcolor(7); cout<< hoTen(tempReader->data.lastname, tempReader->data.firstname);
	gotoXY(47,17); cout<< TrangThaiDocGia(tempReader->data.status);
	if(tempReader->data.numberBookBorrow < 3){
		ShowCur(1);
		gotoXY(102,11); getline(cin, idBookList);
		if(layTenSach(m, idBookList) == "Ma Sach Khong Ton Tai" || idBookList.length() < 8){
			
			ShowCur(0);
			ToMauHCN(55,14,50,9,240);
			textcolor(240);
			gotoXY(68,18);cout<<"Ma Sach Khong Ton Tai!!!";
			textcolor(7); 
			while (true) 
			{
				char c = getch();
				if (c==ENTER)
				{
					system("cls");
				goto a;
				}
				else if (c==ESC)
				{
					return;
				}
				
			}
		}
		
		if(!layThongTinSach(m, idBookList, tempBook, tempBookList)){
			ShowCur(0);
			ToMauHCN(35,14,50,9,240);
			textcolor(240);
			gotoXY(48,18);cout<<"Ma Sach Nay Da Duoc Muon!!!";
			textcolor(7);
			Pause("");
			XoaManHinhTuyChon(21,10,111,26);
			goto a;
		}
		else{
			gotoXY(102,14);cout<< tempBook->nameBook;
			gotoXY(102,17);cout<< trangThaiSach(tempBookList->data.status);
			// da muon cuon nay
			for(NODEDOUBLE_BORROWRETURN* k = tempReader->data.doublelist_borrowReturn.pHead; k!= NULL; k = k->pNext){
				if(k->data.status == 0 && tachLayMaDauSach(idBookList) == tachLayMaDauSach(k->data.idBookList) ){ // sach dang muon va trung ma vua nhap
					ToMauHCN(55,14,50,9,240);
					textcolor(240);
					gotoXY(68,18);cout<<"Doc Gia Dang Muon Sach Nay!!!";
					textcolor(7);
					Pause("");
					XoaManHinhTuyChon(21,10,111,26);
					goto t;
				}
			}
			if(tempBookList->data.status == 0){
				string temp;
				ShowCur(0);
				
				ToMauHCN(70, 20, 50, 10, 240);
				textcolor(240);
				gotoXY(83, 23);
				cout << "Ban Co Chac Chan Muon Muon Sach";
				gotoXY(87, 25);
				cout << "Enter De Tiep Tuc ";
				gotoXY(90, 26);
				cout << "ECS De Huy ";
				textcolor(7);
				while(true){
					char c = getch();
					if(c == ENTER){
						saveBookBorrow(tempReader, tempBook, tempBookList, dateBorrow);
						//KiemTraQuaHan(t, now);
						GiaoDienThongBaoThanhCong("Muon Thanh Cong");
						ToMauHCN(70, 20, 50, 10, 240);
						
						if(tempReader->data.numberBookBorrow >= 3){
							ShowCur(0);
							system("cls");
							ToMauHCN(55,14,50,9,240);
							textcolor(240);
							gotoXY(68,18);cout<<"Doc Gia Da Muon 3 cuon";
							textcolor(7);
							Pause("");
							XoaManHinhTuyChon(21,10,111,26);
							goto t;
						}
						textcolor(240);
						gotoXY(83, 23);
						cout << "Ban Co Muon Them Nua";
						gotoXY(87, 25);
						cout << "Enter De Tiep Tuc ";
						gotoXY(90, 26);
						cout << "ECS De Huy ";
						textcolor(7);
						while(true){
							char c = getch();
							if(c == ENTER){
								system("cls");
								goto a;
							}
							else if(c == ESC){
								textcolor(7);
								system("cls");
								return;
							}
						}
						
					}
					else if(c == ESC){
						textcolor(7);	
						system("cls");
						return ;
					}
				}
							
			}
		}
	}
}

// cau g

void changeInfoBook(TREE_READERTICKET &t, string idBookList, Book* tempBook, NODE_BOOKLIST* tempBookList, Date dateReturn, int borrowStatus, int bookStatus, int readerStatus){
	t->data.status = readerStatus;
	for(NODEDOUBLE_BORROWRETURN* k = t->data.doublelist_borrowReturn.pHead; k != NULL; k = k->pNext){
		if(k->data.idBookList == idBookList && k->data.status != 1){
			k->data.dateReturn = dateReturn;
			k->data.status = borrowStatus;
			tempBookList->data.status = bookStatus;
		}
	}
	for(NODEDOUBLE_BORROWRETURN* k = t->data.doublelist_borrowReturn.pHead; k != NULL; k = k->pNext){
		if(k->data.status == 2 ){
			t->data.status = 0;
		}
	}
}

void bookReturn(TREE_READERTICKET &t, ARRAYBOOK &m){
	system("cls");
	Date now;
	LayNgayHienTai(now);
	
	Date dateReturn;
	LayNgayHienTai(dateReturn);
	
	TREE_READERTICKET tempReader = NULL;
	BOOK* tempBook = NULL;
	NODE_BOOKLIST* tempBooKList = NULL;
	
	int id = 0;
	string idBookList;
	NODEDOUBLE_BORROWRETURN* bookBorrow = NULL;
	DeMuc("TRA SACH");
	xuLyNhapMaDocGia(id, t, 70, 10, "tra");
		if(id == -999){
			return;
		}
	t:	getInfoReader(t, id, tempReader);	
		XoaManHinhTuyChon(21,10,111,23);
		giaoDienSachMuon1DocGia();
		printBookReturn(m, tempReader, 30,10);
		gotoXY(40,21); cout<<"NHAP MA SACH : ";
		VeHCN(60,20,20,2,4);
		gotoXY(62,21);fflush(stdin);getline(cin, idBookList);
		while(!checkMaSachTra(tempReader, idBookList, bookBorrow)){
			system("cls");
			gotoXY(82,21); cout<<"        ";
			gotoXY(82,21);
			ToMauHCN(55,14,50,9,240);
			textcolor(240);
			gotoXY(68, 17);
			cout << "KHONG CO MA SACH VUA NHAP";
			gotoXY(72, 20);
			cout << "Enter De Tiep Tuc ";
			gotoXY(75, 21);
			cout << "ECS De Huy ";
			textcolor(7);
			while (true)
			{
				char c = getch();
				if (c==ENTER)
				{
					system("cls");
					goto t;
				}
				else if (c==ESC)
				return;
			}
		}
		XoaManHinhTuyChon(21,10,111,23);
		giaoDienTRaSach();
		gotoXY(37,11);textcolor(4); cout<< tempReader->data.idReader;
		gotoXY(37,14);textcolor(7); cout<< hoTen(tempReader->data.lastname,tempReader->data.firstname);
		gotoXY(37,17);cout<< TrangThaiDocGia(tempReader->data.status);
		gotoXY(37,20);cout<< trangThaiMuonTra(bookBorrow->data.status);
		gotoXY(92,20);cout<<bookBorrow->data.dateBorrow.day;
		gotoXY(103,20);cout<<bookBorrow->data.dateBorrow.month;
		gotoXY(114,20);cout<<bookBorrow->data.dateBorrow.year;
		
	
		gotoXY(92,11);cout<<bookBorrow->data.idBookList;
		if(!layThongTinSachTra(m, idBookList, tempBook, tempBooKList)){
			return;	
		}
		gotoXY(92,14);cout<< tempBook->nameBook;
		gotoXY(92,17);cout<< trangThaiSach(tempBooKList->data.status);
		string temp;
	x:	
		gotoXY(92,23);getline(cin, temp);
		while(atoi(temp.c_str()) < 1 || atoi(temp.c_str()) > 31){
			gotoXY(92,23);cout<<"   ";
			gotoXY(92,23);getline(cin, temp);
		}
		dateReturn.day = atoi(temp.c_str());
	
		gotoXY(103,23);getline(cin, temp);
		while(atoi(temp.c_str()) < 1 || atoi(temp.c_str()) > 12){
			gotoXY(103,23);cout<<"   ";
			gotoXY(103,23);getline(cin, temp);
		}
		dateReturn.month = atoi(temp.c_str());
		
		gotoXY(114,23);getline(cin, temp);
		while(atoi(temp.c_str()) < bookBorrow->data.dateBorrow.year || atoi(temp.c_str()) > now.year){
			gotoXY(114,23);cout<<"    ";
			gotoXY(114,23);getline(cin, temp);
		}
		dateReturn.year = atoi(temp.c_str());
		if(dateReturn.year == bookBorrow->data.dateBorrow.year){
			if(dateReturn.month < bookBorrow->data.dateBorrow.month){
				gotoXY(92,23);cout<<"    ";	
				gotoXY(103,23);cout<<"    ";
				gotoXY(114,23);cout<<"    ";
				goto x;
			}
			else if(dateReturn.month == bookBorrow->data.dateBorrow.month){
				if(dateReturn.day < bookBorrow->data.dateBorrow.day){
					gotoXY(92,23);cout<<"    ";	
					gotoXY(103,23);cout<<"    ";
					gotoXY(114,23);cout<<"    ";
					goto x;
				}
			}
		}
		while(true){
			char c = getch();
			cout<< c;
			if(c == 59 ){
				changeInfoBook(tempReader, idBookList, tempBook, tempBooKList, dateReturn, 1, 0, 1);
				tempReader->data.numberBookBorrow--;
				KiemTraQuaHan(t, now);
				GiaoDienThongBaoThanhCong("Tra Thanh Cong");
				if(tempReader->data.numberBookBorrow>0){
					textcolor(240);
					ToMauHCN(70, 20, 50, 10, 240);
					gotoXY(83, 23);
					cout << "Ban Co Muon Tra Nua";
					gotoXY(87, 25);
					cout << "Enter De Tiep Tuc ";
					gotoXY(90, 26);
					cout << "ECS De Huy ";
					textcolor(7);
					while(true){
						char c = getch();
						if(c == ENTER){
							system("cls");
							goto t;
						}
						else if(c == ESC){
							textcolor(7);
							system("cls");
							return;
						}
					}	
				}
				return;
			}
			else if(c == 60){
				dateReturn.day = 0;
				dateReturn.month = 0;
				dateReturn.year = 0;
				changeInfoBook(tempReader, idBookList, tempBook, tempBooKList, dateReturn, 2, 2, 0);
				KiemTraQuaHan(t, now);
				GiaoDienThongBaoThanhCong("Cap Nhat Thanh Cong");
				
				if(tempReader->data.numberBookBorrow>0){
					textcolor(240);
					ToMauHCN(70, 20, 50, 10, 240);
					gotoXY(83, 23);
					cout << "Ban Co Muon Tra Nua";
					gotoXY(87, 25);
					cout << "Enter De Tiep Tuc ";
					gotoXY(90, 26);
					cout << "ECS De Huy ";
					textcolor(7);
					while(true){
						char c = getch();
						if(c == ENTER){
							system("cls");
							goto t;
					}
					else if(c == ESC){
						textcolor(7);
						system("cls");
						return;
					}
				}	
			}
			return;
		}
		else if(c == ESC){
			return;
		}
	}
	Pause("");
}

//H

void printBookBorrowByReader(TREE_READERTICKET t, ARRAYBOOK m){
	system("cls");
	DeMuc("DANH SACH SACH MUON");
	int id = 0;
	TREE_READERTICKET tempReader = NULL;
	xuLyNhapMaDocGia(id, t, 90, 10, "tra");
	if(id == -999){
		return;
	}
	getInfoReader(t, id, tempReader);
	XoaManHinhTuyChon(21,10,111,23);
	giaoDienSachMuon1DocGia();
	printBookBorrow(m, tempReader, 30, 10);
	Pause("");
}

// i
void readerOverDueToArray(TREE_READERTICKET t, READERTICKET arr[], int &n){
	if(t == NULL){
		return;
	}
	else {
		readerOverDueToArray(t->pLeft, arr, n);
		if(t->data.daysOverdueMax > 0){
			arr[n++] = t->data;
		}
		readerOverDueToArray(t->pRight, arr, n);
	}
}

void printOverDueHighToLow(TREE_READERTICKET t){
	system("cls");
	Date now;
	LayNgayHienTai(now);
	KiemTraQuaHan(t, now);
	int n = 0;
	READERTICKET* arr = new READERTICKET[numberReaderTicket];
	READERTICKET temp;
	readerOverDueToArray(t, arr, n);
	for(int i = 0; i< n - 1; i++){
		for(int j = i; j < n; j++){
			if(arr[i].daysOverdueMax < arr[j].daysOverdueMax){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp; 
			}
		}
	}
	printPage(arr, n);
}

// j

void mostBorrowToArray(ARRAYBOOK m, BOOK* arr[], int &n){
	
	for(int i = 0; i < m.numberBook; i++){
		if(m.nodesBook[i]->numberBorrows > 0){
			arr[n++] = m.nodesBook[i];
		}
	}
}

void mostBorrowHighToLow(ARRAYBOOK m){
	system("cls");
	int n = 0;
	BOOK* arr[100];
	BOOK* temp = NULL;
	mostBorrowToArray(m, arr, n);
	for(int i = 0; i< n - 1; i++){
		for(int j = i; j < n; j++){
			if(arr[i]->numberBorrows < arr[j]->numberBorrows){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp; 
			}
		}
	}	
	int soTrang = 0;
	int sodu = 0;
	int trang = 1;
	giaoDienXuatDauSach();
	gotoXY(121,17);cout<<"Lan Muon";
	if(n == 0){
		ToMauHCN(75,18,50,4,240);
		textcolor(240);
		gotoXY(83,20);
		cout << "Khong Co Doc Gia Nao !!!";
		textcolor(7);
		Pause("");
	}
	else {
		if(n <= 10){
			for(int i =0; i < n; i++){
				print1book(arr[i],30,i +20 - (trang-1)*10);
				gotoXY(30 + 91,i +20 - (trang-1)*10);cout<<"      ";
				gotoXY(30 + 91,i +20 - (trang-1)*10);
				cout<<CanDeuChuoi(ChuyenSoSangString(arr[i]->numberBorrows),8);
			}
		}
		else{
			for(int i =0; i < 10; i++){
				print1book(arr[i],30,i +20 - (trang-1)*10);
				gotoXY(30 + 91,i +20 - (trang-1)*10);cout<<"      ";
				gotoXY(30 + 91,i +20 - (trang-1)*10);
				cout<<CanDeuChuoi(ChuyenSoSangString(arr[i]->numberBorrows),8);
			}
		}
	}
	textcolor(7);
	Pause("");
}


// exit

void exitProgram(TREE_READERTICKET &t, ARRAYBOOK &m){
	system("cls");
	ShowCur(0);
	
	ToMauHCN(90, 20, 50, 10, 240);
	textcolor(240);
	gotoXY(103, 23);
	cout << "Ban Co Chac Chan Muon Thoat";
	gotoXY(107, 25);
	cout << "Enter De Tiep Tuc ";
	gotoXY(110, 26);
	cout << "ECS De Huy ";
	textcolor(7);
	while(true){
		char c = getch();
		if(c == ENTER){
			system("cls");
			save(t, m);
			deleteMemory(t, m);
			exit(0);
		}
		else if(c == ESC){
			textcolor(7);	
			ShowCur(1);
			break;
		}
	}
				
}

