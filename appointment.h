#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <QString>
#include <QDateTime>
#include <vector>
using namespace std;
class Appointment
{
private:
    int app_id;
    QDateTime app_date;
    QTime app_duration;
    int app_priority;
    vector<int> app_v_resources;
    QString comment;
public:
    Appointment();
};

#endif // APPOINTMENT_H
