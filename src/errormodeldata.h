#ifndef ANIMALMODELDATA_H
#define ANIMALMODELDATA_H

#include "ListModel/alistmodeldata.h"

class ErrorModelData : public AListModelData
{
public:
    ErrorModelData(const QVariant &importance, const QVariant &source, const QVariant &errorDefinition);


    // IModelData interface
public:
    //qml access to roles and developer sould be considered when naming
    QHash<int, QByteArray> roles() const override;
};

#endif // ANIMALMODELDATA_H
