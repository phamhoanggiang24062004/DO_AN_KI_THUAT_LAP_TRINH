#include "SinhVien.h"
#include "KhoaHoc.h"

int A[13] = { 0,31,0,31,30,31,30,31,31,30,31,30,31 };
// Kiem tra nam nhuan
void isLeapYear(int year,int A[13])
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		A[2] = 29;
	}
	else
	{
		A[2] = 28;
	}
}
// Khoi tao danh sach lien ket (sinh vien)
void Initialize_Student(List_Student& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
// Khoi tao Node dslk(sinh vien)
Node_Student* Make_Node_Student(Student x)
{
	Node_Student* NewNode = new Node_Student;
	NewNode->info = x;
	NewNode->pNext = NULL;
	return NewNode;
}
// Them mot sinh vien vao cuoi dslk
void Add_Tail_List_Student(List_Student& l, Student x)
{
	Node_Student* NewNode = Make_Node_Student(x);
	if (l.pHead == NULL && l.pTail==NULL)
	{
		l.pHead = NewNode;
		l.pTail = NewNode;
	}
	else
	{
		l.pTail->pNext = NewNode;
		l.pTail = NewNode;
	}
}
// Xoa sinh vien o dau danh sach
void Remove_Head_List_Student(List_Student& l)
{
	if (l.pHead == NULL)
	{
		cout << "Danh sach sinh vien hien tai dang rong!" << endl;
	}
	else
	{
		Node_Student* temp = l.pHead;
		l.pHead = l.pHead->pNext;
		delete temp;
		temp = NULL;
	}
}
// Xoa sinh vien o cuoi danh sach
void Remove_Tail_List_Student(List_Student& l)
{
	Node_Student* temp = NULL;
	for (Node_Student* i = l.pHead;i->pNext != NULL;i = i->pNext)
	{
		temp = i;
	}
	Node_Student* p = temp->pNext;
	temp->pNext = NULL;
	l.pTail = temp;
	delete p;
	p = NULL;
}
// Xuat thong tin 1 sinh vien
void Print_1Student(Student x)
{
	string FullName = x.FirstName +" "+ x.LastName;
	string Day = to_string(x.DateOfBirth.Day) + "/"  +to_string(x.DateOfBirth.Month) + "/" + to_string(x.DateOfBirth.Year);
	cout <<left<<setw(15)<< x.No << left << setw(20) << x.StudentID << left << setw(25) <<FullName<<left<<setw(15)<< Day << left << setw(15) << x.Gender << left << setw(25) << x.SocialID << endl;
}
// Xuat thong tin danh sach sinh vien
void Print_List_Student(List_Student l)
{
	Node_Student* temp = l.pHead;
	cout << left<<setw(15)<<"So thu tu" << left << setw(20) << "Ma so sinh vien" << left << setw(25) << "Ho va ten" << left << setw(15) << "Ngay sinh" << left << setw(15) << "Gioi tinh" << left << setw(25) << "Can cuoc cong dan" << endl;
	while (temp != NULL)
	{
		Print_1Student(temp->info);
		temp = temp->pNext;
	}
}
// Doc 1 sinh vien tu file csv
void Read_1Student(ifstream& read, Student& x)
{
	read >> x.No;
	read.seekg(1, 1);
	getline(read, x.StudentID, ',');
	getline(read, x.FirstName, ',');
	getline(read, x.LastName, ',');
	getline(read, x.Gender, ',');
	read >> x.DateOfBirth.Month;
	read.seekg(1, 1);
	read >> x.DateOfBirth.Day;
	read.seekg(1, 1);
	read >> x.DateOfBirth.Year;
	read.seekg(1, 1);
	read >> x.SocialID;
	
}
// Doc danh sach sinh vien tu file csv
void Read_File_Student( List_Student& l)
{
	string Link;
	cout << "Nhap vao duong dan den file can doc thong tin sinh vien: ";
	cin >> Link;
	ifstream read;
	read.open(Link, ios_base::in);
	if (read.is_open() == false)
	{
		cout << "Khong mo duoc file co duong dan vua nhap!" << endl;
	}
	else
	{
		string temp;
		getline(read, temp);
		while (read.peek() != EOF)
		{
			Student x;
			Read_1Student(read, x);
			if (x.FirstName != "")
			{
				Add_Tail_List_Student(l, x);
			}
		}
		read.close();
	}
}
// Nhap thong tin cua 1 sinh vien
void Input_1Student(Student &x)
{
	cin.ignore();
	cout << "Nhap ho cua sinh vien: ";
	cin >> x.FirstName;
	cin.ignore();
	cout << "Nhap ho dem va ten cua sinh vien: ";
	getline(cin, x.LastName);
	cout << "Nhap ma so sinh vien: ";
	cin >> x.StudentID;
	cout << "Nhap ngay thang nam sinh cua sinh vien: ";
	cin >> x.DateOfBirth.Day >> x.DateOfBirth.Month >> x.DateOfBirth.Year;
	isLeapYear(x.DateOfBirth.Year,A);
	while (x.DateOfBirth.Day <= 0 || x.DateOfBirth.Day >= 32 || x.DateOfBirth.Month > 12 || x.DateOfBirth.Month <= 0 || x.DateOfBirth.Year <= 0 || x.DateOfBirth.Day > A[x.DateOfBirth.Month])
	{
		cout << "Ngay thang nam sinh nhap vao khong hop le. Vui long nhap lai: ";
		cin >> x.DateOfBirth.Day >> x.DateOfBirth.Month >> x.DateOfBirth.Year;
		isLeapYear(x.DateOfBirth.Year,A);
	}
	cout << "Nhap can cuoc cong dan: ";
	cin >> x.SocialID;
	while (true)
	{
		system("cls");
		cout << "Nhap gioi tinh cua sinh vien: " << endl;
		cout << "1.Nam" << endl;
		cout << "2.Nu" << endl;
		int choose;
		cout << "Nhap vao lua chon: ";
		cin >> choose;
		if (choose == 1)
		{
			x.Gender = "Nam";
			break;
		}
		else if (choose == 2)
		{
			x.Gender = "Nu";
			break;
		}
		else
		{
			cout << "Lua chon nhap vao khong hop le. Vui long kiem tra va nhap lai!" << endl;
			system("pause");
		}
	}
}
// Cap nhat STT cua sinh vien sau khi them hoac xoa
void Update_IDStudent(List_Student& l, string ID)
{
	Node_Student* temp = NULL;
	for (Node_Student* i = l.pHead;i != NULL;i = i->pNext)
	{
		if (strcmp(i->info.StudentID.c_str(), ID.c_str()) == 0)
		{
			temp = i;
			break;
		}

	}
	for (Node_Student* i = temp->pNext;i != NULL;i = i->pNext)
	{
		i->info.No--;
	}
}
// Xoa 1 sinh vien khoi ds sinh vien
void Delete_1Student(List_Student& l,string ID)
{
	if (strcmp(l.pHead->info.StudentID.c_str(), ID.c_str()) == 0)
	{
		
		Remove_Head_List_Student(l);
	}
	else if(strcmp(l.pTail->info.StudentID.c_str(), ID.c_str()) == 0)
	{
		Remove_Tail_List_Student(l);
	}
	else
	{
		Node_Student* temp = NULL;
		for (Node_Student* i = l.pHead;i->pNext != NULL;i=i->pNext)
		{
			if (strcmp(i->info.StudentID.c_str(), ID.c_str()) == 0)
			{
				temp->pNext = i->pNext;
				delete i;
				i = NULL;
				break;
			}
			temp = i;

		}
	}
}
void Free_Node_Student(List_Student& l)
{
	Node_Student* temp = NULL;
	while (l.pHead != NULL)
	{
		temp = l.pHead;
		l.pHead = l.pHead->pNext;
		delete temp;
	}
	temp = NULL;
}