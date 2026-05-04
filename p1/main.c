#include <stdio.h>

int main(void) {
    int N = 0;                            //입력받을 금액
    bool found = false;             //조건을 만족하는 조합을 찾았는지에 대한 bool형
    
    scanf("%d", &N);                  //금액을 나타내는 정수형 N 입력
    
    for(int a = 1; a <= N / 900; a++) {                             // A(900원) 1개 이상 구매
         for(int b = 2; b <= N / 750; b+=2) {                       // B(750원) 1개 이상 구매, 항상 짝수개
             for(int c = 1; c <= N / 200; c++) {                        // C(200원) 1개 이상 구매
                 int sum =  (900 * a) + (750 * b) + (200 * c);                  //총 금액을 나타내는 sum 변수에 각각의 상품마다 
                                                                                 // (상품의 금액 x 구매 수량)의 값을 저장
                 if (sum == N) {                                               //잔돈을 남기지 않았는지 검사해야하니 총 금액과 입력받은 금액이 같은지 확인 
                     if (c < a || c < b) {                              //C 상품 수량이 A 상품 수량보다 작거나 B 상품 수량보다 작은지 검사하는 조건문 
                         printf("%d %d %d\n", a, b, c);                     //구매 수량을 출력
                         
                         found = true;                            //조건을 만족하는지를 기록
                     }
                 }
                
             }
         }
    }
    
    if (found == 0) {                          //모두 순회하고도 경우의 수를 만족하지 않으면
        printf("none");                        //none 출력
    }
    
     return 0;   
    
}
