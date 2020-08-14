//
// Created by stas_malikov on 08.07.2020.
//

#ifndef NEWTASK2_IOSERVICE_H
#define NEWTASK2_IOSERVICE_H

#include "../models/TradeOrganization.h"
#include "models_services/IOUserService.h"

class IOService {
    TradeOrganization &tradeOrganization;
    IOUserService ioUserService;
public:
    IOService(TradeOrganization &_tradeOrganization) :
            tradeOrganization(_tradeOrganization),
        ioUserService(tradeOrganization.getUserList(),tradeOrganization.getCurrentUser()) {}
    ~IOService(){}
    void start();
};

#endif //NEWTASK2_IOSERVICE_H
