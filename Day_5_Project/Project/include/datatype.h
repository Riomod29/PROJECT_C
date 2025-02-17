#ifndef DATATYPE_H // Kiểm tra xem macro FUNCTION_H đã được định nghĩa chưa
#define DATATYPE_H // Định nghĩa macro FUNCTION_H nếu chưa được định nghĩa

#include <stdbool.h> // Thư viện để sử dụng kiểu dữ liệu boolean
// Structs

// datatype cho sinh viên (Student)
struct Student
{                                // Định nghĩa kiểu dữ liệu Student
    char studentID[6];           // Mã sinh viên (6 ký tự + 1 ký tự kết thúc chuỗi)
    char studentName[26];        // Tên sinh viên (20 ký tự + 1 ký tự kết thúc chuỗi)
    char studentMajor[31];       // Ngành học (29 ký tự + 1 ký tự kết thúc chuỗi)
    int studentAge;              // Tuổi
    bool studentSex;             // Giới tính (0: Nam, 1: Nữ)
    char studentPhoneNumber[12]; // Số điện thoại (11 ký tự + 1 ký tự kết thúc chuỗi)
    char studentEmail[51];       // Email (60 ký tự + 1 ký tự kết thúc chuỗi)
    char studentBirthDay[11];    // Ngày sinh (10 ký tự + 1 ký tự kết thúc chuỗi)
    char studentAddress[41];     // Địa chỉ (40 ký tự + 1 ký tự kết thúc chuỗi)
    int studentStatus;           // Trạng thái (0: Nghỉ học, 1: Đang học)
};

// datatype cho lớp học (Class)
// struct Class // Định nghĩa kiểu dữ liệu Class
// {
//     char classID[6];                // Mã lớp (5 ký tự + 1 ký tự kết thúc chuỗi)
//     char className[20];             // Tên lớp (19 ký tự + 1 ký tự kết thúc chuỗi)
//     char classMajors[30];           // Ngành học (29 ký tự + 1 ký tự kết thúc chuỗi)
//     struct Student studentList[40]; // Danh sách sinh viên trong lớp (tối đa 40 sinh viên)
//     int classSize;                  // Số lượng sinh viên trong lớp
//     int classStatus;                // Trạng thái (0: Đã tốt nghiệp, 1: Đang học)
// };
#endif