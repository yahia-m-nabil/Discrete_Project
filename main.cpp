#include <iostream>
#include"ROLI.hpp"
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n_var,n_premises;
    stack<vector<bool>> premises_results;
    vector<bool> final_premise;
    cout<<"Enter number of variables: ";
    cin>>n_var;
    vector<vector<bool>> Main;
    for(int i=0;i<n_var;i++){
        Main.push_back(CreateTruthTable(n_var));
    }
    cout<<"Enter number of premises: ";
    cin>>n_premises;
    for(int i=0;i<n_premises;i++){
        string premise;
        cout<<"Enter premise "<<i+1<<": ";
        cout<<"Enter the logical expression (use & for AND, | for OR, ~ for NOT, > for IMPLIES, = for BICONDITIONAL, and parentheses for grouping): ";
        cin>>premise;
        vector<bool> res = extractLargeString(premise,Main);
        cout<<"Truth Table for Premise "<<i+1<<":\n";
        PRINT(res);
        premises_results.push(res);
    }
    final_premise = checkPremises(premises_results);
    string conclusion;
    cout<<"Enter the conclusion: ";
    cin>>conclusion;
    vector<bool> result = extractLargeString(conclusion,Main);
    cout<<"Truth Table Result:\n";
    PRINT(result);
    cout<<"Truth Table Final Premise:\n";
    PRINT(final_premise);
    cout<<"Is the argument Satisfiable? ";
    if(!CONTRADICITON(final_premise)){
        cout<<"Yes, the argument is Satisfiable."<<endl;
    }
    else{
        cout<<"No, the argument isn't Satisfiable."<<endl;
    }
    cout<<"Truth Table for Implication (Final Premise -> Conclusion):\n";
    PRINT(IMPLIES(final_premise , result));
    cout<<"Is the argument valid? ";
    if(TAUTOLOGY(IMPLIES(final_premise , result))){
        cout<<"Yes, the argument is valid."<<endl;
    }
    else{
        cout<<"No, the argument is Falsifable."<<endl;
    }
    return 0;

}