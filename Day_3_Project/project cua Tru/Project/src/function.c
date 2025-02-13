#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "../include/datatype.h"

typedef struct Class Class;

// Function prototypes
void studentManagementMenu(void);
void sortStudentListMenu();
void sortStudentListAZ();
void sortStudentListZA();
bool isValidEmail(char email[]);
bool isValidPhoneNumber(char phoneNumber[]);
bool isValidName(char name[]);
int isValidStudentInfo(char *emailToCheck, char *phoneNumberToCheck);
void showStudentList();
void addNewStudent();
void editStudentInfo();
void deleteStudent(void);
void searchStudent();

// Hàm menu chính (Main Menu)
void studentManagementMenu(void);

void mainMenu()
{
    int choice;
    do
    {
        printf("\t[===================PTIT====================]\n");
        printf("\t[ 1 = Quan ly sinh vien                     ]\n");
        printf("\t[ 2 = Quan ly giao vien                     ]\n");
        printf("\t[ 3 = Quan ly lop hoc                       ]\n");
        printf("\t[ 0 = Thoat                                 ]\n");
        printf("\t[===========================================]\n");
        printf("\t                                             \n");
        printf("\tNhap Choice cua ban: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            studentManagementMenu();
            break;
        case 2:
            // showStudentManagementMenu();
            break;
        case 3:
            // showStatisticMenu();
            break;
        case 0:
            printf("\n\t\t\t=======KET THUC CHUONG TRINH=======\n");
        }
    } while (choice != 0);
}

// Hàm menu quản lý sinh viên (Management Student Menu)
void studentManagementMenu()
{
    int choice;
    do
    {
        printf("\t[===================SINH VIEN====================]\n");
        printf("\t[ 1 = Xem lib sinh vien                          ]\n");
        printf("\t[ 2 = Them moi sinh vien                         ]\n");
        printf("\t[ 3 = Edit thong tin sinh vien                   ]\n");
        printf("\t[ 4 = Delete sinh vien                           ]\n");
        printf("\t[ 5 = Search sinh vien                           ]\n");
        printf("\t[ 6 = Sap xep danh sach sinh vien theo ten       ]\n");
        printf("\t[ 0 = Quay lai                                   ]\n");
        printf("\t[================================================]\n");
        printf("\tNhap Choice cua ban: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            showStudentList(); // Hàm hiển thị danh sách sinh viên
            break;
        case 2:
            addNewStudent(); // Hàm thêm mới sinh viên
            break;
        case 3:
            editStudentInfo(); // Hàm chỉnh sửa thông tin sinh viên
            break;
        case 4:
            deleteStudent(); // hàm xóa sinh viên
            break;
        case 5:
            searchStudent(); // Hàm tìm kiếm sinh viên
            break;
        case 6:
            sortStudentListMenu(); // Hàm menu thao tác sắp xếp danh sách sinh viên
            break;
        case 0:
            printf("\n\t\t-----Quay lai Menu chinh-----\n");
            break;
        default:
            break;
        }
    } while (choice != 0);
}

// Hàm menu lựa chọn thứ tự sắp xếp danh sách sinh viên
void sortStudentListMenu()
{
    int sortOption;
    do
    {
        printf("\t[-^-^-^-^-^-^-^-^-^-SAP XEP SINH VIEN-^-^-^-^-^-^-^-^-^-^-]\n");
        printf("\t[ 1 = Sap xep theo thu tu A-Z                             ]\n");
        printf("\t[ 2 = Sap xep theo thu tu Z-A                             ]\n");
        printf("\t[ 0 = Huy sap xep quay lai menu quan ly                   ]\n");
        printf("\t[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n");
        printf("\tNhap lua chon cua ban: ");
        scanf("%d", &sortOption);
        switch (sortOption)
        {
        case 1:
            sortStudentListAZ(); // Hàm sắp xếp theo thứ tự A-Z
            break;
        case 2:
            sortStudentListZA(); // Hàm sắp xếp theo thứ tự Z-A
            break;
        case 0:
            printf("\n\t\t*~*~*~*~*~*~Huy sap xep~*~*~*~*~*~*\n\n");
            break;
        default:
            break;
        }
    } while (sortOption != 0);
}

