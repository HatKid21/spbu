#include "keyboard_window.hpp"

#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>


using biv::KeyBoardWindow;

KeyBoardWindow::KeyBoardWindow(QWidget* parent) : QWidget(parent) {
	const int keyboard_width = 1160;
	resize(keyboard_width, 710);
    setWindowTitle("Грустная Клавиатура");
	
	//QPixmap pixmap("projects/qt-keyboard/img/grustnii-smail.png");
	QPixmap pixmap("projects/qt-keyboard/img/grustnii-smail.png");
	image = new QLabel(this);
	image->setFixedSize(200, 200);
	image->setPixmap(pixmap);
	image->setScaledContents(true);
	
	QHBoxLayout* smail_layout = new QHBoxLayout();
	smail_layout->addWidget(image);

    display = new QLineEdit();
	display->setMinimumHeight(80);
	display->setFont(QFont("Roboto", 40));
    display->setReadOnly(true);
	display->setText("Помоги мне заработать лучше...");

	keyboard = new KeyBoard(keyboard_width);

    QVBoxLayout* main_layout = new QVBoxLayout(this);
	main_layout->addLayout(smail_layout);
    main_layout->addWidget(display);
    main_layout->addWidget(keyboard);

    connect(keyboard, &KeyBoard::keyClicked,this, &KeyBoardWindow::appendText);
    connect(keyboard, &KeyBoard::backspaceClicked, this, &KeyBoardWindow::eraseText);
}

void KeyBoardWindow::keyPressEvent(QKeyEvent* event) {
	const int key = event->key();
  if (key == Qt::Key_Backspace){
    eraseText();
    keyboard->press_button(key);
    return;
  }

  if (key == Qt::Key_Space){
    appendText(" ");
    keyboard->press_button(key);
    return;
  }

  if (key == Qt::Key_CapsLock){
    keyboard->toggleCaps();
    keyboard->press_button(key);
    return;
  }

  if (key == Qt::Key_Return){
    QString curText = display->text();
    if (curText.toLower() == "козяблик"){
      QPixmap pixmap("projects/qt-keyboard/img/vesely-smail.jpg");
      image->setPixmap(pixmap);
    } else{
      QPixmap pixmap("projects/qt-keyboard/img/grustnii-smail.png");
      image->setPixmap(pixmap);
    }
    
    display->setText("");
    keyboard->press_button(key); 
    return;
  }


	if (keyboard->is_key_allowed(key)) {
    appendText(keyboard->get_key_text(key));
		keyboard->press_button(key);
	}


}

void KeyBoardWindow::keyReleaseEvent(QKeyEvent* event) {
    const int key = event->key();

    if (keyboard->is_key_allowed(key)) {
        keyboard->release_button(key);
    }
}

void KeyBoardWindow::appendText(const QString& text){
  display->setText(display->text() + text);
}

void KeyBoardWindow::eraseText(){
  QString text = display->text();

  if (!text.isEmpty()){
    display->setText(text.left(text.length() - 1) );
  }
}
