#include <stdio.h>               // Thư viện chuẩn để nhập/xuất
#include <stdbool.h>             // Thư viện để sử dụng kiểu dữ liệu boolean
#include <string.h>              // Thư viện để xử lý chuỗi
#include <ctype.h>               // Thư viện để xử lý ký tự
#include "../include/datatype.h" // Thư viện định nghĩa các kiểu dữ liệu
#include <conio.h>               // Thu vien nhap ki tu ma khong hien thi ra man hinh
#include "../include/function.h"

// Menu Dang nhap
void loginMenu()
{
    printf("\t======STUDENT LOGIN======\n"); // Đăng nhập sinh viên
    printf("\t=====CHOICE YOUR ROLE====\n"); // Chọn vai trò
    printf("\t=========================\n");
    printf("\t\t1. ADMIN\n"); // Admin
    printf("\t=========================\n");
}

// Hàm nhập không hiển thị mật khẩu
void importPassword(char *matKhau, int maxLen) // Nhập mật khẩu không hiển thị
{
    int i = 0;                   // Biến đếm
    char c;                      // Ký tự
    printf("\tNhap mat khau: "); // Nhập mật khẩu của tài khoản admin
    while (i < maxLen - 1)       // Vòng lặp cho đến khi đạt đến độ dài tối đa
    {
        c = getch(); // Đọc ký tự đang ghi
        if (c == 13) // Kiểm tra Enter
        {
            break; // Thoát
        }
        if (c == 8) // Kiểm tra Backspace
        {
            if (i > 0) // Nếu i > 0
            {
                i--;             // Giảm i
                printf("\b \b"); // Xóa ký tự
            }
        }
        else // Ngược lại
        {
            matKhau[i] = c; // Gán ký tự vào mật khẩu
            i++;            // Tăng i
            printf("*");    // Hiển thị "*"
        }
    }
    matKhau[i] = '\0'; // Kết chuỗi
    printf("\n");
}

// Login Admin
int loginAdmin()
{
    FILE *file = fopen("C:\\PROJECT\\data\\admin.bin", "rb"); // Mở file admin.bin
    // Thông tin tài khoản admin
    char username[9], password[6];           // Tên đăng nhập và mật khẩu của admin
    fread(&username, sizeof(char), 8, file); // Đọc tên đăng nhập
    fseek(file, 1, SEEK_CUR);                // Di chuyển con trỏ file
    fread(&password, sizeof(char), 6, file); // Đọc mật khẩu

    // Đăng nhập
    char tempUsername[20], tempPassword[8]; // Tên đăng nhập và mật khẩu tạm
    printf("\tTen dang nhap: ");
    scanf("%s", tempUsername);       // Đọc tên đăng nhập
    importPassword(tempPassword, 8); // Nhập mật khẩu

    if ((strcmp(username, tempUsername) == 0) && (strcmp(password, tempPassword) == 0)) // So sánh tên đăng nhập và mật khẩu
    {
        printf("\t\t  =/= Dang nhap thanh cong =/=\n");
        return 1; // Trả về 1
    }
    else // Ngược lại
    {
        printf("\t      [ERROR]Ten dang nhap va mat khau khong dung !!!\n"); // Thông báo tên đăng nhập hoặc mật khẩu không đúng
        return 0;                                                            // Trả về 0
    }
}

// Login Manage
int loginManege()
{
    int choice;      // Lựa chọn
    int activeAdmin; // Admin đang hoạt động
    while (1)        // Vòng lặp
    {
        loginMenu(); // Hiển thị menu đăng nhập
        printf("\tChon vai tro: ");
        scanf("%d", &choice); // Đọc lựa chọn
        fflush(stdin);        // Xóa bộ nhớ đệm
        switch (choice)       // Kiểm tra lựa chọn
        {
        case 1:                         // Nếu là 1
            activeAdmin = loginAdmin(); // Đăng nhập với tài khoản Admin
            if (activeAdmin)            // Nếu là Admin
            {
                return activeAdmin; // Trả về Admin
            }
            break; // Kết thúc
            // case 2:
            //     activeAdmin = 0;    // Không phải Admin
            //     return activeAdmin; // Trả về không phải Admin
        }
    }
}

