//Noi trien khai cac ham

#include <stdio.h>
#include "datatype.h"
typedef struct Class Class;

// Hàm menu chính (Main Menu)
void mainMenu(){
    int choice;
	    do{
	        printf("\t+-------------------PTIT--------------------+\n");
	        printf("\t| 1. Quan ly sinh vien                      |\n");
	        printf("\t| 2. Quan ly giao vien                      |\n");
	        printf("\t| 3. Quan ly lop hoc                        |\n");
	        printf("\t| 0. Thoat                                  |\n");
	        printf("\t+-------------------------------------------+\n");
	        printf("\tNhap lua chon cua ban: ");
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
	            printf("Ket thuc chuong trinh");
	        }
    } while (choice != 0);
}

// Ham menu quan ly sinh vien (Management Student Menu)
void studentManagementMenu(){
    int choice;
	    do{
	        printf("\t+-------------------SINH VIEN--------------------+\n");
	        printf("\t| 1. Xem danh sach sinh vien                     |\n");
	        printf("\t| 2. Them moi sinh vien                          |\n");
	        printf("\t| 3. Chinh sua thong tin sinh vien               |\n");
	        printf("\t| 4. Xoa sinh vien                               |\n");
	        printf("\t| 5. Tim kiem sinh vien                          |\n");
	        printf("\t| 6. Sap xep danh sach sinh vien theo ten        |\n");
	        printf("\t| 0. Quay lai                                    |\n");
	        printf("\t+------------------------------------------------+\n");
	        printf("\tNhap lua chon cua ban: ");
	        scanf("%d", &choice);
	
	        switch (choice){
	        case 1:
	            showStudentList();
	            break;
	        case 2:
	            addNewStudent();
	            break;
	        case 3:
	            // editStudentInfo();
	            break;
	        case 4:
	            // deleteStudent();
	            break;
	        case 0:
	            printf("\n\t\t-----Quay lai Menu chinh-----\n");
	            break;
	        default:
	            break;
	        }
	    } while (choice != 0);
}

// Ham kiem tra du lieu nhap vao cua sinh vien
int isValidStudentInfo(struct Student studentInfo){
    // Kiem tra truong rong.
    if (strlen(studentInfo.studentID) == 0 || strlen(studentInfo.studentName) == 0 || strlen(studentInfo.studentPhoneNumber) == 0 ||
        strlen(studentInfo.studentEmail) == 0 || strlen(studentInfo.studentAddress) == 0 || strlen(studentInfo.studentBirthDay) == 0 ||
        strlen(studentInfo.studentMajor) == 0)
    {
        printf("=========> Thong tin sinh vien khong duoc de trong <=========\n");
        return 0;
    }

    // Kiem tra do dai tung truong.
    if (strlen(studentInfo.studentID) >= sizeof(studentInfo.studentID) ||
        strlen(studentInfo.studentName) >= sizeof(studentInfo.studentName) ||
        strlen(studentInfo.studentPhoneNumber) >= sizeof(studentInfo.studentPhoneNumber) ||
        strlen(studentInfo.studentEmail) >= sizeof(studentInfo.studentEmail) ||
        strlen(studentInfo.studentAddress) >= sizeof(studentInfo.studentAddress) ||
        strlen(studentInfo.studentBirthDay) >= sizeof(studentInfo.studentBirthDay) ||
        strlen(studentInfo.studentMajor) >= sizeof(studentInfo.studentMajor))
    {
        printf("=========> Do dai thong tin sinh vien khong hop le <=========\n");
        return 0;
    }

    // Kiem tra trung lap trong file
    struct Student existingStudent;
    FILE *inputFile = fopen("D:\\Code C task\\My Main Project\\Project\\data\\Student_Data.txt", "r");
    if (inputFile == NULL)
    {
        printf("=========> Khong mo duoc file du lieu sinh vien <=========\n");
        return 0;
    }

    while (fscanf(inputFile, "%6s %20s %d %d %11s %20s %40s %10s %25s %d",
                  existingStudent.studentID, existingStudent.studentName, &existingStudent.studentAge,
                  &existingStudent.studentSex, existingStudent.studentPhoneNumber, existingStudent.studentEmail,
                  existingStudent.studentAddress, existingStudent.studentBirthDay, existingStudent.studentMajor,
                  &existingStudent.studentStatus) == 10)
    {
        if (strcmp(existingStudent.studentID, studentInfo.studentID) == 0)
        {
            printf("=========> ID sinh vien da ton tai <=========\n");
            fclose(inputFile);
            return 0;
        }
        if (strcmp(existingStudent.studentEmail, studentInfo.studentEmail) == 0)
        {
            printf("=========> Email sinh vien da ton tai <=========\n");
            fclose(inputFile);
            return 0;
        }
        if (strcmp(existingStudent.studentPhoneNumber, studentInfo.studentPhoneNumber) == 0)
        {
            printf("=========> So dien thoai sinh vien da ton tai <=========\n");
            fclose(inputFile);
            return 0;
        }
    }

    fclose(inputFile);
    return 1;
}

