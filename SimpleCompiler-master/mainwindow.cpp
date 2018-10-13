#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lexical.h"
#include "semantic.h"
#include "STree.cpp"
#include <QString>
#include <queue> 
#include "syntax.h"
#include "syntax.cpp"
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QDebug>
#include <QTextEdit>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QScrollArea>
#include <QScrollBar>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QWidget* p = takeCentralWidget();
        if(p)
            delete p;

    setDockNestingEnabled(true);



    QMainWindow::tabifyDockWidget(ui->LexicalAnalysisWin,ui->SemanticAnalysisWin);
    QMainWindow::tabifyDockWidget(ui->LexicalAnalysisWin,ui->SemanticErrWin);

    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openFile);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveFile);
    connect(ui->actionTextEdit, &QAction::triggered, this, &MainWindow::openTextEdit);
    connect(ui->actionLexical_Analyze_Window, &QAction::triggered, this, &MainWindow::openLexicalAnal);
    connect(ui->actionSyntax_Analysis_Window, &QAction::triggered, this, &MainWindow::openSyntaxAnal);
    connect(ui->actionLexcial_Analyze, &QAction::triggered, this, &MainWindow::LexicalAnalysis);
    connect(ui->actionSyntax_Analysis, &QAction::triggered, this, &MainWindow::SyntaxAnalysis);

    connect(ui->actionSemantic_Analysis_Window, &QAction::triggered, this, &MainWindow::openSemanticAnal);
    connect(ui->actionSemantic_Analysis, &QAction::triggered, this, &MainWindow::SemanticAnalysis);
    connect(ui->actionSemantic_Err_Window, &QAction::triggered, this, &MainWindow::openSemanticErr);


}

MainWindow::~MainWindow()
{
    delete ui;
}



FILE* MainWindow::FP(QString path){
    QString tempPath;
    for(int i=0;i<path.size();i++)
    {
        if(path[i]=='/')
        {
            tempPath.append('\\');
            tempPath.append('\\');
        }
        else
        {
            tempPath.append(path[i]);
        }
    }
    if(!path.isEmpty()) {

        char* PATH;
        QByteArray ba = tempPath.toLatin1(); // must
        PATH=ba.data();


        FILE *fp=fopen(PATH,"r");

        if (!fp) {

            return NULL;
        }
        else
            return fp;


    }
    return NULL;
}

void MainWindow::LexicalAnalysis(){
    Lex=new Lexical();

    FILE *fp=FP(PATH);


    while (fp&&!feof(fp)) {

        Lex->Result(fp);
    }

    fclose(fp);
    vector <pair<QString,const char *>>RESULT=Lex->getRESULT();
         QTableWidget *table;
        table = new QTableWidget(RESULT.size(),2);  //新建一4行2列的表格
        //设置表格行标题
        QStringList headerLabels;
        headerLabels << "单词值" << "单词类型";
        table->setHorizontalHeaderLabels(headerLabels);


        //设置表格行标题的对齐方式
        table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
        //自动调整最后一列的宽度使它和表格的右边界对齐
        table->horizontalHeader()->setStretchLastSection(true);

        //设置表格的选择方式
        table->setSelectionBehavior(QAbstractItemView::SelectItems);

        //设置编辑方式

        //设置表格的内容
        int row=0;
        for(vector<pair<QString,const char *>>::const_iterator iter = RESULT.cbegin(); iter != RESULT.cend(); iter++,row++)
        {
            QTableWidgetItem *item0, *item1;
            item0 = new QTableWidgetItem;
            item1 = new QTableWidgetItem;

            QString txt = QString((*iter).first);
            item0->setText(txt);
            table->setItem(row, 0, item0);

            txt = QString((*iter).second);
             //qDebug()<<"s:"<<QString(QLatin1String((*iter).second));
            item1->setText(txt);

            table->setItem(row, 1, item1);

        }
         table->setEditTriggers(QAbstractItemView::NoEditTriggers);

        ui->LexicalAnalysisWin->setWidget(table);
}

