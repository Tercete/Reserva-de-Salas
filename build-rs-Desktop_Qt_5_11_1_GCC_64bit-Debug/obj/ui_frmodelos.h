/********************************************************************************
** Form generated from reading UI file 'frmodelos.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMODELOS_H
#define UI_FRMODELOS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Modelos
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QLabel *label;
    QSpacerItem *spacerItem;
    QComboBox *comboBox;
    QSpacerItem *spacerItem1;
    QPushButton *btAdd;
    QPushButton *btEdit;
    QPushButton *btDelete;
    QTextBrowser *textBrowser;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem2;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *Modelos)
    {
        if (Modelos->objectName().isEmpty())
            Modelos->setObjectName(QStringLiteral("Modelos"));
        Modelos->resize(589, 406);
        const QIcon icon = QIcon(QString::fromUtf8(":/png/buttons/16/frameprint.png"));
        Modelos->setWindowIcon(icon);
        gridLayout = new QGridLayout(Modelos);
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
        label = new QLabel(Modelos);
        label->setObjectName(QStringLiteral("label"));

        hboxLayout->addWidget(label);

        spacerItem = new QSpacerItem(16, 23, QSizePolicy::Maximum, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        comboBox = new QComboBox(Modelos);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(3), static_cast<QSizePolicy::Policy>(0));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);

        hboxLayout->addWidget(comboBox);

        spacerItem1 = new QSpacerItem(51, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem1);

        btAdd = new QPushButton(Modelos);
        btAdd->setObjectName(QStringLiteral("btAdd"));
        const QIcon icon1 = QIcon(QString::fromUtf8(":/png/buttons/16/edit_add.png"));
        btAdd->setIcon(icon1);

        hboxLayout->addWidget(btAdd);

        btEdit = new QPushButton(Modelos);
        btEdit->setObjectName(QStringLiteral("btEdit"));
        const QIcon icon2 = QIcon(QString::fromUtf8(":/png/buttons/16/cell_layout.png"));
        btEdit->setIcon(icon2);

        hboxLayout->addWidget(btEdit);

        btDelete = new QPushButton(Modelos);
        btDelete->setObjectName(QStringLiteral("btDelete"));
        const QIcon icon3 = QIcon(QString::fromUtf8(":/png/buttons/16/button_cancel.png"));
        btDelete->setIcon(icon3);

        hboxLayout->addWidget(btDelete);


        gridLayout->addLayout(hboxLayout, 0, 0, 1, 1);

        textBrowser = new QTextBrowser(Modelos);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout->addWidget(textBrowser, 1, 0, 1, 1);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        spacerItem2 = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem2);

        okButton = new QPushButton(Modelos);
        okButton->setObjectName(QStringLiteral("okButton"));
        const QIcon icon4 = QIcon(QString::fromUtf8(":/png/buttons/16/agt_action_success.png"));
        okButton->setIcon(icon4);

        hboxLayout1->addWidget(okButton);

        cancelButton = new QPushButton(Modelos);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        const QIcon icon5 = QIcon(QString::fromUtf8(":/png/buttons/16/agt_action_fail.png"));
        cancelButton->setIcon(icon5);

        hboxLayout1->addWidget(cancelButton);


        gridLayout->addLayout(hboxLayout1, 2, 0, 1, 1);


        retranslateUi(Modelos);
        QObject::connect(okButton, SIGNAL(clicked()), Modelos, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), Modelos, SLOT(reject()));

        QMetaObject::connectSlotsByName(Modelos);
    } // setupUi

    void retranslateUi(QDialog *Modelos)
    {
        Modelos->setWindowTitle(QApplication::translate("Modelos", "Selecione o Modelo", nullptr));
        label->setText(QApplication::translate("Modelos", "Modelo", nullptr));
        btAdd->setText(QApplication::translate("Modelos", "Adicionar", nullptr));
        btEdit->setText(QApplication::translate("Modelos", "Alterar", nullptr));
        btDelete->setText(QApplication::translate("Modelos", "Excluir", nullptr));
        okButton->setText(QApplication::translate("Modelos", "OK", nullptr));
        cancelButton->setText(QApplication::translate("Modelos", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Modelos: public Ui_Modelos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMODELOS_H
