/********************************************************************************
** Form generated from reading UI file 'frusers.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRUSERS_H
#define UI_FRUSERS_H

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

class Ui_frUsers
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QHBoxLayout *hboxLayout1;
    QPushButton *pbRemover;
    QSpacerItem *spacerItem1;

    void setupUi(QDialog *frUsers)
    {
        if (frUsers->objectName().isEmpty())
            frUsers->setObjectName(QStringLiteral("frUsers"));
        frUsers->resize(600, 400);
        const QIcon icon = QIcon(QString::fromUtf8(":/png/buttons/16/agt_family.png"));
        frUsers->setWindowIcon(icon);
        gridLayout = new QGridLayout(frUsers);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new QTableView(frUsers);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setAlternatingRowColors(true);

        gridLayout->addWidget(tableView, 1, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(frUsers);
        okButton->setObjectName(QStringLiteral("okButton"));
        const QIcon icon1 = QIcon(QString::fromUtf8(":/png/buttons/16/agt_action_success.png"));
        okButton->setIcon(icon1);

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(frUsers);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        const QIcon icon2 = QIcon(QString::fromUtf8(":/png/buttons/16/agt_action_fail.png"));
        cancelButton->setIcon(icon2);

        hboxLayout->addWidget(cancelButton);


        gridLayout->addLayout(hboxLayout, 2, 0, 1, 1);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        pbRemover = new QPushButton(frUsers);
        pbRemover->setObjectName(QStringLiteral("pbRemover"));
        const QIcon icon3 = QIcon(QString::fromUtf8(":/png/buttons/16/button_cancel.png"));
        pbRemover->setIcon(icon3);

        hboxLayout1->addWidget(pbRemover);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem1);


        gridLayout->addLayout(hboxLayout1, 0, 0, 1, 1);


        retranslateUi(frUsers);
        QObject::connect(cancelButton, SIGNAL(clicked()), frUsers, SLOT(reject()));

        QMetaObject::connectSlotsByName(frUsers);
    } // setupUi

    void retranslateUi(QDialog *frUsers)
    {
        frUsers->setWindowTitle(QApplication::translate("frUsers", "Usu\303\241rios", nullptr));
        okButton->setText(QApplication::translate("frUsers", "OK", nullptr));
        cancelButton->setText(QApplication::translate("frUsers", "Cancelar", nullptr));
        pbRemover->setText(QApplication::translate("frUsers", "Remover", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frUsers: public Ui_frUsers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRUSERS_H
