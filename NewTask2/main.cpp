#include "services/IOService.h"
#include "models/User.h"
#include "models/TradeOrganization.h"


int main() {
    TradeOrganization tradeOrganization;
    IOService ioService(tradeOrganization);
    ioService.start();
    return 0;
}