// Hàm sắp xếp danh sách sinh viên theo thứ tự A-Z
void sortStudentListAZ()
{
    struct Student students[100]; // Khai báo danh sách sinh viên
    int countStudentAmount = 0;

    FILE *file = fopen("C:\\CODE\\TTTTTT\\project cua Tru\\Project\\data\\student.bin", "rb");
    if (file == NULL) // Nếu không mở được file (con trỏ file có giá trị NULL),
    {                 // hàm sẽ in ra thông báo lỗi và kết thúc tại đây.
        printf("\t\t                    !!!!!ERROR!!!!!\n");
        printf("\t\t=!=!=!=!=!=!=!=!=> Khong mo duoc file <=!=!=!=!=!=!=!=!=\n");
        return;
    }

    // Đọc dữ liệu từ file vào mảng students
    while (fread(&students[countStudentAmount], sizeof(struct Student), 1, file) == 1)
    {
        countStudentAmount++;
    }
    fclose(file);

    // Sắp xếp A-Z theo tên sinh viên
    for (int i = 0; i < countStudentAmount - 1; i++)
    {
        for (int j = i + 1; j < countStudentAmount; j++)
        {
            if (strcmp(students[i].studentName, students[j].studentName) > 0)
            {
                struct Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    // Hiển thị bảng đã được sắp xếp
    printf("\t\t\t\t\t\t\t[-----------------------Danh sach sinh vien da sap xep-----------------------]\n\n");
    printf("\t+------+--------------------+------+------+-----------+--------------------------------------------------+----------------------------------------+----------+------------------------------+------+\n");
    printf("\t|  ID  |        NAME        | AGE  | SEX  | PHONE NUM |                       EMAIL                      |                ADDRESS                 | BIRTHDAY |              MAJOR           |STATUS|\n");
    printf("\t+------+--------------------+------+------+-----------+--------------------------------------------------+----------------------------------------+----------+------------------------------+------+\n");

    for (int i = 0; i < countStudentAmount; i++)
    {
        printf("\t|%-6s|%-20s|%-6d|%-6s|%-11s|%-50s|%-40s|%-10s|%-30s|%-6s|\n",
               students[i].studentID,
               students[i].studentName,
               students[i].studentAge,
               students[i].studentSex ? "Female" : "Male",
               students[i].studentPhoneNumber,
               students[i].studentEmail,
               students[i].studentAddress,
               students[i].studentBirthDay,
               students[i].studentMajor,
               students[i].studentStatus ? "Active" : "Inactive");
    }

    printf("\t+------+--------------------+------+------+-----------+--------------------------------------------------+----------------------------------------+----------+------------------------------+------+\n");
    printf("\n\t\t\t\t\t\t\t\t[---------------------------End List---------------------------]\n");
    printf("\n");
}

// Hàm sắp xếp danh sách sinh viên theo thứ tự Z-A
void sortStudentListZA()
{
    struct Student students[100]; // Khai báo danh sách sinh viên
    int countStudentAmount = 0;

    FILE *file = fopen("C:\\CODE\\TTTTTT\\project cua Tru\\Project\\data\\student.bin", "rb");
    if (file == NULL)
    {
        printf("\t\t====-----> Khong mo duoc file <-----====\n");
        return;
    }

    // Đọc dữ liệu từ file vào mảng students
    while (fread(&students[countStudentAmount], sizeof(struct Student), 1, file) == 1)
    {
        countStudentAmount++;
    }
    fclose(file);

    // Sắp xếp A-Z theo tên sinh viên
    for (int i = 0; i < countStudentAmount - 1; i++)
    {
        for (int j = i + 1; j < countStudentAmount; j++)
        {
            if (strcmp(students[i].studentName, students[j].studentName) < 0)
            {
                struct Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    // Hiển thị bảng đã được sắp xếp
    printf("\t\t\t\t\t\t\t[-----------------------Danh sach sinh vien da sap xep-----------------------]\n\n");
    printf("\t+------+--------------------+------+------+-----------+--------------------------------------------------+----------------------------------------+----------+------------------------------+------+\n");
    printf("\t|  ID  |        NAME        | AGE  | SEX  | PHONE NUM |                      EMAIL                       |                ADDRESS                 | BIRTHDAY |              MAJOR           |STATUS|\n");
    printf("\t+------+--------------------+------+------+-----------+--------------------------------------------------+----------------------------------------+----------+------------------------------+------+\n");

    for (int i = 0; i < countStudentAmount; i++)
    {
        printf("\t|%-6s|%-20s|%-6d|%-6s|%-11s|%-50s|%-40s|%-10s|%-30s|%-6s|\n",
               students[i].studentID,
               students[i].studentName,
               students[i].studentAge,
               students[i].studentSex ? "Female" : "Male",
               students[i].studentPhoneNumber,
               students[i].studentEmail,
               students[i].studentAddress,
               students[i].studentBirthDay,
               students[i].studentMajor,
               students[i].studentStatus ? "Active" : "Inactive");
    }

    printf("\t+------+--------------------+------+------+-----------+--------------------------------------------------+----------------------------------------+----------+------------------------------+------+\n");
    printf("\n\t\t\t\t\t\t\t\t[---------------------------End List---------------------------]\n");
    printf("\n");
}

// Kiểm tra cú pháp email hợp lệ
bool isValidEmail(char email[])
{
    char *at = strchr(email, '@');
    char *dot = strrchr(email, '.');
    return at && dot && at < dot && strlen(email) <= 50;
}

// Kiểm tra cú pháp số điện thoại (chỉ cho phép 10 số)
bool isValidPhoneNumber(char phoneNumber[])
{
    if (strlen(phoneNumber) != 10)
        return false;
    for (int i = 0; i < 10; i++)
    {
        if (!isdigit(phoneNumber[i]))
            return false;
    }
    return true;
}

// Kiểm tra tên (không chứa số hoặc ký tự đặc biệt)
bool isValidName(char name[])
{
    for (int i = 0; i < strlen(name); i++)
    {
        if (!isalpha(name[i]) && name[i] != ' ')
            return false;
    }
    return true;
}

// Hàm kiểm tra trùng lặp dữ liệu sinh viên
int isValidStudentInfo(char *emailToCheck, char *phoneNumberToCheck)
{
    struct Student existingStudent;

    FILE *inputFile = fopen("C:\\CODE\\TTTTTT\\project cua Tru\\Project\\data\\student.bin", "rb");
    if (inputFile == NULL)
    {
        printf("\t====-----> Khong mo duoc file du lieu sinh vien <-----====\n");
        return 0;
    }

    while (fread(&existingStudent, sizeof(struct Student), 1, inputFile))
    {
        if (strcmp(existingStudent.studentEmail, emailToCheck) == 0)
        {
            printf("\t\t====-----> Email sinh vien da ton tai <-----====\n");
            fclose(inputFile);
            return 0; // Email đã tồn tại
        }
        if (strcmp(existingStudent.studentPhoneNumber, phoneNumberToCheck) == 0)
        {
            printf("\t====-----> So dien thoai sinh vien da ton tai <-----====\n");
            fclose(inputFile);
            return 0; // Số điện thoại đã tồn tại
        }
    }

    fclose(inputFile);
    return 1; // Không có trùng lặp thông tin
}

// Hàm hiển thị danh sách sinh viên
void showStudentList()
{
    struct Student studentInfo;
    FILE *outputFile;

    outputFile = fopen("C:\\CODE\\TTTTTT\\project cua Tru\\Project\\data\\student.bin", "rb");
    if (outputFile == NULL)
    {
        printf("\t\t====-----> File khong ton tai <-----====\n");
        return;
    }

    // Kiểm tra kích thước file
    fseek(outputFile, 0, SEEK_END);
    long fileSize = ftell(outputFile);
    rewind(outputFile);

    if (fileSize == 0)
    {
        printf("\t\t====-----> File khong co du lieu <-----====\n");
        fclose(outputFile);
        return;
    }

    printf("\t\t\t\t\t\t\t[---------------------Danh sach sinh vien---------------------]\n\n");
    printf("\t+------+--------------------+------+------+-----------+--------------------------------------------------+----------------------------------------+----------+------------------------------+------+\n");
    printf("\t|  ID  |        NAME        | AGE  | SEX  | PHONE NUM |                        EMAIL                     |                ADDRESS                 | BIRTHDAY |              MAJOR           |STATUS|\n");
    printf("\t+------+--------------------+------+------+-----------+--------------------------------------------------+----------------------------------------+----------+------------------------------+------+\n");

    // Đọc từng dòng dữ liệu từ file
    while (fread(&studentInfo, sizeof(struct Student), 1, outputFile) == 1)
    {
        // In ra bảng nếu dữ liệu hợp lệ
        if (strlen(studentInfo.studentID) > 0) // Kiểm tra ID hợp lệ
        {
            printf("\t|%-6s|%-20s|%-6d|%-6s|%-11s|%-50s|%-40s|%-10s|%-30s|%-6s|\n",
                   studentInfo.studentID,
                   studentInfo.studentName,
                   studentInfo.studentAge,
                   studentInfo.studentSex ? "Female" : "Male",
                   studentInfo.studentPhoneNumber,
                   studentInfo.studentEmail,
                   studentInfo.studentAddress,
                   studentInfo.studentBirthDay,
                   studentInfo.studentMajor,
                   studentInfo.studentStatus ? "Active" : "Inactive");
        }
    }

    printf("\t+------+--------------------+------+------+-----------+--------------------------------------------------+----------------------------------------+----------+------------------------------+------+\n");

    fclose(outputFile);
    printf("\t\t\t\t\t\t\t[---------------------------End List---------------------------]\n");
    printf("\n");
}

// Hàm thêm mới sinh viên
void addNewStudent()
{
    struct Student newstudentInfo;
    FILE *inputFile;

    inputFile = fopen("C:\\CODE\\TTTTTT\\project cua Tru\\Project\\data\\student.bin", "ab");
    if (inputFile == NULL)
    {
        printf("\t\t                   !!!!! ERROR !!!!!\n");
        printf("\t\t====-----> Khong the mo file Student_Data.bin <-----====\n");
        return;
    }

    printf("Nhap vao ID cua sinh vien: ");
    scanf("%6s", newstudentInfo.studentID);
    getchar(); // Xóa ký tự xuống dòng còn lại sau scanf

    do
    {
        printf("Nhap vao ten cua sinh vien: ");
        fgets(newstudentInfo.studentName, sizeof(newstudentInfo.studentName), stdin);
        newstudentInfo.studentName[strcspn(newstudentInfo.studentName, "\n")] = '\0';
    } while (!isValidName(newstudentInfo.studentName));

    printf("Nhap vao tuoi cua sinh vien: ");
    scanf("%d", &newstudentInfo.studentAge);

    printf("Nhap vao gioi tinh cua sinh vien (0: Nam, 1: Nu): ");
    scanf("%d", &newstudentInfo.studentSex);
    getchar();

    do
    {
        printf("Nhap vao so dien thoai cua sinh vien: ");
        scanf("%11s", newstudentInfo.studentPhoneNumber);
        getchar();
    } while (!isValidPhoneNumber(newstudentInfo.studentPhoneNumber));

    do
    {
        printf("Nhap vao email cua sinh vien: ");
        scanf("%50s", newstudentInfo.studentEmail);
        getchar();
    } while (!isValidEmail(newstudentInfo.studentEmail));

    printf("Nhap vao dia chi cua sinh vien: ");
    fgets(newstudentInfo.studentAddress, sizeof(newstudentInfo.studentAddress), stdin);
    newstudentInfo.studentAddress[strcspn(newstudentInfo.studentAddress, "\n")] = '\0';

    printf("Nhap vao ngay sinh cua sinh vien (dd/mm/yyyy): ");
    scanf("%10s", newstudentInfo.studentBirthDay);
    getchar();

    printf("Nhap vao nganh hoc cua sinh vien: ");
    fgets(newstudentInfo.studentMajor, sizeof(newstudentInfo.studentMajor), stdin);
    newstudentInfo.studentMajor[strcspn(newstudentInfo.studentMajor, "\n")] = '\0';

    printf("Nhap vao trang thai cua sinh vien (0: Nghi hoc, 1: Dang hoc): ");
    scanf("%d", &newstudentInfo.studentStatus);

    if (isValidStudentInfo(newstudentInfo.studentEmail, newstudentInfo.studentPhoneNumber))
    {
        size_t writeCount = fwrite(&newstudentInfo, sizeof(struct Student), 1, inputFile);
        if (writeCount == 1)
        {
            printf("\n\t=====-----> Them sinh vien thanh cong <-----=====\n");
        }
        else
        {
            printf("\t\t              !!!!! ERROR !!!!!\n");
            printf("\n\t====-----> Lỗi ghi dữ liệu vào file <-----====\n");
        }
    }
    else
    {
        printf("\t\t                      !!!!! ERROR !!!!!\n");
        printf("\n\t====-----> Them sinh vien that bai (du lieu khong hop le) <-----====\n\n");
    }

    fclose(inputFile);
}

// Hàm chỉnh sửa thông tin sinh viên giữ nguyên ID
void editStudentInfo()
{
    FILE *file = fopen("C:\\CODE\\TTTTTT\\project cua Tru\\Project\\data\\student.bin", "rb+");
    if (!file)
    {
        printf("\t\t           !!!!! ERROR !!!!!\n");
        printf("\t\t====-----> Khong the mo File <-----====\n");
        return;
    }

    char IDToSearch[7];
    printf("Nhap vao ID sinh vien can chinh sua: ");
    scanf("%6s", IDToSearch);

    struct Student studentInfo;
    int studentFound = 0;

    while (fread(&studentInfo, sizeof(struct Student), 1, file))
    {
        if (strcmp(studentInfo.studentID, IDToSearch) == 0)
        {
            studentFound = 1;
            printf("Tim thay sinh vien: %s\n", studentInfo.studentID);

            // Cập nhật thông tin sinh viên
            do
            {
                printf("Nhap ten moi: ");
                getchar(); // Xóa ký tự xuống dòng còn lại
                fgets(studentInfo.studentName, sizeof(studentInfo.studentName), stdin);
                studentInfo.studentName[strcspn(studentInfo.studentName, "\n")] = '\0';
            } while (!isValidName(studentInfo.studentName));

            printf("Nhap tuoi moi: ");
            scanf("%d", &studentInfo.studentAge);

            printf("Nhap gioi tinh moi (0: Nam, 1: Nu): ");
            scanf("%d", &studentInfo.studentSex);

            do
            {
                printf("Nhap so dien thoai moi: ");
                scanf("%11s", studentInfo.studentPhoneNumber);
            } while (!isValidPhoneNumber(studentInfo.studentPhoneNumber));

            do
            {
                printf("Nhap email moi: ");
                scanf("%50s", studentInfo.studentEmail);
            } while (!isValidEmail(studentInfo.studentEmail));

            printf("Nhap dia chi moi: ");
            getchar();
            fgets(studentInfo.studentAddress, sizeof(studentInfo.studentAddress), stdin);
            studentInfo.studentAddress[strcspn(studentInfo.studentAddress, "\n")] = '\0';

            printf("Nhap ngay sinh moi (dd/mm/yyyy): ");
            scanf("%10s", studentInfo.studentBirthDay);

            printf("Nhap nganh hoc moi: ");
            getchar();
            fgets(studentInfo.studentMajor, sizeof(studentInfo.studentMajor), stdin);
            studentInfo.studentMajor[strcspn(studentInfo.studentMajor, "\n")] = '\0';

            printf("Nhap trang thai moi (0: Nghi hoc, 1: Dang hoc): ");
            scanf("%d", &studentInfo.studentStatus);

            if (!isValidStudentInfo(studentInfo.studentEmail, studentInfo.studentPhoneNumber))
            {
                printf("\t\t                            !!!!! ERROR !!!!!\n");
                printf("\n\t====-----> Chinh sua sinh vien that bai do thong tin khong hop le <-----====\n");
            }
            else
            {
                // Ghi đè thông tin sinh viên
                fseek(file, -sizeof(struct Student), SEEK_CUR);
                if (fwrite(&studentInfo, sizeof(struct Student), 1, file) == 1)
                {
                    printf("\n\t====-----> Cap nhat thong tin hoan tat <-----====\n");
                }
                else
                {
                    printf("\t\t               !!!!! ERROR !!!!!\n");
                    printf("\n\t====-----> Loi ghi du lieu vao file <-----====\n");
                }
            }
            break;
        }
    }

    if (!studentFound)
    {
        printf("Khong tim thay sinh vien co ID %s.\n", IDToSearch);
    }

    fclose(file);
}

// Hàm xóa sinh viên
void deleteStudent()
{
    char IDToDelete[7];
    printf("Nhap vao ID sinh vien can xoa: ");
    scanf("%6s", IDToDelete);

    FILE *inputFile = fopen("C:\\CODE\\TTTTTT\\project cua Tru\\Project\\data\\student.bin", "rb");
    if (inputFile == NULL)
    {
        printf("\t\t           !!!!! ERROR !!!!!\n");
        printf("\t\t====-----> Khong the mo File <-----====\n");
        return;
    }

    FILE *tempFile = fopen("C:\\CODE\\TTTTTT\\project cua Tru\\Project\\data\\Student_Data.bin", "wb");
    if (tempFile == NULL)
    {
        printf("\t\t                   !!!!! ERROR !!!!!\n");
        printf("\t\t====-----> Khong the tao File xoa thong tin <-----====\n");
        fclose(inputFile);
        return;
    }

    struct Student studentInfo;
    int studentFound = 0;

    while (fread(&studentInfo, sizeof(struct Student), 1, inputFile))
    {
        if (strcmp(studentInfo.studentID, IDToDelete) == 0)
        {
            studentFound = 1;
            printf("Tim thay sinh vien: %s\n", studentInfo.studentID);
            char confirm;
            printf("Ban co chac chan muon xoa sinh vien nay? (y/n): ");
            scanf(" %c", &confirm);
            if (confirm == 'y' || confirm == 'Y')
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
        fwrite(&studentInfo, sizeof(struct Student), 1, tempFile);
    }

    fclose(inputFile);
    fclose(tempFile);

    if (!studentFound)
    {
        printf("Khong tim thay sinh vien co ID %s.\n", IDToDelete);
        remove("C:\\CODE\\TTTTTT\\project cua Tru\\Project\\data\\Student_Data.bin");
    }
    else
    {
        if (remove("C:\\CODE\\TTTTTT\\project cua Tru\\Project\\data\\student.bin") == 0 &&
            rename("C:\\CODE\\TTTTTT\\project cua Tru\\Project\\data\\Student_Data.bin", "C:\\CODE\\TTTTTT\\project cua Tru\\Project\\data\\student.bin") == 0)
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
void searchStudent()
{
    char nameToSearch[21];
    printf("Nhap vao ten sinh vien can tim: ");
    getchar(); // Xóa ký tự xuống dòng còn lại
    fgets(nameToSearch, sizeof(nameToSearch), stdin);
    nameToSearch[strcspn(nameToSearch, "\n")] = '\0';

    FILE *inputFile = fopen("C:\\CODE\\TTTTTT\\project cua Tru\\Project\\data\\student.bin", "rb");
    if (inputFile == NULL)
    {
        printf("\t\t           !!!!! ERROR !!!!!\n");
        printf("\t\t====-----> Khong the mo File <-----====\n");
        return;
    }

    struct Student studentInfo;
    int studentFound = 0;

    printf("\t\t\t\t\t\t\t[---------------------Danh sach sinh vien tim thay---------------------]\n\n");
    printf("\t+------+--------------------+------+------+-----------+--------------------------------------------------+----------------------------------------+----------+------------------------------+------+\n");
    printf("\t|  ID  |        NAME        | AGE  | SEX  | PHONE NUM |                        EMAIL                     |                ADDRESS                 | BIRTHDAY |              MAJOR           |STATUS|\n");
    printf("\t+------+--------------------+------+------+-----------+--------------------------------------------------+----------------------------------------+----------+------------------------------+------+\n");

    while (fread(&studentInfo, sizeof(struct Student), 1, inputFile))
    {
        if (strstr(studentInfo.studentName, nameToSearch) != NULL)
        {
            studentFound = 1;
            printf("\t|%-6s|%-20s|%-6d|%-6s|%-11s|%-50s|%-40s|%-10s|%-30s|%-6s|\n",
                   studentInfo.studentID,
                   studentInfo.studentName,
                   studentInfo.studentAge,
                   studentInfo.studentSex ? "Female" : "Male",
                   studentInfo.studentPhoneNumber,
                   studentInfo.studentEmail,
                   studentInfo.studentAddress,
                   studentInfo.studentBirthDay,
                   studentInfo.studentMajor,
                   studentInfo.studentStatus ? "Active" : "Inactive");
        }
    }

    printf("\t+------+--------------------+------+------+-----------+--------------------------------------------------+----------------------------------------+----------+------------------------------+------+\n");

    if (!studentFound)
    {
        printf("\n\t\t\t\t\t\t\t\t====-----> Khong tim thay sinh vien nao <-----====\n\n");
    }

    fclose(inputFile);
    printf("\t\t\t\t\t\t\t[~-~-~-~-~-~-~-~-~-~-~-~-~-~-End List~-~-~-~-~-~-~-~-~-~-~]\n");
    printf("\n");
}
