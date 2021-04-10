#ifndef ENUMS_H
#define ENUMS_H

#include <QObject>

class Enums : public QObject
{
    Q_OBJECT
public:
    enum class ErrorRoles : int {
        ImportanceRole = Qt::UserRole + 1,
        SourceRole,
        ErrorDefinitionRole
    };
    Q_ENUM(ErrorRoles)

};
#endif // ENUMS_H