// Hàm sắp xếp danh sách sinh viên theo thứ tự A-Z
void sortStudentListAZ()
{
    struct Student students[100]; // Khai báo danh sách sinh viên
    int countStudentAmount = 0;   // Khai báo biến đếm số lượng sinh viên

    FILE *file = fopen("C:\\PROJECT\\data\\student.bin", "rb");                   // Mở file để đọc dữ liệu
    if (file == NULL)                                                             // Nếu không mở được file (con trỏ file có giá trị NULL),
    {                                                                             // hàm sẽ in ra thông báo lỗi và kết thúc tại đây.
        printf("\t\t                    !!!!!ERROR!!!!!\n");                      // In ra thông báo lỗi
        printf("\t\t=!=!=!=!=!=!=!=!=> Khong mo duoc file <=!=!=!=!=!=!=!=!=\n"); // In ra thông báo lỗi
        return;
    }

    // Đọc dữ liệu từ file vào mảng students
    while (fread(&students[countStudentAmount], sizeof(struct Student), 1, file) == 1) // Đọc dữ liệu từ file vào mảng students
    {
        countStudentAmount++; // Tăng biến đếm số lượng sinh viên sau mỗi lần đọc thành công
    }
    fclose(file); // Đóng file sau khi đọc xong

    // Sắp xếp danh sách sinh viên theo thứ tự A-Z dựa trên tên sinh viên
    for (int i = 0; i < countStudentAmount - 1; i++) // Duyệt qua từng sinh viên trong mảng
    {
        for (int j = i + 1; j < countStudentAmount; j++) // So sánh tên của sinh viên i với sinh viên j
        {
            if (strcmp(students[i].studentName, students[j].studentName) > 0) // Nếu tên sinh viên i lớn hơn tên sinh viên j
            {
                struct Student temp = students[i]; // Hoán đổi vị trí của sinh viên i và sinh viên j
                students[i] = students[j];         // Gán sinh viên j vào vị trí của sinh viên i
                students[j] = temp;                // Gán sinh viên i vào vị trí của sinh viên j
            }
        }
    }

    // Hiển thị bảng danh sách sinh viên đã được sắp xếp
    printf("\t\t\t\t\t\t\t[-----------------------Danh sach sinh vien da sap xep-----------------------]\n\n");
    printf("\t+-----+-------------------------+-----+------+-----------+------------------------------+----------------------------------------+----------+------------------------------+-----------+\n");
    printf("\t| STT |          NAME           | AGE | SEX  | PHONE NUM |             EMAIL            |                ADDRESS                 | BIRTHDAY |              MAJOR           |   STATUS  |\n");
    printf("\t+-----+-------------------------+-----+------+-----------+------------------------------+----------------------------------------+----------+------------------------------+-----------+\n");

    // Duyệt qua từng sinh viên trong mảng và in ra thông tin
    for (int i = 0; i < countStudentAmount; i++) // Duyệt qua từng sinh viên trong mảng
    {
        printf("\t|%-5s|%-25s|%-5d|%-6s|%-11s|%-30s|%-40s|%-10s|%-30s|%-11s|\n", // In ra thông tin sinh viên
               students[i].studentID,                                            // In ID sinh viên
               students[i].studentName,                                          // In tên sinh viên
               students[i].studentAge,                                           // In tuổi sinh viên
               students[i].studentSex ? "Female" : "Male",                       // In giới tính sinh viên (Female nếu true, Male nếu false)
               students[i].studentPhoneNumber,                                   // In số điện thoại sinh viên
               students[i].studentEmail,                                         // In email sinh viên
               students[i].studentAddress,                                       // In địa chỉ sinh viên
               students[i].studentBirthDay,                                      // In ngày sinh của sinh viên
               students[i].studentMajor,                                         // In ngành học của sinh viên
               students[i].studentStatus ? "Active" : "Inactive");               // In trạng thái sinh viên (Active nếu true, Inactive nếu false)
    }

    // In ra dòng kết thúc bảng
    printf("\t+-----+-------------------------+-----+------+-----------+------------------------------+----------------------------------------+----------+------------------------------+-----------+\n");
    ;
    printf("\n\t\t\t\t\t\t\t\t[---------------------------End List---------------------------]\n");
    printf("\n");
}

