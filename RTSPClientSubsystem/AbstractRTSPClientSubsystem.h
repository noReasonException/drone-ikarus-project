//
// Created by noreasonexception on 4/14/18.
//

#ifndef IKARUS_PROJECT_ABSTRACTRTSPCLIENTSUBSYSTEM_H
#define IKARUS_PROJECT_ABSTRACTRTSPCLIENTSUBSYSTEM_H


#include <QMutex>
#include "../Consumer/OptionConsumer/OptionConsumer.h"
#include "../Interfaces/OptionSupplierFactory.h"
#include "../Supplier/LogSupplier/LogSupplier.h"
#include "../InformationObject/Option/ChildOptions/LatencyOption.h"
#include "../InformationObject/Option/ChildOptions/LocationOption.h"
#include "../InformationObject/Option/ChildOptions/ResolutionOption.h"
#include "../InformationObject/Option/ChildOptions/ClientStatusOption.h"
#include "../InformationObject/Option/ChildOptions/WindowHandleOption.h"
#include "../Supplier/DataSupplier/DataSupplier.h"

class AbstractRTSPClientSubsystem : public OptionConsumer,
                                    public OptionSupplierFactory{
public:
    AbstractRTSPClientSubsystem();
    virtual ~AbstractRTSPClientSubsystem()= default;

private:
    LogSupplier*supplier;
    DataSupplier*dataSupplier;
    QMutex *consumerLocker;

public:
    void accept(InformationObjectSupplier *supplier, InformationObject *info) override;

    OptionSupplier *createSupplier(QString supplierName) override;
    LogSupplier *getLogSupplier() const;
    DataSupplier *getDataSupplier() const;

protected:

    //@may be null
    virtual bool onLatencySettingChangedHandler(class LatencyOption*)=0;
    virtual bool onResolutionSettingChangedHandler(class ResolutionOption*)=0;
    virtual bool onClientStatusSettingChangedHandler(class ClientStatusOption*)=0;
    virtual bool onWindowHandlerSettingChangedHandler(class WindowHandleOption*)=0;
    virtual bool onLocationSettingChangedHandler(class LocationOption*)=0;




};


#endif //IKARUS_PROJECT_ABSTRACTRTSPCLIENTSUBSYSTEM_H
