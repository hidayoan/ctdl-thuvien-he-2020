
int Random()
{
	srand(time(NULL));
	int a;
	while (true)
	{
		a = 1 + rand() % randomInt;
		if (randomArray[a] == false)
		{
			randomArray[a] = true;
			numberReaderTicket++;
			return a;
		}
	}
}

// dinh dang chuoi
void DinhDangChuoi(string &str){
	// xoa khoang trang
	while(str[0] == ' '){ // ki tu dau la` khoang trang
		str.erase(str.begin() + 0); //  xoa
	}
	while(str[str.length() - 1] == ' ' ){ // ki tu cuoi la` khoang trang
		str.erase(str.begin() + str.length() - 1); //  xoa
	}
	for(int i = 0; i < str.length() - 1; i++){ // 2 khoang trang lien nhau
		if(str[i] == ' ' && str[i+1] == ' '){
			str.erase(str.begin() + i); // xoa
			i--;
		}
	}
	
	// dinh dang lai chu~ cai' dau` in hoa va cac chu~ sau viet' thuong`
	// -chu~ cai' sau
	for(int i = 0; i < str.length() - 1; i++){
		
	}
	// -chu~ cai' dau`
	for(int i = 0; i < str.length(); i++){
		if(i == 0 && (str[i] >= 97 && str[i]<= 122)){ // neu ki tu dau viet thuong a-z
			str[i] = str[i] - 32;						//A-Z
		}
		if(str[i] == ' ' && (str[i+1] >= 97 && str[i+1]<= 122)){// neu ki tu sau dau cach viet thuong a-z
			str[i+1] = str[i+1] - 32;							//A-Z
		}
	}
}

//can deu chuoi
string CanDeuChuoi(string str, int chieuRong){
	if(str.empty()){ // chuoi rong
		return str;
	}
	else if(str.length() > chieuRong){
		return str;
	}
	else return string((chieuRong - str.length()) / 2, ' ') +str; // them 1/2 khoang cach zo str
}
char Chuyen1SoSangKiTu(int n){
	switch (n)
	{
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 0:
		return '0';
	}
}
string ChuyenSoSangString1(int n)
{
	string str;
	int a;
	while (n > 0)
	{
		a = n % 10;
		Chuyen1SoSangKiTu(a);
		str.insert(str.begin() + 0, Chuyen1SoSangKiTu(a));
		n = n / 10;
	}
	return str;
}
	// de xuat
string ChuyenSoSangString(int n)
{
	string str;
	int a;
	if (n == 0)
	{
		str = "0";
	}
	while (n > 0)
	{
		a = n % 10;
		Chuyen1SoSangKiTu(a);
		str.insert(str.begin() + 0, Chuyen1SoSangKiTu(a));
		n = n / 10;
	}
	return str;
}
// xu ly doc gia
void takeIdReader_all(TREE_READERTICKET t, string arrName[], int arrID[], int &i){
	if(t == NULL){
		return;
	}
	takeIdReader_all(t->pLeft, arrName, arrID, i);
	arrName[i] = t->data.lastname + " " + t->data.firstname;
	arrID[i] = t->data.idReader;
	i++;
	takeIdReader_all(t->pRight, arrName, arrID, i);
}
void takeIdReader_delete(TREE_READERTICKET t, string name[], int id[], int &i ){
	if(t == NULL){ // rong~
		return;
	}
	takeIdReader_delete(t->pLeft,name,id,i);
	if(t->data.numberBookBorrow == 0 && t->data.status == 1){// trang thai dang hd, ko muon cuon nao`
		name[i] = t->data.lastname + " " + t->data.firstname;
		id[i] = t->data.idReader;
		i++;
	}

	takeIdReader_delete(t->pRight,name,id,i);
}
	// tra
