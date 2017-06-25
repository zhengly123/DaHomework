#include "export.h"

QByteArray ExportMes_login(QByteArray material1,QByteArray material2)
{
    return "client=true&ask=login&user="+material1+"&password="+material2;
}
QByteArray ExportMes_register(QByteArray material1,QByteArray material2)
{
    return "client=true&ask=register&user="+material1+"&password="+material2;
}
