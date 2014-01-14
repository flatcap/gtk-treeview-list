#ifndef _EXAMPLEWINDOW_H_
#define _EXAMPLEWINDOW_H_

#include <gtkmm.h>

class ExampleWindow : public Gtk::Window
{
public:
	ExampleWindow (void);
	~ExampleWindow() = default;

protected:
	class ModelColumns : public Gtk::TreeModel::ColumnRecord
	{
	public:
		ModelColumns()
		{
			add (m_col_id);
			add (m_col_name);
			add (m_col_number);
			add (m_col_percentage);
		}

		Gtk::TreeModelColumn<int>           m_col_id;
		Gtk::TreeModelColumn<Glib::ustring> m_col_name;
		Gtk::TreeModelColumn<short>         m_col_number;
		Gtk::TreeModelColumn<int>           m_col_percentage;
	};

	ModelColumns m_Columns;

	Gtk::Box m_VBox;

	Gtk::TreeView m_TreeView;
	Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
};

#endif // _EXAMPLEWINDOW_H_

