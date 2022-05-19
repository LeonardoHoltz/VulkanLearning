#include "../Headers/ProgramOptions.h"

void ProgramOptions::setupProgramOptions(int argc, char* argv[]) {
	po::options_description desc("Allowed options");
	desc.add_options()("verbose", "Allow all program outputs to be showed.");
	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);
}