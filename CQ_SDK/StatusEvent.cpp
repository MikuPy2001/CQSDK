#include "StatusEvent.h"

#include "Unpack.h"
#include "tool.h"
#include "event.h"

void CQ::StatusEvent::color_green() { color = ������_��; }
void CQ::StatusEvent::color_orange() { color = ������_��; }
void CQ::StatusEvent::color_red() { color = ������_��; }
void CQ::StatusEvent::color_crimson() { color = ������_���; }
void CQ::StatusEvent::color_black() { color = ������_��; }
void CQ::StatusEvent::color_gray() { color = ������_��; }

std::string CQ::statusEVEreturn(StatusEvent & eve)
{
	Unpack pack;
	std::string _ret = pack.add(eve.data).add(eve.dataf).add(eve.color).getAll();
	_ret = base64_encode(_ret);
	return _ret;
}