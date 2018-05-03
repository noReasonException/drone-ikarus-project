//
// Created by noreasonexception on 5/3/18.
//

#ifndef IKARUS_PROJECT_INFORMATIONEXPORTER_H
#define IKARUS_PROJECT_INFORMATIONEXPORTER_H

#include <QtCore/QSettings>
#include "../Consumer/InformationObjectConsumer.h"
#include "../Interfaces/InformationSupplierFactory.h"
#include "../Supplier/InformationObjectSupplier.h"
/****
 * class InformationExporter
 * This class represents a generar information transaction to files
 *
 */
class InformationExporter: public InformationObjectConsumer,
                            public InformationSupplierFactory{
private:
    QSettings settings;
protected:
public:
    void accept(InformationObjectSupplier *supplier, InformationObject *info) override=0;

    InformationObjectSupplier *createSupplier(QString supplierName) override;

    InformationExporter();

protected:
    const QSettings &getSettings() const;
};


#endif //IKARUS_PROJECT_INFORMATIONEXPORTER_H
