#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MAX_CHI 50
#define MAX_TEN 50
#define MAX_TIEN 1000000000LL

typedef struct {
    char ten[MAX_TEN];
    long long soTien;
} KhoanChi;

/*
 * Tra ve:
 *  1: doc thanh cong
 *  0: ket thuc luong nhap
 * -1: dong qua dai
 */
int docDong(char *buffer, int kichThuoc) {
    if (fgets(buffer, kichThuoc, stdin) == NULL) {
        return 0;
    }

    char *xuongDong = strchr(buffer, '\n');

    if (xuongDong != NULL) {
        *xuongDong = '\0';
        return 1;
    }

    /* Kiem tra phan con lai cua dong. */
    int c = getchar();

    if (c == '\n' || c == EOF) {
        return 1;
    }

    while ((c = getchar()) != '\n' && c != EOF) {
        /* Bo phan du de khong anh huong lan nhap tiep theo. */
    }

    return -1;
}

int nhapSo(const char *thongBao,
          long long min,
          long long max,
          long long *ketQua) {
    char dong[128];

    while (1) {
        printf("%s", thongBao);

        int trangThai = docDong(dong, sizeof(dong));

        if (trangThai == 0) {
            return 0;
        }

        if (trangThai == -1) {
            printf("Du lieu qua dai. Vui long nhap lai.\n");
            continue;
        }

        char *cuoi;
        errno = 0;

        long long giaTri = strtoll(dong, &cuoi, 10);

        if (cuoi == dong) {
            printf("Vui long nhap mot so nguyen.\n");
            continue;
        }

        while (isspace((unsigned char)*cuoi)) {
            cuoi++;
        }

        if (errno == ERANGE || *cuoi != '\0'
            || giaTri < min || giaTri > max) {
            printf("Nhap so nguyen tu %lld den %lld.\n", min, max);
            continue;
        }

        *ketQua = giaTri;
        return 1;
    }
}

int nhapTen(char *ten) {
    while (1) {
        printf("Ten khoan chi: ");

        int trangThai = docDong(ten, MAX_TEN);

        if (trangThai == 0) {
            return 0;
        }

        if (trangThai == -1) {
            printf("Ten toi da %d byte. Vui long nhap lai.\n",
                   MAX_TEN - 1);
            continue;
        }

        int coNoiDung = 0;

        for (int i = 0; ten[i] != '\0'; i++) {
            if (!isspace((unsigned char)ten[i])) {
                coNoiDung = 1;
                break;
            }
        }

        if (coNoiDung) {
            return 1;
        }

        printf("Ten khong duoc de trong.\n");
    }
}

/* Tra ve 0 khi nguoi dung ket thuc luong nhap. */
int themKhoanChi(KhoanChi ds[], int *soLuong) {
    if (*soLuong >= MAX_CHI) {
        printf("Danh sach da day.\n");
        return 1;
    }

    KhoanChi moi;

    if (!nhapTen(moi.ten)) {
        return 0;
    }

    if (!nhapSo("So tien (dong): ", 1, MAX_TIEN, &moi.soTien)) {
        return 0;
    }

    ds[*soLuong] = moi;
    (*soLuong)++;

    printf("Da them khoan chi.\n");
    return 1;
}

void hienThiDanhSach(const KhoanChi ds[], int soLuong) {
    if (soLuong == 0) {
        printf("Chua co khoan chi nao.\n");
        return;
    }

    long long tong = 0;

    printf("\n%-5s %-49s %s\n", "STT", "Ten khoan chi", "So tien");

    for (int i = 0; i < soLuong; i++) {
        printf("%-5d %-49s %lld\n",
               i + 1, ds[i].ten, ds[i].soTien);

        tong += ds[i].soTien;
    }

    printf("Tong chi: %lld dong\n", tong);
}

void timLonNhat(const KhoanChi ds[], int soLuong) {
    if (soLuong == 0) {
        printf("Chua co khoan chi nao.\n");
        return;
    }

    int viTriMax = 0;

    for (int i = 1; i < soLuong; i++) {
        if (ds[i].soTien > ds[viTriMax].soTien) {
            viTriMax = i;
        }
    }

    printf("Khoan chi lon nhat: %s - %lld dong\n",
           ds[viTriMax].ten, ds[viTriMax].soTien);
}

int main(void) {
    KhoanChi danhSach[MAX_CHI];
    int soLuong = 0;
    long long luaChon;

    while (1) {
        printf("\n===== QUAN LY CHI TIEU =====\n");
        printf("1. Them khoan chi\n");
        printf("2. Xem danh sach va tong tien\n");
        printf("3. Tim khoan chi lon nhat\n");
        printf("0. Thoat\n");

        if (!nhapSo("Lua chon: ", 0, 3, &luaChon)) {
            printf("\nKet thuc chuong trinh.\n");
            return 0;
        }

        switch (luaChon) {
            case 1:
                if (!themKhoanChi(danhSach, &soLuong)) {
                    printf("\nKet thuc chuong trinh.\n");
                    return 0;
                }
                break;

            case 2:
                hienThiDanhSach(danhSach, soLuong);
                break;

            case 3:
                timLonNhat(danhSach, soLuong);
                break;

            case 0:
                printf("Tam biet!\n");
                return 0;
        }
    }
}