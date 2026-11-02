#include "finddialog.h"
#include "ui_finddialog.h"

FindDialog::FindDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FindDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("查找"));
    ui->labelResult->clear();
    ui->radioDown->setChecked(true);
    connect(ui->lineEditFind,&QLineEdit::textChanged,this,[this](const QString &){
        ui->labelResult->clear();
    });
}

FindDialog::~FindDialog()
{
    delete ui;
}

void FindDialog::setFindText(const QString &text){
    ui->lineEditFind->setText(text);
    ui->lineEditFind->selectAll();
    ui->lineEditFind->setFocus();
}

QString FindDialog::findText() const{
    return ui->lineEditFind->text();
}

void FindDialog::showResult(const QString &text,bool isError){
    ui->labelResult->setText(text);
    ui->labelResult->setStyleSheet(isError?QStringLiteral("color:#c0392b;"):"color:#2d7d46;");
}

void FindDialog::on_btnFindNext_clicked(){
    const QString key=ui->lineEditFind->text();
    if(key.isEmpty()){
        showResult(tr("请输入要查找的内容"),true);
        ui->lineEditFind->setFocus();
        return;
    }
    emit findNextRequested(key,
                           ui->checkCase->isChecked(),
                           ui->radioUp->isChecked());
}

void FindDialog::on_btnClose_clicked(){
    close();
}
