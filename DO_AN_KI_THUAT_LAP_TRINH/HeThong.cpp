#include "HeThong.h"
void Initialize_Register(List_Register& l)
{
	l.pHead = l.pTail = NULL;
}
Node_Register * Make_Node_Register(New_Register x)
{
	Node_Register* NewNode = new Node_Register;
	NewNode->data = x;
	NewNode->pNext = NULL;
	return NewNode;
}
void Add_Tail_List_Register(List_Register& l, New_Register x)
{
	Node_Register* NewNode = Make_Node_Register(x);
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
void Register(int choose,HeThong &HT)
{
	
	if (choose == 1)
	{
		ofstream write;
		while (true)
		{
			system("cls");
			cout << " ---------------------- REGISTER -----------------------" << endl;
			cout << "|1. Ho ten giang vien.                                  |" << endl;
			cout << "|2. ID giang vien.                                      |" << endl;
			cout << "|3. Dat mat khau va nhap lai mat khau.                  |" << endl;
			cout << " -----------------------   END   -----------------------" << endl;
			cout << "1. Ho ten giang vien: ";
			cin.ignore();
			string Name;
			getline(cin, Name);
			cout << "2. ID giang vien: ";
			string ID;
			cin >> ID;
			cout << "3. Tao mat khau: ";
			string pass;
			cin >> pass;
			string mk;
			do
			{
				cout << "4. Nhap lai mat khau vua tao: ";
				cin >> mk;
				if (mk.compare(pass) != 0)
				{
					cout << "Mat khau vua nhap khong trung khop voi mat khau tao lan dau tien. Vui long kiem tra va nhap lai!" << endl;
					system("pause");
				}
			} while (mk.compare(pass) != 0);
			write.open("REGIS_TEA.txt", ios_base::app);
			write << Name << "," << ID << "," << pass << endl;
			write.close();
			New_Register x;
			x.Name = Name;
			x.ID = ID;
			x.pass = pass;
			Add_Tail_List_Register(HT.REGIS_TEA, x);
			cout << "Ban da tao tai khoan thanh cong. Hay dang nhap lai vao he thong." << endl;
			system("pause");
			break;

		}
	}
	else if (choose == 2)
	{
		ofstream write;
		while (true)
		{
			system("cls");
			cout << " ---------------------- REGISTER -----------------------" << endl;
			cout << "|1. Ho ten sinh vien.                                   |" << endl;
			cout << "|2. Ma so sinh vien.                                    |" << endl;
			cout << "|3. Dat mat khau va nhap lai mat khau.                  |" << endl;
			cout << " -----------------------   END   -----------------------" << endl;
			cout << "1. Ho ten sinh vien: ";
			cin.ignore();
			string Name;
			getline(cin, Name);
			cout << "2. Ma so sinh vien: ";
			string ID;
			cin >> ID;
			cout << "3. Tao mat khau: ";
			string pass;
			cin >> pass;
			string mk;
			do
			{
				cout << "4. Nhap lai mat khau vua tao: ";
				cin >> mk;
				if (mk.compare(pass) != 0)
				{
					cout << "Mat khau vua nhap khong trung khop voi mat khau tao lan dau tien. Vui long kiem tra va nhap lai!" << endl;
					system("pause");
				}
			} while (mk.compare(pass) != 0);
			write.open("REGIS_STU.txt", ios_base::app);
			write << Name << "," << ID << "," << pass << endl;
			write.close();
			New_Register x;
			x.Name = Name;
			x.ID = ID;
			x.pass = pass;
			Add_Tail_List_Register(HT.REGIS_STU, x);
			cout << "Ban da tao tai khoan thanh cong. Hay dang nhap lai vao he thong." << endl;
			system("pause");
			break;
		}
	}
}
void System(HeThong &System,string &maso,int &choose)
{
	Initialize_Register(System.REGIS_STU);
	Initialize_Register(System.REGIS_TEA);
	ifstream rf;
	rf.open("REGIS_STU.txt", ios_base::in);
	string a;
	rf >> a;
	if (a != "") 
	{
		int n = int(a.length());
		rf.seekg(-n, 1);
		/*Read_File_Register(System.REGIS_STU, 2);*/
		while (rf.eof() == false)
		{
			New_Register a;
			getline(rf, a.Name, ',');
			getline(rf, a.ID, ',');
			rf >> a.pass;
			char t;
			rf >> t;
			if (rf.eof() == false)
			{
				rf.seekg(-1, 1);
			}
			Add_Tail_List_Register(System.REGIS_STU, a);
		}
	}
	rf.close();
	ifstream rff;
	rff.open("REGIS_TEA.txt", ios_base::in);
	string b;
	rff >> b;
	if (b != "")
	{
		int m = int(b.length());
		rff.seekg(-m, 1);
		while (rff.eof() == false)
		{

		
			/*Read_File_Register(System.REGIS_TEA, 1);*/
			New_Register a;
			getline(rff, a.Name, ',');
			getline(rff, a.ID, ',');
			rff >> a.pass;
			char t;
			rff >> t;
			if(rff.eof()==false)
			rff.seekg(-1, 1);
			Add_Tail_List_Register(System.REGIS_TEA, a);
		}
	}
	rff.close();
	while (true)
	{
		
		while (true)
		{
			system("cls");
			cout << " ------------------------------------------------------" << endl;
			cout << "|   TRUONG DAI HOC KHOA HOC TU NHIEN-DHQG HO CHI MINH  |" << endl;
			cout << "|------------------------------------------------------|" << endl;
			cout << "|                                           | 3. QUIT  |" << endl;
			cout << "|                                            ----------|" << endl;
			cout << "|                      --------                        |" << endl;
			cout << "|                     | SYSTEM |                       |" << endl;
			cout << "|                      --------                        |" << endl;
			cout << "|   ---------                              ---------   |" << endl;
			cout << "|  |1.TEACHER|                            |2.STUDENT|  |" << endl;
			cout << "|   ---------                              ---------   |" << endl;
			cout << "|                                                      |" << endl;
			cout << " ------------------------------------------------------" << endl;
			do
			{
				cout << "Nhap lua chon vai tro cua ban: ";
				cin >> choose;
				if (choose < 1 || choose >3)
				{
					cout << "Lua chon nhap vao khong hop le. Vui long kiem tra va nhap lai!" << endl;
					system("pause");
				}
			} while (choose < 1 || choose >3);
			break;
		}
		if (choose == 3)
		{
			break;
		}
		system("cls");
		cout << " ------------------------------------------------------" << endl;
		cout << "|   TRUONG DAI HOC KHOA HOC TU NHIEN-DHQG HO CHI MINH  |" << endl;
		cout << "|------------------------------------------------------|" << endl;
		cout << "|                      --------                        |" << endl;
		cout << "|                     | SYSTEM |                       |" << endl;
		cout << "|                      --------                        |" << endl;
		cout << "|   ----------                              -------    |" << endl;
		cout << "|  |1.REGISTER|                            |2.LOGIN|   |" << endl;
		cout << "|   ----------                              -------    |" << endl;
		cout << "|                                                      |" << endl;
		cout << " ------------------------------------------------------" << endl;
		int luachon;
		cout << "Nhap vao lua chon: ";
		cin >> luachon;
		if (luachon == 1)
		{
			Register(choose,System);
		}
		else if (luachon == 2)
		{
			if (choose == 1)
			{
				bool tam = false;
				cout << "Nhap ID cua giang vien: ";
				cin >> System.account;
				cout << "Nhap mat khau: ";
				cin >> System.pass;
				ifstream read;
				read.open("REGIS_TEA.txt", ios_base::in);
				while (read.eof() == false)
				{
					string Name;
					getline(read, Name, ',');
					string ID;
					getline(read, ID, ',');
					string pass;
					read >> pass;
					if (ID.compare(System.account) == 0 && pass.compare(System.pass) == 0)
					{

						tam = true;
						cout << "Ban da dang nhap thanh cong vao he thong!" << endl;
						system("pause");
						break;
					}
				}
				read.close();

				if (tam == false)
				{
					cout << "Tai khoan hoac mat khau da nhap sai. Vui long kiem tra va nhap lai!" << endl;
					system("pause");
				}
				else
				{
					break;
				}
			}
			else if (choose == 2)
			{
				bool tam = false;
				cout << "Nhap ID cua sinh vien: ";
				cin >> System.account;
				cout << "Nhap mat khau: ";
				cin >> System.pass;

				ifstream read;
				read.open("REGIS_STU.txt", ios_base::in);
				while (read.eof() == false)
				{
					string Name;
					getline(read, Name, ',');
					string ID;
					getline(read, ID, ',');
					string pass;
					read >> pass;
					if (ID.compare(System.account) == 0 && pass.compare(System.pass) == 0)
					{
						maso = System.account;
						tam = true;
						cout << "Ban da dang nhap thanh cong vao he thong!" << endl;
						system("pause");
						break;
					}
				}
				read.close();

				if (tam == false)
				{
					cout << "Tai khoan hoac mat khau da nhap sai. Vui long kiem tra va nhap lai!" << endl;
					system("pause");
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			cout << "Lua chon nhap vao khong hop le. Vui long kiem tra va nhap lai!" << endl;
		}
	}
}
void Update_Pass(HeThong s, int choose)
{
    if(choose==1)
	{
		ofstream write;
		write.open("REGIS_TEA.txt", ios_base::out);
		while (s.REGIS_TEA.pHead != NULL)
		{
			write << s.REGIS_TEA.pHead->data.Name << "," << s.REGIS_TEA.pHead->data.ID << "," << s.REGIS_TEA.pHead->data.pass << endl;
			s.REGIS_TEA.pHead = s.REGIS_TEA.pHead->pNext;
		}
		write.close();
	}
    else if(choose == 2)
	{
		ofstream write;
		write.open("REGIS_STU.txt", ios_base::out);
		while (s.REGIS_STU.pHead != NULL)
		{
			write << s.REGIS_STU.pHead->data.Name << "," << s.REGIS_STU.pHead->data.ID << "," << s.REGIS_STU.pHead->data.pass << endl;
			s.REGIS_STU.pHead = s.REGIS_STU.pHead->pNext;
		}
		write.close();
	}
}

