//Syntax?
//type variableName = value;
//What types of grouped data exist in C?
//nhóm số nguyên:char, short, int, long, long long, unsigned int,kiểu số thực: float, double, long double,kiểu logic: _Bool,boolean ,kiểu con trỏ: pointer,kiểu mảng: array,kiểu cấu trúc: struct,kiểu liên kết: union,kiểu liệt kê: enum
//struct?
//struct là một kiểu dữ liệu trong C cho phép nhóm các biến có kiểu dữ liệu khác nhau lại với nhau thành một thực thể duy nhất. Nó giúp tổ chức dữ liệu phức tạp và tạo ra các đối tượng có cấu trúc rõ ràng. Mỗi biến trong struct được gọi là một thành viên (member) của struct.
// typedef struct {
//     uint8_t id;
//     float temperature;
//     uint8_t status;
// } Sensor;
//  Sensor sensor1 = {1, 28.5f, 1};
//  Sensor sensor2 = {2, 30.2f, 0};
//pointer?
//pointer là một biến trong C lưu trữ địa chỉ bộ nhớ của một biến khác. Nó cho phép truy cập và thao tác trực tiếp với dữ liệu trong bộ nhớ, giúp quản lý bộ nhớ hiệu quả và hỗ trợ các cấu trúc dữ liệu phức tạp như danh sách liên kết và cây. Pointer có thể được sử dụng để truyền tham chiếu, tạo mảng động và quản lý tài nguyên hệ thống.
//union?
//union là một kiểu dữ liệu trong C cho phép lưu trữ nhiều biến khác nhau trong cùng một vùng nhớ, nhưng chỉ có thể sử dụng một biến tại một thời điểm. Kích thước của union được xác định bởi thành viên có kích thước lớn nhất. Union hữu ích khi cần tiết kiệm bộ nhớ và làm việc với các dữ liệu có thể thay đổi kiểu.
// có sự khác nhau giữa struct và union là struct lưu trữ tất cả các thành viên cùng lúc, trong khi union chỉ lưu trữ một thành viên tại một thời điểm.
//enum?
//enum là một kiểu dữ liệu trong C cho phép định nghĩa một tập hợp các hằng số có tên, giúp cải thiện khả năng đọc và bảo trì mã nguồn. Mỗi hằng số trong enum được ánh xạ tới một giá trị nguyên, bắt đầu từ 0 theo mặc định, nhưng có thể được chỉ định giá trị cụ thể. Enum thường được sử dụng để đại diện cho các trạng thái, lựa chọn hoặc danh sách các giá trị có ý nghĩa trong chương trình.
//typedef enum {
//     DEVICE_OFF,
//     DEVICE_STARTING,
//     DEVICE_RUNNING,
//     DEVICE_ERROR
// } DeviceState;
// sizeof ?
// sizeof là toán tử trong C được sử dụng để xác định kích thước bộ nhớ (tính bằng byte) mà một kiểu dữ liệu hoặc một biến chiếm. Nó giúp lập trình viên biết được lượng bộ nhớ cần thiết để lưu trữ dữ liệu và có thể hữu ích trong việc quản lý bộ nhớ và tối ưu hóa hiệu suất của chương trình.
//
//What are the sizes of data types in C?
//kích thước của các kiểu dữ liệu trong C có thể thay đổi tùy thuộc vào hệ thống và trình biên dịch, nhưng dưới đây là kích thước điển hình trên hầu hết các hệ thống 32-bit và 64-bit:
// char: 1 byte
// short: 2 bytes
// int: 4 bytes
// long: 4 bytes (trên hệ thống 32-bit) hoặc 8 bytes (trên hệ thống 64-bit)
// long long: 8 bytes
// unsigned int: 4 bytes
// float: 4 bytes
// double: 8 bytes
// long double: 8 bytes (trên hầu hết các hệ thống, nhưng có thể lớn hơn trên một số hệ thống)
// _Bool: 1 byte
// pointer: 4 bytes (trên hệ thống 32-bit) hoặc 8 bytes (trên hệ thống 64-bit)
// array: kích thước phụ thuộc vào số lượng phần tử và kiểu dữ liệu của mảng
// 
// cách hiểu nghĩa đơn giản của các kiểu dữ liệu như uint8_t, uint16_t, uint32_t, uint64_t là u=unsigned, int=integer, 8/16/32/64=bit, t=type. Ví dụ: uint8_t là kiểu dữ liệu số nguyên không dấu 8 bit, uint16_t là kiểu dữ liệu số nguyên không dấu 16 bit, uint32_t là kiểu dữ liệu số nguyên không dấu 32 bit, uint64_t là kiểu dữ liệu số nguyên không dấu 64 bit.
//When should you use `int` versus `uint32_t`?
// Sử dụng int khi thực hiện các phép tính số nguyên thông thường, không yêu cầu độ rộng bit cụ thể.Sử dụng uint32_t khi dữ liệu phải có chính xác 32 bit,
//type casting in C
//Type casting trong C là quá trình chuyển đổi một giá trị từ kiểu dữ liệu này sang kiểu dữ liệu khác. Nó cho phép lập trình viên kiểm soát cách dữ liệu được biểu diễn và xử lý trong chương trình. Type casting có thể được thực hiện một cách tường minh (explicit) hoặc ngầm định (implicit).
// int c = (int) 3.14; // explicit casting
//What is Integer Promotion in C?
//Integer Promotion trong C là một quy tắc trong quá trình chuyển đổi kiểu dữ liệu số nguyên. Khi thực hiện các phép toán giữa các kiểu dữ liệu số nguyên có kích thước nhỏ hơn int (như char hoặc short), các giá trị này sẽ được "nâng cấp" (promoted) lên kiểu int trước khi thực hiện phép toán. Điều này giúp đảm bảo rằng các phép toán được thực hiện với độ chính xác và phạm vi phù hợp, tránh mất dữ liệu hoặc kết quả không mong muốn.
//bitwise operators in C
//Bitwise operators trong C là các toán tử được sử dụng để thao tác trực tiếp trên các bit của số nguyên. Chúng cho phép thực hiện các phép toán logic và dịch bit, giúp lập trình viên kiểm soát dữ liệu ở mức thấp hơn. Các toán tử bitwise phổ biến bao gồm:
// & (AND): Thực hiện phép toán AND giữa các bit tương ứng.
// | (OR): Thực hiện phép toán OR giữa các bit tương ứng.
// ^ (XOR): Thực hiện phép toán XOR giữa các bit tương ứng.
// ~ (NOT): Đảo ngược các bit của một số.
// << (Left Shift): Dịch các bit sang trái, thêm các bit 0 vào bên phải.
// >> (Right Shift): Dịch các bit sang phải, loại bỏ các bit bên phải và thêm các bit 0 vào bên trái (hoặc giữ bit dấu đối với số âm).
//
//What is the difference between `const` and `volatile`?
//`const` là một từ khóa trong C được sử dụng để khai báo một biến hoặc đối tượng không thể thay đổi giá trị sau khi được khởi tạo. Nó giúp bảo vệ dữ liệu khỏi việc bị thay đổi ngoài ý muốn và cải thiện khả năng đọc mã nguồn.
//`volatile` là một từ khóa trong C được sử dụng để thông báo cho trình biên dịch rằng giá trị của một biến có thể thay đổi bất ngờ, ví dụ như khi biến đó được truy cập bởi phần cứng hoặc các luồng khác. Nó ngăn trình biên dịch tối ưu hóa các truy cập đến biến đó, đảm bảo rằng mỗi lần truy cập đều lấy giá trị mới nhất từ bộ nhớ.
// các để in giá trị ra màn hình của từng kiểu dữ liệu trong C:
// char: printf("%c", variable);
// short: printf("%hd", variable);
// int: printf("%d", variable);
// long: printf("%ld", variable);
// sizeof: printf("%zu", sizeof(variable));
// có sự khác biệt với php ta sử dụng echo và var_dump $tenbien để in ra giá trị của biến, echo chỉ in ra giá trị của biến, trong khi var_dump cung cấp thông tin chi tiết hơn về kiểu dữ liệu và giá trị của biến. Ví dụ:

#include <stdio.h>
typedef struct {
    int id;
    float temperature;
} Sensor;
void updateByValue(Sensor sensor, float value)
{
    sensor.temperature += value;
}
void updateByPointer(Sensor *sensor, float value)
{
    sensor->temperature += value;
}

int main(void) {
    Sensor sensor1 = {1, 28.5f};
    Sensor sensor2 = {2, 30.2f};
    printf("Sensor 1: ID=%d, Temperature=%.1f\n", sensor1.id, sensor1.temperature);
    printf("Sensor 2: ID=%d, Temperature=%.1f\n", sensor2.id, sensor2.temperature);
    sensor1.temperature += 1.5f;
    printf("After increasing, Sensor 1: ID=%d, Temperature=%.1f\n", sensor1.id, sensor1.temperature);
    updateByValue(sensor1, 2.0f);
    printf("After updateByValue, Sensor 1: ID=%d, Temperature=%.1f\n", sensor1.id, sensor1.temperature);
    updateByPointer(&sensor1, 2.0f);    
    printf("After updateByPointer, Sensor 1: ID=%d, Temperature=%.1f\n", sensor1.id, sensor1.temperature);
    return 0;
}
