#ifndef INSERTCOUNT_H
#define INSERTCOUNT_H

class InsertCount
{
private:

    int insertcount;
    InsertCount();
public:
    static InsertCount *insertCount;
    static InsertCount *getCount();

    int getInsertcount() const;
    void setInsertcount(int value);
};

#endif // INSERTCOUNT_H
