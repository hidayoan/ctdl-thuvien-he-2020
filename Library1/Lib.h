
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
void Pause(char *message = "Press any key to continue . . . "

) {
  std::cout << message;
  HANDLE hStdin; 
  DWORD cNumRead; 
  INPUT_RECORD irInBuf[1];
  if ( HANDLE(hStdin = GetStdHandle( STD_INPUT_HANDLE )) == INVALID_HANDLE_VALUE )
    return;
  while ( true )  { 
    if (! ReadConsoleInput( hStdin, irInBuf, 1, &cNumRead) )
      return;
    for (DWORD i = 0; i < cNumRead; ++i)
      if ( irInBuf[i].EventType == KEY_EVENT && irInBuf[i].Event.KeyEvent.bKeyDown ) {
        std::cout << '\n';
        return;
      }
  }
}

void XoaManHinhTuyChon(int toadoX,int toadoY,int chieudai,int chieucao)
{
	textcolor(7);
	for (int i = toadoY; i < chieucao+toadoY; i++)
	{
		for (int j = toadoX; j < toadoX + chieudai; j++)
		{
			gotoXY(j, i);
			cout << " ";
		}
	}
}

void ToMauHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mauText)
{
	textcolor(mauText);
	for (int i = toadoY + 1; i < toadoY + chieucao; i++)
	{
		for (int j = toadoX + 1; j < chieudai + toadoX; j++)
		{
			gotoXY(j, i);
			cout << " ";
		}
	}
	textcolor(7);
}
void VeHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mauSet){
	SetColor(mauSet);
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}
	SetColor(7);
}

void GiaoDienThongBaoThanhCong(string x)
{
	ToMauHCN(70, 17, 50, 10, 95);
	textcolor(95);
	gotoXY(71, 20);
	cout << CanDeuChuoi(x, 49);
	gotoXY(83, 23);
	system("pause");
	textcolor(7);
}

void DeMuc(string x)
{
	SetColor(14);
	gotoXY(20, 7);
	cout << CanDeuChuoi(x, 126);
	textcolor(7);
	
}


void giaoDienDanhSachDocGia(int toadoX, int toadoY){

	for(int i = toadoX - 20; i< toadoX + 31; i++){
		
		if(i == toadoX - 11){
			gotoXY(i, toadoY);cout<<(char)203;
			gotoXY(i, toadoY + 2);cout<<(char)206;
			gotoXY(i, toadoY + 15);cout<<(char)202;
		}
		else{
			gotoXY(i,toadoY);cout<<(char)205;
			gotoXY(i,toadoY + 2);cout<<(char)205;
			gotoXY(i,toadoY + 15);cout<<(char)205;
		}
	}
	for(int i = toadoY + 1; i < toadoY + 15; i++){
		
		if(i == toadoY + 2){
			gotoXY(toadoX - 21, i);cout<<(char)204;
			gotoXY(toadoX + 31, i);cout<<(char)185;	
		}
		else{
			gotoXY(toadoX - 21,i);cout<<(char)186;
			gotoXY(toadoX + 31,i);cout<<(char)186;
			gotoXY(toadoX - 11,i);cout<<(char)186;
		}
	}
	gotoXY(toadoX - 21, toadoY);cout<<(char)201;
	gotoXY(toadoX + 31, toadoY);cout<<(char)187;
	gotoXY(toadoX - 21, toadoY + 15);cout<<(char)200;
	gotoXY(toadoX + 31, toadoY + 15);cout<<(char)188;
	gotoXY(toadoX - 18, toadoY+1); cout<< "Ma so";
	gotoXY(toadoX, toadoY+1); cout<< "Ten Doc Gia";
	gotoXY(toadoX , toadoY + 20); cout<< "Nhap ma so :";
	VeHCN(toadoX  + 15, toadoY + 19,16,2,15);
}

