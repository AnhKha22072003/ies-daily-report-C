# BÁO CÁO HỌC TẬP — NGÀY 01

**Nội dung:** Nền tảng C cho lập trình nhúng  
**Ngày báo cáo:** 02/11/2026 · **Gửi:** Mentor

> Hôm nay em tập trung tìm hiểu cách C làm việc với kiểu dữ liệu, biến, bộ nhớ, hàm và mảng. Trong quá trình học, em so sánh với PHP và các ngôn ngữ đã sử dụng để nhận ra những điểm cần thay đổi khi chuyển từ backend sang lập trình nhúng.

## 1. Hôm nay đã học được gì?

| Nội dung | Những gì em đã tìm hiểu và thực hành |
| :--- | :--- |
| **Tổng quan C** | Vai trò của C trong lập trình nhúng, quá trình biên dịch, cấu trúc chương trình với `main`, thư viện và cách in dữ liệu bằng `printf`. |
| **Kiểu dữ liệu, biến và bộ nhớ** | Các kiểu số nguyên, số thực, ký tự; dùng `sizeof` để xem kích thước dữ liệu; tìm hiểu `uint8_t`, `int16_t`, `uint32_t`, ép kiểu và integer promotion. Bước đầu phân biệt giá trị của biến với địa chỉ trong bộ nhớ. |
| **Tổ chức dữ liệu** | Đọc về `struct`, `union`, `enum`; dùng `struct Sensor` để nhóm mã cảm biến và nhiệt độ. So sánh hàm nhận bản sao `Sensor` với hàm nhận con trỏ: chỉ cách thứ hai trong ví dụ cập nhật được cảm biến gốc. |
| **Toán tử và điều khiển** | Ôn `if/else`, `for`; tìm hiểu thao tác bit và mặt nạ bit qua cờ READY/ERROR/BUSY, GPIO mô phỏng; đọc ví dụ phân loại nhiệt độ và kiểm tra timeout khi bộ đếm quay vòng. |
| **Hàm** | Ôn kiểu trả về, tham số, `return`; chia bài toán cảm biến thành các hàm kiểm tra dữ liệu, tìm nhiệt độ lớn nhất và xác định cảnh báo. Đã đọc thêm về `const`, `volatile`, `static`, `extern`, `inline` nhưng cần luyện cách dùng. |
| **Mảng** | Khai báo, khởi tạo, duyệt và thêm phần tử trong giới hạn sức chứa; phân biệt `count` với `capacity`. Thực hành tính tổng, trung bình nhiệt độ; làm quen `size_t` và cách đếm phần tử bằng `sizeof` khi còn thao tác trực tiếp với mảng. |

**Bài thực hành:** [Tổng quan](01_intro.c) · [Kiểu dữ liệu và Sensor](02_data_types.c) · [Toán tử, điều kiện và GPIO](03_operators_and_control_flow.c) · [Hàm xử lý cảm biến](04_function.c) · [Mảng nhiệt độ](05_arrays.c).

## 2. Những so sánh em đã ghi nhận khi học

| Liên hệ với kiến thức đã có | Điểm em nhận ra ở C |
| :--- | :--- |
| **In dữ liệu trong PHP:** quen dùng `echo` và `var_dump`. | Trong C, em dùng `printf` và chọn định dạng phù hợp như `%d`, `%c`, `%f`, `%zu`. `var_dump` của PHP hỗ trợ xem cả kiểu và giá trị; khi học C, em cần chú ý rõ kiểu dữ liệu mình đang in. |
| **Duyệt dữ liệu trong PHP/JavaScript:** quen với `foreach` hoặc các cách duyệt phần tử có sẵn. | C không có cú pháp `foreach`; trong bài em dùng `for`, chỉ số và số phần tử để duyệt mảng. |
| **Mảng và collection trong C#/Java:** đã quen với mảng và các cấu trúc như List, Map, Dictionary. | Mảng C có cách truy cập theo chỉ số quen thuộc, nhưng C không có sẵn các collection cấp cao này trong thư viện chuẩn. Với mảng cố định trong bài, em phải tự quản lý số phần tử đang dùng và kiểm tra sức chứa trước khi thêm. |
| **Hàm và tổ chức chương trình từ backend/C#:** đã quen chia chức năng, truyền tham số và nhận kết quả. | Có thể áp dụng lại tư duy chia nhỏ bài toán, nhưng cần học kỹ việc truyền con trỏ để sửa dữ liệu gốc và cách dùng các từ khóa của C khi tổ chức hàm. |

## 3. Tự đánh giá

Em đã nắm **cơ bản đến trung bình** nội dung ngày 1 về kiểu dữ liệu, biến, kích thước bộ nhớ và hàm; mảng và con trỏ mới ở bước đầu. Kinh nghiệm backend giúp em tiếp cận nhanh luồng xử lý và cách chia chức năng. Em hiểu cơ bản về OOP nhưng cần ôn lại và luyện tập trong ngày 2.

**Cần củng cố:** con trỏ, quan hệ giữa mảng và con trỏ, cách hàm thay đổi dữ liệu gốc, và cách xây dựng hàm trong chương trình nhúng thực tế. Các bài hiện tại là ví dụ chạy trên máy tính; GPIO mới được mô phỏng, chưa thực hành trên STM32.

## 4. Nội dung ngày tiếp theo

- **Con trỏ:** luyện địa chỉ, giải tham chiếu, truyền mảng và `struct` vào hàm.
- **OOP:** ôn các nguyên lý cơ bản, liên hệ với kinh nghiệm backend.
- **STM32:** tìm hiểu tổng quan vi điều khiển và cách bắt đầu một chương trình nhúng.

---

