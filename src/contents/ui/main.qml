import QtQuick 2.1
import org.kde.kirigami 2.11 as Kirigami
import QtQuick.Controls 2.0 as Controls

Kirigami.ApplicationWindow {
    id: root

    title: i18n("QR Code Scanner")

    function passiveNotification(text) {
        showPassiveNotification(text, "long")
    }

    Component.onCompleted: {
        qrca.passiveNotificationRequested.connect(passiveNotification)
        if (encodeText) {
            pageStack.layers.push(qrCodeEncoderPage)
        }
    }

    Kirigami.PagePool {
        id: mainPagePool
    }

    globalDrawer: Kirigami.GlobalDrawer {
        title: i18n("QR-Code Scanner")
        titleIcon: "view-barcode"

        actions: [
            Kirigami.PagePoolAction {
                text: i18n("Scan")
                icon.name: "camera-photo-symbolic"
                pagePool: mainPagePool
                page: "QrCodeScannerPage.qml"
            },
            Kirigami.PagePoolAction {
                text: i18n("Create")
                icon.name: "document-new-symbolic"
                pagePool: mainPagePool
                page: "QrCodeEncoderPage.qml"
            },
            Kirigami.PagePoolAction {
                text: i18n("About")
                icon.name: "help-feedback"
                pagePool: mainPagePool
                page: "AboutPage.qml"
            }

        ]
    }

    contextDrawer: Kirigami.ContextDrawer {}

    Component {id: qrCodeScannerPage; QrCodeScannerPage {}}
    Component {id: qrCodeEncoderPage; QrCodeEncoderPage {}}
    Component {id: aboutPage; AboutPage {}}

    pageStack.initialPage: qrCodeScannerPage
}
