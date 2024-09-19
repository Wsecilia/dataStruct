#include <stdio.h>

typedef struct Birthday
{
	int year;
	int month;
	int day;
} Birthday;


typedef struct Student
{
	int id;
	char *name;
	int age;
	float score;
	Birthday bir;
}student;

void printStuInfo(student *stu,int len){
	for (size_t i = 0; i < len; i++)
	{
		printf("学号：%d\t姓名：%s\t年龄：%d\t成绩：%.2f\t出生年月：%d-%d-%d\n",
			   (stu + i)->id, (stu + i)->name, (stu + i)->age, (stu + i)->score, (stu + i)->bir.year, (stu + i)->bir.month, (stu + i)->bir.day);
	};
}

int main(){
	student stu[] = {
		{1001, "hong", 34, 89.5, {2000,11,23}},
		{1002, "gang", 24, 94.5, {2001,1,11}},
		{1003, "mei", 25, 94.5, {1999,1,16}}};
	printStuInfo(stu, sizeof(stu)/sizeof(stu[0]));
	return 0;
}
