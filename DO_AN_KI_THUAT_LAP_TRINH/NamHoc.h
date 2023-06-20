#pragma once
#include "KhoaHoc.h"
struct Date_Learn
{
	int Day;
	int Month;
	int Year;
};
struct New_Semester
{
	int Semester_Name;
	Date_Learn Start;
	Date_Learn End;
	List_Course LIST_COURSE;
	/*List_Class LIST_CLASS;*/

};
struct SchoolYear
{
	string year;
	New_Semester* Sem ;
};
struct Node_SchoolYear
{
	SchoolYear info;
	Node_SchoolYear* pNext;

};
struct List_SchoolYear
{
	Node_SchoolYear* pHead, * pTail;
};
void init_schoolyear(SchoolYear& x);
void init_ListSy(List_SchoolYear& l);
Node_SchoolYear* Make_Node_Sy(SchoolYear x);
void Add_Tail_Sy(List_SchoolYear& l, SchoolYear x);
void Create_Semester(SchoolYear &NH, int &temp);
void Input_SchoolYear(List_SchoolYear & l,SchoolYear &NH,List_Class &CL,int &hocky);
void Free_Node_SchoolYear(List_SchoolYear &l);
