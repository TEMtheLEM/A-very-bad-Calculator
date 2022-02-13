#include "Main.h"
#include "Frame.h"


bool Main::OnInit() {
	Frame *frame = new Frame();
	frame->Show();
	return true;
}
