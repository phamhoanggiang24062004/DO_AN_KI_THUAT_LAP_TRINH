#include "LopHoc.h"


bool isEmpty_Class(List_Class l)
{
	return (l.pHead == NULL);
}
void Initialize_Class(List_Class& l)
{
	l.pHead = NULL;
}
Node_Class* Make_Node_Class(New_Class x)
{
	Node_Class* NewNode = new Node_Class;
	NewNode->info = x;
	NewNode->pNext = NULL;
	return NewNode;
}
void Add_Tail_Class(List_Class& l, New_Class x)
{
	Node_Class* NewNode = Make_Node_Class(x);
	if (l.pHead == NULL)
	{
		l.pHead = NewNode;
		
	}
	else
	{
		Node_Class* temp = l.pHead;
		while (temp->pNext != NULL)
		{
			temp = temp->pNext;
		}
		temp->pNext = NewNode;
	}
}
void Number_Student_1Class(New_Class &CLASS)
{
	CLASS.Number_Student = 0;
	Node_Student* temp = CLASS.LIST_STUDENT.pHead;
	while (temp != NULL)
	{
		CLASS.Number_Student++;
		temp = temp->pNext;
	}
}
void Print_1Class(New_Class x)
{
	Node_Student* temp = x.LIST_STUDENT.pHead;
	cout << left << setw(20) << x.Class_Name << left << setw(17) << x.type << left << setw(25) << x.Number_Student << endl;
}
void Print_List_Class(List_Class l)
{
	cout << left << setw(20) << "Ten lop hoc" << left << setw(17) <<"He dao tao"<< left << setw(25) << "So luong sinh vien" << endl;
	for (Node_Class* i = l.pHead;i != NULL;i = i->pNext)
	{
		Print_1Class(i->info);
	}
}
void Print_ListStudent_1Class(List_Class l,string Name)
{
	Node_Class* i = new Node_Class;
	for ( i = l.pHead;i != NULL;i = i->pNext)
	{
		if (_stricmp(i->info.Class_Name.c_str(), Name.c_str()) == 0)
		{
			
			cout << setw(63) << "DANH SACH SINH VIEN" << endl;
			Print_List_Student(i->info.LIST_STUDENT);
			break;
		}
	}
	if (i == NULL)
	{
		cout << "Khong tim thay lop can tim." << endl;
	}
}
void Free_Node_Class(List_Class& l)
{
	Node_Class* temp = l.pHead;
	while (temp != NULL)
	{
		Free_Node_Student(temp->info.LIST_STUDENT);
		temp = temp->pNext;
	}
}