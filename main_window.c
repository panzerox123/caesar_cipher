#include <gtk-3.0/gtk/gtk.h>
#include <stdio.h>
#include "cypher.h"
#include<string.h>

GtkWidget *entry_str_label;
GtkWidget *key_str_label;
GtkWidget *opt_str_label;
GtkWidget *window;
GtkWidget *encrypt_btn;
GtkWidget *decrypt_btn;
GtkWidget *grid;
GtkWidget *entry_string;
GtkWidget *key_string;
GtkWidget *status_label;
GtkWidget *status_box;
GtkTextBuffer *buffer;

void destroy_window(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void encrypt_caller()
{
    char * data = gtk_entry_get_text(entry_string);
    char * key_val = gtk_entry_get_text(key_string);
    int key = atoi(key_val);
    char temp[50];
    strcpy(temp,data);
    gtk_text_buffer_insert_at_cursor(buffer,"Data: ",-1);
    gtk_text_buffer_insert_at_cursor(buffer,data,-1);
    gtk_text_buffer_insert_at_cursor(buffer,"\tKey: ",-1);
    gtk_text_buffer_insert_at_cursor(buffer,key_val,-1);
    char * out = encrypt(temp,key);
    gtk_text_buffer_insert_at_cursor(buffer,"\tEncrypted data: ",-1);
    gtk_text_buffer_insert_at_cursor(buffer,out,-1);
    gtk_text_buffer_insert_at_cursor(buffer,"\n",-1);
    write_to_file(data,key,out,"Encrypted");
}

static void decrypt_caller()
{
    char * data = gtk_entry_get_text(entry_string);
    char * key_val = gtk_entry_get_text(key_string);
    int key = atoi(key_val);
    char temp[50];
    strcpy(temp,data);
    gtk_text_buffer_insert_at_cursor(buffer,"Data: ",-1);
    gtk_text_buffer_insert_at_cursor(buffer,data,-1);
    gtk_text_buffer_insert_at_cursor(buffer,"\tKey: ",-1);
    gtk_text_buffer_insert_at_cursor(buffer,key_val,-1);
    char * out = decrypt(temp,key);
    gtk_text_buffer_insert_at_cursor(buffer,"\tDecrypted data: ",-1);
    gtk_text_buffer_insert_at_cursor(buffer,out,-1);
    gtk_text_buffer_insert_at_cursor(buffer,"\n",-1);
    write_to_file(data,key,out,"Decrypted");
}

int main(int argc, char *argv[])
{
    //Init
    gtk_init(&argc, &argv);
    grid = gtk_grid_new();
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy_window), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);
    encrypt_btn = gtk_button_new_with_label("ENCRYPT");
    decrypt_btn = gtk_button_new_with_label("DECRYPT");
    entry_string = gtk_entry_new();
    key_string = gtk_entry_new();
    status_box = gtk_text_view_new();
    entry_str_label = gtk_label_new("Enter string to code/decode:");
    key_str_label = gtk_label_new("Enter Key value:");
    opt_str_label = gtk_label_new("Encrypt/Decrypt?");
    status_label = gtk_label_new("Status:");
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(status_box));
    //Signal Handler
    g_signal_connect(GTK_WIDGET(encrypt_btn), "clicked", G_CALLBACK(encrypt_caller), "button");
    g_signal_connect(GTK_WIDGET(decrypt_btn), "clicked", G_CALLBACK(decrypt_caller), "button");
    //Setting Grid
    gtk_grid_set_row_homogeneous(grid, TRUE);
    gtk_grid_set_column_homogeneous(grid, TRUE);
    gtk_text_view_set_editable(status_box, FALSE);
    gtk_grid_attach(GTK_GRID(grid), entry_str_label, 0, 0, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_string, 0, 1, 4, 1);
    gtk_grid_attach(GTK_GRID(grid), key_str_label, 0, 2, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), key_string, 0, 3, 4, 1);
    gtk_grid_attach(GTK_GRID(grid), opt_str_label, 0, 5, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), encrypt_btn, 0, 6, 4, 2);
    gtk_grid_attach(GTK_GRID(grid), decrypt_btn, 6, 6, 4, 2);
    gtk_grid_attach(GTK_GRID(grid), status_label, 0, 8, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), status_box, 0, 10, 8, 5);
    gtk_container_add(GTK_CONTAINER(window), grid);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
