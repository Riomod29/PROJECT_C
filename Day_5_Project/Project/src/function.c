#include <stdio.h>               // Thư viện chuẩn để nhập/xuất
#include <stdbool.h>             // Thư viện để sử dụng kiểu dữ liệu boolean
#include <string.h>              // Thư viện để xử lý chuỗi
#include <ctype.h>               // Thư viện để xử lý ký tự
#include "../include/datatype.h" // Thư viện định nghĩa các kiểu dữ liệu

// ADMIN LOGIN ********************************************************
void adminLogin()
{
    char username[20]; // Khai báo mảng chứa tên đăng nhập
    char password[20]; // Khai báo mảng chứa mật khẩu

    while (1) // Vòng lặp vô hạn cho đến khi đăng nhập thành công
    {
        printf("\n**********ADMIN LOGIN**********\n"); // Hiển thị tiêu đề đăng nhập
        printf("Enter username: ");                    // Nhập tên đăng nhập
        fgets(username, sizeof(username), stdin);      // Nhập tên đăng nhập từ bàn phím
        // Loại bỏ ký tự xuống dòng cuối cùng
        username[strcspn(username, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng cuối cùng
        printf("Enter password: ");
        fgets(password, sizeof(password), stdin); // Nhập mật khẩu từ bàn phím
        // Loại bỏ ký tự xuống dòng cuối cùng
        password[strcspn(password, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng cuối cùng
        // Kiem tra tai khoan va mat khau admin
        if (strcmp(username, "admin") == 0 && strcmp(password, "123") == 0) // So sánh tên đăng nhập và mật khẩu
        {
            printf("Login successful! Welcome, Admin.\n"); // Đăng nhập thành công, chào mừng Admin
            break;                                         // Dang nhap thanh cong, thoat khoi vong lap
        }
        else
        {
            printf("Invalid username or password. Please try again.\n"); // Tên đăng nhập hoặc mật khẩu không hợp lệ, vui lòng thử lại
        }
    }
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
    ;
    printf("\n\t\t\t\t\t\t\t\t[---------------------------End List---------------------------]\n");
    printf("\n");
}

// Hàm sắp xếp danh sách sinh viên theo thứ tự Z-A
void sortStudentListZA()
{
    struct Student students[100]; // Khai báo danh sách sinh viên
    int countStudentAmount = 0;   // Khai báo biến đếm số lượng sinh viên

    FILE *file = fopen("C:\\CODE\\TTTTTT\\project cua Tru\\Project\\data\\student.bin", "rb"); // Mở file để đọc dữ liệu
    if (file == NULL)                                                                          // Nếu không mở được file (con trỏ file có giá trị NULL),
    {
        printf("\t\t====-----> Khong mo duoc file <-----====\n");
        return;
    }

    // Đọc dữ liệu từ file vào mảng students
    while (fread(&students[countStudentAmount], sizeof(struct Student), 1, file) == 1)
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
    for (int i = 0; i < strlen(name); i++) // Duyệt qua từng ký tự trong tên
    {
        if (!isalpha(name[i]) && name[i] != ' ') // Kiểm tra nếu ký tự không phải là chữ cái và không phải là khoảng trắng
            return false;
    }
    return true; // Trả về true nếu tất cả các ký tự đều là chữ cái hoặc khoảng trắng
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
    printf("\t+-----+-------------------------+-----+------+-----------+------------------------------+----------------------------------------+----------+------------------------------+-----------+\n");
    printf("\t| STT |          NAME           | AGE | SEX  | PHONE NUM |             EMAIL            |                ADDRESS                 | BIRTHDAY |              MAJOR           |   STATUS  |\n");
    printf("\t+-----+-------------------------+-----+------+-----------+------------------------------+----------------------------------------+----------+------------------------------+-----------+\n");

    // Đọc từng dòng dữ liệu từ file
    while (fread(&studentInfo, sizeof(struct Student), 1, outputFile) == 1)
    {
        // In ra bảng nếu dữ liệu hợp lệ
        if (strlen(studentInfo.studentID) > 0) // Kiểm tra ID hợp lệ
        {
            printf("\t|%-5s|%-25s|%-5d|%-6s|%-11s|%-30s|%-40s|%-10s|%-30s|%-11s|\n",
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

    printf("\t+-----+-------------------------+-----+------+-----------+------------------------------+----------------------------------------+----------+------------------------------+-----------+\n");

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

    printf("\tNhap vao ID cua sinh vien: ");
    scanf("%6s", newstudentInfo.studentID);
    getchar(); // Xóa ký tự xuống dòng còn lại sau scanf

    do
    {
        printf("\tNhap vao ten cua sinh vien: ");
        fgets(newstudentInfo.studentName, sizeof(newstudentInfo.studentName), stdin);
        newstudentInfo.studentName[strcspn(newstudentInfo.studentName, "\n")] = '\0';
    } while (!isValidName(newstudentInfo.studentName));

    printf("\tNhap vao tuoi cua sinh vien: ");
    scanf("%d", &newstudentInfo.studentAge);

    printf("\tNhap vao gioi tinh cua sinh vien (0: Nam, 1: Nu): ");
    scanf("%d", &newstudentInfo.studentSex);
    getchar();

    do
    {
        printf("\tNhap vao so dien thoai cua sinh vien: ");
        scanf("%11s", newstudentInfo.studentPhoneNumber);
        getchar();
    } while (!isValidPhoneNumber(newstudentInfo.studentPhoneNumber));

    do
    {
        printf("\tNhap vao email cua sinh vien: ");
        scanf("%50s", newstudentInfo.studentEmail);
        getchar();
    } while (!isValidEmail(newstudentInfo.studentEmail));

    printf("\tNhap vao dia chi cua sinh vien: ");
    fgets(newstudentInfo.studentAddress, sizeof(newstudentInfo.studentAddress), stdin);
    newstudentInfo.studentAddress[strcspn(newstudentInfo.studentAddress, "\n")] = '\0';

    printf("\tNhap vao ngay sinh cua sinh vien (dd/mm/yyyy): ");
    scanf("%10s", newstudentInfo.studentBirthDay);
    getchar();

    printf("\tNhap vao nganh hoc cua sinh vien: ");
    fgets(newstudentInfo.studentMajor, sizeof(newstudentInfo.studentMajor), stdin);
    newstudentInfo.studentMajor[strcspn(newstudentInfo.studentMajor, "\n")] = '\0';

    printf("\tNhap vao trang thai cua sinh vien (0: Nghi hoc, 1: Dang hoc): ");
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
                scanf("%30s", studentInfo.studentEmail);
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
                fseek(file, sizeof(struct Student), SEEK_CUR);
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
    printf("\tNhap vao ten sinh vien can tim: ");
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
    printf("\t+-----+-------------------------+-----+------+-----------+------------------------------+----------------------------------------+----------+------------------------------+-----------+\n");
    printf("\t| STT |          NAME           | AGE | SEX  | PHONE NUM |             EMAIL            |                ADDRESS                 | BIRTHDAY |              MAJOR           |   STATUS  |\n");
    printf("\t+-----+-------------------------+-----+------+-----------+------------------------------+----------------------------------------+----------+------------------------------+-----------+\n");

    while (fread(&studentInfo, sizeof(struct Student), 1, inputFile))
    {
        if (strstr(studentInfo.studentName, nameToSearch) != NULL)
        {
            studentFound = 1;
            printf("\t|%-5s|%-25s|%-5d|%-6s|%-11s|%-30s|%-40s|%-10s|%-30s|%-11s|\n",
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
        printf("\t[ 6 = Sap xep danh sach sinh vien theo ten       ]\n");
        printf("\t[ 0 = Quay lai                                   ]\n");
        printf("\t[================================================]\n");
        printf("\tNhap Choice cua ban: ");
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
        printf("\t[ 0 = Thoat                                 ]\n");
        printf("\t[===========================================]\n");
        printf("\t                                             \n");
        printf("\tNhap Choice cua ban: ");
        scanf("%d", &choice);

        switch (choice) // Xử lý lựa chọn của người dùng
        {
        case 1:
            studentManagementMenu(); // Gọi hàm menu quản lý sinh viên
            break;
        case 2:
            // showStudentManagementMenu(); // Gọi hàm menu quản lý giáo viên
            break;
        case 3:
            // showStatisticMenu(); // Gọi hàm menu thống kê
            break;
        case 0:
            printf("\n\t\t\t=======KET THUC CHUONG TRINH=======\n");
            break;
        }
    } while (choice != 0); // Lặp lại cho đến khi người dùng chọn thoát (choice = 0)
}
