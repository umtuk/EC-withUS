//
//  main.cpp
//  2309
//
//  Created by 이영현 on 24/07/2019.
//  Copyright © 2019 이영현. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int nine_dwarf[9];
    int nine_sum=0;
    int index_1, index_2;
    
    for(int i=0; i<9; i++){
        int input;
        cin>>input;
        nine_dwarf[i]=input;
        nine_sum+=input;
    }
    
    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            int sum=0;
            sum=nine_dwarf[i]+nine_dwarf[j];
            if(nine_sum-sum==100){
                index_1=nine_dwarf[i];
                index_2=nine_dwarf[j];
                break;
            }
        }
    }
    
    sort(nine_dwarf, nine_dwarf+9);
    cout<<'\n';
    
    for(int k=0; k<9; k++){
        if(nine_dwarf[k]!=index_1&&nine_dwarf[k]!=index_2){
            cout<<nine_dwarf[k]<<'\n';
        }
        else
            continue;
    }
    
    return 0;
}