void MainWindow::SyntaxAnalysis(){

    FILE *fp=FP(PATH);
    STREE = new STree();
    if(!Analyze(STREE,fp))
        QMessageBox::about(NULL, "错误", "语法分析错误。");




    QTreeWidget *STT=new QTreeWidget(ui->SyntaxAnalysisWin);

   /* QList<QTreeWidgetItem *> rootList;

    queue<STree*> Q;
    queue<QTreeWidgetItem *>QItem;
    Q.push(STREE);
    QTreeWidgetItem *imageItem1 = new QTreeWidgetItem;   //添加第一个父节点
    imageItem1->setText(0,QString(STREE->getData()) );

    rootList.append(imageItem1);
    QItem.push(imageItem1);
    while (!Q.empty()) {

        STree* temp = Q.front();
        Q.pop();
        QTreeWidgetItem * tempItem=QItem.front();
        QItem.pop();

        for (int i=0; i<temp->getchild_num(); i++)
        {
            Q.push(temp->getChild(i));
            QTreeWidgetItem *newItem = new QTreeWidgetItem;   //添加第一个父节点
            newItem->setText(0,tr(temp->getChild(i)->getData()));

            //rootList.append(newItem);
            QItem.push(newItem);
            tempItem->addChild(newItem);
        }



    }

    STree *root = STREE;
    stack <STree*> ST;
    stack <int> DT;
    STree *current;

    ST.push(root);
    DT.push(0);

    int depth = 0;
    while (!ST.empty())
    {
        current = ST.top();
        ST.pop();
        depth = DT.top();
        DT.pop();
        for (int i = 0; i < depth; i++)
        {
            cout << "  ";
        }
        cout << current->getData() << endl;
        depth++;
        for (int j = 0; j <= current->getchild_num() - 1; j++)
        {
            ST.push(current->getChild(j));
            DT.push(depth);
        }
    }
*/
     QList<QTreeWidgetItem *> rootList;
    stack <STree*> ST;
    stack<QTreeWidgetItem *>QItem;
    STree *current;

    ST.push(STREE);
    QTreeWidgetItem *imageItem1 = new QTreeWidgetItem;   //添加第一个父节点
    imageItem1->setText(0,QString(STREE->getData()) );
    QItem.push(imageItem1);

    rootList.append(imageItem1);
    while (!ST.empty())
    {

        current = ST.top();
        ST.pop();
        QTreeWidgetItem * tempItem=QItem.top();
        QItem.pop();

        for (int j=0; j < current->getchild_num(); j++)
        {
            ST.push(current->getChild(j));
            QTreeWidgetItem *newItem = new QTreeWidgetItem;   //添加第一个父节点
            newItem->setText(0,tr(current->getChild(j)->getData()));

            //rootList.append(newItem);

            tempItem->addChild(newItem);
            QItem.push(newItem);
        }
    }



   // ST->header()->setMinimumSectionSize(2000);
    QHBoxLayout *layout = new QHBoxLayout;
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    //ST->setMinimumSize (100, 100 );
    //ST->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); //可选;
    scrollArea->setWidget(STT);
    scrollArea->setAlignment(Qt::AlignCenter);  // 居中对齐
    scrollArea->setWidgetResizable(true);  // 自动调整大小

    //scrollArea->show();
    STT->setHeaderLabel(tr("语法分析树"));
    STT->insertTopLevelItems(0,rootList);  //将结点插入部件中

    STT->expandAll(); //全部展开
    ui->SyntaxAnalysisWin->setWidget(scrollArea);


}

void MainWindow::openTextEdit(){
    ui->TextEdit->show();
}

