#!/bin/bash

./runBuildLinux.sh
# Generate coverage report
cd build
./matrix_tests
lcov --capture --directory . --output-file coverage.info --ignore-errors mismatch
lcov --remove coverage.info '/usr/*' --output-file coverage_filtered.info
genhtml coverage.info --output-directory coverage_report
# Open the coverage report in a web browser
xdg-open coverage_report/index.html
