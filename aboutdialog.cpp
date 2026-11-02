#include "aboutdialog.h"
#include "ui_aboutdialog.h"

#include <QIcon>

aboutDialog::aboutDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::aboutDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("关于"));

    ui->labelIcon->setPixmap(QIcon(QStringLiteral(":/icons/help-about.svg")).pixmap(72,72));
}

aboutDialog::~aboutDialog()
{
    delete ui;
}
