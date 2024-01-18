import os
import sys
import subprocess

# Commands
compile_cmd = "g++ solver.cpp -std=c++11 -o solver.x"
test_cmd = "./solver.x < "

# Testcase
testcase = "tests/testcase.txt"
solution = "Solved Board: \n🟦🟥🟦🟥\n🟦🟥🟥🟦\n🟥🟦🟦🟥\n🟥🟦🟥🟦"

# Run Commands
try:
    output = subprocess.check_output(compile_cmd, stderr=subprocess.STDOUT, shell=True)
except subprocess.CalledProcessError as exc:  # If compile failed
    print("Status: Failed to compile (", exc.returncode, ")\n", exc.output)
else:  # If successful compile
    result = os.popen(test_cmd + testcase)

    # Check
    if solution in result.read():
        print("Test Case Passed.")
    else:
        print("Test Case Failed.")