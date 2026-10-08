#pragma once

#include <cstddef>
#include <unordered_map>

#include <QGridLayout>
#include <QWidget>

#include "keyboard_button.hpp"
#include "keyboard_data.hpp"
#include "key_data.hpp"

namespace biv {
	class KeyBoard : public QWidget {
    Q_OBJECT
		private:
			const int button_width;
			std::unordered_map<int, KeyBoardButton*> buttons;
			
			KeyBoardData* keyboard_data;

      bool capsLock = false;
		
		public:
			KeyBoard(const int width, QWidget* parent = nullptr);
			
			QString get_key_text(const int code) const;
			bool is_key_allowed(const int code) const noexcept;
      void toggleCaps();
      void press_button(const int code);
      void release_button(const int code);
			
		private:
			void create_buttons(
				const std::vector<KeyData>& data, 
				QGridLayout* layout, 
				const int line,
				const int start_position
			);
    signals:
      void keyClicked(const QString& test);
      void backspaceClicked();

	};
}
