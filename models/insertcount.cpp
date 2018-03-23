#include "insertcount.h"

int InsertCount::getInsertcount() const
{
    return insertcount;
}

void InsertCount::setInsertcount(int value)
{
    insertcount = value;
}

InsertCount::InsertCount()
{
    insertcount = 0;
}

InsertCount *InsertCount::getCount()
{


        if(insertCount == nullptr){
            insertCount = new InsertCount();
            return insertCount;
        }
        else{
            return insertCount;
        }


}

