/********************************************************************************
** Form generated from reading UI file 'frareas.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAREAS_H
#define UI_FRAREAS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_areas
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QPushButton *pbAdcionar;
    QPushButton *pbRemover;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem1;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QTableView *tableView;

    void setupUi(QDialog *areas)
    {
        if (areas->objectName().isEmpty())
            areas->setObjectName(QStringLiteral("areas"));
        areas->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/png/buttons/16/edit_group.png"), QSize(), QIcon::Normal, QIcon::Off);
        areas->setWindowIcon(icon);
        gridLayout = new QGridLayout(areas);
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
        pbAdcionar = new QPushButton(areas);
        pbAdcionar->setObjectName(QStringLiteral("pbAdcionar"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/png/buttons/16/edit_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbAdcionar->setIcon(icon1);

        hboxLayout->addWidget(pbAdcionar);

        pbRemover = new QPushButton(areas);
        pbRemover->setObjectName(QStringLiteral("pbRemover"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/png/buttons/16/button_cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbRemover->setIcon(icon2);

        hboxLayout->addWidget(pbRemover);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);


        gridLayout->addLayout(hboxLayout, 0, 0, 1, 1);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        spacerItem1 = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem1);

        okButton = new QPushButton(areas);
        okButton->setObjectName(QStringLiteral("okButton"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/png/buttons/16/agt_action_success.png"), QSize(), QIcon::Normal, QIcon::Off);
        okButton->setIcon(icon3);

        hboxLayout1->addWidget(okButton);

        cancelButton = new QPushButton(areas);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/png/buttons/16/agt_action_fail.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon4);

        hboxLayout1->addWidget(cancelButton);


        gridLayout->addLayout(hboxLayout1, 2, 0, 1, 1);

        tableView = new QTableView(areas);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setAlternatingRowColors(true);

        gridLayout->addWidget(tableView, 1, 0, 1, 1);


        retranslateUi(areas);
        QObject::connect(okButton, SIGNAL(clicked()), areas, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), areas, SLOT(reject()));

        QMetaObject::connectSlotsByName(areas);
    } // setupUi

    void retranslateUi(QDialog *areas)
    {
        areas->setWindowTitle(QApplication::translate("areas", "\303\201reas", nullptr));
        pbAdcionar->setText(QApplication::translate("areas", "Adcionar", nullptr));
        pbRemover->setText(QApplication::translate("areas", "Remover", nullptr));
        okButton->setText(QApplication::translate("areas", "OK", nullptr));
        cancelButton->setText(QApplication::translate("areas", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class areas: public Ui_areas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAREAS_H
