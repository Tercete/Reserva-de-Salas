/********************************************************************************
** Form generated from reading UI file 'frmain.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMAIN_H
#define UI_FRMAIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSalas;
    QAction *actionAdicionar;
    QAction *actionRemover;
    QAction *actionAlterar;
    QAction *actionUsuarios;
    QAction *actionCores;
    QAction *actionImprimirLista;
    QAction *actionImprimirReserva;
    QAction *actionHoje;
    QAction *actionCopiar;
    QAction *actionAreas;
    QAction *actionSobreRS;
    QAction *actionSobreQt;
    QAction *actionEnglish;
    QAction *actionPortugu_s;
    QAction *actionTESTE;
    QAction *actionDs;
    QAction *actionSemanal;
    QAction *actionMensal;
    QAction *actionOutro;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QPushButton *pbAdicionar;
    QPushButton *pbRemover;
    QSpacerItem *spacerItem;
    QLabel *lbAreas;
    QComboBox *cbArea;
    QSpacerItem *spacerItem1;
    QToolButton *btAnte;
    QLabel *lbData;
    QToolButton *btProx;
    QTableWidget *tbReservas;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjuda;
    QMenu *menuConfigura_es;
    QMenu *menuLingua;
    QMenu *menuEstilo;
    QMenu *menuIntervalo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(722, 554);
        QIcon icon;
        icon.addFile(QStringLiteral(":/png/buttons/16/dissociatecell.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionSalas = new QAction(MainWindow);
        actionSalas->setObjectName(QStringLiteral("actionSalas"));
        actionSalas->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/png/buttons/16/irkick.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSalas->setIcon(icon1);
        actionAdicionar = new QAction(MainWindow);
        actionAdicionar->setObjectName(QStringLiteral("actionAdicionar"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/png/buttons/16/edit_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdicionar->setIcon(icon2);
        actionRemover = new QAction(MainWindow);
        actionRemover->setObjectName(QStringLiteral("actionRemover"));
        actionRemover->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/png/buttons/16/button_cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemover->setIcon(icon3);
        actionAlterar = new QAction(MainWindow);
        actionAlterar->setObjectName(QStringLiteral("actionAlterar"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/png/buttons/16/cell_layout.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAlterar->setIcon(icon4);
        actionUsuarios = new QAction(MainWindow);
        actionUsuarios->setObjectName(QStringLiteral("actionUsuarios"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/png/buttons/16/agt_family.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUsuarios->setIcon(icon5);
        actionCores = new QAction(MainWindow);
        actionCores->setObjectName(QStringLiteral("actionCores"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/png/buttons/16/appearance.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCores->setIcon(icon6);
        actionImprimirLista = new QAction(MainWindow);
        actionImprimirLista->setObjectName(QStringLiteral("actionImprimirLista"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/png/buttons/16/print_printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionImprimirLista->setIcon(icon7);
        actionImprimirReserva = new QAction(MainWindow);
        actionImprimirReserva->setObjectName(QStringLiteral("actionImprimirReserva"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/png/buttons/16/agt_print.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionImprimirReserva->setIcon(icon8);
        actionHoje = new QAction(MainWindow);
        actionHoje->setObjectName(QStringLiteral("actionHoje"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/png/buttons/16/today.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHoje->setIcon(icon9);
        actionCopiar = new QAction(MainWindow);
        actionCopiar->setObjectName(QStringLiteral("actionCopiar"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/png/buttons/16/editcopy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopiar->setIcon(icon10);
        actionAreas = new QAction(MainWindow);
        actionAreas->setObjectName(QStringLiteral("actionAreas"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/png/buttons/16/edit_group.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAreas->setIcon(icon11);
        actionSobreRS = new QAction(MainWindow);
        actionSobreRS->setObjectName(QStringLiteral("actionSobreRS"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/png/buttons/16/rs.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSobreRS->setIcon(icon12);
        actionSobreQt = new QAction(MainWindow);
        actionSobreQt->setObjectName(QStringLiteral("actionSobreQt"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/png/buttons/16/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSobreQt->setIcon(icon13);
        actionSobreQt->setMenuRole(QAction::AboutQtRole);
        actionEnglish = new QAction(MainWindow);
        actionEnglish->setObjectName(QStringLiteral("actionEnglish"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/png/buttons/16/uk.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnglish->setIcon(icon14);
        actionPortugu_s = new QAction(MainWindow);
        actionPortugu_s->setObjectName(QStringLiteral("actionPortugu_s"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/png/buttons/16/brasil.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPortugu_s->setIcon(icon15);
        actionTESTE = new QAction(MainWindow);
        actionTESTE->setObjectName(QStringLiteral("actionTESTE"));
        actionDs = new QAction(MainWindow);
        actionDs->setObjectName(QStringLiteral("actionDs"));
        actionSemanal = new QAction(MainWindow);
        actionSemanal->setObjectName(QStringLiteral("actionSemanal"));
        actionSemanal->setCheckable(true);
        actionSemanal->setChecked(true);
        actionMensal = new QAction(MainWindow);
        actionMensal->setObjectName(QStringLiteral("actionMensal"));
        actionMensal->setCheckable(true);
        actionOutro = new QAction(MainWindow);
        actionOutro->setObjectName(QStringLiteral("actionOutro"));
        actionOutro->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
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
        pbAdicionar = new QPushButton(centralwidget);
        pbAdicionar->setObjectName(QStringLiteral("pbAdicionar"));
        pbAdicionar->setEnabled(false);
        pbAdicionar->setIcon(icon2);

        hboxLayout->addWidget(pbAdicionar);

        pbRemover = new QPushButton(centralwidget);
        pbRemover->setObjectName(QStringLiteral("pbRemover"));
        pbRemover->setEnabled(false);
        pbRemover->setIcon(icon3);

        hboxLayout->addWidget(pbRemover);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        lbAreas = new QLabel(centralwidget);
        lbAreas->setObjectName(QStringLiteral("lbAreas"));

        hboxLayout->addWidget(lbAreas);

        cbArea = new QComboBox(centralwidget);
        cbArea->setObjectName(QStringLiteral("cbArea"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cbArea->sizePolicy().hasHeightForWidth());
        cbArea->setSizePolicy(sizePolicy);

        hboxLayout->addWidget(cbArea);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem1);

        btAnte = new QToolButton(centralwidget);
        btAnte->setObjectName(QStringLiteral("btAnte"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/png/buttons/16/2leftarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        btAnte->setIcon(icon16);
        btAnte->setAutoRaise(true);

        hboxLayout->addWidget(btAnte);

        lbData = new QLabel(centralwidget);
        lbData->setObjectName(QStringLiteral("lbData"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lbData->sizePolicy().hasHeightForWidth());
        lbData->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QStringLiteral("Sans Serif"));
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(true);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        lbData->setFont(font);
        lbData->setFrameShadow(QFrame::Plain);
        lbData->setAlignment(Qt::AlignCenter);

        hboxLayout->addWidget(lbData);

        btProx = new QToolButton(centralwidget);
        btProx->setObjectName(QStringLiteral("btProx"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/png/buttons/16/2rightarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        btProx->setIcon(icon17);
        btProx->setAutoRaise(true);

        hboxLayout->addWidget(btProx);


        gridLayout->addLayout(hboxLayout, 0, 0, 1, 1);

        tbReservas = new QTableWidget(centralwidget);
        tbReservas->setObjectName(QStringLiteral("tbReservas"));

        gridLayout->addWidget(tbReservas, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 722, 24));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuAjuda = new QMenu(menubar);
        menuAjuda->setObjectName(QStringLiteral("menuAjuda"));
        menuConfigura_es = new QMenu(menubar);
        menuConfigura_es->setObjectName(QStringLiteral("menuConfigura_es"));
        menuLingua = new QMenu(menuConfigura_es);
        menuLingua->setObjectName(QStringLiteral("menuLingua"));
        menuEstilo = new QMenu(menuConfigura_es);
        menuEstilo->setObjectName(QStringLiteral("menuEstilo"));
        menuIntervalo = new QMenu(menuConfigura_es);
        menuIntervalo->setObjectName(QStringLiteral("menuIntervalo"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menubar->addAction(menuConfigura_es->menuAction());
        menubar->addAction(menuAjuda->menuAction());
        menuMenu->addAction(actionAreas);
        menuMenu->addAction(actionSalas);
        menuMenu->addAction(actionUsuarios);
        menuMenu->addAction(actionCores);
        menuAjuda->addAction(actionSobreRS);
        menuAjuda->addAction(actionSobreQt);
        menuConfigura_es->addAction(menuLingua->menuAction());
        menuConfigura_es->addAction(menuEstilo->menuAction());
        menuConfigura_es->addAction(menuIntervalo->menuAction());
        menuLingua->addAction(actionEnglish);
        menuLingua->addAction(actionPortugu_s);
        menuEstilo->addSeparator();
        menuIntervalo->addAction(actionSemanal);
        menuIntervalo->addAction(actionMensal);
        menuIntervalo->addAction(actionOutro);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RS", nullptr));
        actionSalas->setText(QApplication::translate("MainWindow", "Salas", nullptr));
        actionAdicionar->setText(QApplication::translate("MainWindow", "Adicionar", nullptr));
        actionAdicionar->setIconText(QApplication::translate("MainWindow", "Adicionar", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAdicionar->setToolTip(QApplication::translate("MainWindow", "Adicionar", nullptr));
#endif // QT_NO_TOOLTIP
        actionRemover->setText(QApplication::translate("MainWindow", "Remover", nullptr));
        actionAlterar->setText(QApplication::translate("MainWindow", "Alterar", nullptr));
        actionUsuarios->setText(QApplication::translate("MainWindow", "Usu\303\241rios", nullptr));
        actionUsuarios->setIconText(QApplication::translate("MainWindow", "Usu\303\241rios", nullptr));
#ifndef QT_NO_TOOLTIP
        actionUsuarios->setToolTip(QApplication::translate("MainWindow", "Usu\303\241rios", nullptr));
#endif // QT_NO_TOOLTIP
        actionCores->setText(QApplication::translate("MainWindow", "Cores", nullptr));
        actionImprimirLista->setText(QApplication::translate("MainWindow", "Imprimir Lista", nullptr));
        actionImprimirReserva->setText(QApplication::translate("MainWindow", "Imprimir Reserva", nullptr));
        actionHoje->setText(QApplication::translate("MainWindow", "Hoje", nullptr));
        actionCopiar->setText(QApplication::translate("MainWindow", "Copiar Lista", nullptr));
        actionAreas->setText(QApplication::translate("MainWindow", "\303\201reas", nullptr));
        actionSobreRS->setText(QApplication::translate("MainWindow", "Sobre o Reserva de Salas", nullptr));
        actionSobreQt->setText(QApplication::translate("MainWindow", "Sobre o Qt", nullptr));
        actionEnglish->setText(QApplication::translate("MainWindow", "English", nullptr));
        actionPortugu_s->setText(QApplication::translate("MainWindow", "Portugu\303\252s", nullptr));
        actionTESTE->setText(QApplication::translate("MainWindow", "TESTE", nullptr));
        actionDs->setText(QApplication::translate("MainWindow", "ds", nullptr));
        actionSemanal->setText(QApplication::translate("MainWindow", "Semanal", nullptr));
        actionMensal->setText(QApplication::translate("MainWindow", "Mensal", nullptr));
        actionOutro->setText(QApplication::translate("MainWindow", "Outro...", nullptr));
        pbAdicionar->setText(QApplication::translate("MainWindow", "Adicionar", nullptr));
        pbRemover->setText(QApplication::translate("MainWindow", "Remover", nullptr));
        lbAreas->setText(QApplication::translate("MainWindow", "\303\201rea", nullptr));
        btAnte->setText(QString());
        lbData->setText(QApplication::translate("MainWindow", "Data", nullptr));
        btProx->setText(QString());
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", nullptr));
        menuAjuda->setTitle(QApplication::translate("MainWindow", "Ajuda", nullptr));
        menuConfigura_es->setTitle(QApplication::translate("MainWindow", "Configura\303\247\303\265es", nullptr));
        menuLingua->setTitle(QApplication::translate("MainWindow", "Lingua", nullptr));
        menuEstilo->setTitle(QApplication::translate("MainWindow", "Estilo", nullptr));
        menuIntervalo->setTitle(QApplication::translate("MainWindow", "Intervalo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMAIN_H
