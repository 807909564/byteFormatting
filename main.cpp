#include <QCoreApplication>
#include <QStringList>
#include <QtMath>

#include <QDebug>

QString GetFileSize(qint64 size) {
    if (!size) {
        return "0 Bytes";
    }
    static QStringList sizeNames;
    if (sizeNames.empty()) {
        sizeNames << " Bytes" << " KB" << " MB" << " GB" << " TB"
                  << " PB" << "EB" << " ZB" << " YB";
    }
    int i = qFloor(qLn(size) / qLn(1024));
    return QString::number(size * 1.0 / qPow(1024,qFloor(i)), 'f', (i > 1) ? 2 : 0) + sizeNames.at(i);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Test size 65536 byte is"
             << GetFileSize(65536);

    return a.exec();
}
