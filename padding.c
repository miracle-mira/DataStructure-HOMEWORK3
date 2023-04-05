#include <stdio.h>

//구조체 선언
struct student {
    char lastName[13]; //크기가 13인 문자형 배열 선언
    int studentId;     //정수(int,4byte) 변수 선언
    short grade;       //정수(short,2byte) 변수 선언
};


int main()
{
    struct student pst;  //구조체로 선언한 student형 pst 변수 선언
    
    /*
    상식적으로 구조체를 선언했을 때, 13byte(char형 크기 13) + 4byte(studentID) + 2byte(grade) = 19byte라고 생각하지만,
    padding처리로 인해 4의 배수만큼 데이터가 차게된다.
    따라서, 13byte는 16byte로, 4byte는 그대로 4byte, 2byte는 4byte로 패딩된다. == 24byte
    */
    printf("size of student = %ld\n", sizeof(struct student));   

    printf("size of int = %ld\n", sizeof(int));                  //int 자료형의 크기는 4byte
    printf("size of short = %ld\n", sizeof(short));              //short 자료형의 크기는 2byte

    return 0;
}