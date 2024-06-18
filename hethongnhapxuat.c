#include <stdio.h>
#include <string.h>
<<<<<<< HEAD
#include <stdio.h>
#include <string.h>
=======
>>>>>>> 7dfe74da9f5dcac9291b11504172cb884be86bf6
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

<<<<<<< HEAD

=======
    #define CYAN "\x1B[36m"
    #define YELLOW "\x1B[33m"
    #define RED "\x1B[31m"
    #define RESET "\x1B[0m"

// Định nghĩa cấu trúc mathang
>>>>>>> 7dfe74da9f5dcac9291b11504172cb884be86bf6
typedef struct {
    char tenhang[100];
    int soluong;
    double giathanh;
    char code[100];
<<<<<<< HEAD
} mathang;typedef struct {
    char tenhang[100];
    int soluong;
    double giathanh;
    char code[100];
=======
>>>>>>> 7dfe74da9f5dcac9291b11504172cb884be86bf6
} mathang;
void generatecode(const char* name, char* code){ //Hàm tự tạo mã code là chữ cái đầu của tên mặt hàng
    bool isNewWord = true; 
    size_t codeindex = 0;
    for(size_t i=0;i<strlen(name);++i){
        char c=name[i];
        if(isNewWord && isalpha(c)){
            code[codeindex++]=tolower(c);
            isNewWord=false;
        }
        if(isspace(c)){
            isNewWord=true;
        }
    }
    code[codeindex] = '\0';
}
<<<<<<< HEAD
=======

