#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include "finddialog.h"
#include "replacedialog.h"
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//关于
void MainWindow::on_actionAbout_triggered(){
    aboutDialog dlg(this);
    dlg.exec();
}

//查找
void MainWindow::on_actionFind_triggered(){
    if(m_findDlg==nullptr){
        m_findDlg=new FindDialog(this);
        connect(m_findDlg,&FindDialog::findNextRequested,
                this,&MainWindow::onFindNextRequested);
    }

    const QString sel=ui->textEdit->textCursor().selectedText();
    if(!sel.isEmpty()&&!sel.contains(QChar::ParagraphSeparator))
        m_findDlg->setFindText(sel);

    m_findDlg->show();
    m_findDlg->raise();
    m_findDlg->activateWindow();
}

void MainWindow::onFindNextRequested(const QString &text, bool caseSensitive, bool backward)
{
    statusBar()->showMessage(
        tr("查找：%1 %2%3").arg(text,
                                caseSensitive ? tr("[区分大小写]") : QString(),
                                backward ? tr("[向上]") : QString()),
        3000);
}

//替换
void MainWindow::on_actionReplace_triggered(){
    if(m_replaceDlg==nullptr){
        m_replaceDlg=new ReplaceDialog(this);
        connect(m_replaceDlg,&ReplaceDialog::findNextRequested,this,&MainWindow::onReplaceFindNext);
        connect(m_replaceDlg,&ReplaceDialog::replaceRequested,this,&MainWindow::onReplaceRequested);
        connect(m_replaceDlg,&ReplaceDialog::replaceAllRequested,this,&MainWindow::onReplaceAllRequested);
    }
    if(m_findDlg!=nullptr){
        m_findDlg->hide();
    }

    QString seed;
    if(m_findDlg!=nullptr){
        if(!m_findDlg->findText().isEmpty()){
            seed=m_findDlg->findText();
        }
    }
    if(seed.isEmpty()){
        seed=ui->textEdit->textCursor().selectedText();
    }
    if(!seed.isEmpty()&&!seed.contains(QChar::ParagraphSeparator)){
        m_replaceDlg->setFindText(seed);
    }

    m_replaceDlg->show();
    m_replaceDlg->raise();
    m_replaceDlg->activateWindow();
}

void MainWindow::onReplaceFindNext(const QString &text, bool caseSensitive)
{
    statusBar()->showMessage(tr("替换框-查找：%1%2").arg(text,
                                                         caseSensitive ? tr(" [区分大小写]") : QString()), 3000);
}

void MainWindow::onReplaceRequested(const QString &text, const QString &with, bool caseSensitive)
{
    statusBar()->showMessage(tr("替换：%1 → %2%3").arg(text, with,
                                                       caseSensitive ? tr(" [区分大小写]") : QString()), 3000);
}

void MainWindow::onReplaceAllRequested(const QString &text, const QString &with, bool caseSensitive)
{
    statusBar()->showMessage(tr("全部替换：%1 → %2%3").arg(text, with,
                                                           caseSensitive ? tr(" [区分大小写]") : QString()), 3000);
}