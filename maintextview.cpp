#include "stdafx.h"
#include "maintextview.h"

MainTextView::MainTextView()
{
	set_editable(false);
	set_cursor_visible(false);

	m_text_buffer = get_buffer();
	m_text_buffer -> get_bounds(m_iter_start, m_iter_end);
	
	font.set_family(MAIN_FONT);
	modify_font(font);
}

MainTextView::~MainTextView()
{

}

void MainTextView::add_to_buffer(const char *text)
{
	char buff[16];
	CurrentTime(buff, 16);
	m_iter_end = m_text_buffer -> insert(m_iter_end, buff);
	m_iter_end = m_text_buffer -> insert(m_iter_end, text);
}

void MainTextView::add_to_buffer(const char *text, bool stamp)
{
	char buff[16];
	CurrentTime(buff, 16);
	if (stamp) m_iter_end = m_text_buffer -> insert(m_iter_end, buff);
	m_iter_end = m_text_buffer -> insert(m_iter_end, text);
}