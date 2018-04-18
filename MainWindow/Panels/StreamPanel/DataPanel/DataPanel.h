//
// Created by noreasonexception on 4/18/18.
//

#ifndef IKARUS_PROJECT_DATAPANEL_H
#define IKARUS_PROJECT_DATAPANEL_H


#include "../StreamPanel.h"
#include "../../../../Interfaces/LogSupplierFactory.h"
#include "../../../../Consumer/LogConsumer/LogConsumer.h"
#include "../../../../Interfaces/DataSupplierFactory.h"
#include "../../../../Consumer/DataConsumer/DataConsumer.h"

class DataPanel : public StreamPanel,
                  public DataConsumer,
                  public DataSupplierFactory {
public:
    DataPanel();

public:
    void accept(InformationObjectSupplier *supplier, InformationObject *info) override;

    DataSupplier *createSupplier(QString supplierName) override;

};


#endif //IKARUS_PROJECT_DATAPANEL_H
