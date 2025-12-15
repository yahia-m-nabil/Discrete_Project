
#ifndef ROLI_HPP
#define ROLI_HPP
/*
======================================
AUTHOR:Yahia Mohamed Nabil ID:2300644
DESCRIPTION:library made for logic rules and rules of inference
VERSION:1.0
DATE:2024-06-10
======================================
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*===========================DECLARATIONS=============================*/
vector<bool> CreateTruthTable(int n);
vector<bool> AND(vector<bool> x ,vector<bool> y);
vector<bool> OR(vector<bool> x ,vector<bool> y);
vector<bool> NOT(vector<bool> x);
vector<bool> IMPLIES(vector<bool> x ,vector<bool> y);
vector<bool> BICONDITIONAL(vector<bool> x ,vector<bool> y);
void PRINT(vector<bool> x);
vector<bool> extractLargeString(string s , vector<vector<bool>> main);
void extractSmallString(stack<char>& char_stack, stack<vector<bool>>& result_stack);
bool CONTRADICITON(vector<bool> x);
bool TAUTOLOGY(vector<bool> x);
vector<bool> checkPremises(stack<vector<bool>>& premises_results);
/*===========================IMPLEMENTATIONS=============================*/ 
/*===========================ACTIONS ON TRUTH TABLES=============================*/
vector<bool> CreateTruthTable(int n){
    static int iteration=0;
    vector<bool> table;
    int rows = 1<<n;
    table.reserve(rows);
    if(iteration<n){
        for(int i=0;i<rows/(1<<iteration);i++){
                for (int j = 0; j <(1<<iteration); j++)
                {
                    table.push_back(i%2==0?false:true);
                }
            }
            }
    else{
        cerr<<"Exceeded number of variables"<<endl;
    }
    iteration++;
    return table;
}
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
        z.push_back(!(x[i]));
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
/*===========================CHECKING ON STRING=============================*/
void extractSmallString(stack<char>& char_stack, stack<vector<bool>>& result_stack){
    vector<bool> result,left,right;
    while(!char_stack.empty()){
        char op = char_stack.top();
        // cout<<"Processing operator: "<<op<<endl;
        char_stack.pop();
        // if(char_stack.empty()){
        //     continue;
        // }
        // else
        // {
        //  cout<<"char top "<<char_stack.top()<<endl;
        // }
        if(op=='('){
            // cout<<"Reached '('. Ending sub-expression processing.\n";
            break;
        }
        else if(op=='~'){
            vector<bool> operand = result_stack.top();
            // cout<<"Applying NOT on:\n";
            // PRINT(operand);
            result_stack.pop();
            result = NOT(operand);
            result_stack.push(result);
            // cout<<"Result after NOT:\n";
            // PRINT(result);
        }
        else{
            right = result_stack.top();
            // cout<<"Applying "<<op<<" on:\n";
            // PRINT(right);
            result_stack.pop();
            if(char_stack.top()=='~'){
                char_stack.pop();
                left = NOT(result_stack.top());
                // cout<<"and\n";
                // PRINT(operand);
            }
            else{
             left = result_stack.top();
            }
            // cout<<"and\n";
            // PRINT(left);
            result_stack.pop();
            switch(op){
                case '&':
                    result = AND(left,right);
                    break;
                case '|':
                    result = OR(left,right);
                    break;
                case '>':
                    result = IMPLIES(left,right);
                    break;
                case '=':
                    result = BICONDITIONAL(left,right);
                    break;
            }
            result_stack.push(result);
        }
    }
}


vector<bool> extractLargeString(string s , vector<vector<bool>> main){
    stack<char> char_stack;
    stack<vector<bool>> result_stack;
    for(int i=0;i<s.length();i++){
        if(s[i]==')'){
         extractSmallString(char_stack,result_stack);
        }
        else{
            if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')){
                result_stack.push(s[i]>='A' && s[i]<='Z'?main[main.size()-1-(s[i]-'A')]:main[main.size()-1-(s[i]-'a')]);
            }
            else if(s[i]=='~'||s[i]=='&'||s[i]=='|'||s[i]=='>'||s[i]=='='||s[i]=='('){
                char_stack.push(s[i]);
            }
            else{
                cerr<<"Invalid Character in Expression"<<endl;
                exit(1);
            }
        }
    }
    return result_stack.top();
}
/*===========================CHECKING ON TRUTH TABLES=============================*/
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
vector<bool> checkPremises(stack<vector<bool>>& premises_results){
    vector<bool> left , right;
    while(!premises_results.empty()){
        right = premises_results.top();
        if(premises_results.size()>1){
            premises_results.pop();
            left = premises_results.top();
            premises_results.pop();
            premises_results.push(AND(left , right));
        }
        else{
            return premises_results.top();
        }
    }
    return right;
}
/*===========================PRINT=============================*/
void PRINT(vector<bool> x){
    for(int i=0;i<x.size();i++){
        cout<<x[i]<<"\n";
    }
    cout<<endl;
}
// void PRINT(vector<bool> x){
//     for(int i=0;i<x.size();i++){
//         cout<<x[i]<<"\n";
//     }
//     cout<<endl;
// }
// void PRINT(vector<vector<bool>*> x){
//     for(int i=0;i<x.size();i++){
//         cout<<x[i]<<"\n";
//     }
//     cout<<endl;
// }
////////////////////////////////////////////////////////////////
#endif
