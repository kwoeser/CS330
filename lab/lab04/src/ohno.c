/*********************************************

CIS330: Lab 4

Implementation file for the error reporting system

*********************************************/

#include <ohno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static struct ohno_state *state;
/*
out 
name 
error number
*/


/*
 * Initialize the ohno error system with the given file stream and application name.
 *
 * This should allocate and populate the state structure.
 * Make sure to make a copy of `app_name` as we'll need to use this string later when `ohno()` is called.
 *
 * Feel free to return non-zero if anything went wrong (like not having sufficient memory).
 */
int ohno_init(FILE* where_to, const char* app_name)
{
	// Allocate memory with size of ohno_state
	state = malloc(sizeof(struct ohno_state));

	// Allocate memory for app_name; don't forget null character becasue of strlen
	state->name = malloc(strlen(app_name) + 1);
	// cpy
	strcpy(state->name, app_name);
	state->out = where_to;

	return 0;
}

/*
 * Free any memory allocated to the ohno error system.
 *
 * You allocated memory in `ohno_init()`, now you must give it back.
 */
void ohno_free() 
{
	free(state->name);
	free(state);	
}

/*
 * Report an error or warning given the current ohno error system settings (from ohno_init())
 *
 * This function should format `message` and `severity` along with the `app_name` string copied in `ohno_init()`
 * and write (print) a nice message on the saved `FILE *`.
 * The particular formating is up to you. Get creative if your like and feel free to add useful information
 * (e.g. error number or timestamp) to your report.
 */
void ohno(const char* message, ohno_severity_t severity)
{
	
	if (severity == OHNO_FATAL) {
		fprintf(state->out, "App Name: %s, Oh No! Fatal Error: %s\n", state->name, message);	
		exit(EXIT_FAILURE);
	} else if (severity == OHNO_SERIOUS) {
		fprintf(state->out, "App Name: %s, Oh No! Serious Error: %s\n", state->name, message);
		exit(EXIT_FAILURE);
	} else if (severity == OHNO_WARNING) { 
		fprintf(state->out, "App Name: %s, Oh No! Warning Error: %s\n", state->name, message);
		exit(EXIT_FAILURE);
	} else {
		fprintf(state->out, "App Name: %s, Oh No! Error: %s\n", state->name, message);
	}


	
}
