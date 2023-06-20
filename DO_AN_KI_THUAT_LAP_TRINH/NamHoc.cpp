#include "NamHoc.h"


int B[13] = { 0,31,0,31,30,31,30,31,31,30,31,30,31 };

void init_schoolyear(SchoolYear& x)
{
	x.Sem = new New_Semester[2];
}

void init_ListSy(List_SchoolYear& l)
{
	l.pHead = l.pTail = NULL;
}

Node_SchoolYear * Make_Node_Sy(SchoolYear x)
{
	Node_SchoolYear* NewNode = new Node_SchoolYear;
	NewNode->info = x;
	NewNode->pNext = NULL;
	return NewNode;
}

void Add_Tail_Sy(List_SchoolYear& l, SchoolYear x)
{
	Node_SchoolYear* NewNode = Make_Node_Sy(x);
	if (l.pHead == NULL && l.pTail == NULL)
	{
		l.pHead = NewNode;
		l.pTail = NewNode;
	}
	else if (l.pHead != NULL && l.pTail != NULL)
	{
		l.pTail->pNext = NewNode;
		l.pTail = NewNode;
	}
}

void Create_Semester(SchoolYear &NH, int &temp)
{
	Initialize_Course(NH.Sem[0].LIST_COURSE);
	Initialize_Course(NH.Sem[1].LIST_COURSE);
	Initialize_Course(NH.Sem[2].LIST_COURSE);
	while (true)
	{
		system("cls");
		cout << " ------------------- CREATE_SEMESTER --------------------" << endl;
		cout << "|1. Nhap ten hoc ky.                                     |" << endl;
		cout << "|2. Nhap thoi gian bat dau hoc ky.                       |" << endl;
		cout << "|3. Nhap thoi gian ket thuc hoc ky.                      |" << endl;
		cout << "|4. Them cac khoa hoc vao hoc ky.                        |" << endl;
		cout << "|5. Thoat.                                               |" << endl;
		cout << " -----------------------  END  --------------------------" << endl;
		int choose;
		cout << "Nhap vao lua chon: ";
		cin >> choose;
		if (choose == 1)
		{
			while (true)
			{
				cout << " ---------------------------------" << endl;
				cout << "|            TEN HOC KY           |" << endl;
				cout << "|                                 |" << endl;
				cout << "| 1. Hoc ky 1                     |" << endl;
				cout << "| 2. Hoc ky 2                     |" << endl;
				cout << "| 3. Hoc ky 3                     |" << endl;
				cout << "|                                 |" << endl;
				cout << " ---------------------------------" << endl;
				int choose;
				cout << "Nhap lua chon: ";
				cin >> choose;
				if (choose == 1)
				{
					NH.Sem[0].Semester_Name = 1;
					temp = 0;
					break;
				}
				else if (choose == 2)
				{
					NH.Sem[1].Semester_Name = 2;
					temp = 1;
					break;
				}
				else if (choose == 3)
				{
					NH.Sem[2].Semester_Name = 3;
					temp = 2;
					break;
				}
				else
				{
					cout << "Lua chon nhap vao khong hop le. Vui long kiem tra va nhap lai!" << endl;
					system("pause");
				}
			}
		}
		else if (choose == 2)
		{
			if (NH.Sem->Start.Day > 0 && NH.Sem[temp].Start.Month > 0 && NH.Sem[temp].Start.Year > 0)
			{
				cout << "Ban da nhap du lieu ngay thang nam bat dau hoc ki lan luot la: " << NH.Sem[temp].Start.Day << " " << NH.Sem[temp].Start.Month << " " << NH.Sem[temp].Start.Year << endl;
				cout << "Ban co muon nhap lai ngay thang nam khong?" << endl;
				cout << "1. YES" << endl;
				cout << "2. NO" << endl;
				int choose;
				cout << "Nhap vao lua chon: ";
				cin >> choose;
				if (choose == 1)
				{
					cout << "Nhap ngay thang nam bat dau hoc ki lan luot la(day month year): ";
					cin >> NH.Sem[temp].Start.Day >> NH.Sem[temp].Start.Month >> NH.Sem[temp].Start.Year;
					isLeapYear(NH.Sem[temp].Start.Year,B);
					while (NH.Sem[temp].Start.Day <= 0 || NH.Sem[temp].Start.Day >= 32 || NH.Sem[temp].Start.Month > 12 || NH.Sem[temp].Start.Month <= 0 || NH.Sem[temp].Start.Year <= 0 || NH.Sem[temp].Start.Day > B[NH.Sem[temp].Start.Month])
					{
						cout << "Ngay thang nam nhap vao khong hop le. Vui long nhap lai: ";
						cin >> NH.Sem[temp].Start.Day >> NH.Sem[temp].Start.Month >> NH.Sem[temp].Start.Year;
						isLeapYear(NH.Sem[temp].Start.Year,B);
					}
				}
				else if(choose==2)
				{

				}
			}
			else
			{
				cout << "Nhap ngay thang nam bat dau hoc ki lan luot la(day month year): ";
				cin >> NH.Sem[temp].Start.Day >> NH.Sem[temp].Start.Month >> NH.Sem[temp].Start.Year;
				isLeapYear(NH.Sem[temp].Start.Year,B);
				while (NH.Sem[temp].Start.Day <= 0 || NH.Sem[temp].Start.Day >= 32 || NH.Sem[temp].Start.Month > 12 || NH.Sem[temp].Start.Month <= 0 || NH.Sem[temp].Start.Year <= 0 || NH.Sem[temp].Start.Day > B[NH.Sem[temp].Start.Month])
				{
					cout << "Ngay thang nam nhap vao khong hop le. Vui long nhap lai: ";
					cin >> NH.Sem[temp].Start.Day >> NH.Sem[temp].Start.Month >> NH.Sem[temp].Start.Year;
					isLeapYear(NH.Sem[temp].Start.Year,B);
				}
			}
		}
		else if (choose == 3)
		{
			if (NH.Sem->End.Day > 0 && NH.Sem[temp].End.Month > 0 && NH.Sem[temp].End.Year > 0)
			{
				cout << "Ban da nhap du lieu ngay thang nam bat dau hoc ki lan luot la: " << NH.Sem[temp].End.Day << " " << NH.Sem[temp].End.Month << " " << NH.Sem[temp].End.Year << endl;
				cout << "Ban co muon nhap lai ngay thang nam khong?" << endl;
				cout << "1. YES" << endl;
				cout << "2. NO" << endl;
				int choose;
				cout << "Nhap vao lua chon: ";
				cin >> choose;
				if (choose == 1)
				{
					cout << "Nhap ngay thang nam ket thuc hoc ki lan luot la(day month year): ";
					cin >> NH.Sem[temp].End.Day >> NH.Sem[temp].End.Month >> NH.Sem[temp].End.Year;
					isLeapYear(NH.Sem[temp].End.Year,B);
					while (NH.Sem[temp].End.Day <= 0 || NH.Sem[temp].End.Day >= 32 || NH.Sem[temp].End.Month > 12 || NH.Sem[temp].End.Month <= 0 || NH.Sem[temp].End.Year <= 0 || NH.Sem[temp].End.Day > B[NH.Sem[temp].End.Month])
					{
						cout << "Ngay thang nam nhap vao khong hop le. Vui long nhap lai: ";
						cin >> NH.Sem[temp].End.Day >> NH.Sem[temp].End.Month >> NH.Sem[temp].End.Year;
						isLeapYear(NH.Sem[temp].End.Year,B);
					}
				}
				else if (choose == 2)
				{

				}
			}
			else
			{
				cout << "Nhap ngay thang nam ket thuc hoc ki lan luot la(day month year): ";
				cin >> NH.Sem[temp].End.Day >> NH.Sem[temp].End.Month >> NH.Sem[temp].End.Year;
				isLeapYear(NH.Sem[temp].End.Year,B);
				while (NH.Sem[temp].End.Day <= 0 || NH.Sem[temp].End.Day >= 32 || NH.Sem[temp].End.Month > 12 || NH.Sem[temp].End.Month <= 0 || NH.Sem[temp].End.Year <= 0 || NH.Sem[temp].End.Day > B[NH.Sem[temp].End.Month])
				{
					cout << "Ngay thang nam nhap vao khong hop le. Vui long nhap lai: ";
					cin >> NH.Sem[temp].End.Day >> NH.Sem[temp].End.Month >> NH.Sem[temp].End.Year;
					isLeapYear(NH.Sem[temp].End.Year,B);
				}
			}
		}
		else if (choose == 4)
		{
			
			string ID;
			cout << "Nhap ID cua khoa hoc can them: ";
			cin >> ID;
			bool check = true;
			Node_Course* c = NH.Sem[temp].LIST_COURSE.pHead;
			while (c != NULL)
			{
				if (c->info.ID.compare(ID) == 0)
				{
					check = false;
					break;
				}
				c = c->pNext;
			}
			if (check == true)
			{
				cout << "Khoa hoc vua nhap hop le. Vui long nhan Enter de nhap lai thong tin!" << endl;
				system("pause");
				Course x;
				x.Credit_Number = INT_MIN;
				Add_New_Course(x);
				Add_Tail_Course(NH.Sem[temp].LIST_COURSE, x);
				cout << "Da them khoa hoc nay vao danh sach khoa hoc!" << endl;
			}
			else
			{
				cout << "Da ton tai ID cua khoa hoc nay trong danh sach khoa hoc!" << endl;
			}
			system("pause");
		}
		else if (choose == 5)
		{
			break;
		}
		else
		{
			cout << "Lua chon nhap vao khong hop le. Vui long kiem tra va nhap lai!" << endl;
			system("pause");
		}
	}
}
void Input_SchoolYear(List_SchoolYear& l, SchoolYear &NH,List_Class &CL,int &hocky)
{
	init_schoolyear(NH);
	while (true)
	{
		system("cls");
		cout << " ------------------- NEW_SCHOOLYEAR --------------------" << endl;
		cout << "|1. Nhap ten nam hoc.                                   |" << endl;
		cout << "|2. Them cac lop cua sinh vien nam nhat.                |"<<endl;
		cout << "|3. Tao hoc ky moi.                                     |" << endl;
		cout << "|4. Thoat.                                              |" << endl;
		cout << " -----------------------   END   -----------------------" << endl;
		int choose;
		cout << "Nhap vao lua chon: ";
		cin >> choose;
		if (choose == 1)
		{
			if (NH.year != "")
			{
				cout << "Ban da nhap du lieu nam hoc la: " << NH.year << endl;
				cout << "Ban co muon nhap lai khong?" << endl;
				cout << "1. YES" << endl;
				cout << "2. NO" << endl;
				int choose;
				cout << "Nhap vao lua chon: ";
				cin >> choose;
				if (choose == 1)
				{
					cout << "Nhap ten nam hoc(year-year): ";
					cin >> NH.year;
				}
				else if (choose == 2)
				{
					
				}
			}
			else
			{
				cout << "Nhap ten nam hoc(year-year): ";
				cin >> NH.year;
			}
		}
		else if (choose == 2)
		{
			bool check = true;
			New_Class l;
			cout << "Nhap chuong trinh dao tao(CLC/APCS/VP): ";
			cin >> l.type;
			cout << "Nhap ten lop hoc(vd: 22CLC1,22APCS1,...): ";
			cin >> l.Class_Name;
			Node_Class* temp = CL.pHead;
			while (temp != NULL)
			{
				if (temp->info.Class_Name.compare(l.Class_Name) == 0)
				{
					check = false;
					break;
				}
				temp = temp->pNext;
			}
			if (check == true)
			{
				Initialize_Student(l.LIST_STUDENT);
				Read_File_Student(l.LIST_STUDENT);
				Number_Student_1Class(l);
				if (l.Number_Student != 0)
				{
					Add_Tail_Class(CL, l);
					cout << "Da them lop hoc nay vao danh sach lop hoc!" << endl;
				}
			}
			else
			{
				cout << "Da ton tai lop hoc " << l.Class_Name << " trong danh sach lop hoc!" << endl;
			}
			system("pause");
		}
		else if (choose == 3)
		{
			Create_Semester(NH,hocky);
		}
		else if(choose==4)
		{
			break;
	    }
		else
		{
			cout << "Lua chon nhap vao khong hop le. Vui long kiem tra va nhap lai!" << endl;
			system("pause");
		}
    }
	Add_Tail_Sy(l, NH);
}
void Free_Node_SchoolYear(List_SchoolYear& l)
{
	Node_SchoolYear* temp = l.pHead;
	while (temp != NULL)
	{
		Free_Node_Course(temp->info.Sem[0].LIST_COURSE);
		Free_Node_Course(temp->info.Sem[1].LIST_COURSE);
		Free_Node_Course(temp->info.Sem[2].LIST_COURSE);
	}
	temp = NULL;
	while (l.pHead != NULL)
	{
		temp = l.pHead;
		l.pHead = l.pHead->pNext;
		delete temp;
	}
	temp = NULL;
}