#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

    #define CYAN "\x1B[36m"
    #define YELLOW "\x1B[33m"
    #define RED "\x1B[31m"
    #define RESET "\x1B[0m"

// Định nghĩa cấu trúc mathang
typedef struct {
    char tenhang[100];
    int soluong;
    double giathanh;
    char code[100];
} mathang;typedef struct {
    char tenhang[100];
    int soluong;
    double giathanh;
    char code[100];
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
void nhap(mathang *a,int n){
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
    char buffer[256];
    snprintf(buffer, sizeof(buffer),"       NHAP    Mat hang: %s      So luong: %d       Gia tien: %.2lf", kho[n].tenhang, kho[n].soluong, kho[n].giathanh);
    logOperation(buffer);
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
                        printf("Co nhieu mat hang cung ma don hang, vui long nhap day du ten mat hang: ");
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
                            printf("Khong tim thay mat hang voi ten da nhap.\n");
                        }
                    } else {
                        printf("Ten hang: %s\n", kho[j].tenhang);
                        printf("So luong: %d\n", kho[j].soluong);
                        printf("Gia thanh: %lf\n", kho[j].giathanh);

                        int quantity;
                        while (1) {
                            printf("Nhap so luong can nhap: ");
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
                printf("Khong tim thay san pham voi ma nay. Vui long nhap lai.\n");
                i--;
            }
        }

        printf("CAP NHAT KHO HANG HIEN TAI\n");
        hienthi(somathang());

    } else if (check == 2) {
        for (int i = 0; i < n; i++) {
            printf("NHAP THONG TIN MAT HANG SO %d:\n", somathang() + i);
            nhap(&kho[demhang + i],n);
        }
        demhang+=n;
        printf("CAP NHAT KHO HANG HIEN TAI\n");
        hienthi(somathang());
}
}
void sapxep(mathang *kho,int n){
    int luachon;
    printf("Sap xep san pham\n");
    printf("Chon 1: xap xep theo gia thanh\n");
    printf("Chon 2: xap sep theo so luong\n");
    while (true){
    scanf("%d",&luachon);
    if(luachon==1){
        int chon;
        printf("1. Tang dan\n");
        printf("2. Giam dan\n");
        while (true){
        scanf("%d",&chon);
        if(chon==1){
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(kho[i].giathanh>kho[j].giathanh){
                        mathang temp=kho[i];
                        kho[i]=kho[j];
                        kho[j]=temp;
                    }
                }
            }
            hienthi(n);
            break;
        }
        if(chon==2){
             for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(kho[i].giathanh<kho[j].giathanh){
                        mathang temp=kho[i];
                        kho[i]=kho[j];
                        kho[j]=temp;
                    }
                }
            }
            hienthi(n);
            break;
        }
        else printf("Lua chon khong hop le vui long nhap lai\n");
        }
        break;
    }
    if(luachon==2){
        int chon;
        printf("1. Tang dan\n");
        printf("2. Giam dan\n");
        while(true){
        scanf("%d",&chon);
        if(chon==1){
             for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(kho[i].soluong>kho[j].soluong){
                        mathang temp=kho[i];
                        kho[i]=kho[j];
                        kho[j]=temp;
                    }
                }
            }
            hienthi(n);
            break;
        }
        if(chon==2){
             for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(kho[i].soluong<kho[j].soluong){
                        mathang temp=kho[i];
                        kho[i]=kho[j];
                        kho[j]=temp;
                    }
                }
            }
            hienthi(n);
            break;
        }
        else printf("Lựa chọn không hợp lệ vui lòng nhập lại\n");
        break;
        }
    }
    else {
        printf("Lựa chọn không hợp lệ vui lòng nhập lại\n");
    }
   }
}
void baomat() {
    char a[] = "alester";
    char b[] = "top1thaibinh";
    printf("LOG IN(Use the English keyboard to type.)\n");
    while(1) {
        printf("User name:");
        char tk[100];
        scanf("%s", tk);
        if(strcmp(a, tk) != 0) {
            printf("Wrong account, please enter again.\n");
            continue;
        }
        else {
            printf("Password:");
            char mk[100];
            scanf("%s", mk);
            if(strcmp(b, mk) != 0) {
                printf("Wrong password, please re-enter.\n");
                continue;
            }
            else {
                break;
            }
        }
    }
}
void clearLogFile() {
    FILE *logFile = fopen("log.txt", "w");
    if (logFile != NULL) {
        fclose(logFile);
    } else {
        printf("Unable to open log file.\n");
    }
}
void timee(char* timeStr, int maxSize) {
    time_t now = time(0);
    struct tm *ltm = localtime(&now);

    snprintf(timeStr, maxSize, "Ngay: %02d/%02d/%04d Luc: %02d:%02d:%02d",
             ltm->tm_mday,
             ltm->tm_mon + 1,
             ltm->tm_year + 1900,
             ltm->tm_hour + 1,
             ltm->tm_min + 1,
             ltm->tm_sec + 1);
}
void showlog() {
    FILE *logFile = fopen("log.txt", "r");
    if (logFile != NULL) {
        char line[256];
        while (fgets(line, sizeof(line), logFile)) {
            printf("%s", line);
        }
        fclose(logFile);
    } else {
        printf("Unable to open log file.\n");
    }
}
void deletefile() {
    FILE *logFile = fopen("log.txt", "w");
    if (logFile != NULL) {
        fclose(logFile);
    }
}
void laythongtinsanpham() {
    
    char code[100];
    printf("Nhap ma san pham: ");
    scanf("%s",code);
    bool found = false;
    for (int i = 0; i < somathang(); i++) {
        if (strcmp(kho[i].code, code) == 0) {
            found = true;
            printf("Ten hang: %s\n", kho[i].tenhang);
            printf("So luong: %d\n", kho[i].soluong);
            printf("Gia thanh: %.2f\n", kho[i].giathanh);
        }
    }
    if (!found) {
        printf("Khong tim thay san pham voi ma nay.\n");
    }
}
void initialize_empty_item(mathang *item) {
    strcpy(item->tenhang, "");
    item->soluong = 0;
    item->giathanh = 0;
    strcpy(item->code, "");
}
void xoakho(){
  char code[100];
    int n;

    printf("Nhap so luong mat hang xoa khoi kho: ");
    scanf("%d", &n);
    getchar(); // Đọc ký tự newline còn lại

    for (int i = 0; i < n; i++) {
        printf("Nhap ma san pham %d: ", i + 1);
        fgets(code, sizeof(code), stdin);
        code[strcspn(code, "\n")] = '\0'; // Loại bỏ ký tự newline

        bool found = false;
        for (int j = 0; j < somathang(); j++) {
            if (strcmp(kho[j].code, code) == 0) {
                found = true;

                bool checkname = false;
                if (j < somathang() - 1 && strcmp(kho[j].code, kho[j + 1].code) == 0) {
                    printf("Co nhieu mat hang cung ma don hang, vui long nhap day du ten mat hang: ");
                    char Name[100];
                    fgets(Name, sizeof(Name), stdin);
                    Name[strcspn(Name, "\n")] = '\0'; // Loại bỏ ký tự newline

                    for (int k = j; k < somathang(); k++) {
                        if (strcmp(kho[k].tenhang, Name) == 0 && strcmp(kho[k].code, code) == 0) {
                            checkname = true;
                            printf("Ten hang: %s\n", kho[k].tenhang);
                            printf("So Luong: %d\n", kho[k].soluong);
                            printf("Gia: %lf\n", kho[k].giathanh);
                            printf("Da xoa san pham %s khoi kho.\n", kho[k].tenhang);

                            for (int l = k; l < somathang() - 1; ++l) {
                                kho[l] = kho[l + 1];
                            }

                            initialize_empty_item(&kho[somathang() - 1]);
                            break;
                        }
                    }
                    if (!checkname) {
                        printf("Khong tim thay mat hang voi ten da nhap.\n");
                    }
                } else {
                    printf("Ten hang: %s\n", kho[j].tenhang);
                    printf("So luong: %d\n", kho[j].soluong);
                    printf("Gia thanh: %lf\n", kho[j].giathanh);
                    for (int l = j; l < somathang() - 1; ++l) {
                        kho[l] = kho[l + 1];
                    }

                    initialize_empty_item(&kho[somathang() - 1]);
                    break;
                }
            }
        }
        if (!found) {
            printf("Khong tim thay san pham voi ma nay. Vui long nhap lai.\n");
            i--; // Nhập lại khi không tìm thấy sản phẩm
        }
    }

    printf("CAP NHAT KHO HANG HIEN TAI\n");
    hienthi(somathang());
}

