//
// Created by noreasonexception on 5/3/18.
//

#ifndef IKARUS_PROJECT_INFORMATIONEXPORTER_H
#define IKARUS_PROJECT_INFORMATIONEXPORTER_H

#include <QtCore/QSettings>
#include "../Consumer/InformationObjectConsumer.h"
#include "../Interfaces/InformationSupplierFactory.h"
#include "../Supplier/InformationObjectSupplier.h"
#include "../Supplier/LogSupplier/LogSupplier.h"

/****
 * class InformationExporter
 * This class represents a general passing information subsystem to any destination
 *
 *
 */
class InformationExporter: public InformationObjectConsumer,
                            public InformationSupplierFactory{
private:
    QSettings   settings;
    LogSupplier*supplier;
public:
    void accept(InformationObjectSupplier *supplier, InformationObject *info) override=0;

    InformationObjectSupplier *createSupplier(QString supplierName) override;

    explicit InformationExporter(LogSupplier*);
    ~InformationExporter();

protected:
    QSettings   &getSettings() ;
    LogSupplier *getLogSupplier() const;
};


#endif //IKARUS_PROJECT_INFORMATIONEXPORTER_H
