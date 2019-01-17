/********************************************************************************
** Form generated from reading UI file 'frusersareas.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRUSERSAREAS_H
#define UI_FRUSERSAREAS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_frUsersAreas
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
    QLabel *label;
    QListWidget *lsAreas;
    QVBoxLayout *vboxLayout1;
    QSpacerItem *spacerItem;
    QToolButton *tbAdd;
    QToolButton *tbAddAll;
    QToolButton *tbRemoveAll;
    QToolButton *tbRemove;
    QSpacerItem *spacerItem1;
    QVBoxLayout *vboxLayout2;
    QLabel *label_2;
    QListWidget *lsUserAreas;

    void setupUi(QDialog *frUsersAreas)
    {
        if (frUsersAreas->objectName().isEmpty())
            frUsersAreas->setObjectName(QStringLiteral("frUsersAreas"));
        frUsersAreas->resize(412, 168);
        gridLayout = new QGridLayout(frUsersAreas);
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
        label = new QLabel(frUsersAreas);
        label->setObjectName(QStringLiteral("label"));

        vboxLayout->addWidget(label);

        lsAreas = new QListWidget(frUsersAreas);
        lsAreas->setObjectName(QStringLiteral("lsAreas"));
        lsAreas->setSelectionMode(QAbstractItemView::MultiSelection);
        lsAreas->setSortingEnabled(true);

        vboxLayout->addWidget(lsAreas);


        hboxLayout->addLayout(vboxLayout);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(0);
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        spacerItem = new QSpacerItem(16, 26, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        vboxLayout1->addItem(spacerItem);

        tbAdd = new QToolButton(frUsersAreas);
        tbAdd->setObjectName(QStringLiteral("tbAdd"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tbAdd->sizePolicy().hasHeightForWidth());
        tbAdd->setSizePolicy(sizePolicy);
        const QIcon icon = QIcon(QString::fromUtf8(":/png/buttons/16/1rightarrow.png"));
        tbAdd->setIcon(icon);
        tbAdd->setAutoRaise(true);

        vboxLayout1->addWidget(tbAdd);

        tbAddAll = new QToolButton(frUsersAreas);
        tbAddAll->setObjectName(QStringLiteral("tbAddAll"));
        const QIcon icon1 = QIcon(QString::fromUtf8(":/png/buttons/16/2rightarrow.png"));
        tbAddAll->setIcon(icon1);
        tbAddAll->setAutoRaise(true);

        vboxLayout1->addWidget(tbAddAll);

        tbRemoveAll = new QToolButton(frUsersAreas);
        tbRemoveAll->setObjectName(QStringLiteral("tbRemoveAll"));
        const QIcon icon2 = QIcon(QString::fromUtf8(":/png/buttons/16/2leftarrow.png"));
        tbRemoveAll->setIcon(icon2);
        tbRemoveAll->setAutoRaise(true);

        vboxLayout1->addWidget(tbRemoveAll);

        tbRemove = new QToolButton(frUsersAreas);
        tbRemove->setObjectName(QStringLiteral("tbRemove"));
        const QIcon icon3 = QIcon(QString::fromUtf8(":/png/buttons/16/1leftarrow.png"));
        tbRemove->setIcon(icon3);
        tbRemove->setAutoRaise(true);

        vboxLayout1->addWidget(tbRemove);

        spacerItem1 = new QSpacerItem(16, 20, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        vboxLayout1->addItem(spacerItem1);


        hboxLayout->addLayout(vboxLayout1);

        vboxLayout2 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout2->setSpacing(6);
#endif
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
        vboxLayout2->setObjectName(QStringLiteral("vboxLayout2"));
        label_2 = new QLabel(frUsersAreas);
        label_2->setObjectName(QStringLiteral("label_2"));

        vboxLayout2->addWidget(label_2);

        lsUserAreas = new QListWidget(frUsersAreas);
        lsUserAreas->setObjectName(QStringLiteral("lsUserAreas"));
        lsUserAreas->setSelectionMode(QAbstractItemView::MultiSelection);
        lsUserAreas->setSortingEnabled(true);

        vboxLayout2->addWidget(lsUserAreas);


        hboxLayout->addLayout(vboxLayout2);


        gridLayout->addLayout(hboxLayout, 0, 0, 1, 1);


        retranslateUi(frUsersAreas);

        QMetaObject::connectSlotsByName(frUsersAreas);
    } // setupUi

    void retranslateUi(QDialog *frUsersAreas)
    {
        frUsersAreas->setWindowTitle(QApplication::translate("frUsersAreas", "\303\201reas", nullptr));
        label->setText(QApplication::translate("frUsersAreas", "\303\200reas as quais N\303\243o Pertence", nullptr));
#ifndef QT_NO_TOOLTIP
        tbAdd->setToolTip(QApplication::translate("frUsersAreas", "Adcionar", nullptr));
#endif // QT_NO_TOOLTIP
        tbAdd->setText(QString());
#ifndef QT_NO_TOOLTIP
        tbAddAll->setToolTip(QApplication::translate("frUsersAreas", "Adcionar Todas", nullptr));
#endif // QT_NO_TOOLTIP
        tbAddAll->setText(QString());
#ifndef QT_NO_TOOLTIP
        tbRemoveAll->setToolTip(QApplication::translate("frUsersAreas", "Remover Todas", nullptr));
#endif // QT_NO_TOOLTIP
        tbRemoveAll->setText(QString());
#ifndef QT_NO_TOOLTIP
        tbRemove->setToolTip(QApplication::translate("frUsersAreas", "Remover", nullptr));
#endif // QT_NO_TOOLTIP
        tbRemove->setText(QString());
        label_2->setText(QApplication::translate("frUsersAreas", "\303\201reas que Pertence", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frUsersAreas: public Ui_frUsersAreas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRUSERSAREAS_H
