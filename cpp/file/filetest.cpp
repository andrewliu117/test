#include <stdio.h>

void initfile() {
    FILE* fp = fopen("b.txt", "wb");
    int ptr[100] = {0};
    fwrite(ptr, 4, 100, fp);
    fclose(fp);
}

void writecell() {
    FILE* fp = fopen("b.txt", "wb+");
    fseek(fp, 11 * 4, SEEK_SET);
    int i = 28;
    fwrite(&i, 4, 1, fp);
    fclose(fp);
}

void getcell() {
    FILE* fp = fopen("b.txt", "rb");
    fseek(fp, 11 * 4, SEEK_SET);
    int i = 0;
    fread(&i, 4, 1, fp);
    printf("the changed cell is: %d\n", i);
    fclose(fp);
}

void printblock() {
    FILE* fp = fopen("b.txt", "rb");
    int data[10];
    for (int i = 0; i < 10; i++) {
        fread(data, 4, 10, fp);
        for(int j = 0; j< 10; j++) {
            printf("%d ", data[j]);
        }
        printf("\n");
    }
    fclose(fp);
}

int main(void) {

    initfile();
    writecell();
    //getcell();
    //printblock();
}
