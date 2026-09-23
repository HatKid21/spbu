#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

#include "welcome_window.hpp"

using hatkid::WelcomeWindow;

WelcomeWindow::WelcomeWindow(QWidget* parent): QWidget(parent){

  QLabel* text = new QLabel("Добро пожаловать в клавиатуру! Она чего-то взгрустнула. Развесели её!", this);

  QPushButton* button = new QPushButton("Перейти к клавиатуре",this); 
  button->setSizePolicy(
        QSizePolicy::Fixed,
        QSizePolicy::Fixed
    );
  QVBoxLayout* layout = new QVBoxLayout(this);
  layout->addWidget(text,0,Qt::AlignCenter);
  layout->addWidget(button,0, Qt::AlignCenter);
  setLayout(layout);
  connect(button, &QPushButton::clicked, this, &WelcomeWindow::keyboardWindowRequested);

  adjustSize();

}
