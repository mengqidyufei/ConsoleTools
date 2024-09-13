#ifndef ENUMBOOL_H
#define ENUMBOOL_H
#include <QObject>
class EnumBool : public QObject
{
    Q_OBJECT
public:
    enum WidgetAttribute
    {
        A = 0x00000000,
        B = 0x00000001,
        C = 0x00000002,
        D = 0x00000004
    };
    Q_ENUM(WidgetAttribute)

    EnumBool();
    void setAttribute(int attribute, bool on);

private:
    int mAttribute;
    int mHighAttribute[];
};

#endif // ENUMBOOL_H
