//
//  main.cpp
//  2858
//
//  Created by 이영현 on 23/07/2019.
//  Copyright © 2019 이영현. All rights reserved.
//

#include <iostream>
using namespace std;

void dormitory(int L, int W, int R, int B);

int main(int argc, const char * argv[]) {
    //테두리(빨간 블록의 개수)=가로*2+세로*2-4(대각선 블록)
    int R, B;
    cin>>R;
    cin>>B;
    
    int L=(R+4)/2-1;
    int W=1;
    
    dormitory(L, W, R, B);
    
 
    return 0;
}

void dormitory(int L, int W, int R, int B){
    if(L*W==R+B){
        cout<<L<<' '<<W;
    }
    
    else{
        L--;
        W++;
        
        dormitory(L, W, R, B);
    }
}
