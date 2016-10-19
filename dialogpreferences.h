#include <QDialog>
#include "ui_preferences.h"

class DialogPreferences : public QDialog
{
    Q_OBJECT
public:
    explicit DialogPreferences(QWidget *parent = 0);

private:
    Ui:: DialogPreferences *ui;
};