void printReaderUI(int toadoX,int toadoY){	
	for(int i = toadoY + 1; i < toadoY + 7; i++){
		gotoXY(toadoX,i); cout<<(char)186;
		gotoXY(toadoX + 10,i); cout<<(char)186;
		gotoXY(toadoX + 40,i); cout<<(char)186;
		gotoXY(toadoX + 55,i); cout<<(char)186;
		gotoXY(toadoX + 70,i); cout<<(char)186;
		gotoXY(toadoX + 85 ,i); cout<<(char)186;
		gotoXY(toadoX + 100,i); cout<<(char)186;
	}
	for(int i = toadoX + 1; i< toadoX + 100; i++){
		if(i == toadoX + 10){
			gotoXY(i, toadoY);cout<<(char)203;
			gotoXY(i, toadoY + 4);cout<<(char)206;
			gotoXY(i, toadoY + 7);cout<<(char)202;
		}
		else if(i == toadoX + 40){
			gotoXY(i, toadoY);cout<<(char)203;
			gotoXY(i, toadoY+4);cout<<(char)206;
			gotoXY(i, toadoY+7);cout<<(char)202;
		}
		else if(i == toadoX + 55){
			gotoXY(i, toadoY);cout<<(char)203;
			gotoXY(i, toadoY+4);cout<<(char)206;
			gotoXY(i, toadoY+7);cout<<(char)202;
		}
		else if(i == toadoX + 70){
			gotoXY(i, toadoY);cout<<(char)203;
			gotoXY(i, toadoY+4);cout<<(char)206;
			gotoXY(i, toadoY+7);cout<<(char)202;
		}
		else if(i == toadoX + 85){
			gotoXY(i, toadoY);cout<<(char)203;
			gotoXY(i, toadoY+4);cout<<(char)206;
			gotoXY(i, toadoY+7);cout<<(char)202;
		}
		else{
			gotoXY(i,toadoY);cout<<(char)205;
			gotoXY(i,toadoY+4);cout<<(char)205;
			gotoXY(i,toadoY+7);cout<<(char)205;
		}
	}
	gotoXY(toadoX, toadoY+4);cout<<(char)204;
	gotoXY(toadoX+100, toadoY+4);cout<<(char)185;	
	gotoXY(toadoX, toadoY);cout<<(char)201;
	gotoXY(toadoX + 100, toadoY);cout<<(char)187;
	gotoXY(toadoX, toadoY+7);cout<<(char)200;
	gotoXY(toadoX+100, toadoY+7);cout<<(char)188;	
	textcolor(11);
	gotoXY(toadoX+4,toadoY+2); cout<< "ID";
	gotoXY(toadoX+20,toadoY+2); cout<< "Ho va Ten";
	gotoXY(toadoX+46,toadoY+2); cout<< "Phai";
	gotoXY(toadoX+58,toadoY+2); cout<< "Trang Thai";
	gotoXY(toadoX+74,toadoY+1); cout<< "So Sach";
	gotoXY(toadoX+73,toadoY+2); cout<< "Dang Muon";
	gotoXY(toadoX+90,toadoY+1); cout<< "So Ngay";
	gotoXY(toadoX+90,toadoY+2); cout<< "Qua Han";
	textcolor(7);
}


void giaoDienXuatDanhSachDocGia(){
	system("cls");
	textcolor(15);
	for(int i = 31; i < 130; i++){
		if(i == 40 || i == 70 || i == 85 || i == 100 || i == 115){
			gotoXY(i, 15);cout<<(char)203;
			gotoXY(i, 18);cout<<(char)206;
			gotoXY(i, 33);cout<<(char)202;
		}
		else{
			gotoXY(i, 15);cout<<(char)205;
			gotoXY(i, 18);cout<<(char)205;
			gotoXY(i, 33);cout<<(char)205;
		}
	}
	for(int i = 15; i <= 33; i++){
		if(i == 18){
			gotoXY(30, i);cout<<(char)204;
			gotoXY(130, i);cout<<(char)185;
		}
		else if(i == 15){
			gotoXY(30, i);cout<<(char)201;
			gotoXY(130, i);cout<<(char)187;
		}
		else if(i == 33){
			gotoXY(30, i);cout<<(char)200;
			gotoXY(130, i);cout<<(char)188;
		}
		else{
			gotoXY(30, i);cout<<(char)186;
			gotoXY(40, i);cout<<(char)186;
			gotoXY(70, i);cout<<(char)186;
			gotoXY(85, i);cout<<(char)186;
			gotoXY(100, i);cout<<(char)186;
			gotoXY(115, i);cout<<(char)186;
			gotoXY(130, i);cout<<(char)186;
		}
	}
	textcolor(11);
	gotoXY(30+4,15+2); cout<< "ID";
	gotoXY(30+20,15+2); cout<< "Ho va Ten";
	gotoXY(30+46,15+2); cout<< "Phai";
	gotoXY(30+58,15+2); cout<< "Trang Thai";
	gotoXY(30+74,15+1); cout<< "So Sach";
	gotoXY(30+73,15+2); cout<< "Dang Muon";
	gotoXY(30+90,15+1); cout<< "So Ngay";
	gotoXY(30+90,15+2); cout<< "Qua Han";
	textcolor(7);
}

