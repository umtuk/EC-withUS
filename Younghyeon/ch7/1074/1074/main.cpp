//
//  main.cpp
//  1074
//
//  Created by 이영현 on 06/08/2019.
//  Copyright © 2019 이영현. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void print_Z_final(int low, int high, int d_N, int r, int c);

int main(int argc, const char * argv[]) {
    //Z
    int N, r, c;
    cin>>N;
    cin>>r;
    cin>>c;
    vector<vector<int>> input_data (N, vector<int>(N,0));
    
    print_Z_final(0, 0, N, r, c);
    
    return 0;
}

void print_Z_final(int low, int high, int d_N, int r, int c){
    //네모가 하나 남을 때 까지 재귀함수를 돌린다.
    //d_N은 N과 같은 값으로 시작하지만 계속 2로 나눠지며 하나의 네모가 남을 때 까지 재귀함수를 돌릴 수 있게 해 주는 인자.
    
    //재귀 탈출!
    if(d_N==1){
        if(r==0&&c==0)
            cout<<low+0;
        
        else if(r==0&&c==1)
            cout<<low+1;
        
        else if(r==1&&c==0)
            cout<<low+2;
        
        else
            cout<<low+3;
    }
    
    else{
        //위인 경우
        if(r+1<=pow(2,d_N-1)){
            //위, 왼쪽 네모
            if(c+1<=pow(2,d_N-1)){
                //cout<<"1번째"<<endl;
            }
            //위, 오른쪽 네모
            else{
                //cout<<"2번째"<<endl;
                low+=pow(2,d_N-1)*pow(2,d_N-1);
            }
        }
        
        //아래인 경우
        else{
            //아래, 왼쪽 네모
            if(c+1<=pow(2,d_N-1)){
                //cout<<"3번째"<<endl;
                low+=pow(2,d_N-1)*pow(2,d_N-1)*2;
            }
            //아래, 오른쪽 네모
            else{
                //cout<<"4번째"<<endl;
                low+=pow(2,d_N-1)*pow(2,d_N-1)*3;
            }
        }
        
        d_N--;
        //cout<<low<<endl;
        //다음 좌표에 맞지 않을 땐 바꿔주기
        if(r>=pow(2,d_N))
            r-=pow(2,d_N);
        
        if(c>=pow(2,d_N))
            c-=pow(2,d_N);

        
        if(d_N!=0)
            print_Z_final(low, high, d_N, r, c);
    }
    
}
