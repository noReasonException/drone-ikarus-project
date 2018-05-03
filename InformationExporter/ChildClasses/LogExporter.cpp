//
// Created by noreasonexception on 5/3/18.
//

#include "LogExporter.h"
#include "../../MainWindow/Panels/StreamPanel/LogPanel/LogPanel.h"
#include "../../misc/Suppliers/LogSuppliers.h"

void LogExporter::accept(InformationObjectSupplier *supplier, InformationObject *info) {
    InformationExporter::accept(supplier, info);
}

LogExporter::LogExporter() : InformationExporter(LogPanel::getInstance()->createSupplier(LOG_EXPORTER_SUPPLIER)){

}