void giaoDienNhapDauSach(){
	textcolor(14);
	gotoXY(40,9);cout<<"Ma Dau Sach    :";
	gotoXY(40,12);cout<<"Ten Sach      :";
	gotoXY(40,15);cout<<"So Trang      :";
	gotoXY(40,18);cout<<"Tac Gia       :";
	gotoXY(40,21);cout<<"Nam Xuat Ban  :";
	gotoXY(40,24);cout<<"The Loai      :";
	gotoXY(40,27);cout<<"Vi Tri        :";
	gotoXY(40,30);cout<<"So Luong Sach :";
	
	VeHCN(70,8,50,2,14);
	VeHCN(70,11,50,2,14);
	VeHCN(70,14,50,2,14);
	VeHCN(70,17,50,2,14);
	VeHCN(70,20,50,2,14);
	VeHCN(70,23,50,2,14);
	VeHCN(70,26,50,2,14);
	VeHCN(70,29,50,2,14);
	textcolor(7);
}

void giaoDienXuatDauSach(){
	textcolor(14);
	for(int i = 31; i < 130; i++){
		if(i == 40 || i == 55 || i == 65 || i == 80 || i == 90 || i == 105 || i == 120){
			gotoXY(i, 15);cout<<(char)203;
			gotoXY(i, 18);cout<<(char)206;
			gotoXY(i, 33);cout<<(char)202;
		}
		else{
			gotoXY(i, 15);cout<<(char)205;
			gotoXY(i, 18);cout<<(char)205;
			gotoXY(i, 33);cout<<(char)205;
		}
	}
	for(int i = 15; i <= 33; i++){
		if(i == 18){
			gotoXY(30, i);cout<<(char)204;
			gotoXY(130, i);cout<<(char)185;
		}
		else if(i == 15){
			gotoXY(30, i);cout<<(char)201;
			gotoXY(130, i);cout<<(char)187;
		}
		else if(i == 33){
			gotoXY(30, i);cout<<(char)200;
			gotoXY(130, i);cout<<(char)188;
		}
		else{
			gotoXY(30, i);cout<<(char)186;
			gotoXY(40, i);cout<<(char)186;
			gotoXY(55, i);cout<<(char)186;
			gotoXY(65, i);cout<<(char)186;
			gotoXY(80, i);cout<<(char)186;
			gotoXY(90, i);cout<<(char)186;
			gotoXY(105, i);cout<<(char)186;
			gotoXY(120, i);cout<<(char)186;
			gotoXY(130, i);cout<<(char)186;
		}
	}
	textcolor(11);
	gotoXY(33,17);cout<<"ISBN";
	gotoXY(41,17);cout<<"Ten Sach";	
	gotoXY(56,17);cout<<"So Trang";
	gotoXY(70,17);cout<<"Tac Gia";
	gotoXY(81,17);cout<<"Nam X.Ban";
	gotoXY(93,17);cout<<"The Loai";
	gotoXY(107,17);cout<<"Vi Tri";
	gotoXY(121,17);cout<<"So Luong";
}



// giao dien muon sach

