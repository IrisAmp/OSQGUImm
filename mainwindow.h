/*----------------------------------------------------------------------------
		Main Window
	Defines the main window for the application.
----------------------------------------------------------------------------*/
#ifndef __OSQGUIMM_MAINWINDOW_H_DEFINED__
#define __OSQGUIMM_MAINWINDOW_H_DEFINED__


#include "constants.h"
#include "dimensions.h"
#include "helper.h"
#include "maintextview.h"


class MainWindow : public Gtk::Window
{
public:
	MainWindow();
	virtual ~MainWindow();

	// Signal Handlers
	void on_button_clicked(Glib::ustring data);
	void create_conn_settings_window();
	void create_setpoints_window();
	void on_control_safe();
	void on_control_sticky();
	void on_help_about();

private:
	// Child Widgets
	Gtk::VBox m_boxV0;
	Gtk::HBox m_boxH0, m_boxH1;
	Gtk::ToggleButton m_button0, m_button1;
	Gtk::HSeparator m_separator;
	Gtk::Frame m_frame_textview, m_frame_controlbuttons;
	Gtk::Alignment m_alignment;

	Gtk::Table m_table;
	Gtk::Button m_control_w, m_control_a,
	            m_control_s, m_control_d,
	            m_control_q, m_control_e;

	MainTextView m_textview;

	// Menus
	Glib::RefPtr<Gtk::UIManager> m_refUIManager;
	Glib::RefPtr<Gtk::ActionGroup> m_refActionGroup, m_refControlGroup;
	Glib::RefPtr<Gtk::CheckMenuItem> m_refSafe, m_refSticky;
};


#endif//__OSQGUIMM_MAINWINDOW_H_DEFINED__