#pragma once
#include "KhoaHoc.h"
#include <iomanip>
struct MarkBoard
{
	Course COURSE;	
};
struct Node_MarkBoard
{
	MarkBoard info;
	Node_MarkBoard* pNext;
};
struct List_MarkBoard
{
	Node_MarkBoard* pHead;
	Node_MarkBoard* pTail;
};
void Initialize_MarkBoard(List_MarkBoard &MB);
Node_MarkBoard * Make_Node_MB(MarkBoard MB);
void Add_Tail_MB(List_MarkBoard &l, MarkBoard MB);
void Print_1MarkBoard(MarkBoard MB);
void Read_File_Scoreboard(List_Course l, string id_course, List_MarkBoard& lb);
void Print_MarkBoard_1Course(List_MarkBoard l, string id_course);
void Print_MarkBoard_1Class(List_MarkBoard lb, List_Class lc, string name);
void Print_MarkBoard_1Student(List_MarkBoard lb, string ID);
void Update_Student_Result(List_MarkBoard &lb, string ID_Stu, string ID_Course);

