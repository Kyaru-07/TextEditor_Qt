#include "replacedialog.h"
#include "ui_replacedialog.h"

ReplaceDialog::ReplaceDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReplaceDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("替换"));
    ui->labelResult->clear();
    ui->radioDown->setChecked(true);
    connect(ui->lineEditFind,&QLineEdit::textChanged,this,[this](const QString &){
        ui->labelResult->clear();
    });
    connect(ui->lineEditReplace,&QLineEdit::textChanged,this,[this](const QString &){
        ui->labelResult->clear();
    });
}

ReplaceDialog::~ReplaceDialog()
{
    delete ui;
}

void ReplaceDialog::setFindText(const QString &text){
    ui->lineEditFind->setText(text);
    ui->lineEditFind->selectAll();
    ui->lineEditFind->setFocus();
}

QString ReplaceDialog::findText() const{
    return ui->lineEditFind->text();
}

QString ReplaceDialog::replaceText() const{
    return ui->lineEditReplace->text();
}

void ReplaceDialog::showResult(const QString &text,bool isError){
    ui->labelResult->setText(text);
    ui->labelResult->setStyleSheet(isError?QStringLiteral("color:#c0392b;"):QStringLiteral("color:#2d7d46"));
}

bool ReplaceDialog::checkInput(){
    if(ui->lineEditFind->text().isEmpty()){
        showResult(tr("请输入查找的内容"),true);
        ui->lineEditFind->setFocus();
        return false;
    }
    return true;
}

void ReplaceDialog::on_btnFindNext_clicked()
{
    if(!checkInput())
        return;
    emit findNextRequested(ui->lineEditFind->text(),ui->checkCase->isChecked());
}

void ReplaceDialog::on_btnReplace_clicked()
{
    if(!checkInput()){
        return;
    }
    emit replaceRequested(ui->lineEditFind->text(),
                          ui->lineEditReplace->text(),
                          ui->checkCase->isChecked());
}

void ReplaceDialog::on_btnReplaceAll_clicked()
{
    if(!checkInput())
        return;
    emit replaceAllRequested(ui->lineEditFind->text(),
                             ui->lineEditReplace->text(),
                             ui->checkCase->isChecked());
}


void ReplaceDialog::on_btnClose_clicked()
{
    close();
}

