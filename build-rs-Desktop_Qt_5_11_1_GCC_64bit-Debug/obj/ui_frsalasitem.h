/********************************************************************************
** Form generated from reading UI file 'frsalasitem.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRSALASITEM_H
#define UI_FRSALASITEM_H

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

class Ui_SalasItem
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout1;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *vboxLayout2;
    QLineEdit *leSalaID;
    QLineEdit *leNome;
    QLineEdit *leAndar;
    QComboBox *cbArea;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *SalasItem)
    {
        if (SalasItem->objectName().isEmpty())
            SalasItem->setObjectName(QStringLiteral("SalasItem"));
        SalasItem->resize(301, 179);
        const QIcon icon = QIcon(QString::fromUtf8(":/png/buttons/16/cell_layout.png"));
        SalasItem->setWindowIcon(icon);
        gridLayout = new QGridLayout(SalasItem);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        vboxLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        vboxLayout1 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        label = new QLabel(SalasItem);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        vboxLayout1->addWidget(label);

        label_2 = new QLabel(SalasItem);
        label_2->setObjectName(QStringLiteral("label_2"));

        vboxLayout1->addWidget(label_2);

        label_3 = new QLabel(SalasItem);
        label_3->setObjectName(QStringLiteral("label_3"));

        vboxLayout1->addWidget(label_3);

        label_4 = new QLabel(SalasItem);
        label_4->setObjectName(QStringLiteral("label_4"));

        vboxLayout1->addWidget(label_4);


        hboxLayout->addLayout(vboxLayout1);

        vboxLayout2 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout2->setSpacing(6);
#endif
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
        vboxLayout2->setObjectName(QStringLiteral("vboxLayout2"));
        leSalaID = new QLineEdit(SalasItem);
        leSalaID->setObjectName(QStringLiteral("leSalaID"));
        leSalaID->setEnabled(true);

        vboxLayout2->addWidget(leSalaID);

        leNome = new QLineEdit(SalasItem);
        leNome->setObjectName(QStringLiteral("leNome"));

        vboxLayout2->addWidget(leNome);

        leAndar = new QLineEdit(SalasItem);
        leAndar->setObjectName(QStringLiteral("leAndar"));

        vboxLayout2->addWidget(leAndar);

        cbArea = new QComboBox(SalasItem);
        cbArea->setObjectName(QStringLiteral("cbArea"));

        vboxLayout2->addWidget(cbArea);


        hboxLayout->addLayout(vboxLayout2);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem);

        okButton = new QPushButton(SalasItem);
        okButton->setObjectName(QStringLiteral("okButton"));
        const QIcon icon1 = QIcon(QString::fromUtf8(":/png/buttons/16/agt_action_success.png"));
        okButton->setIcon(icon1);

        hboxLayout1->addWidget(okButton);

        cancelButton = new QPushButton(SalasItem);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        const QIcon icon2 = QIcon(QString::fromUtf8(":/png/buttons/16/agt_action_fail.png"));
        cancelButton->setIcon(icon2);

        hboxLayout1->addWidget(cancelButton);


        vboxLayout->addLayout(hboxLayout1);


        gridLayout->addLayout(vboxLayout, 0, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(leSalaID);
        label_2->setBuddy(leNome);
        label_3->setBuddy(leAndar);
#endif // QT_NO_SHORTCUT

        retranslateUi(SalasItem);
        QObject::connect(cancelButton, SIGNAL(clicked()), SalasItem, SLOT(reject()));

        QMetaObject::connectSlotsByName(SalasItem);
    } // setupUi

    void retranslateUi(QDialog *SalasItem)
    {
        SalasItem->setWindowTitle(QApplication::translate("SalasItem", "Sala", nullptr));
        label->setText(QApplication::translate("SalasItem", "<b>No.</b>", nullptr));
        label_2->setText(QApplication::translate("SalasItem", "<b>Sala</b>", nullptr));
        label_3->setText(QApplication::translate("SalasItem", "Andar", nullptr));
        label_4->setText(QApplication::translate("SalasItem", "\303\201rea", nullptr));
        okButton->setText(QApplication::translate("SalasItem", "OK", nullptr));
        cancelButton->setText(QApplication::translate("SalasItem", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SalasItem: public Ui_SalasItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRSALASITEM_H
