/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <QTextEdit>
#include <QSplitter>
#include <QTableWidget>
QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionTextEdit;
    QAction *actionLexical_Analyze_Window;
    QAction *actionLexcial_Analyze;
    QAction *actionSyntax_Analysis;
    QAction *actionSyntax_Analysis_Window;

    QAction *actionSemantic_Analysis;
    QAction *actionSemantic_Analysis_Window;
    QAction *actionSemantic_Err_Window;

    QTextEdit *textEdit;
    QTableWidget *table;

    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menuWindow;
    QMenu *menuAnalyze;
    QStatusBar *statusbar;
    QDockWidget *TextEdit;
    QWidget *dockWidgetContents;
    QDockWidget *LexicalAnalysisWin;
    QWidget *dockWidgetContents_4;
    QDockWidget *SyntaxAnalysisWin;
    QWidget *dockWidgetContents_5;
    QDockWidget *SemanticAnalysisWin;
    QWidget *dockWidgetContents_6;
    QDockWidget *SemanticErrWin;
    QWidget *dockWidgetContents_7;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);

        actionOpen = new QAction(QIcon(":/images/file-open.png"), QObject::tr("&Open..."), MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionOpen->setShortcuts(QKeySequence::Open);
        actionOpen->setStatusTip(QObject::tr("Open an existing file"));

        actionSave = new QAction(QIcon(":/images/file-save.png"), QObject::tr("&Save..."), MainWindow);
        actionSave->setShortcuts(QKeySequence::Save);
        actionSave->setStatusTip(QObject::tr("Save a new file"));
        actionSave->setObjectName(QStringLiteral("actionSave"));

        actionTextEdit = new QAction(MainWindow);
        actionTextEdit->setObjectName(QStringLiteral("actionTextEdit"));
        actionLexical_Analyze_Window = new QAction(MainWindow);
        actionLexical_Analyze_Window->setObjectName(QStringLiteral("actionLexical_Analyze_Window"));
        actionLexcial_Analyze = new QAction(MainWindow);
        actionLexcial_Analyze->setObjectName(QStringLiteral("actionLexcial_Analyze"));
        actionSyntax_Analysis = new QAction(MainWindow);
        actionSyntax_Analysis->setObjectName(QStringLiteral("actionSyntax_Analysis"));
        actionSyntax_Analysis_Window = new QAction(MainWindow);
        actionSyntax_Analysis_Window->setObjectName(QStringLiteral("actionSyntax_Analysis_Window"));
        actionSemantic_Analysis = new QAction(MainWindow);
        actionSemantic_Analysis->setObjectName(QStringLiteral("actionSemantic_Analysis"));
        actionSemantic_Analysis_Window = new QAction(MainWindow);
        actionSemantic_Analysis_Window->setObjectName(QStringLiteral("actionSemantic_Analysis_Window"));
        actionSemantic_Err_Window = new QAction(MainWindow);
        actionSemantic_Err_Window->setObjectName(QStringLiteral("actionSemantic_Err_Window"));





        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        menuWindow = new QMenu(menubar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        menuAnalyze = new QMenu(menubar);
        menuAnalyze->setObjectName(QStringLiteral("menuAnalyze"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        TextEdit = new QDockWidget(MainWindow);
        TextEdit->setObjectName(QStringLiteral("TextEdit"));
        TextEdit->setAutoFillBackground(false);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        TextEdit->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), TextEdit);
        LexicalAnalysisWin = new QDockWidget(QObject::tr("lex anaylasis"),MainWindow);
        LexicalAnalysisWin->setObjectName(QStringLiteral("LexicalAnalysisWin"));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        LexicalAnalysisWin->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), LexicalAnalysisWin);
        SyntaxAnalysisWin = new QDockWidget(MainWindow);
        SyntaxAnalysisWin->setObjectName(QStringLiteral("SyntaxAnalysisWin"));
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QStringLiteral("dockWidgetContents_5"));
        SyntaxAnalysisWin->setWidget(dockWidgetContents_5);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), SyntaxAnalysisWin);
        SemanticAnalysisWin = new QDockWidget(QObject::tr("四元式表"),MainWindow);
        SemanticAnalysisWin->setObjectName(QStringLiteral("SemanticAnalysisWin"));
        dockWidgetContents_6 = new QWidget();
        dockWidgetContents_6->setObjectName(QStringLiteral("dockWidgetContents_6"));
        SemanticAnalysisWin->setWidget(dockWidgetContents_6);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), SemanticAnalysisWin);

        SemanticErrWin = new QDockWidget(QObject::tr("错误列表"),MainWindow);
        SemanticErrWin->setObjectName(QStringLiteral("SemanticErrWin"));
        dockWidgetContents_7 = new QWidget();
        dockWidgetContents_7->setObjectName(QStringLiteral("dockWidgetContents_7"));
        SemanticErrWin->setWidget(dockWidgetContents_7);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), SemanticErrWin);


        menubar->addAction(menu->menuAction());
        menubar->addAction(menuAnalyze->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menu->addAction(actionOpen);
        menu->addAction(actionSave);
        menuWindow->addAction(actionTextEdit);
        menuWindow->addAction(actionLexical_Analyze_Window);
        menuWindow->addAction(actionSyntax_Analysis_Window);
        menuWindow->addAction(actionSemantic_Analysis_Window);
        menuWindow->addAction(actionSemantic_Err_Window);
        menuAnalyze->addAction(actionLexcial_Analyze);
        menuAnalyze->addAction(actionSyntax_Analysis);
        menuAnalyze->addAction(actionSemantic_Analysis);

        textEdit = new QTextEdit(TextEdit);
       // QHBoxLayout *mainlayout = new QHBoxLayout(TextEdit);
        //    mainlayout->setMargin(5);
         //   mainlayout->setSpacing(5);
         //   mainlayout->addWidget(textEdit);
          //  TextEdit->setLayout(mainlayout);
        TextEdit->setWidget(textEdit);
        TextEdit->setWidget(textEdit);
        QFont font;
        font.setPointSize(14);
        TextEdit->setFont(font);

        table = new QTableWidget(4,2);  //新建一4行2列的表格


        //设置表格行标题
        QStringList headerLabels;
        headerLabels << "word num" << "word type";
        table->setHorizontalHeaderLabels(headerLabels);


        //设置表格行标题的对齐方式
        table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

        //设置行表题
        QStringList rowLabels;
        rowLabels << "Line1" << "Line2" << "Line3" << "Line4";
        table->setVerticalHeaderLabels(rowLabels);


        //设置每一行的高度
       // for(int i = 0; i < 4; i++)
          //  table->setRowHeight(i, 22);

        //自动调整最后一列的宽度使它和表格的右边界对齐
        table->horizontalHeader()->setStretchLastSection(true);

        //设置表格的选择方式
        table->setSelectionBehavior(QAbstractItemView::SelectItems);

        //设置编辑方式
        //table->setEditTriggers(QAbstractItemView::DoubleClicked);

        //设置表格的内容
        for (int row = 0; row < 4; ++row)
        {
            QTableWidgetItem *item0, *item1;
            item0 = new QTableWidgetItem;
            item1 = new QTableWidgetItem;

            QString txt = QString("%1").arg(row + 1);
            item0->setText(txt);
            table->setItem(row, 0, item0);

            txt = QString("%1").arg((row + 1) * 2);
            item1->setText(txt);
            table->setItem(row, 1, item1);

        }

        //增加一行
        table->setRowCount(5);
        QTableWidgetItem *vHeader5 = new QTableWidgetItem("Line5");
        table->setVerticalHeaderItem(4, vHeader5);

        QTableWidgetItem *item5_0, *item5_1;
        item5_0 = new QTableWidgetItem;
        item5_1 = new QTableWidgetItem;
        item5_0->setText(QString("%1").arg(5));
        item5_1->setText(QString("%1").arg(5 * 2));
        table->setItem(4, 0, item5_0);
        table->setItem(4, 1, item5_1);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);


        LexicalAnalysisWin->setWidget(table);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        actionTextEdit->setText(QApplication::translate("MainWindow", "TextEdit", Q_NULLPTR));
        actionLexical_Analyze_Window->setText(QApplication::translate("MainWindow", "Lexical Analysis Window", Q_NULLPTR));
        actionLexcial_Analyze->setText(QApplication::translate("MainWindow", "Lexcial Analysis", Q_NULLPTR));
        actionSyntax_Analysis->setText(QApplication::translate("MainWindow", "Syntax Analysis", Q_NULLPTR));
        actionSyntax_Analysis_Window->setText(QApplication::translate("MainWindow", "Syntax Analysis Window", Q_NULLPTR));
        actionSemantic_Analysis->setText(QApplication::translate("MainWindow", "Semantic Analysis", Q_NULLPTR));
        actionSemantic_Analysis_Window->setText(QApplication::translate("MainWindow", "Semantic Analysis Window", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        menuWindow->setTitle(QApplication::translate("MainWindow", "Window", Q_NULLPTR));
        menuAnalyze->setTitle(QApplication::translate("MainWindow", "Analyze", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
