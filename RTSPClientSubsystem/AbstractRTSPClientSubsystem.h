//
// Created by noreasonexception on 4/14/18.
//

#ifndef IKARUS_PROJECT_ABSTRACTRTSPCLIENTSUBSYSTEM_H
#define IKARUS_PROJECT_ABSTRACTRTSPCLIENTSUBSYSTEM_H


#include "../Consumer/OptionConsumer/OptionConsumer.h"
#include "../Interfaces/OptionSupplierFactory.h"
#include "../Supplier/LogSupplier/LogSupplier.h"
#include "../InformationObject/Option/ChildOptions/LatencyOption.h"
#include "../InformationObject/Option/ChildOptions/ResolutionOption.h"
#include "../InformationObject/Option/ChildOptions/ClientStatusOption.h"
#include "../InformationObject/Option/ChildOptions/WindowHandleOption.h"

class AbstractRTSPClientSubsystem : public OptionConsumer,
                                    public OptionSupplierFactory{
public:
    AbstractRTSPClientSubsystem();

private:
    LogSupplier*supplier;
public:
    void accept(InformationObjectSupplier *supplier, InformationObject *info) override;

    OptionSupplier *createSupplier(QString supplierName) override;

protected:
    virtual void generic_initializer()=0;
    //@may be null
    virtual void onLatencySettingChangedHandler(class LatencyOption*)=0;
    virtual void onResolutionSettingChangedHandler(class ResolutionOption*)=0;
    virtual void onClientStatusSettingChangedHandler(class ClientStatusOption*)=0;
    virtual void onWindowHandlerSettingChangedHandler(class WindowHandleOption*)=0;
    LogSupplier *getSupplier() const;




};


#endif //IKARUS_PROJECT_ABSTRACTRTSPCLIENTSUBSYSTEM_H
