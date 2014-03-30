/*----------------------------------------------------------------------------
		Main TextView
	Main TextView.
----------------------------------------------------------------------------*/
#ifndef __MAIN_TEXTVIEW_H_DEFINED__
#define __MAIN_TEXTVIEW_H_DEFINED__


#include "dimensions.h"
#include "constants.h"
#include "helper.h"


class MainTextView : public Gtk::TextView
{
public:
	MainTextView();
	~MainTextView();
	void add_to_buffer(const char *);
	void add_to_buffer(const char *, bool);

private:
	Glib::RefPtr<Gtk::TextBuffer> m_text_buffer;
	Gtk::TextIter m_iter_start, m_iter_end;
	Pango::FontDescription font;
};


#endif//__MAIN_TEXTVIEW_H_DEFINED__