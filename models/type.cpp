#include "type.h"

int Type::getType_id() const
{
    return type_id;
}

void Type::setType_id(int value)
{
    type_id = value;
}

QString Type::getType_label() const
{
    return type_label;
}

void Type::setType_label(const QString &value)
{
    type_label = value;
}

Type::Type()
{
    
}
