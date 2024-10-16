

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

struct sinhVien{
    char hoTenSV[100];
    int maSoSV;
};

void nhapDanhSachSV(int soSV,struct sinhVien *myStructSV){
    for(int i=0 ;i < soSV; i++){
        scanf("%d %s",&myStructSV[i].maSoSV,&myStructSV[i].hoTenSV);
    }
}
void inDanhSachSV(int soSV,struct sinhVien *myStructSV){
    for(int i=0;i < soSV;i++){
        printf("%d %s",myStructSV[i].maSoSV,myStructSV[i].hoTenSV);
    }
    printf("\n");
}
void sapXepDanhSachSV(int soSV, struct sinhVien *myStructSV) {
    for (int i = 1; i < soSV; i++) {
        struct sinhVien key = myStructSV[i];
        int j = i - 1;
 
        /* Di chuyển các phần tử lớn hơn key về phía sau một vị trí */
        while (j >= 0 && myStructSV[j].maSoSV > key.maSoSV) {
            myStructSV[j + 1] = myStructSV[j];
            j = j - 1;
        }
        myStructSV[j + 1] = key;
    }
}

int main(){
    printf("Nhap so luong sinh vien:");
    int soLuongSinhVien;
    scanf("%d",&soLuongSinhVien);
    struct sinhVien *sinhvien = malloc(soLuongSinhVien * sizeof(struct sinhVien));
    nhapDanhSachSV(soLuongSinhVien,sinhvien);
    inDanhSachSV(soLuongSinhVien, sinhvien);
    sapXepDanhSachSV(soLuongSinhVien, sinhvien);
    inDanhSachSV(soLuongSinhVien, sinhvien);
    free(sinhvien);
}

