//
//  main.cpp
//  15649
//
//  Created by 이영현 on 31/07/2019.
//  Copyright © 2019 이영현. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    
    //N과 M(2)
    //길이가 M인 수열을 모두 구하기
    int N, M;
    cin>>N;
    cin>>M;
    int arr[8];
    
    for(int k=0; k<N; k++){
        arr[k]=k+1;
    }
    
    //기저 사례
    if(N==M){
        for(int k=0; k<N; k++)
            cout<<k<<" ";
    }
    
    else{
        for(int k=0; k<N; k++){
            for(int j=0; j<M; j++){
                
            }
        }
    }
    
    return 0;
}
