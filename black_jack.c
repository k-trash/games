#include <gtk/gtk.h>
#include "jack_gui.h"

int main(int argc, char *argv[]){
	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window, 600, 400);
	
	startAgain(NULL, NULL);
	
	gtk_main();

	return 0;
}
