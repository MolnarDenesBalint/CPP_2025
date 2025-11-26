#include <iostream>
#include "SettlementStatisticsImpl.h"

int main() {
    SettlementStatisticsImpl s("telepulesek.csv");
    cout<<"Number of Settlements: "<<s.numSettlements()<<endl;
    cout<<"Number of Counties: "<<s.numCounties()<<endl;
    cout<<"Number of Settlements in Harghita: "<<s.numSettlementsByCounty("HR")<<endl;
    vector<Settlement>HrS=s.findSettlementsByCounty("HR");
    cout<<"Settlements in Harghita:";
    for(Settlement& s:HrS){
        cout<<s;
    }
    Settlement p=s.findSettlementsByNameAndCounty("Praid", "HR");
    cout<<"Finding: Praid -HR: "<<p;
    vector<Settlement> sov=s.findSettlementsByName("Sovata");
    cout<<"Finding Sovata: ";
    for(Settlement s:sov){cout<<s;}
    Settlement max=s.maxPopulationBySettlement(), min=s.minPopulationBySettlement();
    cout<<"Max Population: "<<max<<"\t Min Population: "<<min;
    return 0;
}