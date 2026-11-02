#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

namespace Ui {
class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = nullptr);
    ~FindDialog();
    QString findText() const;
    void setFindText(const QString &text);
    void showResult(const QString &text,bool isError=false);

signals:
    void findNextRequested(const QString &text,bool caseSensitive,bool backward);

private slots:
    void on_btnFindNext_clicked();
    void on_btnClose_clicked();

private:
    Ui::FindDialog *ui;
};

#endif // FINDDIALOG_H
