
#ifndef ROLI_HPP
#define ROLI_HPP
/*
======================================
AUTHOR:Yahia Mohamed Nabil ID:2300644
DESCRIPTION:library made for logic rules and rules of inference
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*===========================CHECKING=============================*/
bool CONTRADICITON(vector<bool> x){
    for(int i=0;i<x.size();i++){
        if(x[i]==true){
            return false;
        }
    }
    return true;
}
bool TAUTOLOGY(vector<bool> x){
    for(int i=0;i<x.size();i++){
        if(x[i]==false){
            return false;
        }
    }
    return true;
}
/*===========================ACTIONS=============================*/
vector<bool> AND(vector<bool> x ,vector<bool> y){
    vector<bool> z;
    for(int i=0;i<x.size();i++){
        z.push_back(x[i]&&y[i]);
    }
    return z;
}
vector<bool> OR(vector<bool> x ,vector<bool> y){
    vector<bool> z;
    for(int i=0;i<x.size();i++){
        z.push_back(x[i]||y[i]);
    }
    return z;
}
vector<bool> NOT(vector<bool> x){
    vector<bool> z;
    for(int i=0;i<x.size();i++){
        z.push_back(!x[i]);
    }
    return z;
}
vector<bool> IMPLIES(vector<bool> x ,vector<bool> y){
    vector<bool> z;
    for(int i=0;i<x.size();i++){
        z.push_back((!x[i])||y[i]);
    }
    return z;
}
vector<bool> BICONDITIONAL(vector<bool> x ,vector<bool> y){
    vector<bool> z;
    for(int i=0;i<x.size();i++){
        z.push_back((x[i]&&y[i])||((!x[i])&&(!y[i])));
    }
    return z;
}
/*===========================PRINT=============================*/
void PRINT(vector<bool> x){
    for(int i=0;i<x.size();i++){
        cout<<x[i]<<"\n";
    }
    cout<<endl;
}
void PRINT(vector<bool> x){
    for(int i=0;i<x.size();i++){
        cout<<x[i]<<"\n";
    }
    cout<<endl;
}
void PRINT(vector<vector<bool>*> x){
    for(int i=0;i<x.size();i++){
        cout<<x[i]<<"\n";
    }
    cout<<endl;
}
////////////////////////////////////////////////////////////////
#endif
