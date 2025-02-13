// Khai báo hàm
#include <stdbool.h>

// Hàm hiển thị menu chính
void mainMenu();
// Hàm hiển thị menu quản lý sinh viên
void studentManagementMenu();
// Hàm menu lựa chọn thứ tự sắp xếp danh sách sinh viên
void sortStudentListMenu();
// Hàm sắp xếp danh sách sinh viên theo thứ tự A-Z
void sortStudentListAZ();
// Hàm sắp xếp danh sách sinh viên theo thứ tự Z-A
void sortStudentListZA();
// Kiểm tra cú pháp email hợp lệ
bool isValidEmail(char email[]);
// Kiểm tra cú pháp số điện thoại (chỉ cho phép 10 số)
bool isValidPhoneNumber(char phoneNumber[]);
// Kiểm tra tên (không chứa số hoặc ký tự đặc biệt)
bool isValidName(char name[]);
// Hàm kiểm tra trùng lặp dữ liệu sinh viên
int isValidStudentInfo(char *emailToCheck, char *phoneNumberToCheck);
// Hàm thêm mới sinh viên
void addNewStudent();
// Hàm hiển thị danh sách sinh viên
void showStudentList();
// Hàm chỉnh sửa thông tin sinh viên giữ nguyên ID
void editStudentInfo();
// Hàm xóa sinh viên
void deleteStudent();
// Hàm tìm kiếm sinh viên
void searchStudent();
// Hàm hiển thị danh sách sinh viên