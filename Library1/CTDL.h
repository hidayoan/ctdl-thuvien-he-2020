//date
struct Date
{
	int day;
	int month;
	int year;
};
// Danh muc sach
struct BookList{
	string idBookList;
	int status; //0: cho muon dc, 1: da cho muon, 2: da thanh li 
	string locate;
};
typedef struct BookList BOOKLIST;

struct Node_BookList{
	BookList data;
	struct Node_BookList* pNext;
};
typedef struct Node_BookList NODE_BOOKLIST;

struct List_BookList{
	NODE_BOOKLIST* pHead;
	NODE_BOOKLIST* pTail;
};
typedef struct List_BookList LIST_BOOKLIST;

//dau sach
struct Book
{
	string idBook;
	string nameBook;
	int numberPages;
	string actor;
	int publishingYear;
	string type;
	int numbersBook;
	int numberBorrows;
	LIST_BOOKLIST listBL;
};
typedef struct Book BOOK;

struct arrayBook{
	int numberBook;
	BOOK* nodesBook[MAX];
};
typedef struct arrayBook ARRAYBOOK;

//Muon Tra
struct borrowReturn{
	string idBookList;
	Date dateBorrow;
	Date dateReturn;
	int  status; // trang thai =0 la sach đang muon (chua tra), =1 la da tra, =2 : lam mat sach chua den
};
typedef struct borrowReturn BORROWRETURN;

struct NodeDouble_borrowReturn{
	BORROWRETURN data;
	struct NodeDouble_borrowReturn* pNext;
	struct NodeDouble_borrowReturn* pPrev;
};
typedef struct NodeDouble_borrowReturn NODEDOUBLE_BORROWRETURN;

struct ListDouble_borrowReturn{
	NODEDOUBLE_BORROWRETURN* pHead;
	NODEDOUBLE_BORROWRETURN* pTail;
};
typedef struct ListDouble_borrowReturn LISTDOUBLE_BORROWRETURN;

//Doc Gia
struct readerTicket{
	int idReader;
	string lastname;
	string firstname;
	string sex;
	int status; //trang thai cua the 1 : la đang hoat dong , 0: la bi khoa
	int numberBookBorrow;
	int daysOverdueMax;
	LISTDOUBLE_BORROWRETURN doublelist_borrowReturn;
};
typedef struct readerTicket READERTICKET;

struct NodeReaderTicket{
	readerTicket data;
	NodeReaderTicket* pLeft;
	NodeReaderTicket* pRight;
};
typedef struct NodeReaderTicket NODEREADERTICKET;
typedef NODEREADERTICKET* TREE_READERTICKET;

