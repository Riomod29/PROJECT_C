#ifndef DATATYPE_H
#define DATATYPE_H

#include <stdbool.h>
// Structs

// Định nghĩa cấu trúc Admin
struct Admin
{
    char username[20];
    char password[20];
};

// Định nghĩa cấu trúc Student
struct Student
{
    char studentID[6];
    char studentName[21];
    int studentAge;
    int studentSex; // 0: Male, 1: Female
    char studentPhoneNumber[12];
    char studentEmail[51];
    char studentAddress[41];
    char studentBirthDay[11];
    char studentMajor[31];
    int studentStatus; // 0: Inactive, 1: Active
};

// Định nghĩa cấu trúc Class
typedef struct Class
{
    // Các thuộc tính của Class
} Class;

#endif // DATATYPE_H
