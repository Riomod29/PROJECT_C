#include <stdbool.h>
// Structs

// datatype cho sinh viên (Student)
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

// datatype cho lớp học (Class)
struct Class
{
    char classID[6];
    char className[20];
    char classMajors[30];
    struct Student studentList[40];
    int classSize;
    int classStatus;
};
