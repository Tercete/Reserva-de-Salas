/********************************************************************************
** Form generated from reading UI file 'frschemas.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRSCHEMAS_H
#define UI_FRSCHEMAS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_frSchemas
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QTableView *tableView;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem1;
    QLabel *lblCor;
    QSpacerItem *spacerItem2;
    QPushButton *pbAlterar;
    QHBoxLayout *hboxLayout2;
    QVBoxLayout *vboxLayout1;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *vboxLayout2;
    QSlider *slRed;
    QSlider *slGreen;
    QSlider *slBlue;
    QHBoxLayout *hboxLayout3;
    QPushButton *pbAdcionar;
    QPushButton *pbRemover;
    QSpacerItem *spacerItem3;

    void setupUi(QDialog *frSchemas)
    {
        if (frSchemas->objectName().isEmpty())
            frSchemas->setObjectName(QStringLiteral("frSchemas"));
        frSchemas->resize(359, 458);
        const QIcon icon = QIcon(QString::fromUtf8(":/png/buttons/16/appearance.png"));
        frSchemas->setWindowIcon(icon);
        gridLayout = new QGridLayout(frSchemas);
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
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(frSchemas);
        okButton->setObjectName(QStringLiteral("okButton"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy);
        const QIcon icon1 = QIcon(QString::fromUtf8(":/png/buttons/16/agt_action_success.png"));
        okButton->setIcon(icon1);

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(frSchemas);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        sizePolicy.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy);
        const QIcon icon2 = QIcon(QString::fromUtf8(":/png/buttons/16/agt_action_fail.png"));
        cancelButton->setIcon(icon2);

        hboxLayout->addWidget(cancelButton);


        gridLayout->addLayout(hboxLayout, 3, 0, 1, 2);

        tableView = new QTableView(frSchemas);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 1, 0, 1, 2);

        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(0);
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(0);
#ifndef Q_OS_MAC
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        spacerItem1 = new QSpacerItem(1, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem1);

        lblCor = new QLabel(frSchemas);
        lblCor->setObjectName(QStringLiteral("lblCor"));
        sizePolicy.setHeightForWidth(lblCor->sizePolicy().hasHeightForWidth());
        lblCor->setSizePolicy(sizePolicy);
        lblCor->setMinimumSize(QSize(40, 40));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(212, 208, 200, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(234, 229, 220, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(128, 128, 128, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(141, 139, 133, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush6(QColor(64, 64, 64, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        QBrush brush7(QColor(10, 36, 106, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush7);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        QBrush brush8(QColor(0, 0, 255, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush8);
        QBrush brush9(QColor(255, 0, 255, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush9);
        QBrush brush10(QColor(232, 232, 232, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        QBrush brush11(QColor(106, 104, 100, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        QBrush brush12(QColor(233, 231, 227, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush12);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        lblCor->setPalette(palette);
        lblCor->setAutoFillBackground(true);
        lblCor->setFrameShape(QFrame::StyledPanel);
        lblCor->setFrameShadow(QFrame::Sunken);
        lblCor->setMidLineWidth(1);

        hboxLayout1->addWidget(lblCor);

        spacerItem2 = new QSpacerItem(1, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem2);


        vboxLayout->addLayout(hboxLayout1);

        pbAlterar = new QPushButton(frSchemas);
        pbAlterar->setObjectName(QStringLiteral("pbAlterar"));

        vboxLayout->addWidget(pbAlterar);


        gridLayout->addLayout(vboxLayout, 2, 1, 1, 1);

        hboxLayout2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout2->setSpacing(6);
#endif
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QStringLiteral("hboxLayout2"));
        vboxLayout1 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        label_3 = new QLabel(frSchemas);
        label_3->setObjectName(QStringLiteral("label_3"));
        QPalette palette1;
        QBrush brush13(QColor(189, 0, 0, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush13);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush7);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Link, brush8);
        palette1.setBrush(QPalette::Active, QPalette::LinkVisited, brush9);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Link, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Link, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        label_3->setPalette(palette1);

        vboxLayout1->addWidget(label_3);

        label = new QLabel(frSchemas);
        label->setObjectName(QStringLiteral("label"));
        QPalette palette2;
        QBrush brush14(QColor(0, 156, 0, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush14);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush7);
        palette2.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Link, brush8);
        palette2.setBrush(QPalette::Active, QPalette::LinkVisited, brush9);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Link, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Highlight, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Link, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        label->setPalette(palette2);

        vboxLayout1->addWidget(label);

        label_2 = new QLabel(frSchemas);
        label_2->setObjectName(QStringLiteral("label_2"));
        QPalette palette3;
        QBrush brush15(QColor(0, 0, 127, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush15);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Highlight, brush7);
        palette3.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Link, brush8);
        palette3.setBrush(QPalette::Active, QPalette::LinkVisited, brush9);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush15);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Highlight, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Link, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Highlight, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Link, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        label_2->setPalette(palette3);

        vboxLayout1->addWidget(label_2);


        hboxLayout2->addLayout(vboxLayout1);

        vboxLayout2 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout2->setSpacing(6);
#endif
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
        vboxLayout2->setObjectName(QStringLiteral("vboxLayout2"));
        slRed = new QSlider(frSchemas);
        slRed->setObjectName(QStringLiteral("slRed"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(5), static_cast<QSizePolicy::Policy>(0));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(slRed->sizePolicy().hasHeightForWidth());
        slRed->setSizePolicy(sizePolicy1);
        slRed->setMinimumSize(QSize(120, 0));
        slRed->setMaximum(255);
        slRed->setOrientation(Qt::Horizontal);

        vboxLayout2->addWidget(slRed);

        slGreen = new QSlider(frSchemas);
        slGreen->setObjectName(QStringLiteral("slGreen"));
        slGreen->setMaximum(255);
        slGreen->setOrientation(Qt::Horizontal);

        vboxLayout2->addWidget(slGreen);

        slBlue = new QSlider(frSchemas);
        slBlue->setObjectName(QStringLiteral("slBlue"));
        slBlue->setMaximum(255);
        slBlue->setOrientation(Qt::Horizontal);

        vboxLayout2->addWidget(slBlue);


        hboxLayout2->addLayout(vboxLayout2);


        gridLayout->addLayout(hboxLayout2, 2, 0, 1, 1);

        hboxLayout3 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout3->setSpacing(6);
#endif
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
        hboxLayout3->setObjectName(QStringLiteral("hboxLayout3"));
        pbAdcionar = new QPushButton(frSchemas);
        pbAdcionar->setObjectName(QStringLiteral("pbAdcionar"));
        const QIcon icon3 = QIcon(QString::fromUtf8(":/png/buttons/16/edit_add.png"));
        pbAdcionar->setIcon(icon3);

        hboxLayout3->addWidget(pbAdcionar);

        pbRemover = new QPushButton(frSchemas);
        pbRemover->setObjectName(QStringLiteral("pbRemover"));
        const QIcon icon4 = QIcon(QString::fromUtf8(":/png/buttons/16/button_cancel.png"));
        pbRemover->setIcon(icon4);

        hboxLayout3->addWidget(pbRemover);

        spacerItem3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout3->addItem(spacerItem3);


        gridLayout->addLayout(hboxLayout3, 0, 0, 1, 1);


        retranslateUi(frSchemas);
        QObject::connect(okButton, SIGNAL(clicked()), frSchemas, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), frSchemas, SLOT(reject()));

        QMetaObject::connectSlotsByName(frSchemas);
    } // setupUi

    void retranslateUi(QDialog *frSchemas)
    {
        frSchemas->setWindowTitle(QApplication::translate("frSchemas", "Esquema de Cores", nullptr));
        okButton->setText(QApplication::translate("frSchemas", "OK", nullptr));
        cancelButton->setText(QApplication::translate("frSchemas", "Cancelar", nullptr));
        lblCor->setText(QString());
        pbAlterar->setText(QApplication::translate("frSchemas", "Alterar", nullptr));
        label_3->setText(QApplication::translate("frSchemas", "Vermelho", nullptr));
        label->setText(QApplication::translate("frSchemas", "Verde", nullptr));
        label_2->setText(QApplication::translate("frSchemas", "Azul", nullptr));
        pbAdcionar->setText(QApplication::translate("frSchemas", "Adcionar", nullptr));
        pbRemover->setText(QApplication::translate("frSchemas", "Remover", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frSchemas: public Ui_frSchemas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRSCHEMAS_H