>>>>>>> 7dfe74da9f5dcac9291b11504172cb884be86bf6
mathang kho[100];
int demhang=0;
void taokho() {
    // khởi tạo các mặt hàng có sẵn trong kho 
     strcpy(kho[0].tenhang, "Kem danh rang");
    kho[0].soluong = 10;
    kho[0].giathanh = 35000;
    generatecode(kho[0].tenhang,kho[0].code);

    strcpy(kho[1].tenhang, "Sua tam");
    kho[1].soluong = 20;
    kho[1].giathanh = 75000;
    generatecode(kho[1].tenhang,kho[1].code);

    strcpy(kho[2].tenhang, "Ban chai");
    kho[2].soluong = 100;
    kho[2].giathanh = 45000;
    generatecode(kho[2].tenhang,kho[2].code);

    strcpy(kho[3].tenhang, "Khau trang");
    kho[3].soluong = 2000;
    kho[3].giathanh = 100000;
    generatecode(kho[3].tenhang,kho[3].code);

    strcpy(kho[4].tenhang, "My pham");
    kho[4].soluong = 250;
    kho[4].giathanh = 500000;
    generatecode(kho[4].tenhang,kho[4].code);

    strcpy(kho[5].tenhang, "Dau goi dau");
    kho[5].soluong = 200;
    kho[5].giathanh = 180000;
    generatecode(kho[5].tenhang,kho[5].code);

    strcpy(kho[6].tenhang, "Kem chong nang");
    kho[6].soluong = 150;
    kho[6].giathanh = 250000;
    generatecode(kho[6].tenhang,kho[6].code);

    strcpy(kho[7].tenhang, "Sua rua mat");
    kho[7].soluong = 100;
    kho[7].giathanh = 180000;
    generatecode(kho[7].tenhang,kho[7].code);

    strcpy(kho[8].tenhang, "Xa phong");
    kho[8].soluong = 1000;
    kho[8].giathanh = 150000;
    generatecode(kho[8].tenhang,kho[8].code);

    strcpy(kho[9].tenhang, "Serum");
    kho[9].soluong = 20000;
    kho[9].giathanh = 100000; 
    generatecode(kho[9].tenhang,kho[9].code);
    
    demhang = 10;
}
int somathang(){
    return demhang;
}
<<<<<<< HEAD
int main(){
    printf("Xin chao cac ban");
=======
int cnt(int n){ //Hàm tính độ dài của 1 số để căn lề bẳng sản phẩm
    int count = 1;
    if(n == 0){
        return 2;
    }
    while(n){
        count++;
        n /= 10;
    }
    return count;
}
// Hàm tính tổng tiền 1 mặt hàng
long long costofwh(){
    long long cost = 0;
    for(int i = 0; i < somathang(); i++){
        cost += kho[i].soluong * kho[i].giathanh;
    }
    return cost;
}
void hienthi(int n){
   printf(CYAN);
    printf("$_____$_______$________________________$_________________$__________________$\n");
    printf("| STT | CODE  |    THE PRODUCT NAME    |  THE QUANTITY   |   COST/1item($)  |\n");

    for (int i = 0; i < n; i++) {
        if (strlen(kho[i].tenhang) == 0) continue;  // Chỉ hiển thị mặt hàng có tên

        if (i < 10) {
            printf("|  %d  |", i);
        } else if (i >= 10 && i < 100) {
            printf("|  %d |", i);
        } else if (i == 100) {
            printf("|%d|", i);
        }

        int ma = strlen(kho[i].code);
        printf(" %s%*s|", kho[i].code, 6 - ma, "");

        int a = strlen(kho[i].tenhang);
        printf("%s%*s|", kho[i].tenhang, 24 - a, "");

        int b = cnt(kho[i].soluong);
        printf("%d%*s|", kho[i].soluong, 18 - b, "");

        char gia_str[20];
        sprintf(gia_str, "%.2f", kho[i].giathanh);
        int c = strlen(gia_str);
        printf("%s%*s|\n", gia_str, 18 - c, "");
    }

    printf("$-----$-------$------------------------$-----------------$------------------$\n");
    printf(RESET);
    printf(YELLOW "Tong so tien hang co trong kho bay gio la: %.2lld" RESET "\n\n", costofwh());

    for (int i = 0; i < n; i++) {
        if (kho[i].soluong < 20 && strlen(kho[i].tenhang) != 0) {
            printf(RED "INFORM: Mat hang '%s' trong kho qua it de duy tri nhu cau\n" RESET, kho[i].tenhang);
        }
    }
}
void logOperation(const char* operation) {
    FILE* logFile = fopen("log.txt", "a");
    if (logFile != NULL) {
        fprintf(logFile, "%s\n", operation);
        fclose(logFile);
    }
}
void nhap(mathang *a){
// Xóa bộ đệm đầu vào để tránh vấn đề với hàm fgets
    while(getchar() != '\n');
    printf("Nhap ten loai mat hang: ");
    fgets(a->tenhang, 100, stdin);
    // Loại bỏ ký tự newline nếu có
    size_t len = strlen(a->tenhang);
    if (len > 0 && a->tenhang[len-1] == '\n') {
        a->tenhang[len-1] = '\0';
    }
    printf("Nhap so luong san pham nhap vao kho: ");
    scanf("%d", &(a->soluong));
    printf("Nhap gia tien tren mot san pham: ");
    scanf("%lf", &(a->giathanh));
    getchar();
    generatecode(a->tenhang,a->code);
}
void xuatkho(){
    int n;
    printf("Nhap so luong mat hang can xuat kho: ");
    scanf("%d",&n);
    getchar();  // Xóa ký tự newline sau khi nhập số lượng
    for (int i = 0; i < n; i++) {
        char code[100];
        printf("Nhap ma san pham %d: ", i + 1);
        fgets(code, sizeof(code), stdin);
        code[strcspn(code, "\n")] = '\0';  // Loại bỏ ký tự newline nếu có
        bool found = false;
        for (int j = 0; j < somathang(); j++) {
            if (strcmp(kho[j].code, code) == 0) {
                found = true;
                bool checkname = false;
                if (j > 0 && strcmp(kho[j].code, kho[j - 1].code) == 0) {
                    continue;
                }
                if (j < somathang() - 1 && strcmp(kho[j].code, kho[j + 1].code) == 0) {
                    printf("Co nhieu mat hang cung ma code, vui long nhap day du ten mat hang: ");
                    char name[100];
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = '\0';
                    for (int k = j; k < somathang(); k++) {
                        if (strcmp(kho[k].tenhang, name) == 0 && strcmp(kho[k].code, code) == 0) {
                            checkname = true;
                            printf("Ten hang: %s\n", kho[k].tenhang);
                            printf("So luong: %d\n", kho[k].soluong);
                            printf("Gia: %.2lf\n", kho[k].giathanh);
                            int quantity;
                            do {
                                printf("Nhap so luong can xuat: ");
                                scanf("%d", &quantity);
                                getchar();

                                if (quantity > 0 && quantity <= kho[k].soluong) {
                                    kho[k].soluong -= quantity;
                                    printf("Da xuat %d san pham.\n", quantity);
                                    break;
                                } else {
                                    printf("So luong nhap vao khong hop le hoac khong du so luong trong kho. Vui long nhap lai.\n");
                                }
                            } while (true);
                            break;
                        }
                    }
                    if (!checkname) {
                        printf("Khong tim thay mat hang.\n");
                    }
                } else {
                    printf("Ten hang: %s\n", kho[j].tenhang);
                    printf("So luong: %d\n", kho[j].soluong);
                    printf("Gia thanh: %.2lf\n", kho[j].giathanh);
                    int quantity;
                    do {
                        printf("Nhap so luong can xuat: ");
                        scanf("%d", &quantity);
                        getchar();
                        if (quantity > 0 && quantity <= kho[j].soluong) {
                            kho[j].soluong -= quantity;
                            printf("Da xuat %d san pham.\n", quantity);
                            break;
                        } else {
                            printf("So luong nhap vao khong hop le hoac khong du so luong trong kho. Vui long nhap lai.\n");
                        }
                    } while (true);
                }
            }
        }
        if (!found) {
            printf("Khong tim thay san pham voi ma nay. Vui long nhap lai.\n");
            i--;
        }
    }
    printf("CAP NHAT KHO HANG HIEN TAI\n");
    hienthi(somathang());
}
void nhapkho(){
    printf("So mat hang co trong kho la: %d\n", somathang());
    printf("SO LUONG MAT HANG MUON THEM VAO KHO: ");
    int n;
    char code[20];
    scanf("%d", &n);
    int check = 0;
    printf("________________LUA CHON NHAP KHO_________________\n");
    printf("|  1.NHAP HANG DA CO TRONG KHO                    |\n");
    printf("|  2.NHAP HANG MOI CHUA CO TRONG KHO              |\n");
    printf("!_________________________________________________!\n");
    scanf("%d", &check);

    if (check == 1) {
        for (int i = 0; i < n; i++) {
            printf("Nhap ma san pham: ");
            scanf("%s", code);
            getchar(); // xóa bỏ kí tự newline khỏi bộ đệm

            int found = 0;
            for (int j = 0; j < somathang(); j++) {
                if (strcmp(kho[j].code, code) == 0) {
                    found = 1;
                    int checkname = 0;

                    if (j > 0 && strcmp(kho[j].code, kho[j - 1].code) == 0) {
                        continue;
                    }

                    if (j < somathang() - 1 && strcmp(kho[j].code, kho[j + 1].code) == 0) {
                        printf(RED "Co nhieu mat hang cung ma don hang, vui long nhap day du ten mat hang: " RESET);
                        char Name[100];
                        fgets(Name, sizeof(Name), stdin);
                        Name[strcspn(Name, "\n")] = 0; // xóa bỏ kí tự newline

                        for (int k = j; k < somathang(); k++) {
                            if (strcmp(kho[k].tenhang, Name) == 0 && strcmp(kho[k].code, code) == 0) {
                                checkname = 1;
                                printf("Ten hang: %s\n", kho[k].tenhang);
                                printf("So Luong: %d\n", kho[k].soluong);
                                printf("Gia: %lf" "\n", kho[k].giathanh);

                                int quantity;
                                while (1) {
                                    printf("Nhap so luong can them: ");
                                    scanf("%d", &quantity);
                                    getchar();
                                    kho[j].soluong += quantity;
                                    printf("Da nhap %d san pham." "\n", quantity);
                                    break;
                                }
                                break;
                            }
                        }
                        if (!checkname) {
                            printf(RED "Khong tim thay mat hang voi ten da nhap." RESET "\n");
                        }
                    } else {
                        printf("Ten hang: %s\n", kho[j].tenhang);
                        printf("So luong: %d\n", kho[j].soluong);
                        printf("Gia thanh: %lf" RESET "\n", kho[j].giathanh);

                        int quantity;
                        while (1) {
                            printf(CYAN "Nhap so luong can nhap: ");
                            scanf("%d", &quantity);
                            getchar();
                            kho[j].soluong += quantity;
                            printf("Da nhap %d san pham." "\n", quantity);
                            break;
                        }
                        break;
                    }
                }
            }
            if (!found) {
                printf(RED "Khong tim thay san pham voi ma nay. Vui long nhap lai." RESET "\n");
                i--;
            }
        }

        printf(YELLOW "CAP NHAT KHO HANG HIEN TAI" RESET "\n");
        hienthi(somathang());

    } else if (check == 2) {
        for (int i = 0; i < n; i++) {
            printf("NHAP THONG TIN MAT HANG SO %d:\n", somathang());
            nhap(kho);
        }
        printf("CAP NHAT KHO HANG HIEN TAI\n");
        hienthi(somathang());
    }
}
int main (){
    taokho();
>>>>>>> 7dfe74da9f5dcac9291b11504172cb884be86bf6
    return 0;
}