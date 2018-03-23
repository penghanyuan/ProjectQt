#ifndef TYPE_H
#define TYPE_H
#include <QString>

class Type
{
private:
    int type_id;
    QString type_label;
public:
    Type();
    int getType_id() const;
    void setType_id(int value);
    QString getType_label() const;
    void setType_label(const QString &value);
};

#endif // TYPE_H