// Ham hien thi danh sach sinh vien.
void showStudentList(){
    struct Student studentInfo;
    FILE *outputFile;

    outputFile = fopen("data.bin", "r");
    if (outputFile == NULL)
    {
        printf("\t\t=========> File khong ton tai <=========\n");
        return;
    }

    printf("\t\t\t\t\t\t\t[---------------------Danh sach sinh vien---------------------]\n\n");
    printf("\t+------+--------------------+------+------+-----------+--------------------+----------------------------------------+----------+------------------------------+------+\n");
    printf("\t|  ID  |        NAME        | AGE  | SEX  | PHONE NUM |        EMAIL       |                ADDRESS                 | BIRTHDAY |              MAJOR           |STATUS|\n");
    printf("\t+------+--------------------+------+------+-----------+--------------------+----------------------------------------+----------+------------------------------+------+\n");

    // Rep tung dong du lieu tu file
    while (fscanf(outputFile, "%6s %19[^0-9] %d %d %11s %19s %39[^0-9] %10s %24[^0-9] %d",
                  studentInfo.studentID,
                  studentInfo.studentName,
                  &studentInfo.studentAge,
                  &studentInfo.studentSex,
                  studentInfo.studentPhoneNumber,
                  studentInfo.studentEmail,
                  studentInfo.studentAddress,
                  studentInfo.studentBirthDay,
                  studentInfo.studentMajor,
                  &studentInfo.studentStatus) == 10)
    {
        // Xu ly in ra bang
        printf("\t|%-6s|%-20s|%-6d|%-6s|%-11s|%-20s|%-40s|%-10s|%-30s|%-6s|\n",
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

    printf("\t+------+--------------------+------+------+-----------+--------------------+----------------------------------------+----------+------------------------------+------+\n");

    fclose(outputFile);
    printf("\t\t\t\t\t\t\t[---------------------------End List---------------------------]\n");
    printf("\n");
}

// Ham them moi sinh vien
void addNewStudent()
{
    struct Student newstudentInfo;
    FILE *inputFile;
    inputFile = fopen("D:\\Code C task\\My Main Project\\Project\\data\\Student_Data.txt", "a");
    if (inputFile == NULL)
    {
        printf("\t\t=========> File khong ton tai <=========\n");
    }
    else
    {
        printf("Nhap vao ID cua sinh vien: ");
        scanf("%s", newstudentInfo.studentID);
        getchar(); // Delete ky tu xuong dong con lai sau scanf

        printf("Nhap vao ten cua sinh vien: ");
        fgets(newstudentInfo.studentName, sizeof(newstudentInfo.studentName), stdin);
        newstudentInfo.studentName[strcspn(newstudentInfo.studentName, "\n")] = '\0';

        printf("Nhap vao tuoi cua sinh vien: ");
        scanf("%d", &newstudentInfo.studentAge);

        printf("Nhap vao gioi tinh cua sinh vien (0: Nam, 1: Nu): ");
        scanf("%d", &newstudentInfo.studentSex);
        getchar();

        printf("Nhap vao so dien thoai cua sinh vien: ");
        scanf("%s", newstudentInfo.studentPhoneNumber);
        getchar();

        printf("Nhap vao email cua sinh vien: ");
        scanf("%s", newstudentInfo.studentEmail);
        getchar();

        printf("Nhap vao dia chi cua sinh vien: ");
        fgets(newstudentInfo.studentAddress, sizeof(newstudentInfo.studentAddress), stdin);
        newstudentInfo.studentAddress[strcspn(newstudentInfo.studentAddress, "\n")] = '\0';

        printf("Nhap vao ngay sinh cua sinh vien: ");
        scanf("%s", newstudentInfo.studentBirthDay);
        getchar();

        printf("Nhap vao nganh hoc cua sinh vien: ");
        fgets(newstudentInfo.studentMajor, sizeof(newstudentInfo.studentMajor), stdin);
        newstudentInfo.studentMajor[strcspn(newstudentInfo.studentMajor, "\n")] = '\0';

        printf("Nhap vao trang thai cua sinh vien (0: Nghi hoc, 1: Dang hoc): ");
        scanf("%d", &newstudentInfo.studentStatus);
        if (isValidStudentInfo(newstudentInfo))
        {
            fprintf(inputFile, "%s %s %d %d %s %s %s %s %s %d\n", newstudentInfo.studentID, newstudentInfo.studentName, newstudentInfo.studentAge, newstudentInfo.studentSex, newstudentInfo.studentPhoneNumber, newstudentInfo.studentEmail, newstudentInfo.studentAddress, newstudentInfo.studentBirthDay, newstudentInfo.studentMajor, newstudentInfo.studentStatus);
            printf("\t\t=========> Them sinh vien thanh cong <=========\n");
        }
        else
        {
            printf("\t=========> Them sinh vien that bai <=========\n");
        }
        fclose(inputFile);
    }
}

// Hàm menu qu?n lý l?p h?c (Management Class Menu)
// void classManagementMenu()
// {
//     int choice;
//     do
//     {
//         printf("\t+-------------------CLASS--------------------+\n");
//         printf("\t| 1. Xem danh sach lop hoc                   |\n");
//         printf("\t| 2. Them moi lop hoc                        |\n");
//         printf("\t| 3. Chinh sua thong tin lop hoc             |\n");
//         printf("\t| 4. Xoa lop hoc                             |\n");
//         printf("\t| 0. Quay lai                                |\n");
//         printf("\t+--------------------------------------------+\n");
//         printf("\tNhap lua chon cua ban: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             // showClassList();
//             break;
//         case 2:
//             // addNewClass();
//             break;
//         case 3:
//             // editClassInfo();
//             break;
//         case 4:
//             // deleteClass();
//             break;
//         case 0:
//             printf("\n\t\t-----Quay lai Menu chinh-----\n");
//             break;
//         default:
//             break;
//         }
//     } while (choice != 0);
// }
// Hàm hi?n th? danh sách l?p h?c
// void showClassList(Class showClass[], int *classCurrentLength)
// {
//     if (*classCurrentLength == 0)
//     {
//         printf("\t|--------------------Danh sach trong--------------------|\n");
//     }
//     printf("\t|--------------------Danh sach lop hoc--------------------|\n");
//     printf("\t+------+--------------------+------------------------------+---+--------+\n");
//     printf("\t|%-6s|%-20s|%-30s|%-3d|%-8d|\n", "ID", "NAME", "MAJOR", "SIZE", "STATUS");
//     printf("\t+------+--------------------+------------------------------+---+--------+\n");
//     for (int i = 0; i < *classCurrentLength; i++)
//     {
//         printf("\t|%-6s|%-20s|%-30s|%-3d|%-8d|\n", showClass->classID, showClass->className, showClass->classMajors,
//                showClass->classSize, showClass->classStatus);
//     }
// }
// Hàm thêm m?i l?p h?c
// void addNewClass(Class newClass[], int *classCurrentLength, int maxClassListSize)
// {
//     int classIDToAdd, classSizeToAdd, classStatusToAdd;
//     char classNameToAdd(20), char classMajorsToAdd;
//     if (*classCurrentLength >= maxClassListSize)
//     {
//         printf("Khong the them lop vi danh sach da day!\n");
//     }
//     printf("Nhap vao ID cua lop hoc moi: ")
// }













//#include <stdio.h>
//#include <stdlib.h>
//
//void showMenu() {
//    printf(" ***Student Management System Using C*** \n\n");
//    printf("          CHOOSE YOUR ROLE            \n");
//    printf("=======================================\n");
//    printf(" [1] Admin.                           \n");
//    printf(" [2] Student.                         \n");
//    printf(" [3] Teacher.                         \n");
//    printf(" [0] Exit the Program.                \n");
//    printf("=======================================\n");
//    printf(" Enter The Choice: ");
//}
//void showLoginMenu() {
//    printf(" ***Student Management System Using C*** \n\n");
//    printf("                 LOGIN                 \n");
//    printf("=======================================\n");
//    printf(" [1] Admin.                           \n");
//    printf(" [0] Exit the Program.                \n");
//    printf("=======================================\n");
//}






//showmenu
//int main() {
//    int choice;
//
//    do {
//        system("cls"); // Dùng "clear" n?u ch?y trên Linux/macOS
//        showMenu();
//        scanf("%d", &choice);
//
//        switch (choice) {
//            case 1:
//                printf("\nYou selected Admin.\n");
//                // Thêm code x? lý Admin ? dây
//                break;
//            case 2:
//                printf("\nYou selected Student.\n");
//                // Thêm code x? lý Student ? dây
//                break;
//            case 3:
//                printf("\nYou selected Teacher.\n");
//                // Thêm code x? lý Teacher ? dây
//                break;
//            case 0:
//                printf("\nExiting the program...\n");
//                exit(0);
//            default:
//                printf("\nInvalid choice! Please try again.\n");
//        }
//        printf("\nPress Enter to continue...");
//        getchar(); getchar(); // Ð?i phím Enter tru?c khi quay l?i menu
//
//    } while (1);
//
//    return 0;
//}

