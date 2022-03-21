
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

FILE* fp;
FILE* binfile;
FILE* records;
//FILE* operator_id;
static int currentcount;

void count() {
    int read[1];
    int write[1];
    if((binfile = fopen("binfile.bin", "r")) == NULL) { //讀現在binfile.txt 裡面現在是不是空的
        binfile = fopen("binfile.bin", "wb+"); // 如果是空的 就 開起編輯 讓他變1
        write[0] = 1;
        fwrite(write, sizeof(int), 1, binfile);
    } else {
        binfile = fopen("binfile.bin", "rb+"); // 其他狀況 打開binfile.txt 
        fseek(binfile, 0, SEEK_SET); // 從一開始開始
        fread(read, sizeof(int), 1, binfile); //讀一次
        fclose(binfile); // 關掉
        write[0] = read[0] + 1; //讓write 陣列第一個數為 剛剛讀到的數字 +1
        binfile = fopen("binfile.bin","wb+");
        fwrite(write, sizeof(int), 1, binfile);
    }
    fclose(binfile);
    currentcount = write[0];
}


void print_num(int ran,int i,FILE* fp) {
    int lotto[6] = {0};
    int special,num;
    ran+=i; //因為執行時間太短 所以要加 i
    fprintf(fp,"[%d]:",i);
    for (int k = 0; k < 6; k++) {
        num = rand()%69+1; // +1是因為從1開始
        lotto[k] = num;
        for (int m = 0; m<k; m++) {
            if (lotto[k]==lotto[m]) {
                k-=1;
                break; // 如果數字重複了 就讓他回去重跑
            }
        }
    }
    for (int a = 0; a<5; a++) {
        for (int b = a+1; b<6; b++) {
            if (lotto[a] > lotto[b]) {
                int temp;
                temp = lotto[a];
                lotto[a] = lotto[b];
                lotto[b] = temp; // 排序
            }
        }
    }
    for (int k = 0; k<6; k++) fprintf(fp,"%02d ",lotto[k]);
    special = rand()%10+1;
    fprintf(fp,"%02d \n",special);
}

void print_none(int i,FILE* fp) {
    fprintf(fp,"[%d]:",i);
    for (int k=1;k<=7;k++) fprintf(fp,"-- ");
    fprintf(fp,"\n");
}


int main() {
    FILE* operator_id;
    int n,b,ran,m,q;
    char name[128];

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請輸入操作人員ID：");
    scanf("%d",&b);

    int currentuser[80];
    char currentname[80];
    int arr_write[99999] = {0};
    int arr_read[99999];
    count();
    
    typedef struct employee {
        int emp_id;
        char emp_name[128];
        int emp_salary;
    } emp_record;
    
    if (b == 0) {
        printf("請輸入要新增操作人員 ID (1-99)：");
        scanf("%d",&m);
        printf("請輸入要新增操作人員 Name：");
        scanf("%s",name);
        printf("請輸入要新增操作人員 Salary：");
        scanf("%d",&q);
        printf("輸入完成");
        emp_record emp_record_t;
        emp_record_t.emp_id = m;
        strcpy( emp_record_t.emp_name, name ); //不用 & 是因為
        emp_record_t.emp_salary = q;
        operator_id = fopen("operator_id.bin","ab");
        fwrite(&emp_record_t, sizeof(int), 1, operator_id);
        fclose(operator_id);
        
    } else {
    printf("請問您要購買幾組樂透彩：");
    scanf("%d",&n);
    fp = fopen("operator_id.bin","wb+");
    fwrite(currentname, sizeof(int), 1, fp);
    
    sprintf(currentname, "lotto[%04d].txt",currentcount);
    //fp = fopen("lotto.txt","w+");
    fp = fopen(currentname,"w+");
    fprintf(fp,"========= lotto649 =========\n");
    //fclose(fp);
    
    
    time_t curtime;
    time(&curtime);
    char* dte=ctime(&curtime);
    size_t len = strlen(dte);
    dte[len-1]='\0'; // 因為time最後會自動換行所以要把它改為結束位元
    fprintf(fp,"= %s =\n",dte);
    fprintf(fp,"========+ No.%05d +========\n",currentcount);
    srand((unsigned)time(NULL));
    ran = rand();
    for (int i=1;i<=5;i++) {
        if (i<=n) print_num(ran,i,fp);
        else print_none(i,fp);
    }
    fprintf(fp,"========* Op.%05d *========\n",b);
    fprintf(fp,"========= csie@CGU =========");
    fclose(fp);
    printf("已為您購買的 %d 組樂透組合輸出至 lotto.txt",n);
    
    typedef struct lotto {
        int lotto_no;
        int lotto_retceipt;
        int emp_id;
        char lotto_date[128];
        char lotto_time[128];
    } lotto_record;
    char date[32];
    char ttime[32];
    time_t now = time(0);
    strftime (date, 32, "%Y%m%d", localtime(&now));
    strftime (ttime, 32, "%H:%M:%S", localtime(&now));
    lotto_record lotto_record_t;
    lotto_record_t.lotto_no = currentcount;
    lotto_record_t.lotto_retceipt = n*50*1.1;
    lotto_record_t.emp_id = b;
    strcpy(lotto_record_t.lotto_date, date);
    strcpy(lotto_record_t.lotto_time, ttime);
    records = fopen ("records.bin","ab");
    fwrite(&lotto_record_t, sizeof(int), 1, records); //& 是因為記憶體位置
    fclose(records);
    
    }
    
    return 0;
}
