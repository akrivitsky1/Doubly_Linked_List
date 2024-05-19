#exe = exename #to be set on the command line
build_dir = build
all:
	cmake -E remove_directory $(build_dir)
	cmake -E make_directory $(build_dir)
	cmake -S . -B $(build_dir)
	cmake --build $(build_dir) --clean-first
	cmake -E copy $(build_dir)/$(exe) .
	cmake -E remove_directory $(build_dir)
