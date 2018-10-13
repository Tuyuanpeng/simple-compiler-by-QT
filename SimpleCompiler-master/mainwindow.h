#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <stdio.h>
#include "syntax.h"
#include "lexical.h"

#include "STree.h"
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QTextStream *TextStr;
    QString PATH;
    Lexical *Lex;
    STree *STREE;
    Grammar* G;
    FILE* FP(QString path);
    void openFile();
    void saveFile();
    void openTextEdit();
    void openLexicalAnal();
    void openSyntaxAnal();
    void openSemanticAnal();
    void openSemanticErr();
    void LexicalAnalysis();
    void SyntaxAnalysis();
    void SemanticAnalysis();
    friend bool Analyze(STree* &root,FILE* fp);
};

#endif // MAINWINDOW_H
