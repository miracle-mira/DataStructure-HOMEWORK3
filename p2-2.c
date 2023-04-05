#include <stdio.h>
void print_one(int *ptr, int rows); //print_one 함수 선언: 반환은 하지 않으며, 매개변수는 정수형 포인터와 정수형 변수이다.


int main()
{
    int one[] = {0, 1, 2, 3, 4};        //크기가 5인 정수형 배열 선언 및 초기화
    //one == &one == &one[0]: 배열의 이름은 그 배열의 첫 인덱스 주소,배열 이름의 주소와 같다. 
    printf("one = %p\n", one);          
    printf("&one = %p\n", &one);
    printf("&one[0] = %p\n", &one[0]);


    printf("\n");

    //print_one함수를 같은 시작주소와 같은 정수로 호출했기 때문에 두 개의 출력값은 같다.
    printf("------------------------------------\n");
    printf(" print_one(&one[0], 5) \n");
    printf("------------------------------------\n");
    print_one(&one[0], 5);  //one배열 [0]인덱스 주소값과 5를 인자로 print_one 함수 호출


    printf("------------------------------------\n");
    printf(" print_one(one, 5) \n");
    printf("------------------------------------\n");
    print_one(one, 5);      //one배열의 이름, 즉 one 배열의 시작주소와 5를 인자로 print_one 함수 호출

    return 0;

}


void print_one(int *ptr, int rows){

    int i;  //정수형 변수 선언 
    printf ("Address \t Contents\n");

    /*
    ptr은 main()의 one 배열의 주소를 저장하고 있으며, rows는 5를 저장하고 있다.
    아래의 반복문은 ptr에 i를 더하고 있다. 이때, ptr은 주소를 담고 있기 때문에 ptr이 가리키고 있는 값의 (자료형*i)만큼 값이 커진다. 
    이때 가리키고 있는 값의 자료형이 int형이기 때문에 4만큼 증가한다.$
    */
    for (i = 0; i < rows; i++)
        printf("%p \t %5d\n", ptr + i, *(ptr + i));

    printf("\n");
}