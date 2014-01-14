#ifndef _EXAMPLEWINDOW_H_
#define _EXAMPLEWINDOW_H_

#include <gtkmm.h>

class ExampleWindow : public Gtk::Window
{
public:
	ExampleWindow (void);
	~ExampleWindow() = default;

protected:
	Gtk::TreeModelColumn<int>           m_col_id;
	Gtk::TreeModelColumn<Glib::ustring> m_col_name;
	Gtk::TreeModelColumn<short>         m_col_number;
	Gtk::TreeModelColumn<int>           m_col_percentage;

	Gtk::TreeModel::ColumnRecord m_Columns;

	Gtk::TreeView m_TreeView;
	Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
};

#endif // _EXAMPLEWINDOW_H_

