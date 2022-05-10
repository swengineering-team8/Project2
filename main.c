#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main(){
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(){
    	char path[] = "text1";
	int res = stat(path,&stat1);
	if(res == -1)
		printf("Erorr: %s exists.\n", path);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
    	char path[] = "text2";
	int res = stat(path,&stat2);
	if(res == -1)
		printf("Erorr: %s exists.\n", path);
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
     	time1=localtime(&stat1.st_mtime); 
        printf("%04d-%02d-%02d %02d:%02d\n", 
                time1->tm_year+1900, time1->tm_mon+1, 
                time1->tm_mday, time1->tm_hour, 
                time1->tm_min);   
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
            time2=localtime(&stat2.st_mtime); 
        printf("%04d-%02d-%02d %02d:%02d\n", 
                time2->tm_year+1900, time2->tm_mon+1, 
                time2->tm_mday, time2->tm_hour, 
                time2->tm_min);
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
    printf("\n");
    printf("size compare\n");
    if((int)stat1.st_size > (int)stat2.st_size){
        printf("text1 is bigger\n"); 
    }
    else if((int)stat1.st_size < (int)stat2.st_size){
        printf("text2 is bigger\n"); 
    }
    else{
        printf("sizes are equal\n");         
    }
    printf("\n");
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
    printf("block compare\n");
    if((int)stat1.st_blocks > (int)stat2.st_blocks){
        printf("text1 is bigger\n");
    }
    else if((int)stat1.st_blocks < (int)stat2.st_blocks){
        printf("text2 is bigger\n");
    }
    else{
        printf("sizes are equal\n"); 
    }
    printf("\n");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
    
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
    
}
