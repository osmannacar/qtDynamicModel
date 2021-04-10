#include "errormodeldata.h"

#include <QVariant>
#include <QDebug>
#include "Enums.h"

ErrorModelData::ErrorModelData(const QVariant &importance, const QVariant &source, const QVariant &errorDefinition)
    : AListModelData()
{
    mDatas.insert(static_cast<int>(Enums::ErrorRoles::ImportanceRole), importance);
    mDatas.insert(static_cast<int>(Enums::ErrorRoles::SourceRole), source);
    mDatas.insert(static_cast<int>(Enums::ErrorRoles::ErrorDefinitionRole), errorDefinition);
}

QHash<int, QByteArray> ErrorModelData::roles() const
{
    static QHash<int, QByteArray> roles = {{static_cast<int>(Enums::ErrorRoles::ImportanceRole), "importance"},
                                           {static_cast<int>(Enums::ErrorRoles::SourceRole), "source"},
                                           {static_cast<int>(Enums::ErrorRoles::ErrorDefinitionRole), "errorDefinition"}};
    return roles;
}
