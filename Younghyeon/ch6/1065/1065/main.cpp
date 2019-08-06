//
//  main.cpp
//  1065
//
//  Created by 이영현 on 23/07/2019.
//  Copyright © 2019 이영현. All rights reserved.
//

#include <iostream>
using namespace std;
//한~두자리수는 모두 한수
//세자리수부터는 같은 간격으로 증가해야 한수!

void han_number(int num, int count);

int main(int argc, const char * argv[]) {
    int num;
    cin>>num;
    han_number(num, 0);

    
    return 0;
}

void han_number(int num, int count){
    
    if(num==0){
        cout<<count;
    }
    
    if(num>0){
        
        if(num<100){
            for(int k=num; k>0; k--){
                count++;
            }
            cout<<count;
        }
        else if(num<10){
            for(int k=num; k>0; k--){
                count++;
            }
            cout<<count;
        }
        
        else if(num==1000){
            num--;
            han_number(num, count);
        }
        
        else{
            int h_jary=num/100;
            int t_jary=(num%100)/10;
            int o_jary=(num%100)%10;
            
            if(h_jary-t_jary==t_jary-o_jary){
                count++;
            }
            num--;
            han_number(num, count);
        }
    }
    
}
