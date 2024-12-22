#include <stdio.h>  
#include <string.h>  

#define MAX_SP 100  

typedef struct {  
    char maSP[20];  
    char tenSP[50];  
    float giaNhap;  
    float giaBan;  
    int soLuong;  
} SanPham;  

int main() {  
    SanPham sp[MAX_SP];  
    int soLuongSP = 0;  
    float doanhThu = 0;  
    int luaChon;  

    do {  
        printf("\nMENU\n");  
        printf("1. Nhap thong tin san pham\n");  
        printf("2. Hien thi danh sach san pham\n");  
        printf("3. Ban san pham\n");  
        printf("4. Doanh thu hien tai\n");  
        printf("5. Thoat\n");  
        printf("Lua chon cua ban: ");  
        scanf("%d", &luaChon);  

        switch (luaChon) {  
            case 1: {  
                if (soLuongSP < MAX_SP) {  
                    printf("Nhap ma san pham: ");  
                    scanf("%s", sp[soLuongSP].maSP);  
                    printf("Nhap ten san pham: ");  
                    scanf("%s", sp[soLuongSP].tenSP); //Lýu ?: ch? nh?n tên không có kho?ng tr?ng  
                    printf("Nhap gia nhap: ");  
                    scanf("%f", &sp[soLuongSP].giaNhap);  
                    printf("Nhap gia ban: ");  
                    scanf("%f", &sp[soLuongSP].giaBan);  
                    printf("Nhap so luong: ");  
                    scanf("%d", &sp[soLuongSP].soLuong);  
                    doanhThu -= sp[soLuongSP].giaNhap * sp[soLuongSP].soLuong; // Gi?m doanh thu khi nh?p hàng  
                    soLuongSP++;  
                } else {  
                    printf("Da dat gioi han so luong san pham!\n");  
                }  
                break;  
            }  
            case 2: {  
                printf("Danh sach san pham:\n");  
                for (int i = 0; i < soLuongSP; i++) {  
                    printf("Ma SP: %s, Ten SP: %s, Gia nhap: %.2f, Gia ban: %.2f, So luong: %d\n",  
                           sp[i].maSP, sp[i].tenSP, sp[i].giaNhap, sp[i].giaBan, sp[i].soLuong);  
                }  
                break;  
            }  
            case 3: {  
                char maSPCanBan[20];  
                int soLuongBan;  
                printf("Nhap ma san pham can ban: ");  
                scanf("%s", maSPCanBan);  
                printf("Nhap so luong can ban: ");  
                scanf("%d", &soLuongBan);  

                for (int i = 0; i < soLuongSP; i++) {  
                    if (strcmp(sp[i].maSP, maSPCanBan) == 0) {  
                        if (sp[i].soLuong >= soLuongBan) {  
                            doanhThu += sp[i].giaBan * soLuongBan;  
                            sp[i].soLuong -= soLuongBan;  
                            printf("Ban hang thanh cong!\n");  
                            break;  
                        } else {  
                            printf("Khong con du hang!\n");  
                            break;  
                        }  
                    }  
                }  
                break;  
            }  
            case 4: printf("Doanh thu hien tai: %.2f\n", doanhThu); break;  
            case 5: printf("Thoat chuong trinh!\n"); break;  
            default: printf("Lua chon khong hop le!\n");  
        }  
    } while (luaChon != 5);  

    return 0;  
}
