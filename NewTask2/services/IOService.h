//
// Created by stas_malikov on 08.07.2020.
//

#ifndef NEWTASK2_IOSERVICE_H
#define NEWTASK2_IOSERVICE_H

#include "../models/TradeOrganization.h"
#include "models_services/IOUserService.h"
#include "models_services/IOSupplierService.h"
#include "models_services/IOShopService.h"


class IOService {
    TradeOrganization &tradeOrganization;

    IOUserService ioUserService;
    IOSupplierService ioSupplierService;
    IOShopService ioShopService;


public:
    IOService(TradeOrganization &_tradeOrganization) :
            tradeOrganization(_tradeOrganization),
            ioUserService(tradeOrganization.getUserList(),tradeOrganization.getCurrentUser()),
            ioSupplierService(tradeOrganization.getSupplier(), tradeOrganization.getShopList(), tradeOrganization.getOrderList()),
            ioShopService(tradeOrganization.getCurrentUser(), tradeOrganization.getShopList(), tradeOrganization.getOrderList())
            {}
    ~IOService(){}
    void start();
};

#endif //NEWTASK2_IOSERVICE_H
