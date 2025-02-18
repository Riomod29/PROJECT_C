#include <stdio.h>
#include <stdlib.h>
#include "../include/function.h"
#include "function.c"

int main()
{
    system("cls");      // Xóa
    system("color 0D"); // Màu nền đen, chữ tím

    // Chỗ này để cập nhật data admin vào file
    //  FILE *file = fopen ("C:\\PROJECT\\data\\admin.bin","ab"); // Tạo file admin.bin
    //  fwrite("admin001\n12345",sizeof(char),14,file); // Ghi thông tin tài khoản admin vào file
    //  fclose(file); // Đóng file

    int isAdmin;             // Biến kiểm tra quyền admin
    isAdmin = loginManege(); // Đăng nhập với tài khoản Admin

    // int isAdmin =1; // Xoa sau khi chay thu
    if (isAdmin) // Nếu là Admin
    {
        printf("\t\t    -----------------------\n");
        printf("\t\t    Xin chao quan tri vien.\n"); // Thông báo đã đăng nhập
        printf("\t\t    -----------------------\n");
    }
    mainMenu(); // Hiển thị menu chính
    return 0;   // Kết thúc chương trình
}
