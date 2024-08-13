#ifndef ENUMBOOL_H
#define ENUMBOOL_H
#include <QObject>
class EnumBool : public QObject
{
    Q_OBJECT
public:
    enum WidgetAttribute
    {
        A = 0,
        B = 1,
        C = 2,
        D = 33
    };
    Q_ENUM(WidgetAttribute)

    EnumBool();
    void setAttribute(int attribute, bool on);

private:
    int mAttribute;
    int mHighAttribute[];
};

#endif // ENUMBOOL_H