int main (){
    deletefile();
    char timeMsg[100];
    timee(timeMsg,sizeof(timeMsg));
    logOperation(timeMsg);
    logOperation("     Dang nhap vao he thong");
    taokho();
     while(1){
        printf("______WELCOME TO THE WAREHOUSE MANAGEMENT SYSTEM______\n");
        printf("|  1.XEM THONG TIN MAT HANG TON KHO                  |\n");
        printf("|  2.XUAT KHO                                        |\n");
        printf("|  3.NHAP HANG VAO KHO                               |\n");
        printf("|  4.SAP XEP THEO YEU CAU                            |\n");
        printf("|  5.KIEM TRA HANG THEO MA SAN PHAM                  |\n");
        printf("|  6.XEM LICH SU XUAT NHAP HANG                      |\n");
        printf("|  7.XOA HANG TRONG KHO                              |\n");
        printf("|  8.DIEU CHINH GIA CAC MAT HANG                     |\n");
        printf("|  0.EXIT THE SYSTEM.                                |\n");
        printf("!____________________________________________________!\n");
        printf("SELECT OPTION: ");
        int lc;
        scanf("%d",&lc);
        if(lc == 1){
            hienthi(somathang());
        }
        else if(lc == 2){
            char timeMsg[100];
            timee(timeMsg,sizeof(timeMsg));
            logOperation(timeMsg);
            xuatkho();
        }
        else if(lc == 3){
            char timeMsg[100];
            timee(timeMsg,sizeof(timeMsg));
            logOperation(timeMsg);
            nhapkho();
        }
        else if(lc == 4){
            sapxep(kho,somathang());
        }
        else if(lc == 5){
            laythongtinsanpham();
        }
        else if(lc==6){
            printf("Lich su nhap & xuat hang trong ngay hom nay\n");
            showlog();
            printf("\n");
        }
        else if(lc==7){
            xoakho();
        }
        else if(lc==8){
            dieuchinhgia();
        }
        else if(lc==0){
            deletefile();
            printf("***** HE THONG DA DONG *****");
            return 0;
        }
        else {
            printf("Lua chon khong họp le vui long nhap lai ");
            return 0;

        }
    }
    return 0;
}