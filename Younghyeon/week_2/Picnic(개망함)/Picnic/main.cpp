//
//  picnic.cpp
//  Algo_6_1
//
//  Created by 이영현 on 16/07/2019.
//  Copyright © 2019 이영현. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int picnic(int index, int t, vector<int>&frnd);

int main(){
    //테스트 케이스의 수는 50 이내로 주어짐.
    //학생의 수는 n으로 주어진다 (2에서 10 사이)
    //친구 쌍의 수는 m으로 주어짐(0과 n(n-1)/2사이)
    //그 다음 줄은 m개의 정수 쌍으로 서로 친구인 두 학생의 번호가 주어진다.
    
    int C,n,m;
    cin>>C;
    
    for(int l=0; l<C; l++){
        cin>>n;
        cin>>m;
        vector<int> frnd;// 이렇게 반복문 안에 넣어주면 계속 초기화가 되나? -> 인서:ㅇㅇ새로 만들어지죠.
        vector<vector<int>> imsi(n*n,vector<int>(n)); // 근데 최대 순서쌍의 개수를 잘 모르겠음 일단 n제곱으로 함.
        cout<<imsi[0][n];
        
        //서로 친구인 두 학생의 번호가 주어진다. (m개의 정수 쌍)
        for(int k=0; k<2*m; k++){
            int num;
            cin>>num;
            frnd.push_back(num);
        }
        picnic(0,m,frnd);
    }
    
    return 0;
}

int picnic(int index, vector<int>&frnd, vector<vector<int>>&imsi){
    int number=0;
    size_t size=frnd.size();
    
    //한 케이스를 검사하는 반복문은 몇 번 돌아가야 하지? 횟수가 정해져있지 않으니까 걍 imsi가 다 채워졌을때로 하자.
    //while
    /*
     while(){
     
     }
     */
    
    
    return number;
}
