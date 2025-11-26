//
// Created by denes on 2025. 11. 26..
//

#ifndef LAB11_SETTLEMENTSTATISTICSIMPL_H
#define LAB11_SETTLEMENTSTATISTICSIMPL_H

#include <map>
#include "SettlementStatistics.h"

class SettlementStatisticsImpl : public SettlementStatistics{
    multimap<string, Settlement> settlements;
public:
    SettlementStatisticsImpl(string filename);

    int numSettlements() const override;

    int numCounties() const override;

    int numSettlementsByCounty(const string &county) const override;

    vector<Settlement> findSettlementsByCounty(const string &county) const override;

    Settlement findSettlementsByNameAndCounty(const string &name, const string &county) const override;

    Settlement maxPopulationBySettlement() const override;

    Settlement minPopulationBySettlement() const override;

    vector<Settlement> findSettlementsByName(const string &name) override;
};
#endif //LAB11_SETTLEMENTSTATISTICSIMPL_H
