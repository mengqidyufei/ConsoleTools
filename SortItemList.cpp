#include "SortItemList.h"
#include <QList>
#include <QDebug>

// 跨组移动，需要根据旧parent和旧index找到旧的全局位置，判断最终是向前移动还是向后移动
template<class T, class G>
bool isMoveForwardInDiffGroup(const QList<T>& allChildren, const QList<T>& topLevelChildren, G group, G preGroup, int preIndex)
{
    int oldPosObjIndex = 0;
    if (preGroup == nullptr)		// 顶层
    {
        T oldPosObj = topLevelChildren.value(preIndex);		// 根据旧的位置得到对应现在的对象
        if (nullptr == oldPosObj || preIndex >= topLevelChildren.count()) // 最上层往下移
        {
            return true;
        }
        else
        {
            oldPosObjIndex = allChildren.indexOf(oldPosObj);	// 得到旧的全局位置
        }
    }
    else
    {
        QList<T> childrenNow = preGroup->getChildren();
        T oldPosObj = childrenNow.value(preIndex);
        if (nullptr == oldPosObj)
        {
            oldPosObjIndex = allChildren.indexOf(preGroup) - 1;
        }
        else
        {
            oldPosObjIndex = allChildren.indexOf(oldPosObj);	// 得到旧的全局位置
        }
    }
    int nowObjIndex = allChildren.indexOf(group);				// 得到现在的全局位置
    bool moveForward = nowObjIndex < oldPosObjIndex;
    return moveForward;
}

// 在srcList内移动一个moveList，并在移动后保证moveList数据之间的顺序不变
// toIndex: srcList - moveList 之后需要移动到的位置
template <class T>
void moveListKeepOrder(QList<T> &srcList, const QList<T> &moveList, int toIndex)
{
    int fromIndex = srcList.indexOf(moveList.first());
    if (fromIndex == toIndex)
        return;
    if (fromIndex > toIndex)    // 向前移动
    {
        for (int index = moveList.count() - 1; index >= 0; index--)
        {
            T value = moveList[index];
            int indexInList = srcList.indexOf(value);
            if (indexInList >= 0)
                srcList.move(indexInList, toIndex);
        }
    }
    else
    {
        if (moveList.last() == srcList.last())		// 向后移动，最后一个值若一样，无需移动
            return;
        for (int index = 0; index < moveList.count(); index++)
        {
            T value = moveList[index];
            int indexInList = srcList.indexOf(value);
            if (indexInList >= 0)
                srcList.move(indexInList, qMin(srcList.count() - 1, moveList.count() - 1 + toIndex));
        }
    }
}

SortItemList::SortItemList()
{
    QList<QString> sortList = {"1", "2", "21"};
    //QList<QString> sortList = {"240", "940", "480", "e00"};
    QList<QString> moveList = {"1", "2"};
    moveListKeepOrder<QString>(sortList, moveList, 2);
    qDebug() << sortList;

}
