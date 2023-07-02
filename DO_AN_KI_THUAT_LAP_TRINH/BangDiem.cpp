#include "BangDiem.h"

void Initialize_MarkBoard(List_MarkBoard& MB)
{
	MB.pHead = MB.pTail = NULL;
}
Node_MarkBoard* Make_Node_MB(MarkBoard x)
{
	Node_MarkBoard* NewNode = new Node_MarkBoard;
	NewNode->info = x;
	NewNode->pNext = NULL;
	return NewNode;

}
void Add_Tail_MB(List_MarkBoard& l, MarkBoard MB)
{
	Node_MarkBoard* NewNode = Make_Node_MB(MB);
	if (l.pHead == NULL && l.pTail == NULL)
	{
		l.pHead = l.pTail = NewNode;
	}
	else
	{
		l.pTail->pNext = NewNode;
		l.pTail = NewNode;
	}
}
void Print_1MarkBoard(MarkBoard MB)
{
	string temp = "Bang Diem Mon " + MB.COURSE.Course_Name + " Lop " + MB.COURSE.CLASS.Class_Name;
	cout << right << setw(88) << temp << endl;
	cout << right << setw(2) << "-";
	for (int i = 1;i <= 137;i++)
	{
		cout << "-";
	}
	cout << endl;
	cout <<left<<setw(3)<<"|" << left << setw(10) << "STT" << left << setw(3) << "|" << left << setw(15) << "ID"<<left<<setw(3)<<"|" << left << setw(26) << "Ho va ten" <<left<<setw(3)<<"|"<< left << setw(17) << "Diem giua ki" <<left<<setw(3)<<"|"<< left << setw(17) << "Diem cuoi ki" <<left<<setw(3)<<"|"<< left << setw(13) << "Diem khac" <<left<<setw(3)<<"|"<< left << setw(20) << "Diem trung binh"<<"|" << endl;
	cout << right << setw(2) << "-";
	for (int i = 1;i <= 137;i++)
	{
		cout << "-";
	}
	cout << endl;
	for (Node_Student* i = MB.COURSE.CLASS.LIST_STUDENT.pHead;i != NULL;i = i->pNext)
	{
		string Full_Name = i->info.FirstName + " " + i->info.LastName;
		cout <<left<<setw(3)<<"|"<< left << setw(10) << i->info.No <<left<<setw(3)<<"|"<< left << setw(15) << i->info.StudentID <<left<<setw(3)<<"|"<< left << setw(26) << Full_Name <<left<<setw(3)<<"|"<< left << setw(17) << i->info.MidtermMark <<left<<setw(3)<<"|"<< left << setw(17) << i->info.FinalMark <<left<<setw(3)<<"|"<< left << setw(13) << i->info.OtherMark <<left<<setw(3)<<"|"<< left << setw(20) << i->info.TotalMark<<"|" << endl;
		cout << right << setw(2) << "-";
		for (int i = 1;i <= 137;i++)
		{
			cout << "-";
		}
		cout << endl;
	}
}
void Print_MarkBoard_1Course(List_MarkBoard l, string id_course)
{
	Node_MarkBoard* temp = l.pHead;
	while (temp != NULL)
	{
		if (temp->info.COURSE.ID.compare(id_course) == 0)
		{
			break;
		}
		temp = temp->pNext;
	}
	if (temp == NULL)

	{
		cout << "Khong tim thay khoa hoc co ten vua nhap hoac chua cap nhat thong tin diem cua khoa hoc!" << endl;
	}
	else
	{
		Print_1MarkBoard(temp->info);
	}
}
void Read_File_Scoreboard(List_Course l, string id_course, List_MarkBoard& lb)
{
	MarkBoard MB;
	Initialize_Student(MB.COURSE.CLASS.LIST_STUDENT);
	Node_MarkBoard* tam = lb.pHead;
	Node_Course* temp = l.pHead;
	while (temp != NULL)
	{
		if (temp->info.ID.compare(id_course) == 0)
		{
			break;
		}
		temp = temp->pNext;
	}
	if (temp == NULL)
	{
		cout << "Khong tim thay khoa hoc nao co ID " << id_course << " vua nhap!" << endl;
	}
	else
	{
		bool check = true;
		while (tam != NULL)
		{
			if (tam->info.COURSE.ID.compare(id_course) == 0)
			{
				check = false;
				break;
			}
			tam = tam->pNext;
		}
		if (check == false)
		{
			cout << "Da ton tai bang diem cua khoa hoc co ID vua nhap trong danh sach bang diem!" << endl;
		}
		else if(check==true)
		{
			MB.COURSE.ID = temp->info.ID;
			MB.COURSE.Course_Name = temp->info.Course_Name;
			MB.COURSE.CLASS.Class_Name = temp->info.CLASS.Class_Name;
			MB.COURSE.Credit_Number = temp->info.Credit_Number;
			ifstream read;
			string link;
			link += "Dssv_" + temp->info.Course_Name + "_" + temp->info.CLASS.Class_Name + ".csv";
			read.open(link, ios_base::in);
			string tam;
			getline(read, tam);
			while (read.peek() != EOF)
			{
				Student x;
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
				getline(read, x.SocialID, ',');
				read >> x.MidtermMark;
				read.seekg(1, 1);
				read >> x.FinalMark;
				read.seekg(1, 1);
				read >> x.OtherMark;
				read.seekg(1, 1);
				read >> x.TotalMark;
				if (x.FirstName != "")
				{
					Add_Tail_List_Student(MB.COURSE.CLASS.LIST_STUDENT, x);
				}
			}
			read.close();
			Add_Tail_MB(lb, MB);
			cout << "Da cap nhat bang diem sinh vien cua khoa hoc tu file csv!" << endl;
		}
	}
}
void Print_MarkBoard_1Class(List_MarkBoard lb, List_Class lc, string name)
{
	float GPA_overall = 0;
	Node_Class* cl = lc.pHead;
	while (cl != NULL)
	{
		if (cl->info.Class_Name.compare(name) == 0)
		{
			break;
		}
		cl = cl->pNext;
	}
	if (cl == NULL)
	{
		cout << "Khong tim thay lop hoc co ten vua nhap. Vui long kiem tra lai!" << endl;
	}
	else
	{
		int stt = 1;
		Number_Student_1Class(cl->info);
		int number_stu = cl->info.Number_Student;
		cout << "THONG TIN DIEM CUOI KI VA GPA CUA SINH VIEN LOP: " << name << endl;
		cout << right << setw(2) << "-";
		for (int i = 1;i <= 102;i++)
		{
			cout << "-";
		}
		cout << endl;
		cout <<left<<setw(3)<<"|"<<left << setw(7) << "STT" << left << setw(3) << "|" << left << setw(30) << "Ho va ten" << left << setw(3) << "|" << left << setw(30) << "Ten khoa hoc" << left << setw(3) << "|" << left << setw(25) << "Diem cuoi ki" <<"|"<< endl;
		cout << right << setw(2) << "-";
		for (int i = 1;i <= 102;i++)
		{
			cout << "-";
		}
		cout << endl;
		Node_Student* St = cl->info.LIST_STUDENT.pHead;

		while (St != NULL)
		{
			float GPA = 0;
			int cnt = 0;
			string Full_Name = St->info.FirstName + " " + St->info.LastName;
			cout <<left<<setw(3)<<"|"<<left<<setw(7)<<stt<<left<<setw(3)<<"|"<<left<<setw(30)<< Full_Name<<left<<setw(3)<<"|"<<right<<setw(31)<<"|"<<right<<setw(28)<<"|" << endl;

			Node_MarkBoard* Mb = lb.pHead; // duyet qua tung bang diem
			while (Mb != NULL)
			{
				Node_Student* temp = Mb->info.COURSE.CLASS.LIST_STUDENT.pHead; // duyet qua cac sinh vien co trong bang diem
				while (temp != NULL)
				{
					if (temp->info.StudentID.compare(St->info.StudentID) == 0)
					{
						cout << "|" << right << setw(10) << "|" << right << setw(33) << "|" <<left<<setw(2)<<" "<< left << setw(30) << Mb->info.COURSE.Course_Name << left << setw(3) << "|" << right << setw(7) << temp->info.FinalMark << right << setw(19) << "|" << endl;
						/*cout <<right<< setw(42) << Mb->info.COURSE.Course_Name <<right<< setw(25) << temp->info.FinalMark << endl;*/
						GPA += temp->info.TotalMark * Mb->info.COURSE.Credit_Number;
						cnt += Mb->info.COURSE.Credit_Number;
						break;
					}
					temp = temp->pNext;
				}
				Mb = Mb->pNext;
			}
			stt++;
			if (GPA != 0 && cnt != 0)
			{
				GPA = GPA / cnt;
				cout << "|" << right << setw(10) << "|" << right << setw(33) << "|" <<left<<setw(2)<<" "<< left << setw(30) << "DIEM GPA:" << left << setw(3) << "|" << right << setw(7) << GPA << right << setw(19) << "|" << endl;
			
				GPA_overall += GPA;
			}
			cout << right << setw(2) << "-";
			for (int i = 1;i <= 102;i++)
			{
				cout << "-";
			}
			cout << endl;
			St = St->pNext;
		}
		cout << "Diem trung binh GPA cua lop " << name << " la: " << (GPA_overall) / number_stu << endl;
	}
}
void Print_MarkBoard_1Student(List_MarkBoard lb, string ID)
{
	Node_MarkBoard* mb = lb.pHead;
	int cnt = 1;
	float GPA = 0;
	int tinchi = 0;
	cout << right << setw(2) << "-";
	for (int i = 1;i <= 94;i++)
	{
		cout << "-";
	}
	cout << endl;
	cout <<left<<setw(3)<<"|" <<left << setw(10) << "STT" << left << setw(3)<<"|"<< left << setw(16) << "ID Khoa hoc" << left << setw(3) <<"|"<< left << setw(20) << "Ten khoa hoc" << left << setw(3) <<"|"<< left << setw(15) << "So tin chi" << left << setw(3) <<"|"<< left << setw(20) << "Diem trung binh" << "|" << endl;
	cout << right << setw(2) << "-";
	for (int i = 1;i <= 94;i++)
	{
		cout << "-";
	}
	cout << endl;
	while (mb != NULL)
	{
		Node_Student* st = mb->info.COURSE.CLASS.LIST_STUDENT.pHead;
		while (st != NULL)
		{
			if (st->info.StudentID.compare(ID) == 0)
			{
				cout << left << setw(3)<<"|"<< left << setw(10) << cnt << left << setw(3) << "|"<< left << setw(16) << mb->info.COURSE.ID << left << setw(3) << "|"<< left << setw(20) << mb->info.COURSE.Course_Name << left << setw(3) << "|"<< left << setw(15) << mb->info.COURSE.Credit_Number << left << setw(3) << "|"<< left << setw(20) << st->info.TotalMark <<"|"<< endl;
				cout << right << setw(2) << "-";
				for (int i = 1;i <= 94;i++)
				{
					cout << "-";
				}
				cout << endl;
				GPA += st->info.TotalMark * mb->info.COURSE.Credit_Number;
				tinchi += mb->info.COURSE.Credit_Number;
				cnt++;
				break;
			}
			st = st->pNext;
		}
		mb = mb->pNext;
	}
	if (GPA != 0 && tinchi != 0)
	{
		cout << "Diem GPA:   " << GPA / tinchi << endl;
	}
}
void Update_Student_Result(List_MarkBoard &lb, string ID_Stu,string ID_Course)
{
	Node_MarkBoard* mb = lb.pHead;
	Node_Student* st = NULL;
	while (mb != NULL)
	{
		if (mb->info.COURSE.ID.compare(ID_Course) == 0)
		{
			break;
		}
		mb = mb->pNext;
	}
	if (mb == NULL)
	{
		cout << "Khong tim thay khoa hoc can cap nhat diem cua sinh vien!" << endl;
	}
	else
	{
		st = mb->info.COURSE.CLASS.LIST_STUDENT.pHead;
		while (st != NULL)
		{
			if (st->info.StudentID.compare(ID_Stu) == 0)
			{
				break;
			}
			st = st->pNext;
		}
		if (st == NULL)
		{
			cout << "Khong tim thay sinh vien nao co ID vua nhap trong khoa hoc nay!" << endl;
		}
		else
		{
			while (true)
			{
				system("cls");
				cout << " ------------ UPDATE-RESULT ------------- " << endl;
				cout << "| 1. Diem giua ki.                       |" << endl;
				cout << " ----------------------------------------" << endl;
				cout << "| 2. Diem cuoi ki.                       |" << endl;
				cout << " ----------------------------------------" << endl;
				cout << "| 3. Diem khac.                          |" << endl;
				cout << " ----------------------------------------" << endl;
				cout << "| 4. Diem tong ket.                      |" << endl;
				cout << " ----------------------------------------" << endl;
				cout << "| 5. Thoat.                              |" << endl;
				cout << " ----------------------------------------" << endl;
				int choose;
				cout << "Nhap vao lua chon: ";
				cin >> choose;
				if (choose == 1)
				{
					cout << "Nhap lai diem giua ki: ";
					cin >> st->info.MidtermMark;
				}
				else if (choose == 2)
				{
					cout << "Nhap lai diem cuoi ki: ";
					cin >> st->info.FinalMark;
				}
				else if (choose == 3)
				{
					cout << "Nhap lai diem khac: ";
					cin >> st->info.OtherMark;
				}
				else if (choose == 4)
				{
					cout << "Nhap lai diem tong ket: ";
					cin >> st->info.TotalMark;
				}
				else if (choose == 5)
				{
					break;
				}
				else
				{
					cout << "Lua chon nhap vao khong hop le.Vui long kiem tra va nhap lai!" << endl;
					system("pause");
				}
			}
			cout << "Da cap nhat ket qua cua sinh vien trong khoa hoc!" << endl;

		}
							
	}
	
}