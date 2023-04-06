#include <stdio.h>
#include <stdlib.h>
int main()
{
    int list[5];               //크기가 5인 정수형 배열 선언
    int *plist[5] = {NULL,};   //크기가 5인 정수형 포인터 배열 선언한 뒤, 모든 배열 원소를 NULL(정수형 0)값으로 초기화 했다.


    plist[0] = (int *)malloc(sizeof(int)); //plist[0] 인덱스 원소에 정수형으로 4byte 크기의 동적 메모리 할당
    list[0] = 1;     //list[0] 인덱스 원소에 1 대입
    list[1] = 100;   //list[1] 인덱스 원소에 100 대입
    *plist[0] = 200; //plist[0]는 동적 메모리를 할당 했는데, 역참조를 이용해 그 동적 메모리에 200을 대입함. 


    printf("\n\n[----- [박미라] [2020069006] -----]\n\n");


    printf("list[0] = %d\n", list[0]);    //list[0]에 저장된 값: 1
    //list == &list == &list[0]: 배열의 이름은 그 배열의 첫 인덱스 주소,배열 이름의 주소와 같다. 
    printf("&list[0] = %p\n", &list[0]);  //list == &list == &list[0]
    printf("list = %p\n", list);          //list == &list == &list[0]  
    printf("&list = %p\n", &list);        //list == &list == &list[0]  


    printf("----------------------------------------\n\n");


    printf("list[1] = %d\n", list[1]);         //list[1]에 저장된 값: 100
    //list[1]의 주소 == list + 1: 배열의 이름은 그 배열의 첫 주소이고, 주소에서 +1은 그 포인터가 가리키는 자료형의 크기만큼 증가하기 때문이다.
    printf("&list[1] = %p\n", &list[1]);       //list[1]의 주소     
    printf("*(list+1) = %d\n", *(list + 1));   //list+1은 주소값이고, 그 주소가 가리키는 곳의 값은, list[1]의 값이므로, 100이다. 
    printf("list+1 = %p\n", list+1);           //list[1]의 주소 == list + 1


    printf("----------------------------------------\n\n");


    //plist[0]은 정수형 4byte 크기의 동적 메모리가 할당된 곳의 주소값이 저장되어있다. 
    printf("*plist[0] = %d\n", *plist[0]);  //plist[0]이 갖고 있는 주소가 가리키는 곳의 값: 200
    printf("&plist[0] = %p\n", &plist[0]);  //&plist[0] == &plist == plist: 배열의 이름은 그 배열의 첫 인덱스 주소,배열 이름의 주소와 같다. 
    printf("&plist = %p\n", &plist);        //&plist[0] == &plist ==
    printf("plist = %p\n", plist);          //&plist[0] == &plist ==

    printf("plist[0] = %p\n", plist[0]);    //plist[0]은 동적 메모리가 할당된 주소값이 저장되어있다.
    //plist 배열을 선언할 때, 모든 값을 NULL(정수형 0)으로 초기화하였고, plist[0]을 제외한 나머지 원소들은 값이 변경되지 않았으므로, 초기값 그대로 '0'값이 저장되어있다. 
    printf("plist[1] = %p\n", plist[1]);    
    printf("plist[2] = %p\n", plist[2]);
    printf("plist[3] = %p\n", plist[3]);
    printf("plist[4] = %p\n", plist[4]);

    
    free(plist[0]); //동적할당을 했을 경우, 사용을 다했으면 꼭! free()를 사용해 동적할당을 해제해야한다. 그래야 메모리 누수를 막을 수 있기 때문이다.


    return 0;
}