// Hàm sắp xếp danh sách sinh viên theo thứ tự Z-A
void sortStudentListZA()
{
    struct Student students[100]; // Khai báo danh sách sinh viên
    int countStudentAmount = 0;   // Khai báo biến đếm số lượng sinh viên

    FILE *file = fopen("C:\\PROJECT\\data\\student.bin", "rb"); // Mở file để đọc dữ liệu
    if (file == NULL)                                           // Nếu không mở được file (con trỏ file có giá trị NULL),
    {
        printf("\t\t====-----> Khong mo duoc file <-----====\n"); // In ra thông báo lỗi
        return;
    }

    // Đọc dữ liệu từ file vào mảng students
    while (fread(&students[countStudentAmount], sizeof(struct Student), 1, file) == 1) // Đọc dữ liệu từ file vào mảng students
    {
        countStudentAmount++; // Tăng biến đếm số lượng sinh viên sau mỗi lần đọc thành công
    }
    fclose(file); // Đóng file sau khi đọc xong

    // Sắp xếp danh sách sinh viên theo thứ tự A-Z dựa trên tên sinh viên
    for (int i = 0; i < countStudentAmount - 1; i++) // Duyệt qua từng sinh viên trong mảng
    {
        for (int j = i + 1; j < countStudentAmount; j++) // So sánh tên của sinh viên i với sinh viên j
        {
            if (strcmp(students[i].studentName, students[j].studentName) < 0) // Nếu tên sinh viên i nhỏ hơn tên sinh viên j
            {
                struct Student temp = students[i]; // Hoán đổi vị trí của sinh viên i và sinh viên j
                students[i] = students[j];         // Gán sinh viên j vào vị trí của sinh viên i
                students[j] = temp;                // Gán sinh viên i vào vị trí của sinh viên j
            }
        }
    }

    // Hiển thị bảng danh sách sinh viên đã được sắp xếp
    printf("\t\t\t\t\t\t\t[-----------------------Danh sach sinh vien da sap xep-----------------------]\n\n");
    printf("\t+-----+-------------------------+-----+------+-----------+------------------------------+----------------------------------------+----------+------------------------------+-----------+\n");
    printf("\t| STT |          NAME           | AGE | SEX  | PHONE NUM |             EMAIL            |                ADDRESS                 | BIRTHDAY |              MAJOR           |   STATUS  |\n");
    printf("\t+-----+-------------------------+-----+------+-----------+------------------------------+----------------------------------------+----------+------------------------------+-----------+\n");

    // Duyệt qua từng sinh viên trong mảng và in ra thông tin
    for (int i = 0; i < countStudentAmount; i++)
    {
        printf("\t|%-5s|%-25s|%-5d|%-6s|%-11s|%-30s|%-40s|%-10s|%-30s|%-11s|\n", // In ra thông tin sinh viên
               students[i].studentID,                                            // In ID sinh viên
               students[i].studentName,                                          // In tên sinh viên
               students[i].studentAge,                                           // In tuổi sinh viên
               students[i].studentSex ? "Female" : "Male",                       // In giới tính sinh viên (Female nếu true, Male nếu false)
               students[i].studentPhoneNumber,                                   // In số điện thoại sinh viên
               students[i].studentEmail,                                         // In email sinh viên
               students[i].studentAddress,                                       // In địa chỉ sinh viên
               students[i].studentBirthDay,                                      // In ngày sinh của sinh viên
               students[i].studentMajor,                                         // In ngành học của sinh viên
               students[i].studentStatus ? "Active" : "Inactive");               // In trạng thái sinh viên (Active nếu true, Inactive nếu false)
    }

    // In ra dòng kết thúc bảng
    printf("\t+-----+-------------------------+-----+------+-----------+------------------------------+----------------------------------------+----------+------------------------------+-----------+\n");
    printf("\n\t\t\t\t\t\t\t\t[---------------------------End List---------------------------]\n");
    printf("\n");
}

// MENU SẮP XẾP THỨ TỰ SINH VIÊN ***************************************
void sortStudentListMenu() // Menu sắp xếp danh sách sinh viên
{
    int sortOption; // Khai báo biến lựa chọn
    do
    {
        printf("\t[-^-^-^-^-^-^-^-^-^-SAP XEP SINH VIEN-^-^-^-^-^-^-^-^-^-^-]\n");
        printf("\t[ 1 = Sap xep theo thu tu A-Z                             ]\n");
        printf("\t[ 2 = Sap xep theo thu tu Z-A                             ]\n");
        printf("\t[ 0 = Huy sap xep quay lai menu quan ly                   ]\n");
        printf("\t[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n");
        printf("\tNhap lua chon cua ban: ");
        scanf("%d", &sortOption); // Đọc lựa chọn từ bàn phím
        switch (sortOption)       // Kiểm tra lựa chọn
        {
        case 1:
            sortStudentListAZ(); // Hàm sắp xếp theo thứ tự A-Z
            break;
        case 2:
            sortStudentListZA(); // Hàm sắp xếp theo thứ tự Z-A
            break;
        case 0:
            printf("\n\t\t*~*~*~*~*~*~Huy sap xep~*~*~*~*~*~*\n\n"); // Thoát khỏi menu sắp xếp
            break;
        default:
            break;
        }
    } while (sortOption != 0); // Lặp lại cho đến khi người dùng chọn thoát (sortOption = 0)
}

// Kiểm tra cú pháp email hợp lệ
bool isValidEmail(char email[])
{
    char *at = strchr(email, '@');                       // Tìm ký tự '@' trong chuỗi email
    char *dot = strrchr(email, '.');                     // Tìm ký tự '.' cuối cùng trong chuỗi email
    return at && dot && at < dot && strlen(email) <= 50; // Kiểm tra email có chứa '@' và '.' và '@' đứng trước '.' và độ dài email không quá 50 ký tự
}

// Kiểm tra cú pháp số điện thoại (chỉ cho phép 10 số)
bool isValidPhoneNumber(char phoneNumber[])
{
    if (strlen(phoneNumber) != 10) // Kiểm tra độ dài của số điện thoại có bằng 10 không
        return false;
    for (int i = 0; i < 10; i++) // Duyệt qua từng ký tự trong số điện thoại
    {
        if (!isdigit(phoneNumber[i])) // Kiểm tra nếu ký tự không phải là số
            return false;
    }
    return true; // Trả về true nếu tất cả các ký tự đều là số và độ dài bằng 10
}

// Kiểm tra tên (không chứa số hoặc ký tự đặc biệt)
bool isValidName(char name[])
{
    for (size_t i = 0; i < strlen(name); i++) // Duyệt qua từng ký tự trong tên
    {
        if (!isalpha(name[i]) && name[i] != ' ') // Kiểm tra nếu ký tự không phải là chữ cái và không phải là khoảng trắng
            return false;
    }
    return true; // Trả về true nếu tất cả các ký tự đều là chữ cái hoặc khoảng trắng
}

