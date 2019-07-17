//
//  main.cpp
//  Clock
//
//  Created by 이영현 on 17/07/2019.
//  Copyright © 2019 이영현. All rights reserved.
//

#include <iostream>
using namespace std;
int clock(int sum, int num, int C, int** test);

int main(int argc, const char * argv[]) {
    int C;
    int test[30][16];
    cout<<"테스트 케이스 개수 입력"<<'\n';
    cin>>C;
    
    for(int j=0; j<C; j++){
        for(int i=0; i<16; i++){
            cin>>test[j][i];
        }
    }
    int number=0;
    
    for(int l=0; l<C; l++){
        clock(0, 0, l, (int**)test);
    }
 
    return 0;
}

//순서 강제를 사용하려 했지만.. 이건 이웃한 애들끼리 스위치가 연결 된 게 아니니까 조금 다른방식으로 접근해야겠다.
//예제에서 보여줬던 방향 자체를 배열에 저장했던 게 생각난다. 이를 응용 해 볼까?
int clock(int sum, int num, int C, int** test ){
    
    for(int l=0; l<16; l++){
        if(test[C][l]!=12){
            break;
        }
        
        if(l==15&&test[C][l]==12){
            return 0;
        }
    }
    char swit[10][17]={"oooxxxxxxxxxxxxx","xxxoxxxoxoxoxxxx","xxxxoxxxxxoxxxoo","oxxxooooxxxxxxxx"
,"xxxxxxoooxoxoxxx","oxoxxxxxxxxxxxoo","xxxoxxxxxxxxxxoo","xxxxooxoxxxxxxoo","xoooooxxxxxxxxx","xxxoooxxxoxxxoxx"
    };
    
    for(int j=0; j<10; j++){
        //그런데 어떤 스위치를 사용해야 하지
        if(swit[j][num]=='o'){
            test[C][num]+=3;
            
            //근데 이렇게 했을 때 스위치에 연결된 다른 시계들도 변하니까 그게 문제지..
            if(test[C][num]==15)
                test[C][num]=3;
        }
    }
    
    return sum;
}
