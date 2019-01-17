/********************************************************************************
** Form generated from reading UI file 'frreserva.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRRESERVA_H
#define UI_FRRESERVA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Reserva
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tabPrincipal;
    QGridLayout *gridLayout1;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
    QLabel *label_4;
    QLineEdit *leDepto;
    QVBoxLayout *vboxLayout1;
    QLabel *label_7;
    QComboBox *cbSala;
    QVBoxLayout *vboxLayout2;
    QLabel *label;
    QTextEdit *teNotas;
    QVBoxLayout *vboxLayout3;
    QLabel *label_5;
    QLineEdit *leAssunto;
    QWidget *tabHorario;
    QWidget *widget;
    QHBoxLayout *hboxLayout1;
    QVBoxLayout *vboxLayout4;
    QHBoxLayout *hboxLayout2;
    QLabel *label_6;
    QDateEdit *deData;
    QHBoxLayout *hboxLayout3;
    QLabel *label_2;
    QTimeEdit *teHoraIN;
    QHBoxLayout *hboxLayout4;
    QLabel *label_3;
    QTimeEdit *teHoraFim;
    QHBoxLayout *hboxLayout5;
    QSpacerItem *spacerItem;
    QCheckBox *cbRecorrente;
    QSpacerItem *spacerItem1;
    QSpacerItem *spacerItem2;
    QFrame *frameRecorrente;
    QFrame *frameSemanal;
    QGridLayout *gridLayout2;
    QHBoxLayout *hboxLayout6;
    QCheckBox *cbSemanal1;
    QCheckBox *cbSemanal2;
    QCheckBox *cbSemanal3;
    QCheckBox *cbSemanal4;
    QHBoxLayout *hboxLayout7;
    QCheckBox *cbSemanal5;
    QCheckBox *cbSemanal6;
    QCheckBox *cbSemanal7;
    QSpacerItem *spacerItem3;
    QHBoxLayout *hboxLayout8;
    QSpacerItem *spacerItem4;
    QCheckBox *cbSemanalSN;
    QSpacerItem *spacerItem5;
    QWidget *widget1;
    QHBoxLayout *hboxLayout9;
    QLabel *label_8;
    QDateEdit *deDataTermino;
    QSpacerItem *spacerItem6;
    QComboBox *cbTipoRecorrencia;
    QFrame *frameMensal;
    QGridLayout *gridLayout3;
    QComboBox *cbMensalDOW;
    QComboBox *cbMensalOrdem;
    QHBoxLayout *hboxLayout10;
    QSpacerItem *spacerItem7;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *Reserva)
    {
        if (Reserva->objectName().isEmpty())
            Reserva->setObjectName(QStringLiteral("Reserva"));
        Reserva->resize(434, 410);
        const QIcon icon = QIcon(QString::fromUtf8(":/png/buttons/16/player_time.png"));
        Reserva->setWindowIcon(icon);
        gridLayout = new QGridLayout(Reserva);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(Reserva);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabPrincipal = new QWidget();
        tabPrincipal->setObjectName(QStringLiteral("tabPrincipal"));
        gridLayout1 = new QGridLayout(tabPrincipal);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(0);
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        label_4 = new QLabel(tabPrincipal);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(5), static_cast<QSizePolicy::Policy>(0));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setTextFormat(Qt::RichText);
        label_4->setIndent(-1);

        vboxLayout->addWidget(label_4);

        leDepto = new QLineEdit(tabPrincipal);
        leDepto->setObjectName(QStringLiteral("leDepto"));
        leDepto->setMaxLength(80);

        vboxLayout->addWidget(leDepto);


        hboxLayout->addLayout(vboxLayout);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(0);
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        label_7 = new QLabel(tabPrincipal);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setTextFormat(Qt::RichText);

        vboxLayout1->addWidget(label_7);

        cbSala = new QComboBox(tabPrincipal);
        cbSala->setObjectName(QStringLiteral("cbSala"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(3), static_cast<QSizePolicy::Policy>(0));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cbSala->sizePolicy().hasHeightForWidth());
        cbSala->setSizePolicy(sizePolicy1);

        vboxLayout1->addWidget(cbSala);


        hboxLayout->addLayout(vboxLayout1);


        gridLayout1->addLayout(hboxLayout, 1, 0, 1, 1);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setSpacing(0);
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
        vboxLayout2->setObjectName(QStringLiteral("vboxLayout2"));
        label = new QLabel(tabPrincipal);
        label->setObjectName(QStringLiteral("label"));
        label->setTextFormat(Qt::RichText);

        vboxLayout2->addWidget(label);

        teNotas = new QTextEdit(tabPrincipal);
        teNotas->setObjectName(QStringLiteral("teNotas"));

        vboxLayout2->addWidget(teNotas);


        gridLayout1->addLayout(vboxLayout2, 2, 0, 1, 1);

        vboxLayout3 = new QVBoxLayout();
        vboxLayout3->setSpacing(0);
        vboxLayout3->setContentsMargins(0, 0, 0, 0);
        vboxLayout3->setObjectName(QStringLiteral("vboxLayout3"));
        label_5 = new QLabel(tabPrincipal);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setTextFormat(Qt::RichText);

        vboxLayout3->addWidget(label_5);

        leAssunto = new QLineEdit(tabPrincipal);
        leAssunto->setObjectName(QStringLiteral("leAssunto"));
        leAssunto->setMaxLength(255);

        vboxLayout3->addWidget(leAssunto);


        gridLayout1->addLayout(vboxLayout3, 0, 0, 1, 1);

        tabWidget->addTab(tabPrincipal, QString());
        tabHorario = new QWidget();
        tabHorario->setObjectName(QStringLiteral("tabHorario"));
        widget = new QWidget(tabHorario);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(9, 9, 394, 127));
        hboxLayout1 = new QHBoxLayout(widget);
        hboxLayout1->setSpacing(0);
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout4 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout4->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout4->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout4->setObjectName(QStringLiteral("vboxLayout4"));
        hboxLayout2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout2->setObjectName(QStringLiteral("hboxLayout2"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        hboxLayout2->addWidget(label_6);

        deData = new QDateEdit(widget);
        deData->setObjectName(QStringLiteral("deData"));
        deData->setAlignment(Qt::AlignHCenter);

        hboxLayout2->addWidget(deData);


        vboxLayout4->addLayout(hboxLayout2);

        hboxLayout3 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout3->setSpacing(6);
#endif
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
        hboxLayout3->setObjectName(QStringLiteral("hboxLayout3"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        hboxLayout3->addWidget(label_2);

        teHoraIN = new QTimeEdit(widget);
        teHoraIN->setObjectName(QStringLiteral("teHoraIN"));
        teHoraIN->setAlignment(Qt::AlignHCenter);
        teHoraIN->setTime(QTime(8, 0, 0));

        hboxLayout3->addWidget(teHoraIN);


        vboxLayout4->addLayout(hboxLayout3);

        hboxLayout4 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout4->setSpacing(6);
#endif
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
        hboxLayout4->setObjectName(QStringLiteral("hboxLayout4"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        hboxLayout4->addWidget(label_3);

        teHoraFim = new QTimeEdit(widget);
        teHoraFim->setObjectName(QStringLiteral("teHoraFim"));
        teHoraFim->setAlignment(Qt::AlignHCenter);
        teHoraFim->setTime(QTime(8, 0, 0));

        hboxLayout4->addWidget(teHoraFim);


        vboxLayout4->addLayout(hboxLayout4);

        hboxLayout5 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout5->setSpacing(6);
#endif
        hboxLayout5->setContentsMargins(0, 0, 0, 0);
        hboxLayout5->setObjectName(QStringLiteral("hboxLayout5"));
        spacerItem = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout5->addItem(spacerItem);

        cbRecorrente = new QCheckBox(widget);
        cbRecorrente->setObjectName(QStringLiteral("cbRecorrente"));
        cbRecorrente->setLayoutDirection(Qt::RightToLeft);

        hboxLayout5->addWidget(cbRecorrente);

        spacerItem1 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout5->addItem(spacerItem1);


        vboxLayout4->addLayout(hboxLayout5);


        hboxLayout1->addLayout(vboxLayout4);

        spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem2);

        frameRecorrente = new QFrame(tabHorario);
        frameRecorrente->setObjectName(QStringLiteral("frameRecorrente"));
        frameRecorrente->setGeometry(QRect(9, 142, 394, 175));
        frameRecorrente->setFrameShape(QFrame::StyledPanel);
        frameRecorrente->setFrameShadow(QFrame::Raised);
        frameSemanal = new QFrame(frameRecorrente);
        frameSemanal->setObjectName(QStringLiteral("frameSemanal"));
        frameSemanal->setGeometry(QRect(11, 44, 372, 120));
        frameSemanal->setFrameShape(QFrame::StyledPanel);
        frameSemanal->setFrameShadow(QFrame::Raised);
        gridLayout2 = new QGridLayout(frameSemanal);
#ifndef Q_OS_MAC
        gridLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout2->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout2->setObjectName(QStringLiteral("gridLayout2"));
        hboxLayout6 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout6->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout6->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout6->setObjectName(QStringLiteral("hboxLayout6"));
        cbSemanal1 = new QCheckBox(frameSemanal);
        cbSemanal1->setObjectName(QStringLiteral("cbSemanal1"));

        hboxLayout6->addWidget(cbSemanal1);

        cbSemanal2 = new QCheckBox(frameSemanal);
        cbSemanal2->setObjectName(QStringLiteral("cbSemanal2"));

        hboxLayout6->addWidget(cbSemanal2);

        cbSemanal3 = new QCheckBox(frameSemanal);
        cbSemanal3->setObjectName(QStringLiteral("cbSemanal3"));

        hboxLayout6->addWidget(cbSemanal3);

        cbSemanal4 = new QCheckBox(frameSemanal);
        cbSemanal4->setObjectName(QStringLiteral("cbSemanal4"));

        hboxLayout6->addWidget(cbSemanal4);


        gridLayout2->addLayout(hboxLayout6, 0, 0, 1, 1);

        hboxLayout7 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout7->setSpacing(6);
#endif
        hboxLayout7->setContentsMargins(0, 0, 0, 0);
        hboxLayout7->setObjectName(QStringLiteral("hboxLayout7"));
        cbSemanal5 = new QCheckBox(frameSemanal);
        cbSemanal5->setObjectName(QStringLiteral("cbSemanal5"));

        hboxLayout7->addWidget(cbSemanal5);

        cbSemanal6 = new QCheckBox(frameSemanal);
        cbSemanal6->setObjectName(QStringLiteral("cbSemanal6"));

        hboxLayout7->addWidget(cbSemanal6);

        cbSemanal7 = new QCheckBox(frameSemanal);
        cbSemanal7->setObjectName(QStringLiteral("cbSemanal7"));

        hboxLayout7->addWidget(cbSemanal7);

        spacerItem3 = new QSpacerItem(71, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout7->addItem(spacerItem3);


        gridLayout2->addLayout(hboxLayout7, 1, 0, 1, 1);

        hboxLayout8 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout8->setSpacing(6);
#endif
        hboxLayout8->setContentsMargins(0, 0, 0, 0);
        hboxLayout8->setObjectName(QStringLiteral("hboxLayout8"));
        spacerItem4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout8->addItem(spacerItem4);

        cbSemanalSN = new QCheckBox(frameSemanal);
        cbSemanalSN->setObjectName(QStringLiteral("cbSemanalSN"));

        hboxLayout8->addWidget(cbSemanalSN);

        spacerItem5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout8->addItem(spacerItem5);


        gridLayout2->addLayout(hboxLayout8, 2, 0, 1, 1);

        widget1 = new QWidget(frameRecorrente);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 10, 355, 27));
        hboxLayout9 = new QHBoxLayout(widget1);
#ifndef Q_OS_MAC
        hboxLayout9->setSpacing(6);
#endif
        hboxLayout9->setContentsMargins(0, 0, 0, 0);
        hboxLayout9->setObjectName(QStringLiteral("hboxLayout9"));
        hboxLayout9->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(widget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        hboxLayout9->addWidget(label_8);

        deDataTermino = new QDateEdit(widget1);
        deDataTermino->setObjectName(QStringLiteral("deDataTermino"));
        deDataTermino->setAlignment(Qt::AlignHCenter);

        hboxLayout9->addWidget(deDataTermino);

        spacerItem6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout9->addItem(spacerItem6);

        cbTipoRecorrencia = new QComboBox(widget1);
        cbTipoRecorrencia->addItem(QString());
        cbTipoRecorrencia->addItem(QString());
        cbTipoRecorrencia->setObjectName(QStringLiteral("cbTipoRecorrencia"));

        hboxLayout9->addWidget(cbTipoRecorrencia);

        frameMensal = new QFrame(frameRecorrente);
        frameMensal->setObjectName(QStringLiteral("frameMensal"));
        frameMensal->setGeometry(QRect(0, 120, 346, 74));
        frameMensal->setFrameShape(QFrame::StyledPanel);
        frameMensal->setFrameShadow(QFrame::Raised);
        gridLayout3 = new QGridLayout(frameMensal);
#ifndef Q_OS_MAC
        gridLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout3->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout3->setObjectName(QStringLiteral("gridLayout3"));
        cbMensalDOW = new QComboBox(frameMensal);
        cbMensalDOW->setObjectName(QStringLiteral("cbMensalDOW"));

        gridLayout3->addWidget(cbMensalDOW, 1, 0, 1, 1);

        cbMensalOrdem = new QComboBox(frameMensal);
        cbMensalOrdem->addItem(QString());
        cbMensalOrdem->addItem(QString());
        cbMensalOrdem->addItem(QString());
        cbMensalOrdem->addItem(QString());
        cbMensalOrdem->setObjectName(QStringLiteral("cbMensalOrdem"));

        gridLayout3->addWidget(cbMensalOrdem, 0, 0, 1, 1);

        tabWidget->addTab(tabHorario, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        hboxLayout10 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout10->setSpacing(6);
#endif
        hboxLayout10->setContentsMargins(0, 0, 0, 0);
        hboxLayout10->setObjectName(QStringLiteral("hboxLayout10"));
        spacerItem7 = new QSpacerItem(249, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout10->addItem(spacerItem7);

        okButton = new QPushButton(Reserva);
        okButton->setObjectName(QStringLiteral("okButton"));
        QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy2);
        const QIcon icon1 = QIcon(QString::fromUtf8(":/png/buttons/16/agt_action_success.png"));
        okButton->setIcon(icon1);

        hboxLayout10->addWidget(okButton);

        cancelButton = new QPushButton(Reserva);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        sizePolicy2.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy2);
        const QIcon icon2 = QIcon(QString::fromUtf8(":/png/buttons/16/agt_action_fail.png"));
        cancelButton->setIcon(icon2);

        hboxLayout10->addWidget(cancelButton);


        gridLayout->addLayout(hboxLayout10, 1, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        label_4->setBuddy(leDepto);
        label_7->setBuddy(leDepto);
        label_5->setBuddy(leAssunto);
        label_6->setBuddy(deDataTermino);
        label_2->setBuddy(teHoraIN);
        label_3->setBuddy(teHoraFim);
        label_8->setBuddy(deDataTermino);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(leAssunto, leDepto);
        QWidget::setTabOrder(leDepto, cbSala);
        QWidget::setTabOrder(cbSala, teNotas);
        QWidget::setTabOrder(teNotas, tabWidget);
        QWidget::setTabOrder(tabWidget, okButton);
        QWidget::setTabOrder(okButton, cancelButton);
        QWidget::setTabOrder(cancelButton, deData);
        QWidget::setTabOrder(deData, teHoraIN);
        QWidget::setTabOrder(teHoraIN, teHoraFim);
        QWidget::setTabOrder(teHoraFim, cbRecorrente);
        QWidget::setTabOrder(cbRecorrente, deDataTermino);
        QWidget::setTabOrder(deDataTermino, cbTipoRecorrencia);
        QWidget::setTabOrder(cbTipoRecorrencia, cbSemanal1);
        QWidget::setTabOrder(cbSemanal1, cbSemanal2);
        QWidget::setTabOrder(cbSemanal2, cbSemanal3);
        QWidget::setTabOrder(cbSemanal3, cbSemanal4);
        QWidget::setTabOrder(cbSemanal4, cbSemanal5);
        QWidget::setTabOrder(cbSemanal5, cbSemanal6);
        QWidget::setTabOrder(cbSemanal6, cbSemanal7);
        QWidget::setTabOrder(cbSemanal7, cbSemanalSN);
        QWidget::setTabOrder(cbSemanalSN, cbMensalOrdem);
        QWidget::setTabOrder(cbMensalOrdem, cbMensalDOW);

        retranslateUi(Reserva);
        QObject::connect(cancelButton, SIGNAL(clicked()), Reserva, SLOT(reject()));

        QMetaObject::connectSlotsByName(Reserva);
    } // setupUi

    void retranslateUi(QDialog *Reserva)
    {
        Reserva->setWindowTitle(QApplication::translate("Reserva", "Reserva", nullptr));
        label_4->setText(QApplication::translate("Reserva", "Departamento", nullptr));
        label_7->setText(QApplication::translate("Reserva", "<b>Sala</b>", nullptr));
        label->setText(QApplication::translate("Reserva", "Notas", nullptr));
        label_5->setText(QApplication::translate("Reserva", "<b>Assunto</b>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabPrincipal), QApplication::translate("Reserva", "Reserva", nullptr));
        label_6->setText(QApplication::translate("Reserva", "<b>Data</b>", nullptr));
        label_2->setText(QApplication::translate("Reserva", "<b>Inicio</b>", nullptr));
        teHoraIN->setDisplayFormat(QApplication::translate("Reserva", "hh:mm", nullptr));
        label_3->setText(QApplication::translate("Reserva", "<b>Fim</b>", nullptr));
        teHoraFim->setDisplayFormat(QApplication::translate("Reserva", "hh:mm", nullptr));
        cbRecorrente->setText(QApplication::translate("Reserva", "Reserva Recorrente", nullptr));
        cbSemanal1->setText(QApplication::translate("Reserva", "CheckBox", nullptr));
        cbSemanal2->setText(QApplication::translate("Reserva", "CheckBox", nullptr));
        cbSemanal3->setText(QApplication::translate("Reserva", "CheckBox", nullptr));
        cbSemanal4->setText(QApplication::translate("Reserva", "CheckBox", nullptr));
        cbSemanal5->setText(QApplication::translate("Reserva", "CheckBox", nullptr));
        cbSemanal6->setText(QApplication::translate("Reserva", "CheckBox", nullptr));
        cbSemanal7->setText(QApplication::translate("Reserva", "CheckBox", nullptr));
        cbSemanalSN->setText(QApplication::translate("Reserva", "Semana Sim/Semana N\303\243o", nullptr));
        label_8->setText(QApplication::translate("Reserva", "<b>Data T\303\251rmino</b>", nullptr));
        cbTipoRecorrencia->setItemText(0, QApplication::translate("Reserva", "Semanal", nullptr));
        cbTipoRecorrencia->setItemText(1, QApplication::translate("Reserva", "Mensal", nullptr));

        cbMensalOrdem->setItemText(0, QApplication::translate("Reserva", "Primeira", nullptr));
        cbMensalOrdem->setItemText(1, QApplication::translate("Reserva", "Segunda", nullptr));
        cbMensalOrdem->setItemText(2, QApplication::translate("Reserva", "Pen\303\272ltima", nullptr));
        cbMensalOrdem->setItemText(3, QApplication::translate("Reserva", "\303\232ltima", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tabHorario), QApplication::translate("Reserva", "Hor\303\241rio", nullptr));
        okButton->setText(QApplication::translate("Reserva", "OK", nullptr));
        cancelButton->setText(QApplication::translate("Reserva", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reserva: public Ui_Reserva {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRRESERVA_H
