#ifndef APGUI_HPP
#define APGUI_HPP

#include <QMainWindow>

namespace Ui {
class ApGui;
}

class ApGui : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ApGui(QWidget *parent = 0);
    ~ApGui();
    
private:
    Ui::ApGui *ui;
};

#endif // APGUI_HPP
