#include "Main.h"
#include "Frame.h"


bool Main::OnInit() {
	Frame *frame = new Frame();
	frame->SetMinSize(wxSize(400, 400));
	frame->Show();

	return true;
}
