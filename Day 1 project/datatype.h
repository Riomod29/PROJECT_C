//Import nhung thu vien, khai bao cac struct

#include <stdbool.h>
// Structs

// datatype cho sinh vien (Student)
struct Student
{
    char studentID[7];
    char studentName[21];
    char studentMajor[30];
    int studentAge;
    bool studentSex;
    char studentPhoneNumber[12];
    char studentEmail[21];
    char studentBirthDay[11];
    char studentAddress[41];
    int studentStatus;
};

// datatype cho lop hoc (Class)
struct Class
{
    char classID[6];
    char className[20];
    char classMajors[30];
    struct Student studentList[40];
    int classSize;
    int classStatus;
};


//#include <stdbool.h>
//
//struct Date{
//	int month, day, year;
//};
//
//struct Student
//{
//	char studentId[10];
//	char classroomId[10];
//	char name[20];
//	struct Date dateOfBirth;
//	bool gender;
//	char email[30];
//	char phone[20];
//	char password[20];
//};
//
//struct Classroom
//{
//	char classroomId[10];
//	char teacherId[10];
//	char classroomName[10];
//	struct Student students[];
//};
//
//struct Teacher
//{
//	char teacherId[10];
//	char classroomIs[10];
//	char Name[20];
//	struct Date dateOfBirth;
//	bool  gender;
//	char Email[30];
//	char Phone[20];
//	char password[20];
//	struct Classroom classrooms[];	
//};



//struct Category{
//	char categoryID[50];
//	char categoryName[50];
//};
//struct Product{
//	//Dien cac thuoc tinh
//};