void giaoDienMuonSach(){
	DeMuc("MUON SACH");
	VeHCN(45,10,30,2,4);
	VeHCN(45,13,30,2,10);
	VeHCN(45,16,30,2,10);
	
	VeHCN(100,10,30,2,14);
	VeHCN(100,13,30,2,10);
	VeHCN(100,16,30,2,10);
	VeHCN(100,19,8,2,10);
	VeHCN(111,19,8,2,10);
	VeHCN(122,19,8,2,10);
	
	gotoXY(25,11); cout<<"Ma Doc Gia      :";
	gotoXY(25,14); cout<<"Ten Doc Gia     :";
	gotoXY(25,17); cout<<"Trang Thai      :";
	
	gotoXY(87,11); cout<<"Ma Sach   :";
	gotoXY(87,14); cout<<"Ten Sach  :";
	gotoXY(87,17); cout<<"Trang Thai :";
	gotoXY(87,20); cout<<"Ngay Muon :";
	
	gotoXY(70,25);cout<< "Danh Sach Sach Da Muon";
	
	for(int i = 31; i < 130; i++){
		if(i == 50 || i == 90 || i == 110){
			gotoXY(i, 27);cout<<(char)203;
			gotoXY(i, 29);cout<<(char)206;
			gotoXY(i, 34);cout<<(char)202;
		}
		else{
			gotoXY(i, 27);cout<<(char)205;
			gotoXY(i, 29);cout<<(char)205;
			gotoXY(i, 34);cout<<(char)205;
		}
	}
	for(int i = 27; i <= 34; i++){
		if(i == 29){
			gotoXY(30, i);cout<<(char)204;
			gotoXY(130, i);cout<<(char)185;
		}
		else if(i == 27){
			gotoXY(30, i);cout<<(char)201;
			gotoXY(130, i);cout<<(char)187;
		}
		else if(i == 34){
			gotoXY(30, i);cout<<(char)200;
			gotoXY(130, i);cout<<(char)188;
		}
		else{
			gotoXY(30, i);cout<<(char)186;
			gotoXY(50, i);cout<<(char)186;
			gotoXY(90, i);cout<<(char)186;
			gotoXY(110, i);cout<<(char)186;
			gotoXY(130, i);cout<<(char)186;
		}
	}
	gotoXY(37,28); cout<< "Ma Sach";
	gotoXY(66,28); cout<< "Ten Sach";
	gotoXY(95,28); cout<< "Trang Thai";
	gotoXY(116,28); cout<< "Ngay Muon";
}

void giaoDienSachMuon1DocGia(){
	for(int i = 31; i < 130; i++){
		if(i == 50 || i == 90 || i == 110){
			gotoXY(i, 10);cout<<(char)203;
			gotoXY(i, 12);cout<<(char)206;
			gotoXY(i, 17);cout<<(char)202;
		}
		else{
			gotoXY(i, 10);cout<<(char)205;
			gotoXY(i, 12);cout<<(char)205;
			gotoXY(i, 17);cout<<(char)205;
		}
	}
	for(int i = 10; i <= 17; i++){
		if(i == 12){
			gotoXY(30, i);cout<<(char)204;
			gotoXY(130, i);cout<<(char)185;
		}
		else if(i == 10){
			gotoXY(30, i);cout<<(char)201;
			gotoXY(130, i);cout<<(char)187;
		}
		else if(i == 17){
			gotoXY(30, i);cout<<(char)200;
			gotoXY(130, i);cout<<(char)188;
		}
		else{
			gotoXY(30, i);cout<<(char)186;
			gotoXY(50, i);cout<<(char)186;
			gotoXY(90, i);cout<<(char)186;
			gotoXY(110, i);cout<<(char)186;
			gotoXY(130, i);cout<<(char)186;
		}
	}
	gotoXY(37,11); cout<< "Ma Sach";
	gotoXY(66,11); cout<< "Ten Sach";
	gotoXY(95,11); cout<< "Trang Thai";
	gotoXY(116,11); cout<< "Ngay Muon";
}

void giaoDienTRaSach(){
	DeMuc("Danh Muc Sach Dang Muon");
	VeHCN(35,10,30,2,4);
	VeHCN(35,13,30,2,10);
	VeHCN(35,16,30,2,10);
	VeHCN(35,19,30,2,10);
	
	VeHCN(90,10,30,2,14);
	VeHCN(90,13,30,2,10);
	VeHCN(90,16,30,2,10);
	VeHCN(90,19,8,2,10);
	VeHCN(101,19,8,2,10);
	VeHCN(112,19,8,2,10);
	VeHCN(90,22,8,2,10);
	VeHCN(101,22,8,2,10);
	VeHCN(112,22,8,2,10);
	
	gotoXY(15,11); cout<<"Ma Doc Gia     :";
	gotoXY(15,14); cout<<"Ten Doc Gia    :";
	gotoXY(15,17); cout<<"Trang Thai     :";
	gotoXY(15,20); cout<<"Trang Thai Tra :";
	gotoXY(77,11); cout<<"Ma Sach    :";
	gotoXY(77,14); cout<<"Ten Sach   :";
	gotoXY(77,17); cout<<"Trang Thai :";
	gotoXY(77,20); cout<<"Ngay Muon  :";
	gotoXY(77,23); cout<<"Ngay Tra   :";
	
	gotoXY(40,26); cout<<"F1:TRA SACH";
	gotoXY(60,26); cout<<"F2:LAM MAT SACH";
	gotoXY(90,26); cout<<"ESC:CANCEL";
}

