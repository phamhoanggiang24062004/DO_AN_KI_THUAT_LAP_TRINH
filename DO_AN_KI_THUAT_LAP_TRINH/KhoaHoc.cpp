#include "KhoaHoc.h"
bool isEmpty_Course(List_Course l)
{
	return (l.pHead == NULL);
}
void Initialize_Course(List_Course& l)
{
	l.pHead = l.pTail = NULL;
}
Node_Course* Make_Node_Course(Course x)
{
	Node_Course* NewNode = new Node_Course;
	NewNode->info = x;
	NewNode->pNext = NULL;
	return NewNode;
}
void Add_Tail_Course(List_Course& l, Course x)
{
	Node_Course* NewNode = Make_Node_Course(x);
	if (l.pHead == NULL && l.pTail==NULL)
	{
		l.pHead = NewNode;
		l.pTail = NewNode;
	}
	else if(l.pHead!=NULL && l.pTail !=NULL)
	{
		l.pTail->pNext = NewNode;
		l.pTail = NewNode;
	}
}
void Remove_Head_List_Course(List_Course& l)
{
	if (l.pHead == NULL)
	{
		cout << "Danh sach khoa hoc hien tai dang rong!" << endl;
	}
	else
	{
		Node_Course* temp = l.pHead;
		l.pHead = l.pHead->pNext;
		delete temp;
		temp = NULL;
	}
}
void Remove_Tail_List_Course(List_Course& l)
{
	Node_Course* temp = NULL;
	for (Node_Course* i = l.pHead;i->pNext != NULL;i = i->pNext)
	{
		temp = i;
	}
	Node_Course* p = temp->pNext;
	temp->pNext = NULL;
	l.pTail = temp;
	delete p;
	p = NULL;
}
void Print_1Course(Course x)
{
	
    cout << left<<setw(15)<<x.ID <<left<< setw(30) << x.Course_Name <<left<< setw(16) << x.CLASS.Class_Name<<left<<setw(20)<<x.CLASS.TEACHER.Teacher_Name<<left<<setw(20)<<x.Credit_Number<<left<<setw(18)<<x.Day<<left<<setw(15)<<x.Session <<left<<setw(24)<<x.CLASS.Number_Student<< endl;

}
void Print_List_Course(List_Course l)
{
	
	cout << right << setw(85) << "DANH SACH KHOA HOC" << endl;
	cout << left << setw(15) << "ID khoa hoc" << left << setw(30) << "Ten khoa hoc" << left << setw(16) << "Ten lop hoc" << left << setw(20) << "Ten giang vien" << left << setw(20) << "So tin chi" << left << setw(18) << "Ngay hoc(Thu)" << left << setw(15) << "Buoi hoc" << left << setw(24) << "So luong sinh vien" << endl;
	while (l.pHead != NULL)
	{

		Print_1Course(l.pHead->info);
		l.pHead = l.pHead->pNext;
	}
	
}
void Add_New_Course(Course& temp)
{
	Initialize_Student(temp.CLASS.LIST_STUDENT);
	while (true)
	{
		system("cls");
		cout << " --------------------  NEW_COURSE  ----------------------" << endl;
		cout << "|1. Nhap ten khoa hoc.                                   |" << endl;
		cout << "|2. Nhap ID khoa hoc.                                    |" << endl;
		cout << "|3. Nhap ten lop hoc.                                    |" << endl;
		cout << "|4. Nhap ten giang vien.                                 |" << endl;
		cout << "|5. Nhap so tin chi.                                     |" << endl;
		cout << "|6. Nhap ngay hoc trong tuan.                            |" << endl;
		cout << "|7. Nhap buoi hoc trong tuan.                            |" << endl;
		cout << "|8. Them danh sach sinh vien da dang ki khoa hoc nay.    |" << endl;
		cout << "|9. Thoat.                                               |" << endl;
		cout << " -----------------------   END  -------------------------" << endl;
		int choose;
		cout << "Nhap vao lua chon: ";
		cin >> choose;
		if (choose == 1)
		{
			if (temp.Course_Name != "")
			{
				cout << "Ban da nhap ten khoa hoc la: " << temp.Course_Name << endl;
				cout << "Ban co muon nhap lai du lieu khong?" << endl;
				cout << "1. YES" << endl;
				cout << "2. NO" << endl;
				int choose;
				cout << "Nhap vao lua chon: ";
				cin >> choose;
				if (choose == 1)
				{
					cin.ignore();
					cout << "Nhap ten khoa hoc: ";
					getline(cin, temp.Course_Name);

				}
				else if (choose == 2)
				{

				}

			}
			else
			{
				cin.ignore();
				cout << "Nhap ten khoa hoc: ";
				getline(cin, temp.Course_Name);
			}
		}
		else if (choose == 2)
		{
			if (temp.ID != "")
			{
				cout << "Ban da nhap ID khoa hoc la: " << temp.ID << endl;
				cout << "Ban co muon nhap lai du lieu khong?" << endl;
				cout << "1. YES" << endl;
				cout << "2. NO" << endl;
				int choose;
				cout << "Nhap vao lua chon: ";
				cin >> choose;
				if (choose == 1)
				{
					cout << "Nhap ID khoa hoc: ";
					cin >> temp.ID;

				}
				else if (choose == 2)
				{

				}
			}
			else
			{
				cout << "Nhap ID khoa hoc: ";
				cin >> temp.ID;
			}
		}
		else if (choose == 3)
		{
			if (temp.CLASS.Class_Name != "")
			{
				cout << "Ban da nhap ten lop hoc la: " << temp.CLASS.Class_Name << endl;
				cout << "Ban co muon nhap lai du lieu khong?" << endl;

				cout << "1. YES" << endl;
				cout << "2. NO" << endl;
				int choose;
				cout << "Nhap vao lua chon: ";
				cin >> choose;
				if (choose == 1)
				{

					cout << "Nhap ten lop hoc: ";
					cin >> temp.CLASS.Class_Name;

				}
				else if (choose == 2)
				{

				}


			}
			else
			{
				cout << "Nhap ten lop hoc: ";
				cin >> temp.CLASS.Class_Name;
			}
		}
		else if (choose == 4)
		{
			if (temp.CLASS.TEACHER.Teacher_Name != "")
			{
				cout << "Ban da nhap ten giang vien la: " << temp.CLASS.TEACHER.Teacher_Name << endl;
				cout << "Ban co muon nhap lai du lieu khong?" << endl;

				cout << "1. YES" << endl;
				cout << "2. NO" << endl;
				int choose;
				cout << "Nhap vao lua chon: ";
				cin >> choose;
				if (choose == 1)
				{
					cin.ignore();
					cout << "Nhap ten giang vien: ";
					getline(cin, temp.CLASS.TEACHER.Teacher_Name);

				}
				else if (choose == 2)
				{

				}


			}
			else
			{
				cin.ignore();
				cout << "Nhap ten giang vien: ";
				getline(cin, temp.CLASS.TEACHER.Teacher_Name);
			}
		}
		else if (choose == 5)
		{
			if (temp.Credit_Number > 0)
			{
				cout << "Ban da nhap so tin chi la: " << temp.Credit_Number << endl;
				cout << "Ban co muon nhap lai du lieu khong?" << endl;

				cout << "1. YES" << endl;
				cout << "2. NO" << endl;
				int choose;
				cout << "Nhap vao lua chon: ";
				cin >> choose;
				if (choose == 1)
				{
					cout << "Nhap so tin chi: ";
					cin >> temp.Credit_Number;

				}
				else if (choose == 2)
				{

				}


			}
			else
			{
				cout << "Nhap so tin chi: ";
				cin >> temp.Credit_Number;
				while (temp.Credit_Number <= 0)
				{
					cout << "Du lieu nhap vao khong hop le. Vui long kiem tra va nhap lai: ";
					cin >> temp.Credit_Number;
				}
			}
		}
		else if (choose == 6)
		{
			while (true)
			{
				system("cls");
				cout << " ---------------------------------" << endl;
				cout << "|       NGAY HOC TRONG TUAN       |" << endl;
				cout << "|                                 |" << endl;
				cout << "| 2. Thu hai(MON)                 |" << endl;
				cout << "| 3. Thu ba(TUE)                  |" << endl;
				cout << "| 4. Thu tu(WED)                  |" << endl;
				cout << "| 5. Thu nam(THU)                 |" << endl;
				cout << "| 6. Thu sau(FRI)                 |" << endl;
				cout << "| 7. Thu bay(SAT)                 |" << endl;
				cout << "|                                 |" << endl;
				cout << " ---------------------------------" << endl;
				int choose;
				cout << "Nhap vao lua chon: ";
				cin >> choose;
				if (choose == 2)
				{
					temp.Day = 2;
					break;
				}
				else if (choose == 3)
				{
					temp.Day = 3;
					break;
				}
				else if (choose == 4)
				{
					temp.Day = 4;
					break;
				}
				else if (choose == 5)
				{
					temp.Day = 5;
					break;
				}
				else if (choose == 6)
				{
					temp.Day = 6;
					break;
				}
				else if (choose == 7)
				{
					temp.Day = 7;
					break;
				}
				else
				{
					cout << "Lua chon nhap vao khong hop le.Vui long kiem tra lai!" << endl;
					system("pause");
				}
			}

		}
		else if (choose == 7)
		{
			while (true)
			{
				system("cls");
				cout << " ---------------------------------" << endl;
				cout << "|       BUOI HOC TRONG TUAN       |" << endl;
				cout << "|                                 |" << endl;
				cout << "| 1. 07:30                        |" << endl;
				cout << "| 2. 09:30                        |" << endl;
				cout << "| 3. 13:30                        |" << endl;
				cout << "| 4. 15:30                        |" << endl;
				cout << "|                                 |" << endl;
				cout << " ---------------------------------" << endl;
				int choose;
				cout << "Nhap vao lua chon: ";
				cin >> choose;
				if (choose == 1)
				{
					temp.Session = "07:30";
					break;
				}
				else if (choose == 2)
				{
					temp.Session = "09:30";
					break;
				}
				else if (choose == 3)
				{
					temp.Session = "13:30";
					break;
				}
				else if (choose == 4)
				{
					temp.Session = "15:30";
					break;
				}
				else
				{
					cout << "Lua chon nhap vao khong hop le.Vui long kiem tra lai!" << endl;
					system("pause");
				}
			}
		}
		else if (choose == 8)
		{
			Read_File_Student(temp.CLASS.LIST_STUDENT);
			Number_Student_1Class(temp.CLASS);
			if (temp.CLASS.Number_Student != 0)
			{
				cout << "Da them danh sach sinh vien vao khoa hoc!" << endl;
			}
			system("pause");
		}
		else if (choose == 9)
		{
			break;
			cout << "Da them khoa hoc nay vao danh sach khoa hoc!" << endl;
			system("pause");
		}
		else
		{
			cout << "Lua chon nhap vao khong hop le. Vui long kiem tra va nhap lai!" << endl;
			system("pause");
		}
	}

}
void Print_ListCourse_1Student(List_Course l, string ID)
{
	int cnt = 1;
	bool check = false;
	Node_Course* temp = l.pHead;
	cout << right << setw(63) << "DANH SACH KHOA HOC" << endl;
	cout << left << setw(10) << "STT" << left << setw(12) << "ID" << left << setw(20) << "Ten khoa hoc" << left << setw(15) << "So tin chi" << left << setw(18) << "Ngay hoc(Thu)" << left << setw(15) << "Buoi hoc"<<left<<setw(24)<<"So luong sinh vien" << endl;
	while (temp != NULL)
	{
	
		    Node_Student* St = temp->info.CLASS.LIST_STUDENT.pHead;
			while (St != NULL)
			{
				if (St->info.StudentID.compare(ID) == 0)
				{
					cout << left << setw(10) << cnt << left << setw(12) << temp->info.ID << left << setw(20) << temp->info.Course_Name << left << setw(15) << temp->info.Credit_Number << left << setw(18) << temp->info.Day << left << setw(15) << temp->info.Session <<left<<setw(24)<<temp->info.CLASS.Number_Student<< endl;
					cnt++;
					check = true;
					break;
				}
				St = St->pNext;
			}
		
		temp = temp->pNext;
	}
	if (check == false)
	{
		cout << "Khong tim thay khoa hoc nao cua sinh vien co ma so " << ID << endl;
	}
	
}
bool Delete_Course(List_Course& l,string ID)
{
	
	if (strcmp(l.pHead->info.ID.c_str(), ID.c_str()) == 0)
	{
		Remove_Head_List_Course(l);
		return true;
	}
	else if (strcmp(l.pTail->info.ID.c_str(), ID.c_str()) == 0)
	{
		Remove_Tail_List_Course(l);
		return true;
	}
	else
	{
		Node_Course* temp = NULL;
		for (Node_Course* i = l.pHead;i->pNext != NULL;i = i->pNext)
		{
			if (strcmp(i->info.ID.c_str(), ID.c_str()) == 0)
			{
				temp->pNext = i->pNext;// cho phan next cua node k-1(k la node can xoa) tro toi node k+1(sau node can xoa)
				delete i;
				i = NULL;
				return true;
				break;
			}
			temp = i;

		}
	}
	return false;
}
void Print_ListStudent_1Course(List_Course l,string ID)
{
	
	Node_Course* c = l.pHead;
	while (c != NULL)
	{
		if (c->info.ID.compare(ID) == 0)
		{
			cout << right<<setw(70) << "DANH SACH SINH VIEN CUA KHOA HOC" << endl;
			Print_List_Student(c->info.CLASS.LIST_STUDENT);
			break;
		}
		c = c->pNext;
	}
	if (c==NULL)
	{
		cout << "Khong tim thay khoa hoc co ma so " << ID << " vua nhap." << endl;
	}
}
void Check_List_Course(List_Course l, string &ID)
{
	cout << "Nhap ID cua sinh vien can in danh sach khoa hoc: ";
	cin >> ID;
	// duyet qua tung khoa hoc
	for (Node_Course* i = l.pHead;i != NULL;i = i->pNext)
	{
		// duyet qua danh sach sinh vien trong khoa hoc do
		for (Node_Student* j = i->info.CLASS.LIST_STUDENT.pHead;j != NULL;j = j->pNext)
		{
			if (strcmp(j->info.StudentID.c_str(), ID.c_str()) == 0)
			{
				Print_1Course(i->info);
			}
			break;
		}
	}
}
void Output_File_1Course(List_Course l,string ID_Course)
{
	Node_Course* temp = l.pHead;
	while (temp != NULL)
	{
		if (temp->info.ID.compare(ID_Course) == 0)
		{
			break;
		}
		temp = temp->pNext;

	}
	if (temp == NULL)
	{
		cout << "Khong tim thay khoa hoc nao co ID trung voi du lieu nhap vao!" << endl;
		system("pause");
	}
	else
	{
		
		Node_Student* tam = temp->info.CLASS.LIST_STUDENT.pHead;
		ofstream write;
		string name;
		name = "Dssv_"+temp->info.Course_Name +"_"+ temp->info.CLASS.Class_Name+".csv";
		write.open(name, ios_base::out);
		write << "STT,ID,Ho,Ten,Gioi tinh,Ngay sinh,CCCD,Diem giua ky,Diem cuoi ky,Diem khac,Diem trung binh" << endl;
		while (tam != NULL)
		{
			write << tam->info.No << "," << tam->info.StudentID << "," << tam->info.FirstName<<","<<tam->info.LastName<<","<<tam->info.Gender<< "," << tam->info.DateOfBirth.Day<<"/"<<tam->info.DateOfBirth.Month<<"/"<<tam->info.DateOfBirth.Year<<","<<tam->info.SocialID << endl;
			tam = tam->pNext;
		}
		write.close();
		cout << "Da xuat danh sach sinh vien cua khoa hoc ra file csv!" << endl;
	}
}
int Add_New_Student(List_Course &l,string ID)
{
	Node_Course* temp = l.pHead;
	while (temp != NULL)
	{
		if (temp->info.ID.compare(ID) == 0)
		{
			if (temp->info.CLASS.Number_Student < temp->info.Number_Student_Max)
			{
				Student x;
				cout << "NHAP THONG TIN CUA SINH VIEN CAN THEM: " << endl;
				temp->info.CLASS.Number_Student++;
				x.No = temp->info.CLASS.Number_Student;
				Input_1Student(x);
				Add_Tail_List_Student(temp->info.CLASS.LIST_STUDENT, x);
				return 1;
			}
			else
			{
				return 2; // khoa hoc full
			}
		}
		temp = temp->pNext;
	}
	return 0;// khong tim thay khoa hoc co ma vua nhap
}
int Remove_Student(List_Course& l, string ID)
{
	Node_Course* temp = l.pHead;
	// Tim ra lop cu the vua nhap vao
	while (temp != NULL)
	{
		if (temp->info.ID.compare(ID) == 0)
		{
			string id_stu;
			cout << "Nhap ID cua sinh vien can xoa khoi khoa hoc: ";
			cin >> id_stu;
			Node_Student* st = temp->info.CLASS.LIST_STUDENT.pHead;
			while (st != NULL)
			{
				if (st->info.StudentID.compare(id_stu) == 0)
				{
					Update_IDStudent(temp->info.CLASS.LIST_STUDENT, id_stu);
			
					Delete_1Student(temp->info.CLASS.LIST_STUDENT, id_stu);
					Number_Student_1Class(temp->info.CLASS);
					return 1;
				}
				st = st->pNext;
			}
			if (st == NULL)
			{
				return 2;
			}
			
		}
		temp = temp->pNext;
	}
	if (temp == NULL)
	{
		return 0;
	}
}
void Update_Course_Information(List_Course &l, string ID_Course)
{
	Node_Course* temp = l.pHead;
	while (temp != NULL)
	{
		if (temp->info.ID.compare(ID_Course) == 0)
		{
			break;
		}
		temp = temp->pNext;
	}
	if (temp == NULL)
	{
		cout << "Khong tim thay khoa hoc can cap nhat thong tin trong danh sach khoa hoc!" << endl;
	}
	else
	{
		while (true)
		{
			system("cls");
			cout << " -------------  UPDATE_COURSE_INFORMATION  --------------" << endl;
			cout << "|1. Ten khoa hoc.                                        |" << endl;
			cout << "|2. ID khoa hoc.                                         |" << endl;
			cout << "|3. Ten lop hoc.                                         |" << endl;
			cout << "|4. Ten giang vien.                                      |" << endl;
			cout << "|5. So tin chi.                                          |" << endl;
			cout << "|6. Ngay hoc trong tuan.                                 |" << endl;
			cout << "|7. Buoi hoc trong tuan.                                 |" << endl;
			cout << "|8. Thoat.                                               |" << endl;
			cout << " -----------------------   END  -------------------------" << endl;
			int choose;
			cout << "Nhap vao lua chon: ";
			cin >> choose;
			if (choose == 1)
			{
				cout << "Nhap lai ten khoa hoc: ";
				cin.ignore();
				getline(cin, temp->info.Course_Name);
			}
			else if (choose == 2)
			{
				cout << "Nhap lai ID khoa hoc: ";
				cin >> temp->info.ID;
			}
			else if (choose == 3)
			{
				cout << "Nhap lai ten lop hoc: ";
				cin >> temp->info.CLASS.Class_Name;
			}
			else if (choose == 4)
			{
				cout << "Nhap lai ten giang vien: ";
				cin.ignore();
				getline(cin, temp->info.CLASS.TEACHER.Teacher_Name);
			}
			else if (choose == 5)
			{
				cout << "Nhap lai so tin chi: ";
				cin >> temp->info.Credit_Number;
			}
			else if (choose == 6)
			{
				while (true)
				{
					system("cls");
					cout << " ---------------------------------" << endl;
					cout << "|       NGAY HOC TRONG TUAN       |" << endl;
					cout << "|                                 |" << endl;
					cout << "| 2. Thu hai(MON)                 |" << endl;
					cout << "| 3. Thu ba(TUE)                  |" << endl;
					cout << "| 4. Thu tu(WED)                  |" << endl;
					cout << "| 5. Thu nam(THU)                 |" << endl;
					cout << "| 6. Thu sau(FRI)                 |" << endl;
					cout << "| 7. Thu bay(SAT)                 |" << endl;
					cout << "|                                 |" << endl;
					cout << " ---------------------------------" << endl;
					int choose;
					cout << "Nhap vao lua chon: ";
					cin >> choose;
					if (choose == 2)
					{
						temp->info.Day = 2;
						break;
					}
					else if (choose == 3)
					{
						temp->info.Day = 3;
						break;
					}
					else if (choose == 4)
					{
						temp->info.Day = 4;
						break;
					}
					else if (choose == 5)
					{
						temp->info.Day = 5;
						break;
					}
					else if (choose == 6)
					{
						temp->info.Day = 6;
						break;
					}
					else if (choose == 7)
					{
						temp->info.Day = 7;
						break;
					}
					else
					{
						cout << "Lua chon nhap vao khong hop le.Vui long kiem tra lai!" << endl;
						system("pause");
					}
				}
			}
			else if (choose == 7)
			{
				while (true)
				{
					system("cls");
					cout << " ---------------------------------" << endl;
					cout << "|       BUOI HOC TRONG TUAN       |" << endl;
					cout << "|                                 |" << endl;
					cout << "| 1. 07:30                        |" << endl;
					cout << "| 2. 09:30                        |" << endl;
					cout << "| 3. 13:30                        |" << endl;
					cout << "| 4. 15:30                        |" << endl;
					cout << "|                                 |" << endl;
					cout << " ---------------------------------" << endl;
					int choose;
					cout << "Nhap vao lua chon: ";
					cin >> choose;
					if (choose == 1)
					{
						temp->info.Session = "07:30";
						break;
					}
					else if (choose == 2)
					{
						temp->info.Session = "09:30";
						break;
					}
					else if (choose == 3)
					{
						temp->info.Session = "13:30";
						break;
					}
					else if (choose == 4)
					{
						temp->info.Session = "15:30";
						break;
					}
					else
					{
						cout << "Lua chon nhap vao khong hop le.Vui long kiem tra lai!" << endl;
						system("pause");
					}
				}
			}
			else if (choose == 8)
			{
				break;
			}
			else
			{
				cout << "Lua chon nhap vao khong hop le.Vui long kiem tra va nhap lai!" << endl;
				system("pause");
			}
		}
		cout << "Da cap nhat lai thong tin cua khoa hoc!" << endl;
	}
}
void Free_Node_Course(List_Course& l)
{
	Node_Course* temp = l.pHead;
	while (temp != NULL)
	{
		Free_Node_Student(temp->info.CLASS.LIST_STUDENT);
		temp = temp->pNext;
	}
}