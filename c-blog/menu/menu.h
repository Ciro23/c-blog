#ifndef menu_h
#define menu_h

/**
 * Displays a menu with all the available options for
 * this program.
 * @return 1 to stop the execution of the program, or any
 * other number otherwise.
 */
int display_choices(void);
void call_selected_feature(int feature);

#endif /* menu_h */