// Hàm kiểm tra trùng lặp dữ liệu sinh viên
int isValidStudentInfo(char *idToCheck, char *emailToCheck, char *phoneNumberToCheck) // Kiểm tra trùng lặp thông tin sinh viên
{
    struct Student existingStudent; // Khai báo biến kiểu dữ liệu Student

    FILE *inputFile = fopen("C:\\PROJECT\\data\\student.bin", "rb"); // Mở file để đọc dữ liệu
    if (inputFile == NULL)
    {
        printf("\t====-----> Khong mo duoc file du lieu sinh vien <-----====\n"); // In ra thông báo lỗi
        return 0;
    }

    // Đọc từng dòng dữ liệu từ file
    while (fread(&existingStudent, sizeof(struct Student), 1, inputFile)) // Đọc từng dòng dữ liệu từ file
    {
        if (strcmp(existingStudent.studentID, idToCheck) == 0) // So sánh ID
        {
            printf("\t\t====-----> Ma sinh vien da ton tai <-----====\n"); // In ra thông báo lỗi
            fclose(inputFile);
            return 0; // ID đã tồn tại
        }

        if (strcmp(existingStudent.studentEmail, emailToCheck) == 0) // So sánh email
        {
            printf("\t\t====-----> Email sinh vien da ton tai <-----====\n"); // In ra thông báo lỗi
            fclose(inputFile);
            return 0; // Email đã tồn tại
        }
        if (strcmp(existingStudent.studentPhoneNumber, phoneNumberToCheck) == 0) // So sánh số điện thoại
        {
            printf("\t====-----> So dien thoai sinh vien da ton tai <-----====\n"); // In ra thông báo lỗi
            fclose(inputFile);
            return 0; // Số điện thoại đã tồn tại
        }
    }

    fclose(inputFile);
    return 1; // Không có trùng lặp thông tin
}

// Hàm hiển thị danh sách sinh viên
void showStudentList() // Hiển thị danh sách sinh viên
{
    struct Student studentInfo; // Khai báo biến kiểu dữ liệu Student
    FILE *outputFile;           // Khai báo con trỏ file

    outputFile = fopen("C:\\PROJECT\\data\\student.bin", "rb"); // Mở file để đọc dữ liệu
    if (outputFile == NULL)                                     // Nếu không mở được file
    {
        printf("\t\t====-----> File khong ton tai <-----====\n"); // In ra thông báo lỗi
        return;                                                   // Kết thúc hàm
    }

    // Kiểm tra kích thước file
    fseek(outputFile, 0, SEEK_END);    // Di chuyển con trỏ file đến cuối file
    long fileSize = ftell(outputFile); // Lấy kích thước file
    rewind(outputFile);                // Đưa con trỏ file về đầu file

    if (fileSize == 0) // Nếu file không có dữ liệu
    {
        printf("\t\t====-----> File khong co du lieu <-----====\n"); // In ra thông báo lỗi
        fclose(outputFile);                                          // Đóng file
        return;                                                      // Kết thúc hàm
    }

    printf("\t\t\t\t\t\t\t[---------------------Danh sach sinh vien---------------------]\n\n");
    printf("\t+-----+-------------------------+-----+------+-----------+------------------------------+----------------------------------------+----------+------------------------------+-----------+\n");
    printf("\t| STT |          NAME           | AGE | SEX  | PHONE NUM |             EMAIL            |                ADDRESS                 | BIRTHDAY |              MAJOR           |   STATUS  |\n");
    printf("\t+-----+-------------------------+-----+------+-----------+------------------------------+----------------------------------------+----------+------------------------------+-----------+\n");

    // Đọc từng dòng dữ liệu từ file
    while (fread(&studentInfo, sizeof(struct Student), 1, outputFile) == 1) // Đọc từng dòng dữ liệu từ file
    {
        // In ra bảng nếu dữ liệu hợp lệ
        if (strlen(studentInfo.studentID) > 0) // Kiểm tra ID hợp lệ
        {
            printf("\t|%-5s|%-25s|%-5d|%-6s|%-11s|%-30s|%-40s|%-10s|%-30s|%-11s|\n", // In ra thông tin sinh viên
                   studentInfo.studentID,                                            // In ID sinh viên
                   studentInfo.studentName,                                          // In tên sinh viên
                   studentInfo.studentAge,                                           // In tuổi sinh viên
                   studentInfo.studentSex ? "Female" : "Male",                       // In giới tí
                   studentInfo.studentPhoneNumber,                                   // In số điện thoại sinh viên
                   studentInfo.studentEmail,                                         // In email sinh viên
                   studentInfo.studentAddress,                                       // In địa chỉ sinh viên
                   studentInfo.studentBirthDay,                                      // In ngày sinh của sinh viên
                   studentInfo.studentMajor,                                         // In ngành học của sinh viên
                   studentInfo.studentStatus ? "Active" : "Inactive");               // In trạng thái sinh viên
        }
    }

    printf("\t+-----+-------------------------+-----+------+-----------+------------------------------+----------------------------------------+----------+------------------------------+-----------+\n");

    fclose(outputFile); // Đóng file
    printf("\t\t\t\t\t\t\t[---------------------------End List---------------------------]\n");
    printf("\n");
}