void takeIdReader_return(TREE_READERTICKET t, string name[], int id[], int &i ){
	if(t == NULL){ // rong~
		return;
	}
	takeIdReader_return(t->pLeft,name,id,i);
	if(t->data.numberBookBorrow > 0){
		name[i] = t->data.lastname + " " + t->data.firstname;
		id[i] = t->data.idReader;
		i++;
	}
	takeIdReader_return(t->pRight,name,id,i);
}
	// muon
void takeIdReader_borrow(TREE_READERTICKET t, string name[], int id[], int &i ){
	if(t == NULL){ // rong~
		return;
	}
	takeIdReader_borrow(t->pLeft,name,id,i);
	if(t->data.numberBookBorrow < 3 && t->data.status == 1 && t->data.daysOverdueMax ==0)  {// so sach muon chua full va trang thai dang hd
		if(t->data.numberBookBorrow == 0){
			name[i] = t->data.lastname + " " + t->data.firstname;
			id[i] = t->data.idReader;
			i++;
		}
		else{
			for(NODEDOUBLE_BORROWRETURN* k = t->data.doublelist_borrowReturn.pHead; k != NULL; k= k->pNext){
				if(k->data.status == 0){
					name[i] = t->data.lastname + " " + t->data.firstname;
					id[i] = t->data.idReader;
					i++;
					break;
				}
			}
		}
	}
	takeIdReader_borrow(t->pRight,name,id,i);
}
string TrangThaiDocGia(int n)
{
	if (n == 1)
		return "Hoat Dong";
	else
		return "Khoa";
}
//Ghep Ho Ten
string hoTen(string ho, string ten){
	string temp = ho;
	temp = temp + " " + ten;
	DinhDangChuoi(temp);
	return temp;
}
string addIdBook(string maDauSach, int i){
	string temp = maDauSach;
	temp = temp + "_" + ChuyenSoSangString1(i);
	return temp;
}
//chuyen cay nhi phan thanh mang
void treeToArray(TREE_READERTICKET t, READERTICKET dg[], int& i){
	if(t == NULL){ // mang rong thi` out
		return;
	}
	else { // sap xep tang dan
		treeToArray(t->pLeft, dg, i);
		dg[i++]= t->data;
		treeToArray(t->pRight, dg, i);
	}
}
// sap xep theo ten
void sortByName(TREE_READERTICKET t, READERTICKET dg[], int & h){
	
	treeToArray(t, dg, h);
	for(int i = 0; i< h -1; i++){
		for(int j = i + 1; j < h; j++){
			//if( hoTen(dg[i].lastname, dg[i].firstname) > hoTen(dg[j].lastname, dg[j].firstname) ){
			if(dg[i].firstname > dg[j].firstname ){
				READERTICKET tempDG;
				tempDG = dg[i];
				dg[i] = dg[j];
				dg[j] = tempDG;
			}
		}
	}
}

// loc the loai bi trung
void locTheLoai(ARRAYBOOK m, string a[], int &n, int ma[]){
	n = m.numberBook;
	for(int i = 0; i < n; i++){
		a[i] = m.nodesBook[i]->type;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] == a[j]) {
				for(int k = j; k<n-1;k++){
					a[k] = a[k+1];
				}
				n--;
				i--;
			}
		}
	}
	for(int i=0;i<n;i++){
		ma[i] = i;
	}
}

void chuyenDauSachSangMang(ARRAYBOOK m, BOOK* ds[], int &h, string theLoai){
	if(m.numberBook == 0){
		return;
	}
	else{
		for(int i=0 ;i< m.numberBook; i++){
			if(m.nodesBook[i]->type == theLoai){
				ds[h++] = m.nodesBook[i];
			}
		}
	}
}

bool xuLyNhapNamXuatBan(int nam){
	if(nam >=  2020 || nam < 1800){
		return false;
	}
	return true;
}
string tachLayMaDauSach(string str)
{
	string str1;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '_')
		{
			break;
		}
		str1.push_back(str[i]);
	}
	return str1;
}
string layTenSach(ARRAYBOOK m, string maSach)
{
	for (int i = 0; i < m.numberBook; i++)
	{
		if (m.nodesBook[i]->idBook == tachLayMaDauSach(maSach))
		{
			return m.nodesBook[i]->nameBook;
		}
	}
	return "Ma Sach Khong Ton Tai";
}

