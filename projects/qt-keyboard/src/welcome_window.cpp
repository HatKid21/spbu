#include <QPushButton>
#include <QGridLayout>

#include "welcome_window.hpp"

using hatkid::WelcomeWindow;

WelcomeWindow::WelcomeWindow(QWidget* parent) : QWidget(parent){
  QPushButton* button = new QPushButton("Перейти к клавиатуре",this); 
  button->setSizePolicy(
        QSizePolicy::Fixed,
        QSizePolicy::Fixed
    );
  QGridLayout* layout = new QGridLayout(this);
  layout->addWidget(button,0, Qt::AlignCenter);
  setLayout(layout);
  connect(button, &QPushButton::clicked, this, &WelcomeWindow::keyboardWindowRequested);
}