void MainWindow::SemanticAnalysis()
{
   /* G=new Grammar();
    G->Init_Grammar();
    G->Show_Grammar();
    G->First();
    G->Follow();
    G->Show_First();
    G->Show_Follow();
    G->MTable();
*/
    FILE *fp=FP(PATH);
    STREE = new STree();
    if(!Analyze(STREE,fp))
        QMessageBox::about(NULL, "错误", "语法分析错误。");

    Semantic SEM;

    SEM.PostOrderTraverse(STREE);

    SEM.StableOut();
    /*                输出符号表                     */
    int ROW = 0;
    for(Quadruples* p = STREE->QLparent->head;p != NULL; p = p->next)
    {
        ROW++;
    }

         QTableWidget *table;
        table = new QTableWidget(ROW,5);
        //设置表格行标题
        QStringList headerLabels;
        headerLabels << "label" << "op"<<"arg1"<<"arg2"<<"result";
        table->setHorizontalHeaderLabels(headerLabels);
        QHeaderView* headerView = table->horizontalHeader();
        headerView->setSectionResizeMode(QHeaderView::Stretch);

        //设置表格行标题的对齐方式
        table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
        //自动调整最后一列的宽度使它和表格的右边界对齐
        table->horizontalHeader()->setStretchLastSection(true);

        //设置表格的选择方式
        table->setSelectionBehavior(QAbstractItemView::SelectItems);

        //设置编辑方式

        //设置表格的内容
        int row=0;
        for(Quadruples* TempQuad = STREE->QLparent->head; TempQuad != NULL; TempQuad = TempQuad->next,row++)
        {
            QTableWidgetItem *item0, *item1, *item2, *item3, *item4;
            item0 = new QTableWidgetItem;
            item1 = new QTableWidgetItem;
            item2 = new QTableWidgetItem;
            item3 = new QTableWidgetItem;
            item4 = new QTableWidgetItem;



            item0->setText(tr(TempQuad->label));
            table->setItem(row, 0, item0);
           // qDebug(TempQuad->label);

            item1->setText(tr(TempQuad->op));
            table->setItem(row, 1, item1);


            item2->setText(tr(TempQuad->arg1));
            table->setItem(row, 2, item2);


            item3->setText(tr(TempQuad->arg2));
            table->setItem(row, 3, item3);


            item4->setText(tr(TempQuad->result));
            table->setItem(row, 4, item4);

        }
         table->setEditTriggers(QAbstractItemView::NoEditTriggers);

        ui->SemanticAnalysisWin->setWidget(table);

         /*                输出错误列表                     */
        ROW = 0;
        for(ERR_Node* p = SEM.Etable.head;p != NULL; p = p->next)
        {
            ROW++;
        }

        QTableWidget *ErrTable;
        ErrTable = new QTableWidget(ROW,1);
        //设置表格行标题
        QStringList ErrheaderLabels;
        ErrheaderLabels << "说明";
        ErrTable->setHorizontalHeaderLabels(ErrheaderLabels);
        QHeaderView* ErrheaderView = ErrTable->horizontalHeader();
        ErrheaderView->setSectionResizeMode(QHeaderView::Stretch);

        //设置表格行标题的对齐方式
        ErrTable->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
        //自动调整最后一列的宽度使它和表格的右边界对齐
        ErrTable->horizontalHeader()->setStretchLastSection(true);

        //设置表格的选择方式
        ErrTable->setSelectionBehavior(QAbstractItemView::SelectItems);

        //设置编辑方式

        //设置表格的内容
        int row1=0;
        for(ERR_Node* TempErr = SEM.Etable.head; TempErr!= NULL; TempErr = TempErr->next,row1++)
        {
            QTableWidgetItem *item0;
            item0 = new QTableWidgetItem;


             QString txt = QString(TempErr->ErrorMessage);
            item0->setText(txt);
            ErrTable->setItem(row1, 0, item0);
           // qDebug(TempQuad->label);

        }
        ErrTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

        ui->SemanticErrWin->setWidget(ErrTable);

}

void MainWindow::openLexicalAnal(){
    ui->LexicalAnalysisWin->show();
}

void MainWindow::openSyntaxAnal(){
    ui->SyntaxAnalysisWin->show();
}

void MainWindow::openSemanticAnal(){
    ui->SemanticAnalysisWin->show();
}

void MainWindow::openSemanticErr(){
    ui->SemanticErrWin->show();
}

void MainWindow::openFile()
{
    QString path = QFileDialog::getOpenFileName(this,
                                                tr("Open File"),
                                                ".",
                                                tr("Text Files(*.txt);;Cpp Files(*.cpp);;Header Files(*.h)"));
    if(!path.isEmpty()) {
        QFile file(path);
        PATH=path;
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this, tr("Read File"),
                                 tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream in(&file);
        TextStr = new QTextStream(&file);
        ui->textEdit->setText(in.readAll());
        file.close();
    } else {
        QMessageBox::warning(this, tr("Path"),
                             tr("You did not select any file."));
    }
}

void MainWindow::saveFile()
{

    QString path=PATH;
    if(!path.isEmpty()) {
        QFile file(path);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, tr("Write File"),
                                       tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream out(&file);
        out << ui->textEdit->toPlainText();
        file.close();
    } else {
        QMessageBox::warning(this, tr("Path"),
                             tr("You did not select any file."));
    }
}
