/********************************************************************************
** Form generated from reading UI file 'frsalas.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRSALAS_H
#define UI_FRSALAS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Salas
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QPushButton *btAdicionar;
    QPushButton *btAlterar;
    QPushButton *btExcluir;
    QSpacerItem *spacerItem;
    QTableWidget *tbSalas;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem1;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *Salas)
    {
        if (Salas->objectName().isEmpty())
            Salas->setObjectName(QStringLiteral("Salas"));
        Salas->resize(454, 375);
        const QIcon icon = QIcon(QString::fromUtf8(":/png/buttons/16/irkick.png"));
        Salas->setWindowIcon(icon);
        gridLayout = new QGridLayout(Salas);
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
        btAdicionar = new QPushButton(Salas);
        btAdicionar->setObjectName(QStringLiteral("btAdicionar"));
        const QIcon icon1 = QIcon(QString::fromUtf8(":/png/buttons/16/edit_add.png"));
        btAdicionar->setIcon(icon1);

        hboxLayout->addWidget(btAdicionar);

        btAlterar = new QPushButton(Salas);
        btAlterar->setObjectName(QStringLiteral("btAlterar"));
        const QIcon icon2 = QIcon(QString::fromUtf8(":/png/buttons/16/cell_layout.png"));
        btAlterar->setIcon(icon2);

        hboxLayout->addWidget(btAlterar);

        btExcluir = new QPushButton(Salas);
        btExcluir->setObjectName(QStringLiteral("btExcluir"));
        const QIcon icon3 = QIcon(QString::fromUtf8(":/png/buttons/16/button_cancel.png"));
        btExcluir->setIcon(icon3);

        hboxLayout->addWidget(btExcluir);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);


        vboxLayout->addLayout(hboxLayout);

        tbSalas = new QTableWidget(Salas);
        if (tbSalas->columnCount() < 4)
            tbSalas->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tbSalas->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tbSalas->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tbSalas->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tbSalas->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tbSalas->setObjectName(QStringLiteral("tbSalas"));
        tbSalas->setAlternatingRowColors(true);

        vboxLayout->addWidget(tbSalas);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        spacerItem1 = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem1);

        okButton = new QPushButton(Salas);
        okButton->setObjectName(QStringLiteral("okButton"));
        const QIcon icon4 = QIcon(QString::fromUtf8(":/png/buttons/16/agt_action_success.png"));
        okButton->setIcon(icon4);

        hboxLayout1->addWidget(okButton);

        cancelButton = new QPushButton(Salas);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        const QIcon icon5 = QIcon(QString::fromUtf8(":/png/buttons/16/agt_action_fail.png"));
        cancelButton->setIcon(icon5);

        hboxLayout1->addWidget(cancelButton);


        vboxLayout->addLayout(hboxLayout1);


        gridLayout->addLayout(vboxLayout, 0, 0, 1, 1);


        retranslateUi(Salas);
        QObject::connect(okButton, SIGNAL(clicked()), Salas, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), Salas, SLOT(reject()));

        QMetaObject::connectSlotsByName(Salas);
    } // setupUi

    void retranslateUi(QDialog *Salas)
    {
        Salas->setWindowTitle(QApplication::translate("Salas", "Salas", nullptr));
        btAdicionar->setText(QApplication::translate("Salas", "Adicionar", nullptr));
        btAlterar->setText(QApplication::translate("Salas", "Alterar", nullptr));
        btExcluir->setText(QApplication::translate("Salas", "Excluir", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tbSalas->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Salas", "No.", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tbSalas->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Salas", "Sala", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tbSalas->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Salas", "Andar", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tbSalas->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Salas", "\303\201rea", nullptr));
        okButton->setText(QApplication::translate("Salas", "OK", nullptr));
        cancelButton->setText(QApplication::translate("Salas", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Salas: public Ui_Salas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRSALAS_H
