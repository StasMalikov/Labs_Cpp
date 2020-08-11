#include "services/IOService.h"
#include "models/User.h"
#include "models/TradeOrganization.h"


int main() {
    User user("stas", UserType::wholesale);
    TradeOrganization tradeOrganization;
    IOService ioService(tradeOrganization);
    ioService.start();
    return 0;
}