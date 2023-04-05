#include <stdio.h>

//구조체 선언: 구조체를 자료형으로 변수를 선언할 때, 'struct student1 변수명 = {};'으로 선언해야함.
struct student1 {
    char lastName;
    int studentId;
    char grade;
};

//typedef 구조체 선언: 구조체를 자료형으로 변수를 선언할 때, 'student2 변수명 = {};'으로 struct를 쓰지 않아도 선언됨.
typedef struct {
    char lastName;
    int studentId;
    char grade;
} student2;


int main() {
    struct student1 st1 = {'A', 100, 'A'};           //구조체로 선언한 student1형 변수를 {'A', 100, 'A'}로 초기화하여 st1로 선언
    printf("st1.lastName = %c\n", st1.lastName);     //st1의 lastName 출력: A
    printf("st1.studentId = %d\n", st1.studentId);   //st1의 studentId 출력: 100
    printf("st1.grade = %c\n", st1.grade);           //st1의 grade 출력: A


    student2 st2 = {'B', 200, 'B'};                  //구조체로 선언한 student2형 변수를 {'A', 100, 'A'}로 초기화하여 st1로 선언
    printf("\nst2.lastName = %c\n", st2.lastName);   //st2의 lastName 출력: B
    printf("st2.studentId = %d\n", st2.studentId);   //st2의 studentId 출력: 200
    printf("st2.grade = %c\n", st2.grade);           //st2의 grade 출력: B


    student2 st3; //구조체로 선언한 student2형 변수를 str3로 선언
    st3 = st2;    //str2의 값들을 st3에 대입
    printf("\nst3.lastName = %c\n", st3.lastName);   //st3의 lastName 출력: B, st2의 lastName과 일치
    printf("st3.studentId = %d\n", st3.studentId);   //st3의 studentId 출력: 200, st2의 studentId와 일치
    printf("st3.grade = %c\n", st3.grade);           //st3의 grade 출력: B, st2의 grade와 일치


    //C언어에서 구조체는 같은 구조체 타입이라고 하더라도, 두 개의 변수 자체를 직접 비교하는 게 불가능. 
    //따라서 구조체 요소들 자체를 비교해야한다. 

    /* 
    위와 같은 이유로 아래 코드는 에러가 뜬다.
    if(st3 == st2) 
        printf("equal\n");
    else
        printf("not equal\n");
    */

   //구조체 비교는 다음과 같이 구조체 각각의 요소를 비교해주어야한다.
    if((st3.lastName == st2.lastName) && (st3.studentId == st2.studentId) && (st3.grade == st2.grade))
        printf("\nequal\n");
    else
        printf("\nnot equal\n");


    return 0;
}