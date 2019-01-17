/********************************************************************************
** Form generated from reading UI file 'frmodelositem.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMODELOSITEM_H
#define UI_FRMODELOSITEM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ModeloItem
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout1;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem;
    QLineEdit *leFundo;
    QSpacerItem *spacerItem1;
    QHBoxLayout *hboxLayout2;
    QSpacerItem *spacerItem2;
    QLineEdit *leFundoAlt;
    QSpacerItem *spacerItem3;
    QTextEdit *teItems;
    QGroupBox *groupBox;
    QGridLayout *gridLayout2;
    QTextEdit *teBody;
    QHBoxLayout *hboxLayout3;
    QSpacerItem *spacerItem4;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QHBoxLayout *hboxLayout4;
    QLabel *label;
    QLineEdit *leModelo;
    QSpacerItem *spacerItem5;

    void setupUi(QDialog *ModeloItem)
    {
        if (ModeloItem->objectName().isEmpty())
            ModeloItem->setObjectName(QStringLiteral("ModeloItem"));
        ModeloItem->resize(531, 569);
        const QIcon icon = QIcon(QString::fromUtf8(":/png/buttons/16/frameprint.png"));
        ModeloItem->setWindowIcon(icon);
        gridLayout = new QGridLayout(ModeloItem);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_2 = new QGroupBox(ModeloItem);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout1 = new QGridLayout(groupBox_2);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(0);
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(2);
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        vboxLayout->addWidget(label_2);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        vboxLayout->addWidget(label_3);


        hboxLayout->addLayout(vboxLayout);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(2);
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(0);
#ifndef Q_OS_MAC
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        spacerItem = new QSpacerItem(16, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem);

        leFundo = new QLineEdit(groupBox_2);
        leFundo->setObjectName(QStringLiteral("leFundo"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leFundo->sizePolicy().hasHeightForWidth());
        leFundo->setSizePolicy(sizePolicy);

        hboxLayout1->addWidget(leFundo);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem1);


        vboxLayout1->addLayout(hboxLayout1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(0);
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QStringLiteral("hboxLayout2"));
        spacerItem2 = new QSpacerItem(16, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem2);

        leFundoAlt = new QLineEdit(groupBox_2);
        leFundoAlt->setObjectName(QStringLiteral("leFundoAlt"));
        sizePolicy.setHeightForWidth(leFundoAlt->sizePolicy().hasHeightForWidth());
        leFundoAlt->setSizePolicy(sizePolicy);

        hboxLayout2->addWidget(leFundoAlt);

        spacerItem3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem3);


        vboxLayout1->addLayout(hboxLayout2);


        hboxLayout->addLayout(vboxLayout1);


        gridLayout1->addLayout(hboxLayout, 0, 0, 1, 1);

        teItems = new QTextEdit(groupBox_2);
        teItems->setObjectName(QStringLiteral("teItems"));
        QFont font;
        font.setFamily(QStringLiteral("Courier"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        teItems->setFont(font);
        teItems->setLineWrapMode(QTextEdit::NoWrap);
        teItems->setAcceptRichText(false);

        gridLayout1->addWidget(teItems, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 2, 0, 1, 1);

        groupBox = new QGroupBox(ModeloItem);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout2 = new QGridLayout(groupBox);
#ifndef Q_OS_MAC
        gridLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout2->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout2->setObjectName(QStringLiteral("gridLayout2"));
        teBody = new QTextEdit(groupBox);
        teBody->setObjectName(QStringLiteral("teBody"));
        teBody->setFont(font);
        teBody->setLineWrapMode(QTextEdit::NoWrap);
        teBody->setAcceptRichText(false);

        gridLayout2->addWidget(teBody, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        hboxLayout3 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout3->setSpacing(6);
#endif
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
        hboxLayout3->setObjectName(QStringLiteral("hboxLayout3"));
        spacerItem4 = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout3->addItem(spacerItem4);

        okButton = new QPushButton(ModeloItem);
        okButton->setObjectName(QStringLiteral("okButton"));
        const QIcon icon1 = QIcon(QString::fromUtf8(":/png/buttons/16/agt_action_success.png"));
        okButton->setIcon(icon1);

        hboxLayout3->addWidget(okButton);

        cancelButton = new QPushButton(ModeloItem);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        const QIcon icon2 = QIcon(QString::fromUtf8(":/png/buttons/16/agt_action_fail.png"));
        cancelButton->setIcon(icon2);

        hboxLayout3->addWidget(cancelButton);


        gridLayout->addLayout(hboxLayout3, 3, 0, 1, 1);

        hboxLayout4 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout4->setSpacing(6);
#endif
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
        hboxLayout4->setObjectName(QStringLiteral("hboxLayout4"));
        label = new QLabel(ModeloItem);
        label->setObjectName(QStringLiteral("label"));

        hboxLayout4->addWidget(label);

        leModelo = new QLineEdit(ModeloItem);
        leModelo->setObjectName(QStringLiteral("leModelo"));
        sizePolicy.setHeightForWidth(leModelo->sizePolicy().hasHeightForWidth());
        leModelo->setSizePolicy(sizePolicy);

        hboxLayout4->addWidget(leModelo);

        spacerItem5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout4->addItem(spacerItem5);


        gridLayout->addLayout(hboxLayout4, 0, 0, 1, 1);

        QWidget::setTabOrder(leModelo, teBody);
        QWidget::setTabOrder(teBody, leFundo);
        QWidget::setTabOrder(leFundo, leFundoAlt);
        QWidget::setTabOrder(leFundoAlt, teItems);
        QWidget::setTabOrder(teItems, okButton);
        QWidget::setTabOrder(okButton, cancelButton);

        retranslateUi(ModeloItem);
        QObject::connect(cancelButton, SIGNAL(clicked()), ModeloItem, SLOT(reject()));

        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(ModeloItem);
    } // setupUi

    void retranslateUi(QDialog *ModeloItem)
    {
        ModeloItem->setWindowTitle(QApplication::translate("ModeloItem", "Modelo", nullptr));
        groupBox_2->setTitle(QApplication::translate("ModeloItem", "Itens", nullptr));
        label_2->setText(QApplication::translate("ModeloItem", "Cor de Fundo", nullptr));
        label_3->setText(QApplication::translate("ModeloItem", "Cor Alternativa", nullptr));
        groupBox->setTitle(QApplication::translate("ModeloItem", "Corpo", nullptr));
        okButton->setText(QApplication::translate("ModeloItem", "OK", nullptr));
        cancelButton->setText(QApplication::translate("ModeloItem", "Cancelar", nullptr));
        label->setText(QApplication::translate("ModeloItem", "Nome", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModeloItem: public Ui_ModeloItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMODELOSITEM_H
