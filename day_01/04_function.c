// thông tin hiểu và nắm về hàm trong lập trình C# áp dụng với C như sau hàm có thể được định nghĩa với các kiểu trả về khác nhau, bao gồm void (không trả về giá trị), int (trả về số nguyên), float (trả về số thực), char (trả về ký tự), và các kiểu dữ liệu khác. Hàm có thể nhận các tham số đầu vào, cho phép truyền dữ liệu từ bên ngoài vào hàm để xử lý. Các tham số này có thể là các biến, hằng số, hoặc các biểu thức. Khi gọi hàm, bạn có thể truyền các giá trị cụ thể cho các tham số này. Hàm có thể được sử dụng để tổ chức mã nguồn, tái sử dụng mã, và cải thiện khả năng đọc và bảo trì của chương trình.
// hàm void không cần trả về giá trị, nhưng có thể thực hiện các tác vụ như in ra màn hình, thay đổi trạng thái của các biến toàn cục, hoặc thực hiện các thao tác khác. Hàm có thể được định nghĩa trong cùng một tệp nguồn hoặc trong các tệp nguồn khác nhau, và có thể được gọi từ bất kỳ đâu trong chương trình, miễn là phạm vi truy cập cho phép. Khi định nghĩa hàm, bạn cần chỉ định kiểu trả về, tên hàm, và danh sách các tham số (nếu có). Khi gọi hàm, bạn chỉ cần sử dụng tên hàm và truyền các giá trị cần thiết cho các tham số.
// hàm ở C không hỗ trợ tham số mặc định như C++, nhưng bạn có thể sử dụng các kỹ thuật khác để đạt được hiệu quả tương tự, chẳng hạn như sử dụng các macro hoặc tạo các hàm overload (nếu sử dụng C++). Hàm có thể được khai báo trước khi định nghĩa, cho phép bạn sử dụng hàm trong các phần của chương trình trước khi nó được định nghĩa. Điều này giúp tổ chức mã nguồn và quản lý phụ thuộc giữa các hàm.
//static functions trong C là các hàm được khai báo với từ khóa static, có phạm vi truy cập giới hạn trong tệp nguồn mà chúng được định nghĩa. Điều này có nghĩa là các hàm static không thể được gọi từ các tệp nguồn khác, giúp tránh xung đột tên và cải thiện tính đóng gói của mã nguồn. Các hàm static thường được sử dụng để thực hiện các tác vụ nội bộ trong một tệp nguồn, chẳng hạn như xử lý dữ liệu hoặc thực hiện các thao tác hỗ trợ cho các hàm công khai khác. Khi sử dụng hàm static, bạn cần đảm bảo rằng chúng chỉ được gọi từ các hàm hoặc phần của chương trình nằm trong cùng một tệp nguồn, và không nên cố gắng truy cập chúng từ bên ngoài.
// biến static trong C là các biến được khai báo với từ khóa static, có phạm vi truy cập giới hạn trong tệp nguồn mà chúng được định nghĩa. Điều này có nghĩa là các biến static không thể được truy cập từ các tệp nguồn khác, giúp tránh xung đột tên và cải thiện tính đóng gói của mã nguồn. Các biến static thường được sử dụng để lưu trữ trạng thái hoặc dữ liệu nội bộ trong một tệp nguồn, chẳng hạn như các biến đếm, cờ trạng thái, hoặc các cấu trúc dữ liệu hỗ trợ cho các hàm công khai khác. Khi sử dụng biến static, bạn cần đảm bảo rằng chúng chỉ được truy cập từ các hàm hoặc phần của chương trình nằm trong cùng một tệp nguồn, và không nên cố gắng truy cập chúng từ bên ngoài.
// extern functions trong C là các hàm được khai báo với từ khóa extern, cho phép chúng được định nghĩa trong các tệp nguồn khác và có thể được gọi từ bất kỳ đâu trong chương trình. Điều này giúp tổ chức mã nguồn và quản lý phụ thuộc giữa các hàm, cho phép bạn chia nhỏ chương trình thành các tệp nguồn riêng biệt và tái sử dụng mã nguồn. Khi sử dụng extern functions, bạn cần đảm bảo rằng chúng được định nghĩa trong một tệp nguồn khác và có phạm vi truy cập phù hợp để tránh xung đột tên và lỗi biên dịch.
//inline là gì?
// inline functions trong C là các hàm được khai báo với từ khóa inline, cho phép trình biên dịch thay thế các lời gọi hàm bằng mã nguồn của hàm đó tại thời điểm biên dịch. Điều này giúp giảm overhead của việc gọi hàm và cải thiện hiệu suất của chương trình, đặc biệt là đối với các hàm nhỏ hoặc được gọi nhiều lần. Tuy nhiên, việc sử dụng inline functions cũng có thể làm tăng kích thước mã nguồn và gây ra các vấn đề về tối ưu hóa nếu không được sử dụng đúng cách. Khi sử dụng inline functions, bạn cần đảm bảo rằng chúng được định nghĩa trong cùng một tệp nguồn hoặc trong các tệp tiêu đề (header files) để trình biên dịch có thể truy cập mã nguồn của chúng tại thời điểm biên dịch.
// notes: có nhiều ứng dụng của hàm trong lập trình C còn chư nắm khi làm việc với con trỏ và các từ khóa const static extern inline, các hàm có thể được sử dụng để tạo ra các thư viện, giao diện lập trình ứng dụng (API), và các mô-đun phần mềm, giúp cải thiện khả năng tái sử dụng mã nguồn và quản lý dự án. Các hàm cũng có thể được sử dụng để triển khai các thuật toán, xử lý dữ liệu, và thực hiện các tác vụ phức tạp trong chương trình, giúp tổ chức mã nguồn và cải thiện khả năng đọc và bảo trì của chương trình.

#include <stdio.h>

// 1. Kiem tra nhiet do hop le
int is_valid_temperature(int temp)
{
    if (temp < -400 || temp > 1250)
    {
        return 0;
    }

    return 1;
}

// 2. Tim nhiet do lon nhat
int find_max(int a, int b, int c)
{
    int max = a;

    if (b > max)
    {
        max = b;
    }

    if (c > max)
    {
        max = c;
    }

    return max;
}

// 3. Xac dinh muc canh bao
int get_alert_level(int temp)
{
    if (temp > 450)
    {
        return 2; // DANGER
    }

    if (temp > 350)
    {
        return 1; // WARNING
    }

    return 0; // NORMAL
}

int main(void)
{
    int sensor1 = 320; // 32.0 C
    int sensor2 = 385; // 38.5 C
    int sensor3 = 470; // 47.0 C

    // Kiem tra du lieu dau vao
    if (!is_valid_temperature(sensor1) ||
        !is_valid_temperature(sensor2) ||
        !is_valid_temperature(sensor3))
    {
        printf("Invalid sensor data!\n");
        return 1;
    }

    // Tim gia tri lon nhat
    int max_temp = find_max(
        sensor1, sensor2, sensor3
    );

    // Lay muc canh bao
    int level = get_alert_level(max_temp);

    printf("Max temperature: %.1f C\n",
           max_temp / 10.0);

    if (level == 0)
    {
        printf("Status: NORMAL\n");
    }
    else if (level == 1)
    {
        printf("Status: WARNING\n");
    }
    else
    {
        printf("Status: DANGER\n");
    }

    return 0;
}



