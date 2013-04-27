#include "apgui.hpp"
#include "ui_apgui.h"

ApGui::ApGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ApGui)
{
    ui->setupUi(this);
}

ApGui::~ApGui()
{
    delete ui;
}
