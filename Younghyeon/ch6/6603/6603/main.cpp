//
//  main.cpp
//  6603
//
//  Created by 이영현 on 21/07/2019.
//  Copyright © 2019 이영현. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


void print_lotto (vector<int> &lotto, int first, int index, int plus);

int main(int argc, const char * argv[]) {
    int input=1;

    while(1){
        cin>>input;
        if(input==0)
            break;
            
        vector<int> lotto(input);
        
        for(int i=0; i<input; i++){
            int in;
            cin>>in;
            lotto[i]=in;
        }
        
        print_lotto(lotto, 0, 5, 0);
        
        cout<<'\n';
    }
    return 0;
}

void print_lotto (vector<int> &lotto, int first, int index, int plus){
    size_t size=lotto.size();
    int num=0;
    
    for(int k=first; k<first+index; k++){
        cout<<lotto[k]<<' ';
        num++;
    }
    
    while(num!=6){
        if(index==5){
            for(int k=first; ; k++){
                cout<<lotto[k+plus]<<' ';
                num++;
            }
        }

        //index가 5가 아닐 때는 바로 딱 붙어서 cout를 쓰게 되면 차별화가 되지 않으니까!
        else{
            for(int j=first+1; ; j++){
                cout<<lotto[j+plus]<<' ';
                num++;
            }
        }
    }

    cout<<'\n';
    plus++;
    
    if(index==5){
        if(index+plus<=size){
            plus=0;
            index--;
            
            if(index+first+plus<=size){
                first++;
                index=5;
            }
        }
    }
    
    else{
        if(index+plus+1<=size){
            plus=0;
            index--;
            
            if(index==0||){
                first++;
                index=5;
            }
        }
    }
    
    if(size-first-plus>=6)
        print_lotto(lotto, first, index, plus);
    
    else{
        
    }
    
    

}


/*
 size_t size=lotto.size();
 int num=0;
 
 for(int k=first; k<index; k++){
 cout<<lotto[k]<<' ';
 num++;
 }
 
 if(index==5){
 cout<<lotto[index+plus];
 }
 
 else{
 for(int j=index+plus; j+1<size; j++){
 cout<<lotto[j+1]<<' ';
 }
 }
 //cout<<"안녕하세요 제 index는"<<index<<"고 plus는"<<plus<<"입니다"<<endl;
 
 cout<<'\n';
 plus++;
 
 
 if(size-first-index-plus<=0||index+first+(size-plus-1)>6){
 plus=0;
 index--;
 cout<<"인덱스 감소!"<<endl;
 if(index==0||index+plus+1>=size){
 first++;
 index=5;
 }
 }
 
 //cout<<"안녕하세요 제 index는"<<index<<"고 plus는"<<plus<<"라구요"<<endl;
 
 //재귀함수 탈출
 if(first+index+plus<=size){
 print_lotto(lotto, first, index, plus);
 }
 
 else{
 cout<<"Good bye~"<<'\n';
 }
 
 */

