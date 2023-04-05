#include <stdio.h>
#define MAX_SIZE 100  //기호상수 MAX_SIZE 선언 



float sum1(float list[], int);  //sum1 함수 선언: 반환형은 float형이며, 매개변수는 실수형 배열과 정수형 변수(변수명 따로 지정X)이다.
float sum2(float *list, int);   //sum2 함수 선언: 반환형은 float형이며, 매개변수는 실수형 포인터와 정수형 변수(변수명 따로 지정X)이다.
float sum3(int n, float *list); //sum3 함수 선언: 반환형은 float형이며, 매개변수는 정수형 변수와 실수형 포인터이다.(정수형 변수명 따로 지정하지 않아도 실행됨.)

float input[MAX_SIZE], answer;  //MAX_SIZE(100) 크기인 실수형 input 배열과 실수형 변수(answer)를 글로벌 변수로 선언
int i;                          //정수형 변수를 글로벌 변수로 선언


//sum1,sum2,sum3 모두 인자를 input 주소로 받았기 때문에 합은 다 똑같다.
int main(void)
{
    for(i=0; i < MAX_SIZE; i++)
        input[i] = i;
        //반복문을 사용하여, input 배열의 인덱스 값과 그 인덱스를 가진 배열 원소 값이 같게 초기화함: 즉, 인덱스 0이면 input[0]= 0

    printf("\n\n[----- [박미라] [2020069006] -----]\n\n");

    printf("--------------------------------------\n");
    printf(" sum1(input, MAX_SIZE) \n"); 
    printf("--------------------------------------\n");

    printf("input \t= %p\n", input);      //배열의 이름은 그 배열의 시작 주소를 의미함.

    answer = sum1(input, MAX_SIZE);       //input 배열의 시작 주소와, MAX_SIZE(100)를 인자로 sum1를 호출하였으며,
                                          //sum1은 input을 인자로 받은 매개변수 list의 배열원소들의 합을 반환해, 글로벌 변수 answer에 대입함.
    printf("The sum is: %f\n\n", answer); //현재, answer에 저장된 값, sum1의 반환값이 출력됨.



    printf("--------------------------------------\n");
    printf(" sum2(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");

    printf("input \t= %p\n", input);      //배열의 이름은 그 배열의 시작 주소를 의미함.

    answer = sum2(input, MAX_SIZE);       //sum2 함수 호출: input 주소와, MAX_SIZE(100)을 인자로 호출함.
                                          //sum2은 input을 인자로 받은 매개변수 list의 역참조의 합을 반환해, 글로벌 변수 answer에 대입함.

    printf("The sum is: %f\n\n", answer); //현재, answer에 저장된 값, sum2의 반환값이 출력됨.


    printf("--------------------------------------\n");
    printf(" sum3(MAX_SIZE, input) \n");
    printf("--------------------------------------\n");

    printf("input \t= %p\n", input);      //배열의 이름은 그 배열의 시작 주소를 의미함.
    answer = sum3(MAX_SIZE, input);       //sum3 함수 호출: MAX_SIZE(100)와 input 주소를 인자로 호출함.
                                          //sum3은 input을 인자로 받은 매개변수 list의 역참조의 합을 반환해, 글로벌 변수 answer에 대입함.

    printf("The sum is: %f\n\n", answer); //현재, answer에 저장된 값, sum2의 반환값이 출력됨.

    return 0;
}


float sum1(float list[], int n) {
//사실상 인자를 주소로 하여 sum1을 호출하지만, 그 인자가 배열이라는 것을 한 눈에 파악하기 위해, 매개변수는 배열로 설정한 것임. 어차피 배열의 첫 주소는 시작주소이니깐!
    //sum1은 main()의 list[]에 input을 인자로 받았다. input은 배열의 시작 주소이며, 이는 input의 주소가 list에 저장되었단 뜻이다. 즉, 참조에 의한 호출이다.
    printf("list\t= %p\n", list);      //list에 저장된 값: input 배열의 시작 주소
    printf("&list\t= %p\n\n", &list);  //list가 저장되어 있는 메모리 주소 값: input 주소가 주소를 저장하는 list에 대입된 것이므로 하나의 변수이다. 즉,  list 자체의 주소를 갖고 있음.
    printf("&n\t=%p\n",&n);

    int i;             //정수형 변수 선언
    float tempsum = 0; //실수형 변수 선언 및 0으로 초기화

    for(i = 0;i < n;i++)
        tempsum += list[i]; //반복문을 사용하여 list의 배열원소들의 값들을 모두 더함. 

    return tempsum;     //listd의 배열원소들 값을 모두 더한 결과를 반환함.
}

float sum2(float *list, int n) {
    //sum1은 main()의 list[]에 input을 인자로 받았다. input은 배열의 시작 주소이며, 이는 input의 주소가 list에 저장되었단 뜻이다. 즉, 참조에 의한 호출이다.
    printf("list\t= %p\n", list);      //list에 저장된 값: input 배열의 시작 주소
    printf("&list\t= %p\n\n", &list);  //list가 저장되어 있는 메모리 주소 값: input 주소가 주소를 저장하는 list에 대입된 것이므로 하나의 변수이다. 즉,  list 자체의 주소를 갖고 있음.
        printf("&n\t=%p\n",&n);
int i;
    float tempsum = 0;
    for(i = 0;i < n;i++) 
        tempsum += *(list +i); //반복문을 사용하여 list의 주소를 (float*i)의 사이즈만큼 증가한 뒤, 역참조한 값들을 모두 더함. 

    return tempsum;        //list의 역참조한 값을 모두 더한 결과를 반환함.
}

//여기서는 위의 sum1,sum2와 다르게, 첫 번째 매개변수를 정수형 변수, 두 번째 매개변수를 실수형 포인터 변수로 설정했다. 
float sum3(int n, float *list) {
    //sum1은 main()의 list[]에 input을 인자로 받았다. input은 배열의 시작 주소이며, 이는 input의 주소가 list에 저장되었단 뜻이다. 즉, 참조에 의한 호출이다.
    printf("list\t= %p\n", list);      //list에 저장된 값: input 배열의 시작 주소
    printf("&list\t= %p\n\n", &list);  //sum1,sum2와 다르게 먼저, 정수형 변수 n이 스택에 위치한 다음에, 포인터 변수 list가 자리잡기 때문에 주소값이 다르다. 
        printf("&n\t=%p\n",&n);
int i;
    float tempsum = 0;
    for(i = 0;i < n;i++)
        tempsum += *(list +i);  //반복문을 사용하여 list의 주소를 (float*i)의 사이즈만큼 증가한 뒤, 역참조한 값들을 모두 더함. 

    return tempsum;         //list의 역참조한 값을 모두 더한 결과를 반환함.
}
