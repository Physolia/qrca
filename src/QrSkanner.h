#ifndef QRSKANNER_H
#define QRSKANNER_H

#include <QObject>
#include <QImage>

class QrSkanner : public QObject
{
        Q_OBJECT
public:
	QrSkanner();
        Q_INVOKABLE bool isUrl(const QString &text);
        Q_INVOKABLE QImage encode(const QString &text, const int &width);
};

#endif // QRSKANNER_H
