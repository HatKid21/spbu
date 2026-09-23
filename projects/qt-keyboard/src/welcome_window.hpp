#pragma once

#include <QWidget>

namespace hatkid{
  class WelcomeWindow : public QWidget{
    Q_OBJECT
    public :
      WelcomeWindow(QWidget* parent = nullptr);

    signals:
      void keyboardWindowRequested();

  };
}
