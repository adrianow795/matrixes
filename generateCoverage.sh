#!/bin/bash

# Build the project
./runBuildLinux.sh

# Navigate to the build directory
cd build

# Run the tests
./matrix_tests

# Generate the initial coverage report
lcov --capture --directory . --output-file coverage.info --ignore-errors mismatch

# Remove coverage data for external and standard library files
lcov --remove coverage.info '/usr/*' '/opt/*' '*/googletest/*' '*/boost/*' --output-file coverage_filtered.info

# Remove coverage data for files outside your project directory
lcov --remove coverage_filtered.info '*/test/*' --output-file coverage_filtered.info

# Generate the HTML report
genhtml coverage_filtered.info --output-directory coverage_report

# Open the coverage report in a web browser
xdg-open coverage_report/index.html