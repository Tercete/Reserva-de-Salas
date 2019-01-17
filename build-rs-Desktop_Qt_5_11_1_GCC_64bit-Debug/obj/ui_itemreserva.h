/********************************************************************************
** Form generated from reading UI file 'itemreserva.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMRESERVA_H
#define UI_ITEMRESERVA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_itemReserva
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
    QLabel *lblHoraIn;
    QLabel *lblHoraFim;
    QLabel *label_3;

    void setupUi(QWidget *itemReserva)
    {
        if (itemReserva->objectName().isEmpty())
            itemReserva->setObjectName(QStringLiteral("itemReserva"));
        itemReserva->resize(215, 56);
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(3), static_cast<QSizePolicy::Policy>(0));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(itemReserva->sizePolicy().hasHeightForWidth());
        itemReserva->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(itemReserva);
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
        lblHoraIn = new QLabel(itemReserva);
        lblHoraIn->setObjectName(QStringLiteral("lblHoraIn"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblHoraIn->sizePolicy().hasHeightForWidth());
        lblHoraIn->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg"));
        font.setPointSize(8);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        lblHoraIn->setFont(font);
        lblHoraIn->setTextFormat(Qt::PlainText);
        lblHoraIn->setAlignment(Qt::AlignCenter);

        vboxLayout->addWidget(lblHoraIn);

        lblHoraFim = new QLabel(itemReserva);
        lblHoraFim->setObjectName(QStringLiteral("lblHoraFim"));
        sizePolicy1.setHeightForWidth(lblHoraFim->sizePolicy().hasHeightForWidth());
        lblHoraFim->setSizePolicy(sizePolicy1);
        lblHoraFim->setFont(font);
        lblHoraFim->setTextFormat(Qt::PlainText);
        lblHoraFim->setScaledContents(false);
        lblHoraFim->setAlignment(Qt::AlignCenter);

        vboxLayout->addWidget(lblHoraFim);


        hboxLayout->addLayout(vboxLayout);

        label_3 = new QLabel(itemReserva);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(13), static_cast<QSizePolicy::Policy>(13));
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setTextFormat(Qt::RichText);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(true);

        hboxLayout->addWidget(label_3);


        gridLayout->addLayout(hboxLayout, 0, 0, 1, 1);


        retranslateUi(itemReserva);

        QMetaObject::connectSlotsByName(itemReserva);
    } // setupUi

    void retranslateUi(QWidget *itemReserva)
    {
        itemReserva->setWindowTitle(QApplication::translate("itemReserva", "Form", nullptr));
        lblHoraIn->setText(QApplication::translate("itemReserva", "lblHoraIn", nullptr));
        lblHoraFim->setText(QApplication::translate("itemReserva", "lblHoraFim", nullptr));
        label_3->setText(QApplication::translate("itemReserva", "<b>Assunto</b><br><i>Depto</i>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class itemReserva: public Ui_itemReserva {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMRESERVA_H
