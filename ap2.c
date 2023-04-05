#include <stdio.h>
#include <stdlib.h>

int  main()
{
    int list[5];    //크기가 5인 정수형 배열 선언
    int *plist[5];  //크기가 5인 정수형 포인터 배열 선언


    list[0] = 10;    //list[0] 인덱스 원소에 10 대입
    list[1] = 11;    //list[1] 인덱스 원소에 11 대입
    plist[0] = (int*)malloc(sizeof(int));  //plist[0] 인덱스 원소에 정수형으로 4byte 크기의 동적 메모리 할당

    printf("\n\n[----- [박미라] [2020069006] -----]\n\n");

    printf("list[0] \t= %d\n", list[0]);     //list[0]에 저장된 값: 10
    //list == &list == &list[0]: 배열의 이름은 그 배열의 첫 인덱스 주소,배열 이름의 주소와 같다. 
    printf("list \t\t= %p\n", list);         
    printf("&list[0] \t= %p\n", &list[0]);

    //list[a]의 주소 == list + a: 배열의 이름은 그 배열의 첫 주소이고, 주소에서 +a은 그 포인터가 가리키는 (자료형의 크기*a)만큼 증가하기 때문이다.
    printf("list + 0 \t= %p\n", list+0);     //list + 0 == &list[0]+0: &list[0]
    printf("list + 1 \t= %p\n", list+1);     //list + 1 == &list[0]+1: &list[1]
    printf("list + 2 \t= %p\n", list+2);     //list + 2 == &list[0]+2: &list[2]
    printf("list + 3 \t= %p\n", list+3);     //list + 3 == &list[0]+3: &list[3]
    printf("list + 4 \t= %p\n", list+4);     //list + 4 == &list[0]+4: &list[4]
    printf("&list[4] \t= %p\n", &list[4]);   //&list[0]+0 == list + 4: &list[4]


    free(plist[0]); //동적할당을 했을 경우, 사용을 다했으면 꼭! free()를 사용해 동적할당을 해제해야한다. 그래야 메모리 누수를 막을 수 있기 때문이다.

    return 0;
}