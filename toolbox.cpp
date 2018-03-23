#include "toolbox.h"

ToolBox::ToolBox()
{

}
/**
 * @brief ToolBox::firstToUpper
 * @param string
 * @return the new string
 */
QString ToolBox::firstToUpper(QString string)
{
    QString text = string;
    if(!text.isEmpty())
    {
        text = text.toLower().replace(0,1,text.toLower().at(0).toUpper());
        return text;
    }
    else
        return NULL;
}
