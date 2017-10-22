/*
 *  Eye saver
 *
 *libs: sudo apt-get install libgtk-3-dev
 *compile: gcc `pkg-config --cflags gtk+-3.0` -o eye-saver eye-saver.c `pkg-config --libs gtk+-3.0`
 */
#include <gtk/gtk.h>

/* Time intervals */
guint small_break = 180;
guint long_break = 900;
guint sm_curr = 0;
guint sm_goal = 4;

gboolean toogle (gpointer data){
    GtkWidget *window = (GtkWidget*)data;
    gboolean visible = gtk_widget_is_visible (window);
    gtk_widget_set_visible (window, !visible);
    return TRUE;
}

gboolean hide (gpointer data){
    gtk_widget_hide ((GtkWidget*)data);
    return FALSE;
}

gboolean callback (gpointer data){
    /* Display short or long break */
    GtkWidget *window = (GtkWidget*)data;
    GtkWidget *label = gtk_bin_get_child(GTK_BIN(window));
    if (sm_curr < sm_goal){
        //gtk_label_set_markup((GtkLabel*) label, "<span background=\"black\" foreground=\"blue\" size=\"x-large\">Blue text</span> is <i>cool</i>!");
        gtk_label_set_text((GtkLabel*) label, "Take a 3 minute break!");
        gtk_widget_show_all (window);
        g_timeout_add_seconds(small_break, hide, window);
        sm_curr += 1;
    }else{
        gtk_label_set_text((GtkLabel*)label, "Take a 15 minute break!");
        gtk_widget_show_all (window);
        g_timeout_add_seconds(long_break, hide, window);
        sm_curr = 0;
    }
}

int main (int   argc, char *argv[]){
    GtkWidget *window;
    GtkWidget *label;
    GtkWidget *button;
    GdkRGBA black = {1.0, 1.0, 1.0};
    gtk_init (&argc, &argv);

    //window = gtk_window_new (GTK_WINDOW_POPUP);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Eye saver");
    gtk_window_set_default_size (GTK_WINDOW (window), 600, 400);
    gtk_window_maximize(GTK_WINDOW(window));
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_widget_override_background_color(window, GTK_STATE_FLAG_NORMAL, &black);

    label = gtk_label_new(NULL);
    gtk_container_add (GTK_CONTAINER (window), label);

    //button = gtk_button_new ();
    //gtk_container_add (GTK_CONTAINER (window), button);
    //g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);

    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_timeout_add_seconds(long_break, callback, window);

    gtk_main ();
    return 0;
}
