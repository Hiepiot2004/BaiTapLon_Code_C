#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>


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
int main(){
    printf("Xin chao cac ban");
    return 0;
}