#ifndef TESTCOMMAND_H
#define TESTCOMMAND_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>

QT_FORWARD_DECLARE_CLASS(QString)

class TestCommand
{
public:
    TestCommand();
    void view();
    QString getCommand();
};

#endif // TESTCOMMAND_H
