//
//  main.cpp
//  2309
//
//  Created by 이영현 on 24/07/2019.
//  Copyright © 2019 이영현. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void quad_tree(vector<vector<char>> & arr, int N, int index_k, int index_j);
int location(int N, int k, int j);
//알고리즘 라이브러리에 있는 sort함수를 이용하는것도!!

int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    vector< vector<char> > arr;
    arr.assign(N, vector<char>(N,0));
    
    for(int k=0; k<N; k++){
        for(int j=0; j<N; j++){
            char input;
            cin>>input;
            arr[k][j]=input;
        }
    }
    
    quad_tree(arr, N,0,0);
    
    
    return 0;
}

void quad_tree(vector<vector<char>> & arr, int N, int index_k, int index_j){
    if(arr.size()==1){
        cout<<arr[0][0];
    }
    
    for(int k=index_k; k<N; k++){
        for(int j=index_j; j<N-1; j++){
            //j=0이면 0번쨰와 1번째 비교
            //j=N-2면 N-2번째와 마지막 비교
            //만약 다른 사분면으로 넘어갈 때 발견되면,, 아니 상관 없으려나..?
            if(arr[k][j]!=arr[k][j+1]){
                int where=location(N, k, j);
                switch(where){
                    case 1:
                        cout<<'(';
                        quad_tree(arr,N/2,0,0);
                        cout<<')';
                        break;
                    case 2:
                        cout<<'(';
                        quad_tree(arr,N/2,0,N/4);
                        cout<<')';
                        break;
                    case 3:
                        cout<<'(';
                        quad_tree(arr,N/2,N/4,0);
                        cout<<')';
                        break;
                    default:
                        cout<<'(';
                        quad_tree(arr,N/2,N/4,N/4);
                        cout<<')';
                        break;
                }
            }
            
            if(k==N-1){
                cout<<arr[k][j];
            }
            
        }
        
        
        
    }
}

//왼쪽 위는 , 오른쪽 위는 2, 왼쪽 아래는 3, 오른쪽 아래는 4를 반환한다.
int location(int N, int k, int j){
    if(0<=k&&k<(N/2)){
        if(0<=j&&j<(N/2)){
            return 1;
        }
        
        else{
            return 3;
        }
    }
    
    else{
        if(0<=j&&j<(N/2)){
            return 2;
        }
        
        else{
            return 4;
        }
    }
}
