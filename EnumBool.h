#ifndef ENUMBOOL_H
#define ENUMBOOL_H
#include <QObject>
class EnumBool : public QObject
{
    Q_OBJECT
public:
    enum WidgetAttribute
    {
        A = 1 << 0,
        B = 1 << 1,
        C = 1 << 2,
        D = 1 << 3,
        E = 1 << 4,
        F = 1 << 5,
    };
    Q_ENUM(WidgetAttribute)

    EnumBool();
    void setAttribute(int attribute, bool on);

private:
    int mAttribute;
    int mHighAttribute[];
};

#endif // ENUMBOOL_H