// Hàm thêm mới sinh viên
void addNewStudent() // Thêm mới sinh viên
{
    struct Student newStudent; // Khai báo biến kiểu dữ liệu Student
    FILE *inputFile;           // Khai báo con trỏ file

    inputFile = fopen("C:\\PROJECT\\data\\student.bin", "ab"); // Mở file để ghi dữ liệu
    if (inputFile == NULL)                                     // Nếu không mở được file
    {
        printf("\t\t                   !!!!! ERROR !!!!!\n");                     // In ra thông báo lỗi
        printf("\t\t====-----> Khong the mo file Student_Data.bin <-----====\n"); // In ra thông báo lỗi
        return;
    }

    printf("\tNhap vao ID cua sinh vien: "); // Nhập ID của sinh viên
    scanf("%6s", newStudent.studentID);      // Đọc ID từ bàn phím
    getchar();                               // Xóa ký tự xuống dòng còn lại sau scanf

    do
    {
        printf("\tNhap vao ten cua sinh vien: ");                             // Nhập tên của sinh viên
        fgets(newStudent.studentName, sizeof(newStudent.studentName), stdin); // Đọc tên từ bàn phím
        newStudent.studentName[strcspn(newStudent.studentName, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng cuối cùng
    } while (!isValidName(newStudent.studentName)); // Kiểm tra tên hợp lệ

    printf("\tNhap vao tuoi cua sinh vien: "); // Nhập tuổi của sinh viên
    scanf("%d", &newStudent.studentAge);       // Đọc tuổi từ bàn phím

    printf("\tNhap vao gioi tinh cua sinh vien (0: Nam, 1: Nu): "); // Nhập giới tính của sinh viên
    int tempSex;
    scanf("%d", (int *)&tempSex);    // Đọc giới tính từ bàn phím
    newStudent.studentSex = tempSex; // Gán giá trị cho studentSex
    getchar();                       // Xóa ký tự xuống dòng còn lại sau scanf

    do
    {
        printf("\tNhap vao so dien thoai cua sinh vien: "); // Nhập số điện thoại của sinh viên
        scanf("%11s", newStudent.studentPhoneNumber);       // Đọc số điện thoại từ bàn phím
        getchar();                                          // Xóa ký tự xuống dòng còn lại sau scanf
    } while (!isValidPhoneNumber(newStudent.studentPhoneNumber)); // Kiểm tra số điện thoại hợp lệ

    do
    {
        printf("\tNhap vao email cua sinh vien: "); // Nhập email của sinh viên
        scanf("%50s", newStudent.studentEmail);     // Đọc email từ bàn phím
        getchar();                                  // Xóa ký tự xuống dòng còn lại sau scanf
    } while (!isValidEmail(newStudent.studentEmail)); // Kiểm tra email hợp lệ

    printf("\tNhap vao dia chi cua sinh vien: ");                               // Nhập địa chỉ của sinh viên
    fgets(newStudent.studentAddress, sizeof(newStudent.studentAddress), stdin); // Đọc địa chỉ từ bàn phím
    newStudent.studentAddress[strcspn(newStudent.studentAddress, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng cuối cùng

    printf("\tNhap vao ngay sinh cua sinh vien (dd/mm/yyyy): "); // Nhập ngày sinh của sinh viên
    scanf("%10s", newStudent.studentBirthDay);                   // Đọc ngày sinh từ bàn phím
    getchar();                                                   // Xóa ký tự xuống dòng còn lại sau scanf

    printf("\tNhap vao nganh hoc cua sinh vien: ");                         // Nhập ngành học của sinh viên
    printf("\tNhap vao nganh hoc cua sinh vien: ");                         // Nhập ngành học của sinh viên
    fgets(newStudent.studentMajor, sizeof(newStudent.studentMajor), stdin); // Đọc ngành học từ bàn phím
    newStudent.studentMajor[strcspn(newStudent.studentMajor, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng cuối cùng

    printf("\tNhap vao trang thai cua sinh vien (0: Nghi hoc, 1: Dang hoc): "); // Nhập trạng thái của sinh viên
    scanf("%d", &newStudent.studentStatus);                                     // Đọc trạng thái từ bàn phím

    // Kiểm tra thông tin sinh viên hợp lệ
    if (isValidStudentInfo(newStudent.studentID, newStudent.studentEmail, newStudent.studentPhoneNumber)) // Kiểm tra trùng lập ID, Email, Số điện thoại
    {
        size_t writeCount = fwrite(&newStudent, sizeof(struct Student), 1, inputFile); // Ghi dữ liệu vào file
        if (writeCount == 1)                                                           // Nếu ghi dữ liệu thành công
        {
            printf("\n\t=====-----> Them sinh vien thanh cong <-----=====\n"); // In ra thông báo thành công
        }
        else // Ngược lại
        {
            printf("\t\t              !!!!! ERROR !!!!!\n");                // In ra thông báo lỗi
            printf("\n\t====-----> Lỗi ghi dữ liệu vào file <-----====\n"); // In ra thông báo lỗi
        }
    }
    else
    {
        printf("\t\t                      !!!!! ERROR !!!!!\n");                                // In ra thông báo lỗi
        printf("\n\t====-----> Them sinh vien that bai (du lieu khong hop le) <-----====\n\n"); // In ra thông báo lỗi
    }

    fclose(inputFile);
}

// Hàm chỉnh sửa thông tin sinh viên giữ nguyên ID
void editStudentInfo() // Chỉnh sửa thông tin sinh viên
{
    FILE *file = fopen("C:\\PROJECT\\data\\student.bin", "rb+"); // Mở file để đọc và ghi dữ liệu
    if (!file)                                                   // Nếu không mở được file
    {
        printf("\t\t           !!!!! ERROR !!!!!\n");
        printf("\t\t====-----> Khong the mo File <-----====\n");
        return;
    }

    char IDToSearch[7];                              // Khai báo mảng chứa ID sinh viên cần chỉnh sửa
    printf("Nhap vao ID sinh vien can chinh sua: "); // Nhập ID của sinh viên cần chỉnh sửa
    scanf("%6s", IDToSearch);                        // Đọc ID từ bàn phím

    struct Student studentInfo; // Khai báo biến kiểu dữ liệu Student
    int studentFound = 0;       // Khai báo biến kiểm tra sinh viên có tồn tại hay không

    while (fread(&studentInfo, sizeof(struct Student), 1, file)) // Đọc từng dòng dữ liệu từ file
    {
        if (strcmp(studentInfo.studentID, IDToSearch) == 0) // So sánh ID sinh viên
        {
            studentFound = 1;                                          // Đánh dấu sinh viên đã được tìm thấy
            printf("Tim thay sinh vien: %s\n", studentInfo.studentID); // In ra thông tin sinh viên

            // Cập nhật thông tin sinh viên
            do
            {
                printf("Nhap ten moi: ");                                               // Nhập tên mới
                getchar();                                                              // Xóa ký tự xuống dòng còn lại
                fgets(studentInfo.studentName, sizeof(studentInfo.studentName), stdin); // Đọc tên từ bàn phím
                studentInfo.studentName[strcspn(studentInfo.studentName, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng cuối cùng
            } while (!isValidName(studentInfo.studentName)); // Kiểm tra tên hợp lệ

            printf("Nhap tuoi moi: ");            // Nhập tuổi mới
            scanf("%d", &studentInfo.studentAge); // Đọc tuổi từ bàn phím

            printf("Nhap gioi tinh moi (0: Nam, 1: Nu): "); // Nhập giới tính mới
            int tempSex;
            scanf("%d", &tempSex);            // Đọc giới tính từ bàn phím
            studentInfo.studentSex = tempSex; // Gán giá trị cho studentSex

            do
            {
                printf("Nhap so dien thoai moi: ");            // Nhập số điện thoại mới
                scanf("%11s", studentInfo.studentPhoneNumber); // Đọc số điện thoại từ bàn phím
            } while (!isValidPhoneNumber(studentInfo.studentPhoneNumber)); // Kiểm tra số điện thoại hợp lệ

            do
            {
                printf("Nhap email moi: ");              // Nhập email mới
                scanf("%30s", studentInfo.studentEmail); // Đọc email từ bàn phím
            } while (!isValidEmail(studentInfo.studentEmail)); // Kiểm tra email hợp lệ

            printf("Nhap dia chi moi: ");                                                 // Nhập địa chỉ mới
            getchar();                                                                    // Xóa ký tự xuống dòng còn lại
            fgets(studentInfo.studentAddress, sizeof(studentInfo.studentAddress), stdin); // Đọc địa chỉ từ bàn phím
            studentInfo.studentAddress[strcspn(studentInfo.studentAddress, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng cuối cùng

            printf("Nhap ngay sinh moi (dd/mm/yyyy): "); // Nhập ngày sinh mới
            scanf("%10s", studentInfo.studentBirthDay);  // Đọc ngày sinh từ bàn phím

            printf("Nhap nganh hoc moi: "); // Nhập ngành học mới
            getchar();
            fgets(studentInfo.studentMajor, sizeof(studentInfo.studentMajor), stdin); // Đọc ngành học từ bàn phím
            studentInfo.studentMajor[strcspn(studentInfo.studentMajor, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng cuối cùng

            printf("Nhap trang thai moi (0: Nghi hoc, 1: Dang hoc): "); // Nhập trạng thái mới
            scanf("%d", &studentInfo.studentStatus);                    // Đọc trạng thái từ bàn phím

            // Ghi đè thông tin sinh viên
            fseek(file, -(long)sizeof(struct Student), SEEK_CUR);
            if (fwrite(&studentInfo, sizeof(struct Student), 1, file) == 1)
            {
                printf("\n\t====-----> Cap nhat thong tin hoan tat <-----====\n");
            }
            else
            {
                printf("\t\t               !!!!! ERROR !!!!!\n");
                printf("\n\t====-----> Loi ghi du lieu vao file <-----====\n");
            }
            break;
        }
    }

    if (!studentFound) // Nếu không tìm thấy sinh viên
    {
        printf("Khong tim thay sinh vien co ID %s.\n", IDToSearch);
    }

    fclose(file);
}

// Hàm xóa sinh viên
void deleteStudent()
{
    char IDToDelete[7];                        // Khai báo mảng chứa ID sinh viên cần xóa
    printf("Nhap vao ID sinh vien can xoa: "); // Nhập ID của sinh viên cần xóa
    scanf("%6s", IDToDelete);                  // Đọc ID từ bàn phím

    FILE *inputFile = fopen("C:\\PROJECT\\data\\student.bin", "rb"); // Mở file để đọc dữ liệu
    if (inputFile == NULL)                                           // Nếu không mở được file
    {
        printf("\t\t           !!!!! ERROR !!!!!\n");            // In ra thông báo lỗi
        printf("\t\t====-----> Khong the mo File <-----====\n"); // In ra thông báo lỗi
        return;
    }

    FILE *tempFile = fopen("C:\\PROJECT\\data\\Student_Data.bin", "wb"); // Mở file tạm để ghi dữ liệu
    if (tempFile == NULL)                                                // Nếu không mở được file
    {
        printf("\t\t                   !!!!! ERROR !!!!!\n");                   // In ra thông báo lỗi
        printf("\t\t====-----> Khong the tao File xoa thong tin <-----====\n"); // In ra thông báo lỗi
        fclose(inputFile);
        return;
    }

    struct Student studentInfo; // Khai báo biến kiểu dữ liệu Student
    int studentFound = 0;       // Khai báo biến kiểm tra sinh viên có tồn tại hay không

    while (fread(&studentInfo, sizeof(struct Student), 1, inputFile)) // Đọc từng dòng dữ liệu từ file
    {
        if (strcmp(studentInfo.studentID, IDToDelete) == 0) // So sánh ID sinh viên
        {
            studentFound = 1;                                           // Đánh dấu sinh viên đã được tìm thấy
            printf("Tim thay sinh vien: %s\n", studentInfo.studentID);  // In ra thông tin sinh viên
            char confirm;                                               // Khai báo biến xác nhận xóa sinh viên
            printf("Ban co chac chan muon xoa sinh vien nay? (y/n): "); // Xác nhận xóa sinh viên
            scanf(" %c", &confirm);                                     // Đọc ký tự xác nhận từ bàn phím
            if (confirm == 'y' || confirm == 'Y')                       // Nếu xác nhận xóa sinh viên
            {
                printf("\n\t====-----> Xoa sinh vien thanh cong <-----====\n");
                continue; // Bỏ qua ghi dòng này vào file tạm
            }
            else
            {
                printf("\n\t====-----> Huy lenh xoa sinh vien <-----====\n");
            }
        }
        // Ghi lại thông tin sinh viên không bị xóa vào file tạm
        fwrite(&studentInfo, sizeof(struct Student), 1, tempFile); // Ghi dữ liệu vào file tạm
    }

    fclose(inputFile); // Đóng file gốc
    fclose(tempFile);  // Đóng file tạm

    if (!studentFound) // Nếu không tìm thấy sinh viên
    {
        printf("Khong tim thay sinh vien co ID %s.\n", IDToDelete); // In ra thông báo lỗi
        remove("C:\\PROJECT\\data\\Student_Data.bin");              // Xóa file tạm
    }
    else
    {
        if (remove("C:\\PROJECT\\data\\student.bin") == 0 &&                                      // Xóa file gốc
            rename("C:\\PROJECT\\data\\Student_Data.bin", "C:\\PROJECT\\data\\student.bin") == 0) // Xóa file gốc và đổi tên file tạm
        {
            printf("\n\t====-----> Cap nhat file thanh cong sau khi xoa <-----====\n");
        }
        else
        {
            printf("\t\t                 !!!!! ERROR !!!!!\n");
            printf("\n\t====-----> Loi cap nhat file sau khi xoa <-----====\n");
        }
    }
}

// Hàm tìm kiếm sinh viên
void searchStudent() // Tìm kiếm sinh viên
{
    char nameToSearch[21];                            // Khai báo mảng chứa tên sinh viên cần tìm
    printf("\tNhap vao ten sinh vien can tim: ");     // Nhập tên sinh viên cần tìm
    getchar();                                        // Xóa ký tự xuống dòng còn lại
    fgets(nameToSearch, sizeof(nameToSearch), stdin); // Đọc tên từ bàn phím
    nameToSearch[strcspn(nameToSearch, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng cuối cùng

    FILE *inputFile = fopen("C:\\PROJECT\\data\\student.bin", "rb"); // Mở file để đọc dữ liệu
    if (inputFile == NULL)                                           // Nếu không mở được file
    {
        printf("\t\t           !!!!! ERROR !!!!!\n");            // In ra thông báo lỗi
        printf("\t\t====-----> Khong the mo File <-----====\n"); // In ra thông báo lỗi
        return;
    }

    struct Student studentInfo; // Khai báo biến kiểu dữ liệu Student
    int studentFound = 0;       // Khai báo biến kiểm tra sinh viên có tồn tại hay không

    printf("\t\t\t\t\t\t\t[---------------------Danh sach sinh vien tim thay---------------------]\n\n");
    printf("\t+-----+-------------------------+-----+------+-----------+------------------------------+----------------------------------------+----------+------------------------------+-----------+\n");
    printf("\t| STT |          NAME           | AGE | SEX  | PHONE NUM |             EMAIL            |                ADDRESS                 | BIRTHDAY |              MAJOR           |   STATUS  |\n");
    printf("\t+-----+-------------------------+-----+------+-----------+------------------------------+----------------------------------------+----------+------------------------------+-----------+\n");

    while (fread(&studentInfo, sizeof(struct Student), 1, inputFile)) // Đọc từng dòng dữ liệu từ file
    {
        if (strstr(studentInfo.studentName, nameToSearch) != NULL) // So sánh tên sinh viên
        {
            studentFound = 1;                                                        // Đánh dấu sinh viên đã được tìm thấy
            printf("\t|%-5s|%-25s|%-5d|%-6s|%-11s|%-30s|%-40s|%-10s|%-30s|%-11s|\n", // In ra thông tin sinh viên
                   studentInfo.studentID,                                            // In ID sinh viên
                   studentInfo.studentName,                                          // In tên sinh viên
                   studentInfo.studentAge,                                           // In tuổi sinh viên
                   studentInfo.studentSex ? "Female" : "Male",                       // In giới tí
                   studentInfo.studentPhoneNumber,                                   // In số điện thoại sinh viên
                   studentInfo.studentEmail,                                         // In email sinh viên
                   studentInfo.studentAddress,                                       // In địa chỉ sinh viên
                   studentInfo.studentBirthDay,                                      // In ngày sinh của sinh viên
                   studentInfo.studentMajor,                                         // In ngành học của sinh viên
                   studentInfo.studentStatus ? "Active" : "Inactive");               // In trạng thái sinh viên
        }
    }

    printf("\t+-----+-------------------------+-----+------+-----------+------------------------------+----------------------------------------+----------+------------------------------+-----------+\n");

    if (!studentFound)
    {
        printf("\n\t\t\t\t\t\t\t\t====-----> Khong tim thay sinh vien nao <-----====\n\n");
    }

    fclose(inputFile);

    printf("\t\t\t\t\t\t\t\t[~-~-~-~-~-~-~-~-~-~-~-~-~-~-End List~-~-~-~-~-~-~-~-~-~-~]\n");
    printf("\n");
}

// MENU 01: MENU QUẢN LÝ SINH VIÊN ***************************************
void studentManagementMenu()
{
    int choice; // Khai báo biến lựa chọn
    do          // Vòng lặp do-while
    {
        printf("\t[===================SINH VIEN====================]\n");
        printf("\t[ 1 = Xem lib sinh vien                          ]\n");
        printf("\t[ 2 = Them moi sinh vien                         ]\n");
        printf("\t[ 3 = Edit thong tin sinh vien                   ]\n");
        printf("\t[ 4 = Delete sinh vien                           ]\n");
        printf("\t[ 5 = Search sinh vien                           ]\n");
        printf("\t[ 6 = Sap xep lib sinh vien theo ten             ]\n");
        printf("\t[ 0 = Back                                       ]\n");
        printf("\t[================================================]\n");
        printf("\t                                                  \n");
        printf("\tChon chuc nang: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            showStudentList(); // Hiển thị danh sách sinh viên
            break;
        case 2:
            addNewStudent(); // Thêm mới sinh viên
            break;
        case 3:
            editStudentInfo(); // Chỉnh sửa thông tin sinh viên
            break;
        case 4:
            deleteStudent(); // Xóa sinh viên
            break;
        case 5:
            searchStudent(); // Tìm kiếm sinh viên
            break;
        case 6:
            sortStudentListMenu(); // Sắp xếp danh sách sinh viên
            break;
        case 0:
            printf("\n\t\t-----Quay lai Menu chinh-----\n"); // Quay lại menu chính
            break;                                           // Thoát khỏi menu quản lý sinh viên
        default:                                             // Xử lý lựa chọn không hợp lệ
            break;                                           // Thoát khỏi menu quản lý sinh viên
        } // Kết thúc switch
    } while (choice != 0);
}

// MENU ĐẦU VÀO **********************************************************
void mainMenu()
{
    int choice;
    do
    {
        // Hiển thị menu chính
        printf("\t[===================PTIT====================]\n");
        printf("\t[ 1 = Quan ly sinh vien                     ]\n");
        printf("\t[ 2 = Quan ly giao vien                     ]\n");
        printf("\t[ 3 = Quan ly lop hoc                       ]\n");
        printf("\t[ 0 = Exit                                  ]\n");
        printf("\t[===========================================]\n");
        printf("\t                                             \n");
        printf("\tChon vai tro: ");
        scanf("%d", &choice);

        switch (choice) // Xử lý lựa chọn của người dùng
        {
        case 1:
            studentManagementMenu(); // Gọi hàm menu quản lý sinh viên
            break;
        case 2:
            break;
        case 3:
            break;
        case 0:
            printf("\n\t\t\t=======KET THUC CHUONG TRINH=======\n");
            break;
        }
    } while (choice != 0); // Lặp lại cho đến khi người dùng chọn thoát (choice = 0)
}
