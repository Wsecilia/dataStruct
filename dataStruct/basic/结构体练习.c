#include <stdio.h>

typedef struct birthday{
    int year;
    int month;
    int day;
    char *week;
} birthday;

typedef struct Student
{
    int sId;
    char *name;
    int age;
    float score;
    birthday birthday;
}Student;

void printStuInfo(Student *stu,int len){
    for (size_t i = 0; i < len; i++)
    {
        printf("学号：%d\n姓名：%s\n年龄：%d\n成绩：%.2f\n出生年月：%d-%d-%d\n星期：%s\n",
               stu[i].sId, stu[i].name, stu[i].age, stu[i].score, stu[i].birthday.year, stu[i].birthday.month, stu[i].birthday.day,
               stu[i].birthday.week);
    }
    
}

int main(){
    Student stu[] = {
        {1001, "zhanghong", 15, 77.5, {2001, 5, 9, "星期五"}},
        {1002, "zhaolinger", 30, 97.5, {2000, 11, 9, "星期四"}},
        {1003, "lixiaoyao", 22, 99, {2009, 10, 7, "星期三"}},
        {1004, "zhouzhiruo", 46, 85.3, {1999, 1, 19, "星期一"}}
    };
    printStuInfo(stu, sizeof(stu) / sizeof(stu[0]));
    return 0;
}