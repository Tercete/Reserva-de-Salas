/********************************************************************************
** Form generated from reading UI file 'frdbsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRDBSETTINGS_H
#define UI_FRDBSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_frdbsettings
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *vboxLayout1;
    QLineEdit *leServer;
    QLineEdit *leDatabase;
    QLineEdit *leUser;
    QLineEdit *lePassword;
    QComboBox *cbCharset;
    QHBoxLayout *hboxLayout1;
    QPushButton *helpButton;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *frdbsettings)
    {
        if (frdbsettings->objectName().isEmpty())
            frdbsettings->setObjectName(QStringLiteral("frdbsettings"));
        frdbsettings->resize(262, 193);
        frdbsettings->setModal(true);
        gridLayout = new QGridLayout(frdbsettings);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        vboxLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        label = new QLabel(frdbsettings);
        label->setObjectName(QStringLiteral("label"));

        vboxLayout->addWidget(label);

        label_5 = new QLabel(frdbsettings);
        label_5->setObjectName(QStringLiteral("label_5"));

        vboxLayout->addWidget(label_5);

        label_2 = new QLabel(frdbsettings);
        label_2->setObjectName(QStringLiteral("label_2"));

        vboxLayout->addWidget(label_2);

        label_3 = new QLabel(frdbsettings);
        label_3->setObjectName(QStringLiteral("label_3"));

        vboxLayout->addWidget(label_3);

        label_4 = new QLabel(frdbsettings);
        label_4->setObjectName(QStringLiteral("label_4"));

        vboxLayout->addWidget(label_4);


        hboxLayout->addLayout(vboxLayout);

        vboxLayout1 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        leServer = new QLineEdit(frdbsettings);
        leServer->setObjectName(QStringLiteral("leServer"));

        vboxLayout1->addWidget(leServer);

        leDatabase = new QLineEdit(frdbsettings);
        leDatabase->setObjectName(QStringLiteral("leDatabase"));

        vboxLayout1->addWidget(leDatabase);

        leUser = new QLineEdit(frdbsettings);
        leUser->setObjectName(QStringLiteral("leUser"));

        vboxLayout1->addWidget(leUser);

        lePassword = new QLineEdit(frdbsettings);
        lePassword->setObjectName(QStringLiteral("lePassword"));
        lePassword->setEchoMode(QLineEdit::Password);

        vboxLayout1->addWidget(lePassword);

        cbCharset = new QComboBox(frdbsettings);
        cbCharset->setObjectName(QStringLiteral("cbCharset"));

        vboxLayout1->addWidget(cbCharset);


        hboxLayout->addLayout(vboxLayout1);


        gridLayout->addLayout(hboxLayout, 0, 0, 1, 1);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        helpButton = new QPushButton(frdbsettings);
        helpButton->setObjectName(QStringLiteral("helpButton"));
        const QIcon icon = QIcon(QString::fromUtf8(":/png/buttons/16/help.png"));
        helpButton->setIcon(icon);

        hboxLayout1->addWidget(helpButton);

        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem);

        okButton = new QPushButton(frdbsettings);
        okButton->setObjectName(QStringLiteral("okButton"));
        const QIcon icon1 = QIcon(QString::fromUtf8(":/png/buttons/16/agt_action_success.png"));
        okButton->setIcon(icon1);

        hboxLayout1->addWidget(okButton);

        cancelButton = new QPushButton(frdbsettings);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        const QIcon icon2 = QIcon(QString::fromUtf8(":/png/buttons/16/button_cancel.png"));
        cancelButton->setIcon(icon2);

        hboxLayout1->addWidget(cancelButton);


        gridLayout->addLayout(hboxLayout1, 1, 0, 1, 1);

        QWidget::setTabOrder(leServer, leDatabase);
        QWidget::setTabOrder(leDatabase, leUser);
        QWidget::setTabOrder(leUser, lePassword);
        QWidget::setTabOrder(lePassword, cbCharset);
        QWidget::setTabOrder(cbCharset, okButton);
        QWidget::setTabOrder(okButton, cancelButton);

        retranslateUi(frdbsettings);
        QObject::connect(okButton, SIGNAL(clicked()), frdbsettings, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), frdbsettings, SLOT(reject()));

        QMetaObject::connectSlotsByName(frdbsettings);
    } // setupUi

    void retranslateUi(QDialog *frdbsettings)
    {
        frdbsettings->setWindowTitle(QApplication::translate("frdbsettings", "Servidor", nullptr));
        label->setText(QApplication::translate("frdbsettings", "Servidor", nullptr));
        label_5->setText(QApplication::translate("frdbsettings", "Banco", nullptr));
        label_2->setText(QApplication::translate("frdbsettings", "Usu\303\241rio", nullptr));
        label_3->setText(QApplication::translate("frdbsettings", "Senha", nullptr));
        label_4->setText(QApplication::translate("frdbsettings", "Character set", nullptr));
        helpButton->setText(QApplication::translate("frdbsettings", "Ajuda", nullptr));
        okButton->setText(QApplication::translate("frdbsettings", "OK", nullptr));
        cancelButton->setText(QApplication::translate("frdbsettings", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frdbsettings: public Ui_frdbsettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRDBSETTINGS_H