string trangThaiMuonTra(int trangThai){
	if (trangThai == 0)
		return "Dang Muon";
	else if (trangThai == 1)
		return "Da Tra";
	else if (trangThai == 2)
		return "Da Mat";
}
string trangThaiSach(int trangThai){
	if(trangThai == 0){
		return "Co The Muon";
	}
	else if(trangThai == 1){
		return "Da Cho Muon";
	}
	else if(trangThai == 2){
		return "Da Thanh Li";
	}
}
string formatDate(int ngay, int thang, int nam){
	string t = "";
	if(ngay < 10){
		t = t + "0" + ChuyenSoSangString(ngay);
	}
	else{
		t = t + ChuyenSoSangString(ngay);
	}
	if(thang < 10){
		t = t + "/0" + ChuyenSoSangString(thang) + "/" + ChuyenSoSangString(nam);
	}
	else{
		t = t + "/" + ChuyenSoSangString(thang) + "/" + ChuyenSoSangString(nam);
	}
	return t;
}

bool layThongTinSach(ARRAYBOOK m, string maSach, BOOK* &tempDS, NODE_BOOKLIST* &tempSach){
	for(int i = 0; i< m.numberBook;i++){
		if(tachLayMaDauSach(maSach) == m.nodesBook[i]->idBook){
			for(NODE_BOOKLIST* k = m.nodesBook[i]->listBL.pHead; k!=NULL; k = k->pNext){
				if(maSach == k->data.idBookList && k->data.status == 0){
					tempDS = m.nodesBook[i];
					tempSach = k;
					return true;
				}
			}
		}
	}
	return false;
}
bool layThongTinSachTra(ARRAYBOOK m, string maSach, BOOK* &tempDS, NODE_BOOKLIST* &tempSach){
	for(int i = 0; i< m.numberBook;i++){
		if(tachLayMaDauSach(maSach) == m.nodesBook[i]->idBook){
			for(NODE_BOOKLIST* k = m.nodesBook[i]->listBL.pHead; k!=NULL; k = k->pNext){
				if(maSach == k->data.idBookList){
					tempDS = m.nodesBook[i];
					tempSach = k;
					return true;
				}
			}
		}
	}
	return false;
}

bool checkDate(Date date){
	if(date.year % 400 == 0 || (date.year %4 ==0 && date.year %100 != 0)){
		if(date.month == 2 && date.day <= 29){
			return true;
		}
		else if((date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11 ) && date.day < 31 ){
			return true;
		}
		if(date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12){
			return true;
		}
	}
	else{
		if((date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11 ) && date.day < 31 ){
			return true;
		}
		else if(date.month == 2 && date.day <= 28){
			return true;
		}
		if(date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12){
			return true;
		}
	}
	return false;
}

bool checkMaSachDangMuon(TREE_READERTICKET t,string maSach, NODEDOUBLE_BORROWRETURN* &sachMuon){
	
	for(NODEDOUBLE_BORROWRETURN* k = t->data.doublelist_borrowReturn.pHead;  k != NULL; k = k->pNext){
		if(k->data.idBookList == maSach && k->data.status == 0 ){
			sachMuon = k;
			return true;
		}
	}
	return false;
}

bool checkMaSachTra(TREE_READERTICKET t,string maSach, NODEDOUBLE_BORROWRETURN* &sachMuon){
	
	for(NODEDOUBLE_BORROWRETURN* k = t->data.doublelist_borrowReturn.pHead;  k != NULL; k = k->pNext){
		if(k->data.idBookList == maSach && k->data.status != 1 ){
			sachMuon = k;
			return true;
		}
	}
	return false;
}

