#ifndef FUNCTION_H
#define FUNCTION_H

#include "datatype.h"

// Khai báo các hàm
void studentManagementMenu(void);
void sortStudentListMenu(void);
void sortStudentListAZ(void);
void sortStudentListZA(void);
bool isValidEmail(char email[]);
bool isValidPhoneNumber(char phoneNumber[]);
bool isValidName(char name[]);
int isValidStudentInfo(char *emailToCheck, char *phoneNumberToCheck);
void showStudentList(void);
void addNewStudent(void);
void editStudentInfo(void);
void deleteStudent(void);
void searchStudent(void);
void saveAdminInfo(const char *filename, struct Admin admin);
int loadAdminInfo(const char *filename, struct Admin *admin);
void adminLogin(void);
void mainMenu(void);

#endif // FUNCTION_H