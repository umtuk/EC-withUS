//
//  main.cpp
//  10829
//
//  Created by 이영현 on 23/07/2019.
//  Copyright © 2019 이영현. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;
//큰 수를 계속 반복문으로 돌리면 시간초과 날 것 같음..



int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long long int N;
    cin>>N;
    
    unsigned long long int very_big=pow(2,47);
    
    while(very_big>N){
        very_big/=2;
    }
    
    for(unsigned long long int k=very_big; k>=1; k/=2){
        if(N<k){
            cout<<'0';
        }
        else{
            cout<<'1';
            N-=k;
        }
    }
    
    
    return 0;
}

/*
 int what_is_big_binary(int N, int big){
 
 if(N>big)
 return what_is_big_binary(N, 2*big); //여기서도 return형을 적어줘야 반환 경고가 안 뜬다! 조심조심.
 
 else
 return big;
 }
 */
