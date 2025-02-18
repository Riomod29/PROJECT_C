#ifndef FUNCTION_H // Kiểm tra xem macro FUNCTION_H đã được định nghĩa chưa
#define FUNCTION_H

// Khai báo hàm
#include <stdbool.h>
void adminLogin();            // Hàm đăng nhập với tài khoản Admin
void mainMenu();              // Hàm hiển thị menu chính
void studentManagementMenu(); // Hàm hiển thị menu quản lý sinh viên
void sortStudentListMenu();   // Hàm menu lựa chọn thứ tự sắp xếp danh sách sinh viên
void sortStudentListAZ();     // Hàm sắp xếp danh sách sinh viên theo thứ tự A-Z
void sortStudentListZA();     // Hàm sắp xếp danh sách sinh viên theo thứ tự Z-A

bool isValidEmail(char email[]);                                                       // Kiểm tra cú pháp email hợp lệ
bool isValidPhoneNumber(char phoneNumber[]);                                           // Kiểm tra cú pháp số điện thoại (chỉ cho phép 10 số)
bool isValidName(char name[]);                                                         // Kiểm tra tên (không chứa số hoặc ký tự đặc biệt)
int isValidStudentInfo(char *idToCheck, char *emailToCheck, char *phoneNumberToCheck); // Hàm kiểm tra trùng lặp dữ liệu sinh viên
void addNewStudent();                                                                  // Hàm thêm mới sinh viên
void showStudentList();                                                                // Hàm hiển thị danh sách sinh viên
void editStudentInfo();                                                                // Hàm chỉnh sửa thông tin sinh viên giữ nguyên ID
void deleteStudent();                                                                  // Hàm xóa sinh viên
void searchStudent();
// Hàm tìm kiếm sinh viên

#endif