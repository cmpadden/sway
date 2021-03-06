#include <strings.h>
#include "sway/commands.h"
#include "sway/config.h"

struct cmd_results *cmd_focus_wrapping(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "focus_wrapping", EXPECTED_EQUAL_TO, 1))) {
		return error;
	}

	if (strcasecmp(argv[0], "no") == 0) {
		config->focus_wrapping = WRAP_NO;
	} else if (strcasecmp(argv[0], "yes") == 0) {
		config->focus_wrapping = WRAP_YES;
	} else if (strcasecmp(argv[0], "force") == 0) {
		config->focus_wrapping = WRAP_FORCE;
	} else {
		return cmd_results_new(CMD_INVALID, "focus_wrapping",
				"Expected 'focus_wrapping yes|no|force'");
	}

	return cmd_results_new(CMD_SUCCESS, NULL, NULL);
}
