#include "Variable.h" //bien toan cuc
#include "CTDL.h" //CTDL
#include "Controller.h" //kiem soat truoc khi dung chuc nang
#include "Lib.h" //Thu vien UI
#include "InputController.h" //kiem soat ki tu dau vao
#include "ReleaseMemory.h" //xoa bo nho 
#include "SaveFile.h" //luu file
#include "Request.h" //yeu cau de bai
#include"LoadFile.h" //loadfile

string strMNMain[] = {
" 1:  a.1         Them Doc Gia             ", //1
" 2:  a.2         Xoa Doc Gia              ", //2
" 3:  a.3      Hieu Chinh Doc Gia          ", //3
" 4:  b.        Danh Sach Doc Gia          ", //4
" 5:  c.1         Them Dau Sach            ", //5
" 6:  c.2        Xoa Dau Sach              ", //6
" 7:  d.  DS Cac Dau Sach Theo The Loai    ", //7
" 8:  e.       Tim Thong Tin Sach          ", //8
" 9:  f.            Muon Sach              ", //9
" 10: g.            Tra Sach               ", //10
" 11: h. DS Cac Sach Doc Gia Dang Muon     ", //11
" 12: i.   Danh Sach Doc Gia Qua Han       ", //12
" 13: j. 10 Sach Co So Lan Muon Nhieu Nhat ", //13
" 14:                Thoat                 "  //0
};

void Menu(){
	int j = 8;
	for (int i = 0; i < sizeof(strMNMain) / sizeof(*strMNMain); i++)
	{
		gotoXY(60, j++);
		cout << strMNMain[i];
	}
}

void runMenu(TREE_READERTICKET &tree, ARRAYBOOK &a){
	system("cls");
	ShowCur(1);
	Menu();
	int temp;
	gotoXY(60,26); cout<< "Nhap Chuc Nang :";	
	VeHCN(80,25,10,2,14);
	
	do{
		gotoXY(70,28);cout<<"                    ";
		gotoXY(82,26);cout<<"        ";
		string t = "";
		gotoXY(82,26); cin >> t;
		temp = atoi(t.c_str());
		switch (temp){
			case 1:{
				addReader(tree, Random());
				break;
			}
			case 2:{
				deleteReader(tree);
				break;
			}
			case 3:{
				updateInfoReader(tree);	
				break;
			}
			case 4:{
				printReaderTicket(tree);
				break;
			}
			case 5:{
				addBook(a);
				break;
			}
			case 6:{
				xoaSach(a, tree);
				break;
			}
			case 7:{
				chooseBookType(a);
				break;
			}
			case 8:{
				findBookByKey(a);
				break;
			}
			case 9:{
				borrowBook(tree, a);
				break;
			}
			case 10:{
				bookReturn(tree, a);
				break;
			}
			case 11:{
				printBookBorrowByReader(tree, a);
				break;
			}
			case 12:{
				printOverDueHighToLow(tree);
				break;
			}
			case 13:{
				mostBorrowHighToLow(a);
				break;
			}
			case 14:{
				exitProgram(tree, a);
				break;
			}
			default:{
				gotoXY(70,28);cout<<"Nhap Sai";
				Pause("");
				break;
			}
		}
	} 
	while(temp < 1 || temp > 14);
}


void Khoitao(TREE_READERTICKET &tree, ARRAYBOOK &a){
	Date now;
	LayNgayHienTai(now);	
	resizeConsole(1300, 700);
	a.numberBook = 0;
	tree = NULL;
	load(a, tree);
	KiemTraQuaHan(tree, now);
	Menu();
}
