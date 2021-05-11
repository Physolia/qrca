/*
 *  Qrca is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Qrca is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this project.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef QRCA_H
#define QRCA_H

#include <KAboutData>
#include <QImage>
#include <QObject>
#include <QUrl>
#include <QVariant>

class QrCodeContent;

class Qrca : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString encodeText READ encodeText WRITE setEncodeText NOTIFY encodeTextChanged)
    Q_PROPERTY(KAboutData aboutData READ aboutData WRITE setAboutData NOTIFY aboutDataChanged)

public:
    Qrca();

    Q_INVOKABLE QImage encode(const QString &text, const int &width) noexcept;
    static Q_INVOKABLE QUrl save(const QImage &image) noexcept;
    static Q_INVOKABLE void saveVCard(const QString &text) noexcept;
    static Q_INVOKABLE QString getVCardName(const QString &text) noexcept;
    Q_INVOKABLE void copyToClipboard(const QrCodeContent &content) noexcept;

    QString encodeText() const noexcept;
    void setEncodeText(const QString &encodeText) noexcept;

    KAboutData aboutData() const noexcept;
    void setAboutData(const KAboutData &aboutData) noexcept;

signals:
    /**
     * Show passive notification
     */
    void passiveNotificationRequested(QString text);

    void encodeTextChanged();
    void aboutDataChanged();

private:
    QString m_encodeText;
    KAboutData m_aboutData;
};

#endif // QRCA_H
