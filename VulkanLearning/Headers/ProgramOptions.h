#ifndef _PROGRAM_OPTIONS_H_
#define _PROGRAM_OPTIONS_H_

#include <..\boost\program_options.hpp>

namespace po = boost::program_options;

/*
* ===============================================
* Options
* [--verbose]			Extra output inmformation
* ===============================================
*/

class ProgramOptions {
public:
	static void setupProgramOptions(int argc, char* argv[]);
};

#endif // _PROGRAM_OPTIONS_H_