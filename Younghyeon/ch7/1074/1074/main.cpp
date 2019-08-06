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
void print_Z(vector<vector<int>> input_data, int N, int low, int high);

int main(int argc, const char * argv[]) {
    //Z
    int N, r, c;
    cin>>N;
    cin>>r;
    cin>>c;
    vector<vector<int>> input_data (N, vector<int>(N,0));
    
    print_Z(input_data, N, r, c);
    
    return 0;
}

void print_Z_final(int low, int high, int d_N, int N, int r, int c){
    //네모가 하나 남을 때 까지 재귀함수를 돌린다.
    //d_N은 N과 같은 값으로 시작하지만 계속 2로 나눠지며 하나의 네모가 남을 때 까지 재귀함수를 돌릴 수 있게 해 주는 인자.
    
    //위인 경우
    if(r>d_N/2){
        //위, 왼쪽 네모
        if(c>d_N/2){
            high+=low+pow(2,d_N)-1;
        }
        //위, 오른쪽 네모
        else{
            
        }
    }
    
    //아래인 경우
    else{
        //아래, 왼쪽 네모
        if(c>d_N/2){
            low+=pow(2,N)/2;
            high+=pow(2,N)/2;
            
        }
        //아래, 오른쪽 네모
        else{
            
        }
    }
    
    if(d_N==1)
        cout<<low;
    
    print_Z_final(low, high, d_N, N, r, c);
}


void print_Z(vector<vector<int>> input_data, int N, int r, int c){
    //네모가 하나 남을 때 까지 재귀함수를 돌린다.
    
    //위인 경우
    if(r>N/2){
        
    }
    
    //아래인 경우
    else{
        
    }
    
    print_Z(input_data, N, r, c);
}
