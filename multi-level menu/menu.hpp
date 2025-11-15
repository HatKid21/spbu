#pragma once

namespace hatkid {
	struct MenuItem {
		const char* const title;
		void (*func)();
	};
}