bool KTNamNhuan(int nam)
{
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
	{
		return true;
	}
	else
		return false;
}


int SoNgayCuaThang1(int thang, int nam)
{
	if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
	{
		return 31;
	}
	else if (thang == 2)
	{
		if (KTNamNhuan(nam))
		{
			return 29;
		}
		else
			return 28;
	}
	else
		return 30;
}

int tinhNgay(Date d){
	int total = 0;
	for(int i = 2000; i < d.year ; i++){
		if(KTNamNhuan(i) == true){
			total = total + 366;
		} 
		else {
			total = total + 365;
		}
	}
	
	
	for(int i = 1; i < d.month; i++){
		total = total + SoNgayCuaThang1(i, d.year);
	}
	
	return total + d.day;
}

int sosanhngay(Date d1, Date d2){
	return tinhNgay(d2) - tinhNgay(d1);
}

int ChuyenThang(string str)
{
	if (str == "Jan")
	{
		return 1;
	}
	else if (str == "Feb")
	{
		return 2;
	}
	else if (str == "Mar")
	{
		return 3;
	}
	else if (str == "Apr")
	{
		return 4;
	}
	else if (str == "May")
	{
		return 5;
	}
	else if (str == "Jun")
	{
		return 6;
	}
	else if (str == "Jul")
	{
		return 7;
	}
	else if (str == "Aug")
	{
		return 8;
	}
	else if (str == "Sep")
	{
		return 9;
	}
	else if (str == "Oct")
	{
		return 10;
	}
	else if (str == "Nov")
	{
		return 11;
	}
	else if (str == "Dec")
	{
		return 12;
	}
}

void LayNgayHienTai(Date& d)
{
	// tra ve date/time hien tai dua tren system hien tai
	time_t hientai = time(0);
	// chuyen doi hientai thanh dang chuoi
	char* dt = ctime(&hientai);
	string str1, str2, str3;
	//ngay
	for (int i = 8; i < 10; i++)
	{
		str1.push_back(dt[i]);
	}
	d.day = atoi(str1.c_str());
	// thang
	for (int i = 4; i < 7; i++)
	{
		str2.push_back(dt[i]);
	}
	d.month = ChuyenThang(str2);
	//nam
	for (int i = 20; i < 24; i++)
	{
		str3.push_back(dt[i]);
	}
	d.year = atoi(str3.c_str());
}


void KiemTraQuaHan(TREE_READERTICKET& t, Date NgayHienTai)
{
	bool check = false;
	if (t == NULL)
	{
		return;
	}
	else
	{
		int dayOverDue = 0;
		
		for (NODEDOUBLE_BORROWRETURN* k = t->data.doublelist_borrowReturn.pHead; k != NULL; k = k->pNext)
		{
			if ((k->data.status == 0 || k->data.status == 2) && sosanhngay(k->data.dateBorrow, NgayHienTai) > 7)
			{
				t->data.status = 0;
				check = true;
				if(sosanhngay(k->data.dateBorrow, NgayHienTai) - 7 > dayOverDue){
					dayOverDue = sosanhngay(k->data.dateBorrow, NgayHienTai) - 7;
				}
			}
		}
		if(check == true){
			t->data.daysOverdueMax = dayOverDue;
		}

		KiemTraQuaHan(t->pLeft, NgayHienTai);
		KiemTraQuaHan(t->pRight, NgayHienTai);
	}
}


string upper(string t){
	for(int i = 0; i< t.length();i++){
		if(t[i] >= 97 && t[i] <= 122){
			t[i] = t[i] - 32;
		} 
	}
	return t;
}

void filterType(ARRAYBOOK m, string a[], int &n){
	n = m.numberBook;
	for(int i = 0; i < n; i++){
		a[i] = m.nodesBook[i]->type;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] == a[j]) {
				for(int k = j; k<n-1;k++){
					a[k] = a[k+1];
				}
				n--;
				i--;
			}
		}
	}
}

