

void xuatDocGia(int &id,int arrId[],string arrName[], int soLuong, int toadoX, int toadoY){

	
t:	int soTrang = 0;
	int sodu = 0;
	int trang = 1;
	giaoDienDanhSachDocGia(toadoX, toadoY);
	if(soLuong == 0){
		gotoXY(toadoX, toadoY + 8);
		cout << "Khong Co Doc Gia Nao !!!";
		Pause("");
		id=-999;
		return;
	}
	else{
		if(soLuong <= 10){
			for(int i = 0 ; i < soLuong; i++){
				gotoXY(toadoX - 18, toadoY + 4 + i);
				cout<< arrId[i];
				gotoXY(toadoX - 8, toadoY + 4 + i);
				cout<< arrName[i];
			}
			gotoXY(toadoX+4,toadoY+16);
			cout<< "1/1";
		}
		else{
			if(soLuong % 10 != 0){
				soTrang = soLuong / 10 + 1;
				
			}
			else{
				soTrang = soLuong / 10;
			}
			gotoXY(toadoX+4,toadoY+16);
			cout<< "1/" << soTrang;
			for(int i = 0; i<10;i++){
				gotoXY(toadoX - 18, toadoY + 4 + i);
				cout<< arrId[i];
				gotoXY(toadoX - 8, toadoY + 4 + i);
				cout<< arrName[i];
			}
		}
		while(true){

			if(kbhit()){
				char c = getch();
				
				if(c == 60 && soLuong > 10){ // sang phai
					if(trang < soTrang){
						trang++;
						int tam;
						if(trang*10 < soLuong){
							tam = trang*10;
						}
						else{
							tam = soLuong;
						}
						XoaManHinhTuyChon(toadoX - 20, toadoY + 3 , 9, 12);
						XoaManHinhTuyChon(toadoX - 10, toadoY + 3 , 35, 12);
						for(int i = trang*10-10;i< tam; i++){
							gotoXY(toadoX - 18, toadoY + 4 + i - (trang-1)*10);
							cout<< arrId[i];
							gotoXY(toadoX - 8, toadoY + 4 + i- (trang-1)*10);
							cout<< arrName[i];
						}
						gotoXY(toadoX+4,toadoY+16);
						cout<< trang << "/" << soTrang;
					}
					else{
						XoaManHinhTuyChon(toadoX - 20, toadoY + 3 , 9, 12);
						XoaManHinhTuyChon(toadoX - 10, toadoY + 3 , 35, 12);
						trang = 1;
						for(int i = trang*10-10;i< trang*10; i++){
							gotoXY(toadoX - 18, toadoY + 4 + i- (trang-1)*10);
							cout<< arrId[i];
							gotoXY(toadoX - 8, toadoY + 4 + i- (trang-1)*10);
							cout<< arrName[i];
						}
						gotoXY(toadoX+4,toadoY+16);
						cout<< trang << "/" << soTrang;
					}
				}
				else if(c == 59 && soLuong > 10){
					if(trang > 1){
						XoaManHinhTuyChon(toadoX - 20, toadoY + 3 , 9, 12);
						XoaManHinhTuyChon(toadoX - 10, toadoY + 3 , 35, 12);
						trang--;
						for(int i = trang*10-10;i< trang*10; i++){
							gotoXY(toadoX - 18, toadoY + 4 + i - (trang-1)*10);
							cout<< arrId[i];
							gotoXY(toadoX - 8, toadoY + 4 + i - (trang-1)*10);
							cout<< arrName[i];
						}
						gotoXY(toadoX+4,toadoY+16);
						cout<< trang << "/" << soTrang;
					}
					else{
						XoaManHinhTuyChon(toadoX - 20, toadoY + 3 , 9, 12);
						XoaManHinhTuyChon(toadoX - 10, toadoY + 3 , 35, 12);
						trang = soTrang;
						for(int i = trang*10-10;i< soLuong; i++){
							gotoXY(toadoX - 18, toadoY + 4 + i - (trang-1)*10);
							cout<< arrId[i];
							gotoXY(toadoX - 8, toadoY + 4 + i - (trang-1)*10);
							cout<< arrName[i];
						}
						gotoXY(toadoX+4,toadoY+16);
						cout<< soTrang << "/" << soTrang;
					}
				}
				else if(c == 32){
					bool check = true;
					string temp = "";
					ShowCur(1);
					gotoXY(toadoX + 18, toadoY + 20);
					cin>>temp;
					while(check){
					
						for(int i = 0; i < soLuong; i++){
							if(arrId[i] == atoi(temp.c_str())  ){
								check = false;
								id = atoi(temp.c_str());
								break;
							}
							else{
								check = true;
							}
						}
						if(check == true){					
							gotoXY(toadoX + 18, toadoY + 25);
							cout<< "KO CO MA VUA NHAP";
							gotoXY(toadoX + 18, toadoY + 20); cout<<"           ";
							ShowCur(1);
							gotoXY(toadoX + 18, toadoY + 20);
							goto t;
						}
						else return;
					}
				}
				else if(c == 27){
					id = -999;
					return;
				}
			}
		}
		
	}
}


void xuLyNhapMaDocGia(int &id,TREE_READERTICKET t, int toadoX, int toadoY,string mucDich){
	//chuyen tu cay nhi phan -> mang
	int *arrId = new int[numberReaderTicket];//mang ma the
	string *arrName = new string[numberReaderTicket];//mang ten
	int n = 0;
	if(mucDich == "layHet"){
		takeIdReader_all(t, arrName, arrId, n);
	}
	if(mucDich == "xoa"){
		takeIdReader_delete(t, arrName, arrId, n);
	}
	if(mucDich == "muon"){
		takeIdReader_borrow(t, arrName, arrId, n);
	}
	if(mucDich == "tra"){
		takeIdReader_return(t, arrName, arrId, n);
	}
	xuatDocGia(id,arrId, arrName, n, toadoX, toadoY);
}
