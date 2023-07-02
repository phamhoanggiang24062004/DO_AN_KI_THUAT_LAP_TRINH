#include "HeThong.h"
#include "NamHoc.h"
#include "BangDiem.h"
void Menu(HeThong x,List_SchoolYear &l, List_Class CL,int &hocky,List_MarkBoard lb )
{
	SchoolYear NH;
	while (true)
	{
		int choose;
		string ID;
		system("cls");
		System(x, ID, choose);
		if (choose == 1)
		{
			while (true)
			{
				system("cls");
				cout << " --------------------------------------------------------------" << endl;
				cout << "| 1.  Tao nam hoc moi.                                         |" << endl;
				cout << " --------------------------------------------------------------" << endl;
				cout << "| 2.  Xem danh sach cac lop hoc.                               |" << endl;
				cout << " --------------------------------------------------------------" << endl;
				cout << "| 3.  Xem danh sach sinh vien cua mot lop hoc.                 |" << endl;
				cout << " --------------------------------------------------------------" << endl;
				cout << "| 4.  Xem danh sach cac khoa hoc.                              |" << endl;
				cout << " --------------------------------------------------------------" << endl;
				cout << "| 5.  Xem danh sach sinh vien cua mot khoa hoc.                |" << endl;
				cout << " --------------------------------------------------------------" << endl;
				cout << "| 6.  Cap nhat thong tin cua khoa hoc.                         |" << endl;
				cout << " --------------------------------------------------------------" << endl;
				cout << "| 7.  Them mot sinh vien vao khoa hoc.                         |" << endl;
				cout << " --------------------------------------------------------------" << endl;
				cout << "| 8.  Xoa mot sinh vien khoi khoa hoc.                         |" << endl;
				cout << " --------------------------------------------------------------" << endl;
				cout << "| 9.  Xoa mot khoa hoc.                                        |" << endl;
				cout << " --------------------------------------------------------------" << endl;
				cout << "| 10. Xuat danh sach sinh vien cua mot khoa hoc ra file csv.   |" << endl;
				cout << " --------------------------------------------------------------" << endl;
				cout << "| 11. Cap nhat bang diem sinh vien tu file csv.                |" << endl;
				cout << " --------------------------------------------------------------" << endl;
				cout << "| 12. Xem bang diem cua mot khoa hoc.                          |" << endl;
				cout << " --------------------------------------------------------------" << endl;
				cout << "| 13. Cap nhat ket qua cua mot sinh vien.                      |" << endl;
				cout << " --------------------------------------------------------------" << endl;
				cout << "| 14. Xem bang diem cua lop.                                   |" << endl;
				cout << " --------------------------------------------------------------" << endl;
				cout << "| 15. Doi mat khau.                                            |" << endl;
				cout << " --------------------------------------------------------------" << endl;
				cout << "| 16. Thoat.                                                   |" << endl;
				cout << " --------------------------------------------------------------" << endl;
				int luachon;
				cout << "Nhap vao lua chon: ";
				cin >> luachon;
				if (luachon == 1)
				{
					Input_SchoolYear(l, NH, CL,hocky);
					Add_Tail_Sy(l, NH);
				}
				else if (luachon == 2)
				{
					if (isEmpty_Class(CL))
					{
						cout << "Khong ton tai lop hoc nao trong danh sach lop hoc!" << endl;
					}
					else
					{
						Print_List_Class(CL);
					}
					system("pause");
				}
				else if (luachon == 3)
				{
					if (isEmpty_Class(CL))
					{
						cout << "Khong ton tai lop hoc nao trong danh sach lop hoc!" << endl;
					}
					else
					{
						string name;
						cout << "Nhap ten lop can xuat danh sach sinh vien: ";
						cin >> name;
						Print_ListStudent_1Class(CL, name);
					}
					system("pause");
				}
				else if (luachon == 4)
				{
					if (isEmpty_Course(NH.Sem[hocky].LIST_COURSE))
					{
						cout << "Khong ton tai khoa hoc nao trong danh sach khoa hoc." << endl;
					}
					else
					{
						Print_List_Course(NH.Sem[hocky].LIST_COURSE);
					}
					system("pause");
				}
				else if (luachon == 5)
				{
					string ID;
					cout << "Nhap ID khoa hoc can xuat danh sach sinh vien: ";
					cin >> ID;
					Print_ListStudent_1Course(NH.Sem[hocky].LIST_COURSE,ID);
					system("pause");
				}
				else if (luachon == 6)
				{
					string id_cousre;
					cout << "Nhap ID cua khoa hoc can cap nhat thong tin: ";
					cin >> id_cousre;
					Update_Course_Information(NH.Sem[hocky].LIST_COURSE, id_cousre);
					system("pause");
				}
				else if (luachon == 7)
				{

					string id_course;
					cout << "Nhap ID cua khoa hoc can them sinh vien: ";
					cin >> id_course;
					int temp = Add_New_Student(NH.Sem[hocky].LIST_COURSE, id_course);
					if (temp == 1)
					{
						cout << "Da them sinh vien vao khoa hoc!" << endl;
					}
					else if (temp == 2)
					{
						cout << "So luong sinh vien cua khoa hoc da day!" << endl;
					}
					else if (temp == 0)
					{
						cout << "Khong tim thay khoa hoc co ID vua nhap!" << endl;
					}
					system("pause");
				}
				else if (luachon == 8)
				{
					string id_course;
					cout << "Nhap ID cua khoa hoc can xoa sinh vien: ";
					cin >> id_course;
					int temp = Remove_Student(NH.Sem[hocky].LIST_COURSE, id_course);
					if (temp == 1)
					{
						cout << "Da xoa sinh vien khoi khoa hoc!" << endl;
					}
					else if (temp == 2)
					{
						cout << "Khong tim thay sinh vien co ten can xoa trong danh sach vien!" << endl;
					}
					else if (temp == 0)
					{
						cout << "Khong tim thay khoa hoc co ID vua nhap!" << endl;
					}
					system("pause");
				}
				else if (luachon == 9)
				{
					string name;
					cout << "Nhap ID cua khoa hoc can xoa: ";
					cin >> name;
					if (Delete_Course(NH.Sem[hocky].LIST_COURSE, name))
					{
						cout << "Da xoa khoa hoc khoi danh sach khoa hoc!" << endl;
					}
					else
					{
						cout << "Khong tim thay khoa hoc nao co ID vua nhap!" << endl;
					}
					system("pause");
				}
				else if (luachon == 10)
				{
					string ID_Course;
					cout << "Nhap ID cua khoa hoc can xuat danh sach sinh vien ra file csv: ";
					cin >> ID_Course;
					Output_File_1Course(NH.Sem[hocky].LIST_COURSE, ID_Course);
					system("pause");
				}
				else if (luachon == 11)
				{
					string id_course;
					cout << "Nhap ID khoa hoc can cap nhat thong tin diem cua sinh vien: ";
					cin >> id_course;
					Read_File_Scoreboard(NH.Sem[hocky].LIST_COURSE,id_course,lb);
					system("pause");
				}
				else if (luachon == 12)
				{
					string id_course;
					cout << "Nhap ID khoa hoc can xuat thong tin bang diem sinh vien: ";
					cin >> id_course;
					Print_MarkBoard_1Course(lb,id_course);
					system("pause");
				}
				else if (luachon == 13)
				{
					string id_stu;
					string id_course;
					cout << "Nhap ID cua khoa hoc can cap nhat ket qua cua sinh vien: ";
					cin >> id_course;
					cout << "Nhap ID cua sinh vien can cap nhat ket qua: ";
					cin >> id_stu;
					Update_Student_Result(lb, id_stu, id_course);
					system("pause");
				}
				else if (luachon == 14)
				{
					string name;
					cout << "Nhap ten cua lop can xuat thong tin bang diem: ";
					cin >> name;
					Print_MarkBoard_1Class(lb, CL, name);
					system("pause");
				}
				else if (luachon == 15)
				{
					bool check = true; // bien check xem mat khau moi co trung voi mat khau cua cac sinh vien khac khong
					string ID_TEA;
					cout << "Nhap ID giang vien: ";
					cin >> ID_TEA;
					string old;
					cout << "Nhap mat khau cu: ";
					cin >> old;
					Node_Register* temp = x.REGIS_TEA.pHead;
					while (temp != NULL)
					{
						if (temp->data.ID.compare(ID_TEA) == 0 && temp->data.pass.compare(old) == 0)
						{
							cout << "Nhap mat khau moi: ";
							string new_pass;
							cin >> new_pass;
							Node_Register* tam = x.REGIS_TEA.pHead;
							while (tam != NULL)
							{
								if (tam->data.pass.compare(new_pass) == 0)
								{
									check = false;
									break;
								}
								tam = tam->pNext;
							}
							if (check == false)
							{
								cout << "Mat khau nay da duoc su dung. Vui long kiem tra va nhap lai!" << endl;
								system("pause");
								break;
							}
							else
							{
								temp->data.pass = new_pass;
								Update_Pass(x, choose);
								cout << "Ban da doi mat khau thanh cong!" << endl;
								system("pause");
								break;
							}
						}
						temp = temp->pNext;
					}
					if (temp == NULL)
					{
						cout << "ID giang vien hoac mat khau nhap vao khong khop. Vui long kiem tra va nhap lai!" << endl;
						system("pause");
					}
				}
				else if (luachon == 16)
				{
					break;
				}
				else
				{
					cout << "Lua chon nhap vao khong hop le.Vui long kiem tra va nhap lai!" << endl;
					system("pause");
                }
			}
		}
		else if (choose == 2)
		{
			while (true)
			{
				system("cls");
				cout << " ------------------------------------" << endl;
				cout << "| 1. Xem thong tin sinh vien.        |" << endl;
				cout << " ------------------------------------" << endl;
				cout << "| 2. Xem danh sach cac khoa hoc.     |" << endl;
				cout << " ------------------------------------" << endl;
				cout << "| 3. Xem bang diem.                  |" << endl;
				cout << " ------------------------------------" << endl;
				cout << "| 4. Doi mat khau.                   |" << endl;
				cout << " ------------------------------------" << endl;
				cout << "| 5. Thoat.                          |" << endl;
				cout << " ------------------------------------" << endl;
				int luachon;
				cout << "Nhap vao lua chon: ";
				cin >> luachon;
				if (luachon == 1)
				{
					bool check = false;
					Node_Class* temp = CL.pHead;
					while (temp != NULL)
					{

						Node_Student* x = temp->info.LIST_STUDENT.pHead;
						while (x != NULL)
						{
							if (x->info.StudentID.compare(ID) == 0)
							{
								check = true;
								cout << "Ho ten sinh vien: " << x->info.FirstName << " " << x->info.LastName << endl;
								cout << "Ma so sinh vien: " << x->info.StudentID << endl;
								cout << "Ngay thang nam sinh: " << x->info.DateOfBirth.Day << "/" << x->info.DateOfBirth.Month << "/" << x->info.DateOfBirth.Year << endl;
								cout << "Gioi tinh: " << x->info.Gender << endl;
								cout << "Can cuoc cong dan: " << x->info.SocialID << endl;
								system("pause");
								break;
							}
							x = x->pNext;
						}
						if (check == true)
						{
							break;
						}
						temp = temp->pNext;
					}
					if (check == false)
					{
						cout << "Khong tim thay sinh vien co ma so " << ID << endl;
						system("pause");
					}
				}
				else if (luachon == 2)
				{
					Print_ListCourse_1Student(NH.Sem[hocky].LIST_COURSE, ID);
					system("pause");
				}
				else if (luachon == 3)
				{
					Print_MarkBoard_1Student(lb, ID);
					system("pause");
				}
				else if (luachon == 4)
				{
					bool check = true;
					string id_stu;
					cout << "Nhap ID cua sinh vien: ";
					cin >> id_stu;
					string old_pass;
					cout << "Nhap mat khau cu: ";
					cin >> old_pass;
					Node_Register* temp = x.REGIS_STU.pHead;
					while (temp != NULL)
					{
						if (temp->data.ID.compare(id_stu) == 0 && temp->data.pass.compare(old_pass) == 0)
						{
							cout << "Nhap mat khau moi: ";
							string new_pass;
							cin >> new_pass;
							Node_Register* tam = x.REGIS_STU.pHead;
							while (tam!=NULL)
							{
								if (tam->data.pass.compare(new_pass) == 0)
								{
									check = false;
									break;
								}
								tam = tam->pNext;
							}
							if (check == false)
							{
								cout << "Mat khau nay da duoc su dung. Vui long kiem tra va nhap lai!" << endl;
								system("pause");
								break;
							}
							else
							{
								temp->data.pass = new_pass;
								Update_Pass(x, choose);
								cout << "Ban da doi mat khau thanh cong!" << endl;
								system("pause");
								break;
							}
						}
						temp = temp->pNext;
					}
					if (temp == NULL)
					{
						cout << "ID sinh vien hoac mat khau nhap vao khong khop. Vui long kiem tra va nhap lai!" << endl;
						system("pause");
					}
				}
				else if (luachon == 5)
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
		else if (choose == 3)
		{
			break;
		}

	}
}
int main()
{
	int hocky;
	List_MarkBoard lb;
	Initialize_MarkBoard(lb);
	List_SchoolYear NH;
	init_ListSy(NH);
	List_Class l;
	Initialize_Class(l);
	HeThong x;
	Menu(x,NH,l,hocky,lb);
	Free_Node_SchoolYear(NH);
	Free_Node_Class(l);
	return 0;
}