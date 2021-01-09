#include <stdlib.h>
#include <gtk/gtk.h>

void cb_button_clicked(GtkWidget *button, gpointer user_data);

int main(int argc, char *argv[]){
	GtkWidget *window;
	GtkWidget *vbox;
	GtkWidget *scroll_window;
	GtkWidget *button;
	GtkWidget *image;	
	
	
	
	if(argc != 2){
		g_print("No Image File\n");
		exit(1);
	}

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	vbox = gtk_vbox_new(FALSE, 2);
	scroll_window = gtk_scrolled_window_new(NULL,NULL);
	button = gtk_button_new_with_label("Quit");
	image = gtk_image_new_from_file(argv[1]);
	
	gtk_widget_set_size_request(window, 300, 200);
	
	gtk_container_add(GTK_CONTAINER(window), vbox);
			
	gtk_box_pack_start(GTK_BOX(vbox), scroll_window, TRUE, TRUE, 0);
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	
		
	gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scroll_window), image);
	
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(cb_button_clicked), NULL);

	gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);
		
	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}

void cb_button_clicked(GtkWidget *button, gpointer user_data){
	gtk_main_quit();
}
