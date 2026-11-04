#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define SO_DU_TOI_DA 1000000000

static long long soDu = 1000000;

int nhapSo(const char *thongBao, long long *ketQua);
void xemSoDu(void);
int napTien(long long soTien);
int rutTien(long long soTien);
int demGiaoDich(int tang);


int nhapSo(const char *thongBao, long long *ketQua) {
    char dong[100];

    printf("%s", thongBao);

    if (fgets(dong, sizeof(dong), stdin) == NULL) {
        return -1;
    }

    if (strchr(dong, '\n') == NULL) {
        int c = getchar();

        if (c != '\n' && c != EOF) {
            while ((c = getchar()) != '\n' && c != EOF) {
            }

            return 0;
        }
    }

    char *cuoi;
    errno = 0;

    long long giaTri = strtoll(dong, &cuoi, 10);

    if (cuoi == dong || errno == ERANGE) {
        return 0;
    }

    while (isspace((unsigned char)*cuoi)) {
        cuoi++;
    }

    if (*cuoi != '\0') {
        return 0;
    }

    *ketQua = giaTri;
    return 1;
}

void xemSoDu(void) {
    printf("So du: %lld dong\n", soDu);
}

int demGiaoDich(int tang) {

    static int soLan = 0;

    if (tang == 1) {
        soLan++;
    }

    return soLan;
}

int napTien(long long soTien) {
    if (soTien <= 0) {
        printf("So tien phai lon hon 0.\n");
        return 0;
    }

    if (soTien > SO_DU_TOI_DA - soDu) {
        printf("So du sau nap khong duoc vuot 1 ty dong.\n");
        return 0;
    }

    soDu += soTien;
    demGiaoDich(1);

    return 1;
}

int rutTien(long long soTien) {
    if (soTien <= 0) {
        printf("So tien phai lon hon 0.\n");
        return 0;
    }

    if (soTien > soDu) {
        printf("So du khong du.\n");
        return 0;
    }

    soDu -= soTien;
    demGiaoDich(1);

    return 1;
}

int main(void) {
    while (1) {
        long long luaChon;

        printf("\n===== TAI KHOAN =====\n");
        printf("1. Xem so du\n");
        printf("2. Nap tien\n");
        printf("3. Rut tien\n");
        printf("4. Xem so giao dich thanh cong\n");
        printf("0. Thoat\n");

        int trangThai = nhapSo("Lua chon: ", &luaChon);

        if (trangThai == -1) {
            break;
        }

        if (trangThai == 0) {
            printf("Vui long nhap so nguyen.\n");
            continue;
        }

        switch (luaChon) {
            case 1:
                xemSoDu();
                break;

            case 2:
            case 3: {

                long long soTien;

                trangThai = nhapSo("Nhap so tien: ", &soTien);

                if (trangThai == -1) {
                    printf("\nKet thuc chuong trinh.\n");
                    return 0;
                }

                if (trangThai == 0) {
                    printf("So tien khong hop le.\n");
                    break;
                }

                if (luaChon == 2) {
                    if (napTien(soTien)) {
                        printf("Nap tien thanh cong.\n");
                    }
                } else {
                    if (rutTien(soTien)) {
                        printf("Rut tien thanh cong.\n");
                    }
                }

                break;
            }

            case 4:
                printf("So giao dich thanh cong: %d\n",
                       demGiaoDich(0));
                break;

            case 0:
                printf("Tam biet!\n");
                return 0;

            default:
                printf("Vui long chon tu 0 den 4.\n");
        }
    }

    printf("\nKet thuc chuong trinh.\n");
    return 0;
}