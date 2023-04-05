#include<stdio.h>
#include<stdlib.h>

int main()
{
    int **x;  //정수형 이중포인터 선언

    printf("sizeof(x) = %lu\n", sizeof(x));       //x는 이중 포인터이므로 주소를 저장한다. 주소는 64bit 기준, 8byte이므로 x의 크기는 8이다. 
    printf("sizeof(*x) = %lu\n", sizeof(*x));     //x는 이중 포인터이므로 *x 또한 주소를 저장한다. 그러므로 64bit 기준, 8byte이다.
    printf("sizeof(**x) = %lu\n", sizeof(**x));   //x는 이중 포인터로 정수형 포인터이다. **x는 정수형 값을 가리키기 때문에 4byte이다. 

    return 0;
}