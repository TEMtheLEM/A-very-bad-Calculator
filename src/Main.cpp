#include "Main.h"
#include "Frame.h"


Main::Main() {}

Main::~Main() {}

bool Main::OnInit() {
	Frame *frame = new Frame();
	frame->Show();
	return true;
}
