#include <stdlib.h>
#include <gtk/gtk.h>

void cbButtonClicked(GtkWidget *button_, gpointer user_data_);
void changeCards(GtkWidget *button_, gpointer user_data_);

GtkWidget *window;
GtkWidget *vbox;

int main(int argc, char *argv[]){
	GtkWidget *vbox_image;
	GtkWidget *hbox_button;
	GtkWidget *button_1;
	GtkWidget *button_2;
	GtkWidget *image_1;	
	GtkWidget *image_2;	

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	vbox = gtk_vbox_new(FALSE, 2);
	vbox_image = gtk_hbox_new(FALSE, 2);
	hbox_button = gtk_hbox_new(FALSE, 2);
	button_1 = gtk_button_new_with_label("Quit");
	button_2 = gtk_button_new_with_label("Button");
	image_1 = gtk_image_new_from_file("./cards/spade_1.png");
	image_2 = gtk_image_new_from_file("./cards/spade_2.png");
	
	gtk_widget_set_size_request(window, 300, 200);
	
	gtk_container_add(GTK_CONTAINER(window), vbox);

	gtk_box_pack_start(GTK_BOX(vbox), vbox_image, TRUE, TRUE, 0);
	
	gtk_box_pack_start(GTK_BOX(vbox_image), image_1, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_image), image_2, TRUE, TRUE, 0);

	gtk_box_pack_start(GTK_BOX(vbox), hbox_button, TRUE, TRUE, 0);

	g_signal_connect(G_OBJECT(button_1), "clicked", G_CALLBACK(cbButtonClicked), NULL);

	gtk_box_pack_start(GTK_BOX(hbox_button), button_1, TRUE, TRUE, 0);

	g_signal_connect(G_OBJECT(button_2), "clicked", G_CALLBACK(changeCards), vbox_image);

	gtk_box_pack_start(GTK_BOX(hbox_button), button_2, TRUE, TRUE, 0);

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}

void cbButtonClicked(GtkWidget *button_, gpointer user_data_){
	gtk_main_quit();
}

void changeCards(GtkWidget *button_, gpointer user_data_){
	GtkWidget *image_3;
	//gtk_container_remove(GTK_CONTAINER(vbox), user_data_);
	user_data_ = gtk_hbox_new(FALSE, 2);
	gtk_box_pack_start(GTK_BOX(vbox), user_data_, TRUE, TRUE, 0);
	image_3 = gtk_image_new_from_file("./cards/spade_3.png");
	gtk_box_pack_start(GTK_BOX(user_data_), image_3, TRUE, TRUE, 0);
	gtk_widget_show_all(window);
}
