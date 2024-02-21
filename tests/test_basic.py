import os
import sys
import subprocess

# Commands
compile_cmd = "g++ solver.cpp -std=c++11 -o solver.out"
run_cmd = "../solver.out < "

# Testcase
testcase = "testcase.txt"
solution = "Solved Board: \n🟦🟥🟦🟥\n🟦🟥🟥🟦\n🟥🟦🟦🟥\n🟥🟦🟥🟦"

# Test function
def test_correct():
    # Run Commands
    try:
        output = subprocess.check_output(compile_cmd, stderr=subprocess.STDOUT, shell=True)
    except subprocess.CalledProcessError as exc:  # If compile failed
        print("Status: Failed to compile (", exc.returncode, ")\n", exc.output)
    else:  # If successful compile
        result = os.popen(run_cmd + testcase)

        # Check
        assert solution in result.read()
        print("Test Case Passed")