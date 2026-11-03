# ies-daily-report-C

## Viết và chạy C trong VS Code

Thư mục này dùng GCC portable trong `.tools/w64devkit` và tiện ích
Microsoft C/C++ trong VS Code. Cấu hình biên dịch theo chuẩn C17.
Bộ công cụ được tải từ https://github.com/skeeto/w64devkit/releases.

1. Trong VS Code, chọn **File > Open Folder** và mở thư mục `D:\linhtinh\IES`.
2. Mở file C, ví dụ `day_01/01_intro.c`, sửa code rồi nhấn **Ctrl+S** để lưu.
3. Nhấn **Ctrl+Shift+B** để biên dịch và chạy file đang mở.
4. Kết quả xuất hiện trong **Terminal** phía dưới. Nếu chương trình dùng `scanf`,
   bấm vào Terminal, nhập dữ liệu rồi nhấn Enter.

Bạn cũng có thể nhấn **Ctrl+F5** để chạy, hoặc **F5** để chạy có gỡ lỗi.
Nếu được yêu cầu chọn cấu hình, chọn **C: Run or debug active file**.
Để đặt điểm dừng khi gỡ lỗi, bấm vào lề trái cạnh số dòng trước khi nhấn F5.

Nếu muốn có nút chạy nhanh, nhấn **Ctrl+Shift+X**, tìm **Code Runner** của
**Jun Han** (`formulahendry.code-runner`) rồi cài đặt. Sau đó mở file `.c`
và nhấn **Ctrl+Alt+N** hoặc nút **Run Code**. Dự án đã cấu hình Code Runner
để lưu file trước khi chạy và chạy trong Terminal, hỗ trợ nhập với `scanf`.

Mỗi bài tập nên là một file `.c` có một hàm `main`. Cấu hình hiện tại biên dịch
riêng file đang mở. Các file được tạo khi biên dịch nằm trong thư mục `.build`
bên cạnh file C và được Git bỏ qua.

Nếu có lỗi biên dịch, xem thông báo trong Terminal hoặc bảng Problems
(**Ctrl+Shift+M**), sửa lỗi, lưu file rồi chạy lại.
