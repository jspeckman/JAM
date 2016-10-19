#include "dialogpreferences.h"
#include "ui_preferences.h"

DialogPreferences::DialogPreferences(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPreferences)
{

    ui->setupUi(this);
}
