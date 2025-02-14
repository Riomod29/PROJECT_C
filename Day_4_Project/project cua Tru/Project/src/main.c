#include <stdio.h>
#include "function.h"

int main()
{
    // Lưu thông tin admin vào file (chỉ cần thực hiện một lần)
    struct Admin admin = {"admin", "123"};
    saveAdminInfo("admin.bin", admin);

    // Gọi hàm đăng nhập admin
    adminLogin();

    // Tiếp tục các chức năng khác của chương trình
    mainMenu();

    return 0;
}
