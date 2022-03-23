#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
#include <string.h>

FILE* report;
FILE* record;
static char date[64];

typedef struct lotto {
    int lotto_no;
    int lotto_receipt;
    int emp_id;
    char lotto_date[128];
    char lotto_time[128];
} lotto_record;

void cuttime(){ 
	time_t now = time(0);
	strftime(date, 100, "%Y%m%d", localtime(&now));
}

int main() {
    
    report = fopen ("report.txt","w+");
    record = fopen("record.bin","r");
    lotto_record tmp[256];
    int i = 0;
    while(fread(&tmp[i], sizeof(lotto_record), 1, record)){
		i++;
	}	
	i-=1; // 因為剛剛會多加一個

    int no = 0; 
	int datesum = 0, nosum, setsum = 0, receiptsum = 0;
	int j = 0;
	
	fprintf(report,"========= lotto649 Report =========\n");
    fprintf(report,"- Date ------ Num. ------Receipt -\n");
    
    while(j<=i){
		int set = 0; //組數
		int receipt = 0;
		while(strcmp(tmp[j].lotto_date,tmp[j+1].lotto_date) == 0){ //字串比對 如果相同 =0
			set = set + (tmp[j].lotto_receipt/55);
			receipt = receipt + tmp[j].lotto_receipt;
			j++;
		}
		set = set + (tmp[j].lotto_receipt/55);
		receipt = receipt + tmp[j].lotto_receipt;
		no = tmp[j].lotto_no - no;
		datesum ++;
		printf("%d",no);
		setsum = setsum + set;
		receiptsum = receiptsum + receipt;
		fprintf(report, "%s\t%d/%d\t\t%d\n", tmp[j].lotto_date, no, set, receipt);
		no = tmp[j].lotto_no;
		j++;
    }
	
    fprintf(report,"-----------------------------------\n");
    fprintf(report,"\t%d\t%d/%d\t\t%d\n", datesum, tmp[i].lotto_no, setsum, receiptsum);
    cuttime();
    fprintf(report,"======== %s Printed =========", date);
    

    fclose(report);
    fclose(record);

    return 0;
}
