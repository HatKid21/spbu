#include <QApplication>
#include <QWidget>

#include "keyboard_window.hpp"
#include "welcome_window.hpp"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    hatkid::WelcomeWindow welcome_window;
    biv::KeyBoardWindow keyboard_window;

    QObject::connect(
      &welcome_window, &hatkid::WelcomeWindow::keyboardWindowRequested,
      &welcome_window, &QWidget::hide
    );

    QObject::connect(
      &welcome_window, &hatkid::WelcomeWindow::keyboardWindowRequested,
      &keyboard_window, &QWidget::show
    );
  
    welcome_window.show();
	
	
    return app.exec();
}
