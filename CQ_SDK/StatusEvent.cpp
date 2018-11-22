#include "StatusEvent.h"

#include "Unpack.h"
#include "tool.h"
#include "event.h"

void CQ::StatusEvent::color_green() { color = Ðü¸¡´°_ÂÌ; }
void CQ::StatusEvent::color_orange() { color = Ðü¸¡´°_³È; }
void CQ::StatusEvent::color_red() { color = Ðü¸¡´°_ºì; }
void CQ::StatusEvent::color_crimson() { color = Ðü¸¡´°_Éîºì; }
void CQ::StatusEvent::color_black() { color = Ðü¸¡´°_ºÚ; }
void CQ::StatusEvent::color_gray() { color = Ðü¸¡´°_»Ò; }

std::string CQ::statusEVEreturn(StatusEvent & eve)
{
	Unpack pack;
	std::string _ret = pack.add(eve.data).add(eve.dataf).add(eve.color).getAll();
	_ret = base64_encode(_ret);
	return _ret;
}