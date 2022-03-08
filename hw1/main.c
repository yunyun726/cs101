
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void print_num(int ran,int i,FILE *fp) {
    int lotto[6]={0};
    int special,num;
    ran+=i; //因為執行時間太短 所以要加 i
    fprintf(fp,"[%d]:",i);
    srand(ran);
    for (int k=0;k<6;k++) {
        num=rand()%69+1; // +1是因為從1開始
        lotto[k]=num;
        for (int m=0;m<k;m++) {
            if(lotto[k]==lotto[m]) {
                k-=1;
                break; // 如果數字重複了 就讓他回去重跑
            }
        }
    }
    for (int a=0;a<5;a++) {
        for(int b=a+1;b<6;b++) {
            if (lotto[a]>lotto[b]) {
                int temp;
                temp = lotto[a];
                lotto[a]=lotto[b];
                lotto[b]=temp; // 排序
            }
        }
    }
    for(int k=0;k<6;k++) fprintf(fp,"%02d ",lotto[k]);
    special=rand()%10+1;
    fprintf(fp,"%02d \n",special);
}

void print_none(int i,FILE *fp) {
    fprintf(fp,"[%d]:",i);
    for (int k=1;k<=7;k++) fprintf(fp,"-- ");
    fprintf(fp,"\n");
}


int main() {
    FILE *fp;
    printf("歡迎光臨長庚樂透彩購買機台\n請問您要購買幾組樂透彩：");
    int n,ran;
    scanf("%d",&n);
    fp=fopen("lotto.txt","w+");
    fprintf(fp,"========= lotto649 =========\n");
    time_t curtime;
    time(&curtime);
    char* dte=ctime(&curtime);
    size_t len = strlen(dte);
    dte[len-1]='\0'; // 因為time最後會自動換行所以要把它改為結束位元
    fprintf(fp,"= %s =\n",dte);
    srand((unsigned)time(NULL));
    ran=rand();
    for(int i=1;i<=5;i++) {
        if(i<=n) print_num(ran,i,fp);
        else print_none(i,fp);
    }
    
    fprintf(fp,"========= csie@CGU =========");
    fclose(fp);
    printf("已為您購買的 %d 組樂透組合輸出至 lotto.txt",n);
    
    return 0;
}