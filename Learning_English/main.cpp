//
//  main.cpp
//  Learning_English
//
//  Created by 华洲琦 on 2024/3/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>
using namespace std;

struct words{
    string English;
    string Chinese;
    bool spelled;
};

int main(int argc, const char * argv[]) {
    //单词录入、单词学习软件
    vector<words> wordlist;
    //写入单词列表
    while(true){
        words word;
        word.spelled = false;
        cout<<"英文: ";
        cin>>word.English;
        if(word.English == "Quit!") break;  // 录入结束
        cout<<"中文: ";
        cin>>word.Chinese;
        wordlist.push_back(word);
        cout<<"-----------------------"<<endl;
    }
    
    cout<<endl<<"录入完成"<<endl<<endl;
    
    //开始随机排序
    int num = int(wordlist.size());
    default_random_engine e;
    uniform_int_distribution<int> u(0,num-1); // 左闭右闭区间
    e.seed(int(time(0)));
    int cnt = 0;
    
    for(int i=0;;i++){
        if(cnt==num) break;
        //默写
        int idx = u(e);
        if(!wordlist[idx].spelled){
            cnt++;
            wordlist[idx].spelled = true;
            cout<<"-----------------------"<<endl;
            cout<<wordlist[idx].Chinese<<endl;
            string input;
            bool spell_wrong = false;
            while(true){
                cin>>input;
                if(input != wordlist[idx].English){
                    cout<<"拼写错误！重试: ";
                    spell_wrong = true;
                }
                else break;
            }
            //一次拼写错误，重新加入单词表
            if(spell_wrong){
                wordlist[idx].spelled = false;
                cnt--;
            }
        }
    }
    cout<<endl<<"默写完成！"<<endl;
    
    //将单词表写入文件
    
    
}
