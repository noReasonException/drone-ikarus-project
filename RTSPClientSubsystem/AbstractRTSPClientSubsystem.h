//
// Created by noreasonexception on 4/14/18.
//

#ifndef IKARUS_PROJECT_ABSTRACTRTSPCLIENTSUBSYSTEM_H
#define IKARUS_PROJECT_ABSTRACTRTSPCLIENTSUBSYSTEM_H


#include "../Consumer/OptionConsumer/OptionConsumer.h"
#include "../Interfaces/OptionSupplierFactory.h"
#include "../Supplier/LogSupplier/LogSupplier.h"

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
    virtual void onLatencySettingChangedHandler()=0;
    virtual void onResolutionSettingChangedHandler()=0;
    virtual void onClientStatusSettingChangedHandler()=0;
    LogSupplier *getSupplier() const;




};


#endif //IKARUS_PROJECT_ABSTRACTRTSPCLIENTSUBSYSTEM_H
